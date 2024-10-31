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
    IF,
    WHILE,
    ELSE
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

void insertNode(AssemblyList **list, Triple *triple);
void handleGenerateIf(AssemblyList **list, Triple* cond, AssemblyList *then, AssemblyList *elseBlock);
void handle(AssemblyList *block);
void handleGenerateWhile(AssemblyList **list, Triple* cond, AssemblyList *then);
void handleGenerateBinaryOperation(Triple* ar);
void handleGenerateFunc(Triple* ar);
int evalValue(TData* a, TData *b, Operation operation);
#endif