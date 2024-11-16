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
    WHILE,
    IFF,
    LABEL,
    GOTO,
    RET
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

void handleBinaryOperation(TData* value1, TData* value2, Operation op, TData* temporary);
void insertNode(Triple *triple);
void handleWhile(Tree *tree);
void handleIf(Tree *tree);
void handleReturn(TData *ret, Tree *tree);
void handleAsign(Tree *tree);
#endif