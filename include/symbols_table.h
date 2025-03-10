#ifndef SYMBOLS_TABLE_H
#define SYMBOLS_TABLE_H
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct List {
    TData *info; 
    struct List *next;
} LSE;

typedef struct CheckFunctions {
    char* name;
    Type type;
    Tree *params; 
    struct CheckFunctions *next;
} ListFunction;

typedef struct Stack {
    LSE *info;
    struct Stack *next;   
} SymbolsTable;

typedef struct Params {
    char *functionName;
    Tree *params;
    struct Params *next;
} ListParams;
int insertElem(SymbolsTable **SymbolsTable, TData *elem);
int insertLevel(SymbolsTable **symbolsTable, LSE *level);
int insertParams(ListParams **parameteres, char *functionName, Tree *params);
TData *getNode(LSE *level, char* nom, Type type);
TData *findVariable(SymbolsTable *symbolsTable, char* nom, Type type);
TData *findParam(ListParams *params, char* nom, Type type, char *functionName);
Type doesExist(SymbolsTable *symbolsTable, char *name); //checks for the first occurrence of a id, if exists then returns the type

int removeLevel(SymbolsTable **symbolsTable);
int removeNode(LSE **list, TData *node);

int setValueToNode(LSE *list, char* name, Type type, int val);

void setTypeFunction(Type type);

int evalType(Tree* bt);
int evalValue(int a, int b, Token token);

void showTable(SymbolsTable *symbolsTable);
void showLevel(LSE *list);

int checkFunctionCall(ListFunction *functions, char* name, Tree *params);
int insertFunction(ListFunction **functions, Type type, char* name, Tree *params);
int functionExists(ListFunction *functions, Type type, char* name, Tree *params);
int checkParams(Tree* paramsFunction, Tree* paramsCall);

#endif