#include "../include/pseudo_assembly.h"
#include "../include/assembly_generator.h"
#include <string.h>

// List for instructions requiring more than six parameters
PseudoAssembly* extraParamInstructions = NULL;

// Head of the pseudo-assembly instruction list
PseudoAssembly* instructionList = NULL;

// Label counter for generating unique labels
int labelCounter = 1;

// Counter for required parameters in a function
int requiredParamCount = 0;

/**
 * Create and prepend a new pseudo-assembly instruction to the instruction list.
 */
void addPseudoAssemblyInstruction(ASM opcode, TData* operand1, TData* operand2, TData* result) {
    PseudoAssembly* newInstruction = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    newInstruction->tag = opcode;
    newInstruction->op1 = operand1;
    newInstruction->op2 = operand2;
    newInstruction->result = result;
    newInstruction->next = instructionList;
    instructionList = newInstruction;
}

/**
 * Add a comparison operation to the instruction list.
 */
void addComparisonOperation(TOKENS operation, TData* operand1, TData* operand2, TData* result) {
    switch(operation) {
        case T_GREATER_THAN: addPseudoAssemblyInstruction(T_GREATER, operand1, operand2, result); break;
        case T_LESS_THAN:    addPseudoAssemblyInstruction(T_LESS, operand1, operand2, result); break;
        case EEQ:            addPseudoAssemblyInstruction(T_EQUAL, operand1, operand2, result); break;
        default: break;
    }
}

/**
 * Add a boolean operation to the instruction list.
 */
void addBooleanOperation(TOKENS operation, TData* operand1, TData* operand2, TData* result) {
    switch(operation) {
        case EAND: addPseudoAssemblyInstruction(T_AND, operand1, operand2, result); break;
        case EOR:  addPseudoAssemblyInstruction(T_OR, operand1, operand2, result); break;
        default: break;
    }
}

/**
 * Add an arithmetic operation to the instruction list.
 * Checks for division/modulo by zero.
 */
void addArithmeticOperation(TOKENS operation, TData* operand1, TData* operand2, TData* result) {
    switch(operation) {
        case PLUS:  addPseudoAssemblyInstruction(T_PLUS, operand1, operand2, result); break;
        case MINUS: addPseudoAssemblyInstruction(T_MINUS, operand1, operand2, result); break;
        case PROD:  addPseudoAssemblyInstruction(T_PROD, operand1, operand2, result); break;
        case EDIV:
            if ((operand2 && operand2->value == 0) || (findInstructionResult(operand2->varname) && findInstructionResult(operand2->varname)->value == 0)) {
                printf("\033[31mCannot divide by zero\033[0m, error at line: %d\n", operand1->line);
                exit(1);
            }
            addPseudoAssemblyInstruction(T_DIV, operand1, operand2, result);
            break;
        case EMOD:
            if ((operand2 && operand2->value == 0) || (findInstructionResult(operand2->varname) && findInstructionResult(operand2->varname)->value == 0)) {
                printf("\033[31mCannot modulo by zero\033[0m, error at line: %d\n", operand1->line);
                exit(1);
            }
            addPseudoAssemblyInstruction(T_MOD, operand1, operand2, result);
            break;
        default: break;
    }
}

/**
 * Add a translation of an AST operation to pseudo-assembly instructions.
 */
void translateASTOperation(TOKENS operation, Tree* leftNode, Tree* rightNode, Tree* resultNode) {
    TData *leftSymbol = leftNode->symbol;
    TData *rightSymbol = rightNode ? rightNode->symbol : NULL;
    TData *resultSymbol = resultNode->symbol;
    TData *rightLookup = rightNode ? findInstructionResult(rightNode->symbol->varname) : NULL;

    switch(operation) {
        case ASIGN:
            if(rightLookup) {
                leftSymbol->value = rightLookup->value;
            } else if(rightSymbol) {
                leftSymbol->value = rightSymbol->value;
            }
            addPseudoAssemblyInstruction(T_ASIGN, leftSymbol, rightSymbol, leftSymbol);
            break;
        case PLUS: case MINUS: case PROD: case EDIV: case EMOD:
            addArithmeticOperation(operation, leftSymbol, rightSymbol, resultSymbol);
            break;
        case EAND: case EOR:
            addBooleanOperation(operation, leftSymbol, rightSymbol, resultSymbol);
            break;
        case T_GREATER_THAN: case T_LESS_THAN: case EEQ:
            addComparisonOperation(operation, leftSymbol, rightSymbol, resultSymbol);
            break;
        case EWHILE:
            addPseudoAssemblyInstruction(T_WHILE, leftSymbol, rightSymbol, resultSymbol);
            break;
        case EIF:
            addPseudoAssemblyInstruction(T_IF, leftSymbol, rightSymbol, resultSymbol);
            break;
        case ENOT:
            addPseudoAssemblyInstruction(T_NOT, leftSymbol, rightSymbol, resultSymbol);
            break;
        default: break;
    }
}

/**
 * Find a result symbol in the pseudo-assembly instruction list by name.
 */
TData *findInstructionResult(char *name) {
    if (!name) return NULL;
    PseudoAssembly* current = instructionList;
    while(current) {
        if(current->result && strcmp(name, current->result->varname) == 0)
            return current->result;
        current = current->next;
    }
    return NULL;
}

/**
 * Generate pseudo-assembly instructions from an AST and reverse the instruction list.
 */
void generateThreeAddressCode(Tree* astRoot) {
    generateCode(astRoot);
    invertASM(&instructionList);
}

/**
 * Generate pseudo-assembly instructions for global variables.
 */
void generateGlobalVariableInstructions() {
    TData *scope = getSymbolTable();
    while(scope) {
        TData *entry = scope->table;
        while(entry) {
            if(entry->token == VARINT || entry->token == VARBOOL) {
                char *dummyName = "_";
                addPseudoAssemblyInstruction(T_GLOBAL, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), entry);
            }
            entry = entry->next;
        }
        scope = scope->next;
    }
}

/**
 * Recursively generate pseudo-assembly instructions from an AST.
 */
void generateCode(Tree* node) {
    if (!node) return;
    TOKENS nodeToken = node->symbol->token;
    if (nodeToken == ERETURN) {
        handleReturnOperation(node);
        createReturnInstruction(node->left->symbol);
    } else if (nodeToken == RETINT || nodeToken == RETBOL || nodeToken == RETVOID) {
        if (strcmp(node->symbol->varname, "main") == 0) {
            handleMainFunction(node);
            createFunctionEndInstruction(node->symbol);
        } else {
            handleFunctionDefinition(node);
            requiredParamCount = 0;
            createFunctionEndInstruction(node->symbol);
        }
    } else if (nodeToken == CALL_F) {
        processOperations(node->right);
        processFunctionCalls(node->right);
        generateParameterLoadInstructions(node->right);
        createFunctionCallInstruction(node->left->symbol, node->symbol);
    } else if (nodeToken == EIF) {
        handleIfStatement(node);
    } else if (nodeToken == EWHILE) {
        handleWhileStatement(node);
    } else {
        if (strcmp(node->symbol->varname, "PROGRAM") == 0) {
            generateGlobalVariableInstructions();
        }
        if (node->right && node->left) {
            handleBinaryOperation(node);
        } else if (node->left) {
            handleUnaryOperation(node);
        } else if (node->right) {
            generateCode(node->right);
        }
    }
}

/**
 * Handle code generation for return operations.
 */
void handleReturnOperation(Tree* node) {
    if (node->left) generateCode(node->left);
    if (node->right) generateCode(node->right);
}

/**
 * Handle code generation for the main function.
 */
void handleMainFunction(Tree* node) {
    createFunctionStartInstruction(node->symbol);
    if (node->left) generateCode(node->left);
    if (node->right) generateCode(node->right);
    if (node->symbol->token == RETVOID) {
        char *dummyName = " ";
        addPseudoAssemblyInstruction(T_RETURN, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0));
    }
}

/**
 * Recursively process arithmetic, boolean, and comparison operations in the AST.
 */
void processOperations(Tree* node) {
    if (!node) return;
    if (node->left) processOperations(node->left);
    if (node->right) processOperations(node->right);
    TOKENS nodeToken = node->symbol->token;
    bool isArithmetic = (nodeToken == PLUS || nodeToken == MINUS || nodeToken == PROD || nodeToken == EDIV || nodeToken == EMOD);
    bool isBoolean = (nodeToken == EOR || nodeToken == EAND || nodeToken == ENOT);
    bool isComparison = (nodeToken == T_GREATER_THAN || nodeToken == T_LESS_THAN || nodeToken == EEQ);
    if (isArithmetic || isBoolean || isComparison) {
        generateCode(node);
    }
}

/**
 * Recursively process function calls in the AST.
 */
void processFunctionCalls(Tree* node) {
    if (!node) return;
    if (node->left) processFunctionCalls(node->left);
    if (node->right) processFunctionCalls(node->right);
    if (node->symbol->token == CALL_F) {
        generateParameterLoadInstructions(node->right);
        createFunctionCallInstruction(node->left->symbol, node->symbol);
    }
}

/**
 * Recursively generate parameter load instructions for function calls.
 */
void generateParameterLoadInstructions(Tree* node) {
    if (!node) return;
    TOKENS nodeToken = node->symbol->token;
    if (nodeToken != ARGS) {
        createParameterLoadInstruction(node->symbol);
    }
    bool notArithmetic = (nodeToken != PLUS && nodeToken != MINUS && nodeToken != PROD && nodeToken != EDIV && nodeToken != EMOD);
    bool notBoolean = (nodeToken != EOR && nodeToken != EAND && nodeToken != ENOT);
    bool notComparison = (nodeToken != T_GREATER_THAN && nodeToken != T_LESS_THAN && nodeToken != EEQ);
    bool isNotType = (nodeToken != CALL_F && (notArithmetic && notBoolean && notComparison));
    if (isNotType) {
        if (node->left) generateParameterLoadInstructions(node->left);
        if (node->right) generateParameterLoadInstructions(node->right);
    }
}

/**
 * Create a pseudo-assembly instruction for loading a parameter.
 */
void createParameterLoadInstruction(TData* symbol) {
    char *dummyName = "_";
    addPseudoAssemblyInstruction(T_LOAD_PARAM, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), symbol);
}

/**
 * Concatenate two pseudo-assembly instruction lists.
 */
void concatenateInstructionLists(PseudoAssembly *list1, PseudoAssembly *list2) {
    if (!list2) return;
    PseudoAssembly *current = list2;
    while (current->next) current = current->next;
    current->next = list1;
    instructionList = list2;
}

/**
 * Handle code generation for function definitions.
 */
void handleFunctionDefinition(Tree* node) {
    createFunctionStartInstruction(node->symbol);
    if (node->left) {
        processRequiredParameters(node->left);
        invertASM(&extraParamInstructions);
        concatenateInstructionLists(instructionList, extraParamInstructions);
        extraParamInstructions = NULL;
    }
    if (node->right) generateCode(node->right);
    if (node->symbol->token == RETVOID) {
        char *dummyName = " ";
        addPseudoAssemblyInstruction(T_RETURN, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0));
    }
}

/**
 * Recursively process required parameters for a function.
 */
void processRequiredParameters(Tree* node) {
    if (!node) return;
    if (node->symbol->token == PARAMBOOL || node->symbol->token == PARAMINT) {
        requiredParamCount += 1;
        createRequiredParameterInstruction(node->symbol);
    }
    if (node->left) processRequiredParameters(node->left);
    if (node->right) processRequiredParameters(node->right);
}

/**
 * Create a pseudo-assembly instruction for a function call.
 */
void createFunctionCallInstruction(TData* functionName, TData* tempResult) {
    char *dummyName = "_";
    addPseudoAssemblyInstruction(T_CALL, functionName, createSymbol(dummyName, OTHERS, 0, 0), tempResult);
}

/**
 * Create a pseudo-assembly instruction for function start/end.
 */
void createFunctionStartInstruction(TData* functionSymbol) {
    char *dummyName = "_";
    addPseudoAssemblyInstruction(T_FUNC, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), functionSymbol);
}
void createFunctionEndInstruction(TData* functionSymbol) {
    char *dummyName = "_";
    addPseudoAssemblyInstruction(T_END_FUN, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), functionSymbol);
}

/**
 * Handle code generation for IF statements.
 */
void handleIfStatement(Tree* node) {
    generateCode(node->left);
    PseudoAssembly* falseBranch = createFalseBranchLabel(T_IFF, node->left->symbol);
    char* falseLabelName = strdup(falseBranch->result->varname);
    falseBranch->next = instructionList;
    instructionList = falseBranch;

    if (strcmp(node->symbol->varname, "if_then") == 0) {
        generateCode(node->right);
        createLabelInstruction(falseLabelName);
    } else if (strcmp(node->symbol->varname, "if_else") == 0) {
        generateCode(node->right->left);  // then
        PseudoAssembly* jump = createJumpInstruction();
        jump->next = instructionList;
        instructionList = jump;
        createLabelInstruction(falseLabelName);
        generateCode(node->right->right->left); // else
        createLabelInstruction(jump->result->varname);
    }
    free(falseLabelName);
}

/**
 * Handle code generation for WHILE statements.
 */
void handleWhileStatement(Tree* node) {
    PseudoAssembly* jump = createJumpInstruction();
    createLabelInstruction(jump->result->varname);
    generateCode(node->left);
    PseudoAssembly* falseBranch = createFalseBranchLabel(T_WF, node->left->symbol);
    falseBranch->next = instructionList;
    instructionList = falseBranch;
    generateCode(node->right);
    jump->next = instructionList;
    instructionList = jump;
    createLabelInstruction(falseBranch->result->varname);
}

/**
 * Handle code generation for binary operations.
 */
void handleBinaryOperation(Tree* node) {
    if (node->left) generateCode(node->left);
    if (node->right) generateCode(node->right);
    TOKENS nodeToken = node->symbol->token;
    bool isAssignmentOrBool = nodeToken == ASIGN || nodeToken == EAND || nodeToken == EOR || nodeToken == EEQ || nodeToken == T_GREATER_THAN || nodeToken == T_LESS_THAN;
    bool isArithmetic = nodeToken == PLUS || nodeToken == MINUS || nodeToken == PROD || nodeToken == EMOD || nodeToken == EDIV;
    if (isAssignmentOrBool || isArithmetic) {
        translateASTOperation(nodeToken, node->left, node->right, node);
    }
}

/**
 * Handle code generation for unary operations.
 */
void handleUnaryOperation(Tree* node) {
    generateCode(node->left);
    if (node->symbol->token == ENOT) {
        translateASTOperation(node->symbol->token, node->left, NULL, node);
    }
}

/**
 * Reverse the pseudo-assembly instruction list.
 */
void invertASM(PseudoAssembly **list) {
    PseudoAssembly* prev = NULL;
    PseudoAssembly* current = *list;
    PseudoAssembly* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

/**
 * Free all pseudo-assembly instructions.
 */
void freePseudoAssemblyInstructions() {
    PseudoAssembly* current = instructionList;
    while (current) {
        PseudoAssembly* next = current->next;
        if (current->tag == T_IFF) {
            free(current->op2);
            free(current->result);
        } else if (current->tag == T_JUMP || current->tag == T_LABEL) {
            free(current->op1);
            free(current->op2);
            free(current->result);
        }
        free(current);
        current = next;
    }
}

/**
 * Print all pseudo-assembly instructions for debugging.
 */
void printPseudoAssemblyInstructions() {
    PseudoAssembly* current = instructionList;
    printf("\nInstructions\n");
    while (current) {
        if (current->op1 && current->op2) {
            printf("%s %s %s %s\n", tagName[current->tag], current->op1->varname, current->op2->varname, current->result->varname);
        } else if (!current->op1 && current->op2) {
            printf("%s   %s %s\n", tagName[current->tag], current->op2->varname, current->result->varname);
        } else if (current->op1 && !current->op2) {
            printf("%s %s   %s\n", tagName[current->tag], current->op1->varname, current->result->varname);
        } else {
            printf("%s     %s\n", tagName[current->tag], current->result->varname);
        }
        current = current->next;
    }
}

/**
 * Create a pseudo-assembly instruction for a false branch label (used in IF/WHILE).
 */
PseudoAssembly* createFalseBranchLabel(ASM opcode, TData* condition) {
    PseudoAssembly* instruction = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    instruction->tag = opcode;
    instruction->op1 = condition;
    char *dummyName = "_";
    instruction->op2 = createSymbol(dummyName, OTHERS, 0, 0);
    char* labelName = generateUniqueLabelName();
    instruction->result = createSymbol(labelName, OTHERS, 0, 0);
    instruction->next = NULL;
    return instruction;
}

/**
 * Create a pseudo-assembly jump instruction.
 */
PseudoAssembly* createJumpInstruction() {
    PseudoAssembly* jump = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    jump->tag = T_JUMP;
    char *dummyName = "_";
    jump->op1 = createSymbol(dummyName, OTHERS, 0, 0);
    jump->op2 = createSymbol(dummyName, OTHERS, 0, 0);
    char* labelName = generateUniqueLabelName();
    jump->result = createSymbol(labelName, OTHERS, 0, 0);
    jump->next = NULL;
    return jump;
}

/**
 * Generate a unique label name for pseudo-assembly instructions.
 */
char* generateUniqueLabelName() {
    char* labelName = (char*)malloc(10 * sizeof(char));
    sprintf(labelName, "L%d", labelCounter++);
    return labelName;
}

/**
 * Create and append a label instruction to the instruction list.
 */
void createLabelInstruction(char* labelName) {
    char *dummyName = "_";
    addPseudoAssemblyInstruction(T_LABEL, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), createSymbol(labelName, OTHERS, 0, 0));
}

/**
 * Create a pseudo-assembly return instruction.
 */
void createReturnInstruction(TData* functionSymbol) {
    char *dummyName = " ";
    addPseudoAssemblyInstruction(T_RETURN, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), functionSymbol);
}

/**
 * Create a pseudo-assembly instruction for required parameters.
 */
void createRequiredParameterInstruction(TData* paramSymbol) {
    char *dummyName = " ";
    if (requiredParamCount > 6) {
        PseudoAssembly* instruction = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
        instruction->tag = T_REQUIRED_PARAM;
        instruction->op1 = createSymbol(dummyName, OTHERS, 0, 0);
        instruction->op2 = createSymbol(dummyName, OTHERS, 0, 0);
        instruction->result = paramSymbol;
        instruction->next = extraParamInstructions;
        extraParamInstructions = instruction;
    } else {
        addPseudoAssemblyInstruction(T_REQUIRED_PARAM, createSymbol(dummyName, OTHERS, 0, 0), createSymbol(dummyName, OTHERS, 0, 0), paramSymbol);
    }
}

/**
 * Generate the final assembler output from pseudo-assembly instructions.
 */
void generateAssemblerOutput() {
    createFile();
    createWriteASM(instructionList);
}