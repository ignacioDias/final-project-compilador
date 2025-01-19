#ifndef PSEUDOASSEMBLY_H
#define PSEUDOASSEMBLY_H
#include "tree.h"

typedef enum Operation {
    MENOR,
    MAYOR,
    IGUAL,
    MENOS,
    SUMA,
    MULT,
    DIV,
    MOD,
    OR,
    AND,
    NEG,
    ASIGN,
    WHILEF,
    IFF,
    LABEL,
    JUMP,
    RET,
    FUN_CALL,
    FUN_DECL,
    END_FUNC,
    REQUIRED_PARAM,
    LOAD_PARAM,
    DECL
} Operation;

typedef struct {
    Operation op;
    TData *firstOperand; 
    TData *secondOperand; 
    TData *temporary; 
} Triple;

typedef struct ListForTriples {
    Triple *info;
    struct ListForTriples *next;
} AssemblyList;

void handleBinaryOperation(AssemblyList **program, TData* value1, TData* value2, Operation op, TData* temporary);
void insertNode(AssemblyList **program, Triple *triple);
void generatePseudoAssembly(AssemblyList **program, Tree *tree);
void handleFunctionDeclaration(AssemblyList **program, Tree *tree);
void handleParamsDefinition(AssemblyList **program, Tree *tree);
void handleFunctionCall(AssemblyList **program, Tree *tree);
void handleParamsCall(AssemblyList **program, Tree *tree);
void handleIf(AssemblyList **program, Tree *tree);
void handleWhile(AssemblyList **program, Tree *tree);
TData *generateNewLabel();
char* generateNewIDForLabel();
void printAssemblyList(AssemblyList **program);
void printAssemblyListReverse(AssemblyList *current);
const char *operationToString(Operation op);
#endif