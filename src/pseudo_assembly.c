#include "../include/pseudo_assembly.h"
#include "../include/assembly_generator.h"
#include <string.h>

PseudoAssembly* MoreThanSixParams = NULL;
PseudoAssembly* instructions = NULL;

int labID = 1;
int paramReq  = 0;

void createInstallSequence(ASM tag, TData* op1, TData* op2, TData* result) {
    PseudoAssembly* seq = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    seq->tag = tag;
    seq->op1 = op1;
    seq->op2 = op2;
    seq->result = result;
    seq->next = instructions;
    instructions = seq;
}

void operComparate(TOKENS tag, TData* op1, TData* op2, TData* res) {
    switch(tag) {
        case T_GREATER_THAN: createInstallSequence(T_GREATER, op1, op2, res); break;
        case T_LESS_THAN:    createInstallSequence(T_LESS, op1, op2, res); break;
        case EEQ:            createInstallSequence(T_EQUAL, op1, op2, res); break;
        default: break;
    }
}

void opBoolean(TOKENS tag, TData* op1, TData* op2, TData* res) {
    switch(tag) {
        case EAND: createInstallSequence(T_AND, op1, op2, res); break;
        case EOR:  createInstallSequence(T_OR, op1, op2, res); break;
        default: break;
    }
}

void operAritmetic(TOKENS tag, TData* op1, TData* op2, TData* res) {
    switch(tag) {
        case PLUS:  createInstallSequence(T_PLUS, op1, op2, res); break;
        case MINUS: createInstallSequence(T_MINUS, op1, op2, res); break;
        case PROD:  createInstallSequence(T_PROD, op1, op2, res); break;
        case EDIV:
            if ((op2 && op2->value == 0) || (LookupVar(op2->varname) && LookupVar(op2->varname)->value == 0)) {
                printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", op1->line);
                exit(1);
            }
            createInstallSequence(T_DIV, op1, op2, res);
            break;
        case EMOD:
            if ((op2 && op2->value == 0) || (LookupVar(op2->varname) && LookupVar(op2->varname)->value == 0)) {
                printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", op1->line);
                exit(1);
            }
            createInstallSequence(T_MOD, op1, op2, res);
            break;
        default: break;
    }
}

void translate(TOKENS tag, Tree* op1, Tree* op2, Tree* res) {
    TData *op1Symbol = op1->symbol;
    TData *op2Symbol = op2 ? op2->symbol : NULL;
    TData *resSymbol = res->symbol;
    TData *auxRigth = op2 ? LookupVar(op2->symbol->varname) : NULL;

    switch(tag) {
        case ASIGN:
            if(auxRigth) {
                op1Symbol->value = auxRigth->value;
            } else if(op2Symbol) {
                op1Symbol->value = op2Symbol->value;
            }
            createInstallSequence(T_ASIGN, op1Symbol, op2Symbol, op1Symbol);
            break;
        case PLUS: case MINUS: case PROD: case EDIV: case EMOD:
            operAritmetic(tag, op1Symbol, op2Symbol, resSymbol);
            break;
        case EAND: case EOR:
            opBoolean(tag, op1Symbol, op2Symbol, resSymbol);
            break;
        case T_GREATER_THAN: case T_LESS_THAN: case EEQ:
            operComparate(tag, op1Symbol, op2Symbol, resSymbol);
            break;
        case EWHILE:
            createInstallSequence(T_WHILE, op1Symbol, op2Symbol, resSymbol);
            break;
        case EIF:
            createInstallSequence(T_IF, op1Symbol, op2Symbol, resSymbol);
            break;
        case ENOT:
            createInstallSequence(T_NOT, op1Symbol, op2Symbol, resSymbol);
            break;
        default: break;
    }
}

TData *LookupVar(char *name) {
    if (!name) return NULL;
    PseudoAssembly* head = instructions;
    while(head) {
        if(head->result && strcmp(name, head->result->varname) == 0)
            return head->result;
        head = head->next;
    }
    return NULL;
}

void generateThreeDir(Tree* tree) {
    generateCode(tree);
    invertASM(&instructions);
}

void generateVarGlobals() {
    TData *aux = getTable();
    while(aux) {
        TData *rec = aux->table;
        while(rec) {
            if(rec->token == VARINT || rec->token == VARBOOL) {
                char *name1 = "_";
                createInstallSequence(T_GLOBAL, CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0), rec);
            }
            rec = rec->next;
        }
        aux = aux->next;
    }
}

void generateCode(Tree* tree) {
    if (!tree) return;
    TOKENS currentToken = tree->symbol->token;
    if (currentToken == ERETURN) {
        handleGenerateOpReturn(tree);
        createRetTag(tree->left->symbol);
    } else if (currentToken == RETINT || currentToken == RETBOL || currentToken == RETVOID) {
        if (strcmp(tree->symbol->varname, "main") == 0) {
            handleGenerateMain(tree);
            createSentenThreeDir(T_END_FUN, tree->symbol);
        } else {
            handleGenerateFunc(tree);
            paramReq = 0;
            createSentenThreeDir(T_END_FUN, tree->symbol);
        }
    } else if (currentToken == CALL_F) {
        has_Operation(tree->right);
        has_Call_Func(tree->right);
        generateLoadParams(tree->right);
        createCall_Func(tree->left->symbol, tree->symbol);
    } else if (currentToken == EIF) {
        handleGenerateIF(tree);
    } else if (currentToken == EWHILE) {
        handleGenerateWhile(tree);
    } else {
        if (strcmp(tree->symbol->varname, "PROGRAM") == 0) {
            generateVarGlobals();
        }
        if (tree->right && tree->left) {
            handleGenerateBinaryOperation(tree);
        } else if (tree->left) {
            handleUnaryOp(tree);
        } else if (tree->right) {
            generateCode(tree->right);
        }
    }
}

void handleGenerateOpReturn(Tree* tree) {
    if (tree->left) generateCode(tree->left);
    if (tree->right) generateCode(tree->right);
}

void handleGenerateMain(Tree* tree) {
    createSentenThreeDir(T_FUNC, tree->symbol);
    if (tree->left) generateCode(tree->left);
    if (tree->right) generateCode(tree->right);
    if (tree->symbol->token == RETVOID) {
        char *name1 = " ";
        createInstallSequence(T_RETURN, CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0));
    }
}

void has_Operation(Tree* tree) {
    if (!tree) return;
    if (tree->left) has_Operation(tree->left);
    if (tree->right) has_Operation(tree->right);
    TOKENS currentToken = tree->symbol->token;
    bool operArit = (currentToken == PLUS || currentToken == MINUS || currentToken == PROD || currentToken == EDIV || currentToken == EMOD);
    bool operBool = (currentToken == EOR || currentToken == EAND || currentToken == ENOT);
    bool operCondi = (currentToken == T_GREATER_THAN || currentToken == T_LESS_THAN || currentToken == EEQ);
    if (operArit || operBool || operCondi) {
        generateCode(tree);
    }
}

void has_Call_Func(Tree* tree) {
    if (!tree) return;
    if (tree->left) has_Call_Func(tree->left);
    if (tree->right) has_Call_Func(tree->right);
    if (tree->symbol->token == CALL_F) {
        generateLoadParams(tree->right);
        createCall_Func(tree->left->symbol, tree->symbol);
    }
}

void generateLoadParams(Tree* tree) {
    if (!tree) return;
    TOKENS currentToken = tree->symbol->token;
    if (currentToken != ARGS) {
        createTagLoad(tree->symbol);
    }
    bool notOperArit = (currentToken != PLUS && currentToken != MINUS && currentToken != PROD && currentToken != EDIV && currentToken != EMOD);
    bool notOperBool = (currentToken != EOR && currentToken != EAND && currentToken != ENOT);
    bool notOperCondi = (currentToken != T_GREATER_THAN && currentToken != T_LESS_THAN && currentToken != EEQ);
    bool ifNotType = (currentToken != CALL_F && (notOperArit && notOperBool && notOperCondi));
    if (ifNotType) {
        if (tree->left) generateLoadParams(tree->left);
        if (tree->right) generateLoadParams(tree->right);
    }
}

void createTagLoad(TData* symbol) {
    char *name1 = "_";
    createInstallSequence(T_LOAD_PARAM, CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0), symbol);
}

void concatLists(PseudoAssembly *list1, PseudoAssembly *list2) {
    if (!list2) return;
    PseudoAssembly *actual = list2;
    while (actual->next) actual = actual->next;
    actual->next = list1;
    instructions = list2;
}

void handleGenerateFunc(Tree* tree) {
    createSentenThreeDir(T_FUNC, tree->symbol);
    if (tree->left) {
        requireParams(tree->left);
        invertASM(&MoreThanSixParams);
        concatLists(instructions, MoreThanSixParams);
        MoreThanSixParams = NULL;
    }
    if (tree->right) generateCode(tree->right);
    if (tree->symbol->token == RETVOID) {
        char *name1 = " ";
        createInstallSequence(T_RETURN, CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0));
    }
}

void requireParams(Tree* tree) {
    if (!tree) return;
    if (tree->symbol->token == PARAMBOOL || tree->symbol->token == PARAMINT) {
        paramReq += 1;
        createCodRequiredParam(tree->symbol);
    }
    if (tree->left) requireParams(tree->left);
    if (tree->right) requireParams(tree->right);
}

void createCall_Func(TData* nameFunc, TData* tempResult) {
    char *name1 = "_";
    createInstallSequence(T_CALL, nameFunc, CreateSymbol(name1, OTHERS, 0, 0), tempResult);
}

void createSentenThreeDir(ASM tag, TData* func) {
    char *name1 = "_";
    createInstallSequence(tag, CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0), func);
}

void handleGenerateIF(Tree* tree) {
    generateCode(tree->left);
    PseudoAssembly* IFF = createTagForFalse(T_IFF, tree->left->symbol);
    char* labelIFF = strdup(IFF->result->varname);
    IFF->next = instructions;
    instructions = IFF;

    if (strcmp(tree->symbol->varname, "if_then") == 0) {
        generateCode(tree->right);
        createAndAppendTagLabel(labelIFF);
    } else if (strcmp(tree->symbol->varname, "if_else") == 0) {
        generateCode(tree->right->left);  // then
        PseudoAssembly* jump = createJump();
        jump->next = instructions;
        instructions = jump;
        createAndAppendTagLabel(labelIFF);
        generateCode(tree->right->right->left); // else
        createAndAppendTagLabel(jump->result->varname);
    }
    free(labelIFF);
}

void handleGenerateWhile(Tree* tree) {
    PseudoAssembly* jump = createJump();
    createAndAppendTagLabel(jump->result->varname);
    generateCode(tree->left);
    PseudoAssembly* conditionFalse = createTagForFalse(T_WF, tree->left->symbol);
    conditionFalse->next = instructions;
    instructions = conditionFalse;
    generateCode(tree->right);
    jump->next = instructions;
    instructions = jump;
    createAndAppendTagLabel(conditionFalse->result->varname);
}

void handleGenerateBinaryOperation(Tree* tree) {
    if (tree->left) generateCode(tree->left);
    if (tree->right) generateCode(tree->right);
    TOKENS currentToken = tree->symbol->token;
    bool isAsignBool = currentToken == ASIGN || currentToken == EAND || currentToken == EOR || currentToken == EEQ || currentToken == T_GREATER_THAN || currentToken == T_LESS_THAN;
    bool isAritmet = currentToken == PLUS || currentToken == MINUS || currentToken == PROD || currentToken == EMOD || currentToken == EDIV;
    if (isAsignBool || isAritmet) {
        translate(currentToken, tree->left, tree->right, tree);
    }
}

void handleUnaryOp(Tree* tree) {
    generateCode(tree->left);
    if (tree->symbol->token == ENOT) {
        translate(tree->symbol->token, tree->left, NULL, tree);
    }
}

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

void deleteInstructions() {
    PseudoAssembly* current = instructions;
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

void printAsembler() {
    PseudoAssembly* current = instructions;
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

PseudoAssembly* createTagForFalse(ASM tag, TData* condition) {
    PseudoAssembly* seq = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    seq->tag = tag;
    seq->op1 = condition;
    char *name1 = "_";
    seq->op2 = CreateSymbol(name1, OTHERS, 0, 0);
    char* name = generateNameLabel();
    seq->result = CreateSymbol(name, OTHERS, 0, 0);
    seq->next = NULL;
    return seq;
}

PseudoAssembly* createJump() {
    PseudoAssembly* jump = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    jump->tag = T_JUMP;
    char *name1 = "_";
    jump->op1 = CreateSymbol(name1, OTHERS, 0, 0);
    jump->op2 = CreateSymbol(name1, OTHERS, 0, 0);
    char* name = generateNameLabel();
    jump->result = CreateSymbol(name, OTHERS, 0, 0);
    jump->next = NULL;
    return jump;
}

char* generateNameLabel() {
    char* nameLabel = (char*)malloc(10 * sizeof(char));
    sprintf(nameLabel, "L%d", labID++);
    return nameLabel;
}

void createAndAppendTagLabel(char* nameLabel) {
    char *name1 = "_";
    createInstallSequence(T_LABEL, CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(nameLabel, OTHERS, 0, 0));
}

void createRetTag(TData* func) {
    char *name1 = " ";
    createInstallSequence(T_RETURN, CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0), func);
}

void createCodRequiredParam(TData* param) {
    char *name1 = " ";
    if (paramReq > 6) {
        PseudoAssembly* seq = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
        seq->tag = T_REQUIRED_PARAM;
        seq->op1 = CreateSymbol(name1, OTHERS, 0, 0);
        seq->op2 = CreateSymbol(name1, OTHERS, 0, 0);
        seq->result = param;
        seq->next = MoreThanSixParams;
        MoreThanSixParams = seq;
    } else {
        createInstallSequence(T_REQUIRED_PARAM, CreateSymbol(name1, OTHERS, 0, 0), CreateSymbol(name1, OTHERS, 0, 0), param);
    }
}

void generateAssembler() {
    createFile();
    createWriteASM(instructions);
}