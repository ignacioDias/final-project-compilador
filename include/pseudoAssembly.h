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
    T_REQUIRED_PARAM
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

int currentLabel = 1;

void handleBinaryOperation(TData* value1, TData* value2, Operation op, TData* temporary);
void insertNode(Triple *triple);
void handleFunctionDeclaration(Tree *tree);
void handleFunctionCall(Tree *tree);
void handleWhile(Tree *tree);
void handleIf(Tree *tree);
TData *generateNewLabel();
char* generateNewIDForLabel();
void printAssemblyList();
const char *operationToString(Operation op);
#endif