#include "../include/assembly_generator.h"
#include "../include/pseudo_assembly.h"
#include <ctype.h>

// Output file pointer for assembly code
FILE* outputFile;

// Counter for unique labels in boolean operations
int booleanLabelCounter = 0;

// Counter for function parameters (registers)
int functionParameterRegisterIndex = -1;

// Register names for parameter passing (up to 6, x86-64 calling convention)
char parameterRegisters[7][20] = {"edi", "esi", "edx", "ecx", "r8d", "r9d"};

// Counter for extra parameters (passed on stack)
int extraParameterCount = 0;

// Maximum positive stack offset for local variables
int maxStackOffset = 0;

/**
 * Create and open the output assembly file.
 */
void createOutputFile() {
    outputFile = fopen("output.s", "w");
    if (!outputFile) {
        printf("Error creating output.s\n");
        return;
    }
    fclose(outputFile);
}

/**
 * Write a string to the output assembly file.
 */
void writeToOutputFile(char* text) {
    outputFile = fopen("output.s", "a");
    if (!outputFile) {
        printf("Error writing to output file");
        return;
    }
    fprintf(outputFile, "%s", text);
    fclose(outputFile);
}

/**
 * Generate assembly code from the pseudo-assembly instruction list.
 */
void generateAssemblyFromPseudo(PseudoAssembly* instruction) {
    if (!instruction) return;
    ASM opcode = instruction->tag;
    switch (opcode) {
        case T_GLOBAL:
            writeGlobalVariable(instruction);
            if (instruction->next && instruction->next->tag != T_GLOBAL) {
                char buffer[256];
                sprintf(buffer, ".section .text\n\n ");
                writeToOutputFile(buffer);
            }
            break;
        case T_FUNC:
            writeFunctionPrologue(instruction);
            functionParameterRegisterIndex = -1;
            break;
        case T_ASIGN:
            writeAssignment(instruction);
            break;
        case T_IFF: case T_WF:
            writeConditionalJump(instruction);
            break;
        case T_LABEL:
            writeLabel(instruction);
            break;
        case T_JUMP:
            writeJump(instruction);
            break;
        case T_LOAD_PARAM: {
            int paramIndex = 0;
            writeFunctionCallParameter(instruction, paramIndex);
            return;
        }
        case T_REQUIRED_PARAM:
            writeFunctionParameterLoad(instruction);
            break;
        case T_CALL:
            writeFunctionCall(instruction);
            break;
        case T_PLUS: case T_MOD: case T_DIV: case T_PROD: case T_MINUS:
            writeArithmeticOperation(instruction->op1, instruction->op2, instruction->result, opcode);
            break;
        case T_NOT: case T_AND: case T_OR:
            writeBooleanOperation(instruction->op1, instruction->op2, instruction->result, opcode);
            break;
        case T_EQUAL: case T_LESS: case T_GREATER:
            writeComparisonOperation(instruction->op1, instruction->op2, instruction->result, instruction->tag);
            break;
        case T_RETURN:
            writeReturnStatement(instruction);
            writeFunctionEpilogue(instruction);
            break;
        default:
            break;
    }
    if (instruction->next)
        generateAssemblyFromPseudo(instruction->next);
}

/**
 * Write global variable declaration to assembly.
 */
void writeGlobalVariable(PseudoAssembly* instruction) {
    char buffer[256];
    sprintf(buffer, ".section .data\n\n ");
    writeToOutputFile(buffer);
    sprintf(buffer, ".global %s\n\n ", instruction->result->varname);
    writeToOutputFile(buffer);
    sprintf(buffer, "%s: \n    .long 0\n\n", instruction->result->varname);
    writeToOutputFile(buffer);
}

/**
 * Write function prologue to assembly.
 */
void writeFunctionPrologue(PseudoAssembly* instruction) {
    char buffer[256];
    if (strcmp(instruction->result->varname, "main") == 0) {
        sprintf(buffer, "\n.global %s\n ", instruction->result->varname);
        writeToOutputFile(buffer);
    }
    sprintf(buffer, "%s:\n    pushq   %%rbp\n    movq    %%rsp, %%rbp\n", instruction->result->varname);
    writeToOutputFile(buffer);
    maxStackOffset = instruction->result->offset * -1;
    sprintf(buffer, "    subq $%d, %%rsp \n", maxStackOffset);
    writeToOutputFile(buffer);
}

/**
 * Write function epilogue to assembly.
 */
void writeFunctionEpilogue(PseudoAssembly* instruction) {
    char buffer[256];
    sprintf(buffer, "    addq $%d, %%rsp \n", maxStackOffset);
    writeToOutputFile(buffer);
    writeToOutputFile("    popq    %rbp\n");
    writeToOutputFile("    ret\n");
}

/**
 * Write parameter loading for function definition (stack/register).
 */
void writeFunctionParameterLoad(PseudoAssembly* instruction) {
    char buffer[256];
    char* percent = "%";
    TData* param = instruction->result;
    functionParameterRegisterIndex += 1;
    if (functionParameterRegisterIndex > 5) {
        sprintf(buffer, "    movl  %d(%%rbp), %%eax\n", ((functionParameterRegisterIndex - 5) * 16));
        writeToOutputFile(buffer);
        sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", param->offset);
        writeToOutputFile(buffer);
    } else {
        sprintf(buffer, "    movl %s%s, %d(%%rbp)\n", percent, parameterRegisters[functionParameterRegisterIndex], param->offset);
        writeToOutputFile(buffer);
    }
}

/**
 * Write parameter loading for function call (stack/register).
 */
void writeFunctionCallParameter(PseudoAssembly* instruction, int paramIndex) {
    char buffer[256];
    char percent[3] = "%";
    TData *result = instruction->result;
    if (paramIndex >= 6) {
        sprintf(buffer, "    subq $8, %srsp\n", percent);
        writeToOutputFile(buffer);
        extraParameterCount++;
        if (result->token == CONSBOOL) {
            sprintf(buffer, "    pushq $%d\n", strcmp("true", result->varname) == 0 ? 1 : 0);
            writeToOutputFile(buffer);
        } else if (result->token == CONSINT) {
            sprintf(buffer, "    pushq $%s\n", result->varname);
            writeToOutputFile(buffer);
        }
        TOKENS tokenType = result->token;
        bool isArithmetic = (tokenType == PLUS || tokenType == EMOD || tokenType == PROD || tokenType == EDIV || tokenType == EMOD);
        bool isBoolean = (tokenType == EOR || tokenType == EAND || tokenType == ENOT);
        bool isComparison = (tokenType == T_GREATER_THAN || tokenType == T_LESS_THAN || tokenType == EEQ);
        if (result->token == EID || result->token == CALL_F || isArithmetic || isBoolean || isComparison) {
            if (result->offset == 0) {
                sprintf(buffer, "    pushq %s(%%rip)\n", result->varname);
            } else {
                sprintf(buffer, "    pushq %d(%%rbp)\n", result->offset);
            }
            writeToOutputFile(buffer);
        }
    } else {
        if (result->token == CONSBOOL) {
            sprintf(buffer, "    movl $%d, %s%s\n", strcmp("true", result->varname) == 0 ? 1 : 0, percent, parameterRegisters[paramIndex]);
            writeToOutputFile(buffer);
        } else if (result->token == CONSINT) {
            sprintf(buffer, "    movl $%s, %s%s\n", result->varname, percent, parameterRegisters[paramIndex]);
            writeToOutputFile(buffer);
        }
        TOKENS tokenType = result->token;
        bool isArithmetic = (tokenType == PLUS || tokenType == EMOD || tokenType == PROD || tokenType == EDIV || tokenType == EMOD);
        bool isBoolean = (tokenType == EOR || tokenType == EAND || tokenType == ENOT);
        bool isComparison = (tokenType == T_GREATER_THAN || tokenType == T_LESS_THAN || tokenType == EEQ);
        if (result->token == EID || result->token == CALL_F || isArithmetic || isBoolean || isComparison) {
            if (result->offset == 0) {
                sprintf(buffer, "    movl %s(%%rip), %seax\n", result->varname, percent);
            } else {
                sprintf(buffer, "    movl %d(%%rbp), %seax\n", result->offset, percent);
            }
            writeToOutputFile(buffer);
            sprintf(buffer, "    movl %%eax, %s%s\n", percent, parameterRegisters[paramIndex]);
            writeToOutputFile(buffer);
        }
    }
    paramIndex++;
    if (instruction->next && instruction->next->tag == T_LOAD_PARAM) {
        writeFunctionCallParameter(instruction->next, paramIndex);
    } else if (instruction->next) {
        generateAssemblyFromPseudo(instruction->next);
    }
}

/**
 * Write assignment operation to assembly.
 */
void writeAssignment(PseudoAssembly* instruction) {
    TData* destination = instruction->result;
    TData* source = instruction->op2;
    TOKENS sourceType = source->token;
    char buffer[256];

    if (sourceType == CONSINT) {
        if (destination->offset == 0)
            sprintf(buffer, "    movl $%s, %s(%%rip)\n", source->varname, destination->varname);
        else
            sprintf(buffer, "    movl $%s, %d(%%rbp)\n", source->varname, destination->offset);
    } else if (sourceType == CONSBOOL) {
        int val = strcmp("true", source->varname) == 0 ? 1 : 0;
        if (destination->offset == 0)
            sprintf(buffer, "    movl $%d, %s(%%rip)\n", val, destination->varname);
        else
            sprintf(buffer, "    movl $%d, %d(%%rbp)\n", val, destination->offset);
    } else {
        if (source->offset == 0)
            sprintf(buffer, "    movl %s(%%rip), %%eax\n\n", source->varname);
        else
            sprintf(buffer, "    movl %d(%%rbp), %%eax\n\n", source->offset);
        writeToOutputFile(buffer);
        if (destination->offset == 0)
            sprintf(buffer, "    movl %%eax, %s(%%rip)\n\n", destination->varname);
        else
            sprintf(buffer, "    movl %%eax, %d(%%rbp)\n\n", destination->offset);
    }
    writeToOutputFile(buffer);
}

/**
 * Write return statement to assembly.
 */
void writeReturnStatement(PseudoAssembly* instruction) {
    TData* result = instruction->result;
    char buffer[256];

    if (strcmp(" ", result->varname) == 0) return;

    if (result->token == CONSBOOL) {
        int val = strcmp("true", result->varname) == 0 ? 1 : 0;
        sprintf(buffer, "    movl $%d, %%eax\n", val);
    } else if (result->token == CONSINT) {
        sprintf(buffer, "    movl $%s,  %%eax\n", result->varname);
    } else {
        if (result->offset == 0)
            sprintf(buffer, "    movl %s(%%rip),  %%eax\n", result->varname);
        else
            sprintf(buffer, "    movl %d(%%rbp),  %%eax\n", result->offset);
    }
    writeToOutputFile(buffer);
}

/**
 * Write conditional jump for IF/WHILE statements.
 */
void writeConditionalJump(PseudoAssembly* instruction) {
    TData* condition = instruction->op1;
    TData* label = instruction->result;
    char buffer[256];

    if (condition->token == CONSBOOL) {
        int val = strcmp("true", condition->varname) == 0 ? 1 : 0;
        sprintf(buffer, "    movl $%d, %%eax\n", val);
        writeToOutputFile(buffer);
        sprintf(buffer, "    cmpl $1, %%eax\n");
    } else {
        if (condition->offset == 0)
            sprintf(buffer, "    cmpl  $1,  %s(%%rip)\n", condition->varname);
        else
            sprintf(buffer, "    cmpl  $1,  %d(%%rbp)\n", condition->offset);
    }
    writeToOutputFile(buffer);
    sprintf(buffer, "    jne %s\n", label->varname);
    writeToOutputFile(buffer);
}

/**
 * Write label to assembly.
 */
void writeLabel(PseudoAssembly* instruction) {
    char buffer[256];
    writeToOutputFile("\n\n");
    sprintf(buffer, "%s: \n", instruction->result->varname);
    writeToOutputFile(buffer);
}

/**
 * Write unconditional jump to assembly.
 */
void writeJump(PseudoAssembly* instruction) {
    char buffer[256];
    sprintf(buffer, "    jmp %s\n", instruction->result->varname);
    writeToOutputFile(buffer);
}

/**
 * Write function call to assembly.
 */
void writeFunctionCall(PseudoAssembly* instruction) {
    char buffer[256];
    sprintf(buffer, "    call %s\n", instruction->op1->varname);
    writeToOutputFile(buffer);
    if (extraParameterCount > 0) {
        int stackAdjust = extraParameterCount * 16;
        sprintf(buffer, "    addq $%d,  %%rsp\n", stackAdjust);
        writeToOutputFile(buffer);
        extraParameterCount = 0;
    }
    sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", instruction->result->offset);
    writeToOutputFile(buffer);
}

/**
 * Write arithmetic operation to assembly.
 */
void writeArithmeticOperation(TData* op1, TData* op2, TData* result, ASM opcode) {
    outputFile = fopen("output.s", "a");
    if (!outputFile) {
        printf("Error writing to output file");
        return;
    }
    char buffer[100];
    if (opcode == T_PLUS || opcode == T_MOD || opcode == T_PROD) {
        if (op1->token == CONSINT)
            sprintf(buffer, "    movl $%s, %%eax\n", op1->varname);
        else if (op1->offset == 0)
            sprintf(buffer, "    movl %s(%%rip), %%eax\n", op1->varname);
        else
            sprintf(buffer, "    movl %d(%%rbp), %%eax\n", op1->offset);
        writeToOutputFile(buffer);

        if (op2->token == CONSINT)
            sprintf(buffer, "    movl $%s, %%edx\n", op2->varname);
        else if (op2->offset == 0)
            sprintf(buffer, "    movl %s(%%rip), %%edx\n", op2->varname);
        else
            sprintf(buffer, "    movl %d(%%rbp), %%edx\n", op2->offset);
        writeToOutputFile(buffer);

        if (opcode == T_PLUS)
            sprintf(buffer, "    addl %%edx, %%eax\n");
        else if (opcode == T_MOD)
            sprintf(buffer, "    subl %%edx, %%eax\n");
        else
            sprintf(buffer, "    imull %%edx, %%eax\n");
        writeToOutputFile(buffer);

        sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", result->offset);
        writeToOutputFile(buffer);
    } else if (opcode == T_DIV || opcode == T_MOD) {
        if (op1->token == CONSINT)
            sprintf(buffer, "    movl $%s, %%eax\n", op1->varname);
        else if (op1->offset == 0)
            sprintf(buffer, "    movl %s(%%rip), %%eax\n", op1->varname);
        else
            sprintf(buffer, "    movl %d(%%rbp), %%eax\n", op1->offset);
        writeToOutputFile(buffer);

        if (op2->token == CONSINT) {
            sprintf(buffer, "    movl $%s,  %%ecx\n", op2->varname);
            writeToOutputFile(buffer);
            sprintf(buffer, "    cltd\n");
            writeToOutputFile(buffer);
            sprintf(buffer, "    idivl %%ecx\n");
        } else if (op2->offset == 0) {
            sprintf(buffer, "    movl %s(%%rip),  %%ecx\n", op2->varname);
            writeToOutputFile(buffer);
            sprintf(buffer, "    cltd\n");
            writeToOutputFile(buffer);
            sprintf(buffer, "    idivl %%ecx\n");
        } else {
            sprintf(buffer, "    cltd\n");
            writeToOutputFile(buffer);
            sprintf(buffer, "    idivl %d(%%rbp)\n", op2->offset);
        }
        writeToOutputFile(buffer);

        if (opcode == T_DIV)
            sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", result->offset);
        else
            sprintf(buffer, "    movl %%edx, %d(%%rbp)\n", result->offset);
        writeToOutputFile(buffer);
    }
}

/**
 * Write boolean operation to assembly.
 */
void writeBooleanOperation(TData* op1, TData* op2, TData* result, ASM opcode) {
    char buffer[100];
    if (op1->token == CONSBOOL) {
        int val = strcmp("true", op1->varname) == 0 ? 1 : 0;
        sprintf(buffer, "    movl $%d, %%eax\n", val);
        writeToOutputFile(buffer);
        sprintf(buffer, "    cmpl $0, %%eax\n");
    } else if (op1->offset == 0) {
        sprintf(buffer, "    cmpl $0, %s(%%rip)\n", op1->varname);
    } else {
        sprintf(buffer, "    cmpl $0, %d(%%rbp)\n", op1->offset);
    }
    writeToOutputFile(buffer);

    if (opcode == T_AND || opcode == T_OR) {
        if (opcode == T_AND)
            sprintf(buffer, "    je .LA%d \n", booleanLabelCounter + 1);
        else
            sprintf(buffer, "    jne .LO%d \n", booleanLabelCounter + 1);
        writeToOutputFile(buffer);

        if (op2->token == CONSBOOL) {
            int val = strcmp("true", op2->varname) == 0 ? 1 : 0;
            sprintf(buffer, "    movl $%d, %%eax\n", val);
            writeToOutputFile(buffer);
            sprintf(buffer, "    cmpl $0, %%eax\n");
        } else if (op2->offset == 0) {
            sprintf(buffer, "    cmpl $0, %s(%%rip)\n", op2->varname);
        } else {
            sprintf(buffer, "    cmpl $0, %d(%%rbp)\n", op2->offset);
        }
        writeToOutputFile(buffer);

        if (opcode == T_AND) {
            booleanLabelCounter++;
            sprintf(buffer, "    je .LA%d \n", booleanLabelCounter);
        } else {
            booleanLabelCounter++;
            sprintf(buffer, "    je .LO%d \n", booleanLabelCounter + 1);
        }
        writeToOutputFile(buffer);

        if (opcode == T_OR) {
            sprintf(buffer, ".LO%d: \n", booleanLabelCounter);
            writeToOutputFile(buffer);
        }
        sprintf(buffer, "    movl $1, %%eax\n");
        writeToOutputFile(buffer);

        if (opcode == T_AND) {
            booleanLabelCounter++;
            sprintf(buffer, "    jmp .LA%d \n", booleanLabelCounter);
            writeToOutputFile(buffer);
            booleanLabelCounter--;
            sprintf(buffer, ".LA%d: \n", booleanLabelCounter);
        } else {
            booleanLabelCounter++;
            sprintf(buffer, "    jmp .LO%d \n", booleanLabelCounter + 1);
            writeToOutputFile(buffer);
            sprintf(buffer, ".LO%d: \n", booleanLabelCounter);
        }
        writeToOutputFile(buffer);

        sprintf(buffer, "    movl $0, %%eax\n");
        writeToOutputFile(buffer);
        booleanLabelCounter++;
        if (opcode == T_AND)
            sprintf(buffer, ".LA%d: \n", booleanLabelCounter);
        else
            sprintf(buffer, ".LO%d: \n", booleanLabelCounter);
        writeToOutputFile(buffer);
    } else {
        sprintf(buffer, "    sete  %%al\n");
        writeToOutputFile(buffer);
        sprintf(buffer, "    movzbl  %%al, %%eax\n");
        writeToOutputFile(buffer);
    }
    sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", result->offset);
    writeToOutputFile(buffer);
}

/**
 * Write comparison operation to assembly.
 */
void writeComparisonOperation(TData* op1, TData* op2, TData* result, ASM opcode) {
    char buffer[30];
    if (op1->token == CONSINT)
        sprintf(buffer, "    movl $%s , %%eax \n", op1->varname);
    else if (op1->offset == 0)
        sprintf(buffer, "    movl %s(%%rip) , %%eax\n ", op1->varname);
    else
        sprintf(buffer, "    movl %d(%%rbp) , %%eax\n ", op1->offset);
    writeToOutputFile(buffer);

    if (op2->token == CONSINT)
        sprintf(buffer, "   cmpl  $%s , %%eax \n", op2->varname);
    else if (op2->offset == 0)
        sprintf(buffer, "   cmpl %s(%%rip) , %%eax\n", op2->varname);
    else
        sprintf(buffer, "   cmpl %d(%%rbp) , %%eax\n", op2->offset);
    writeToOutputFile(buffer);

    if (opcode == T_ASIGN)
        sprintf(buffer, "    sete %%al\n");
    else if (opcode == T_GREATER)
        sprintf(buffer, "    setg %%al\n");
    else if (opcode == T_LESS)
        sprintf(buffer, "    setl %%al\n");
    writeToOutputFile(buffer);

    sprintf(buffer, "    movzbl %%al, %%eax\n");
    writeToOutputFile(buffer);
    sprintf(buffer, "    movl  %%eax, %d(%%rbp)\n", result->offset);
    writeToOutputFile(buffer);
}
