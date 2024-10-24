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
} ListFunction
;
typedef struct Stack {
    LSE *info;
    struct Stack *next;   
} SymbolsTable;

int insertElem(SymbolsTable **SymbolsTable, TData *elem);
int insertLevel(SymbolsTable **symbolsTable, LSE *level);

TData *getNode(LSE *level, char* nom, Type type);
Type doesExist(SymbolsTable *symbolsTable, char *name); //checks for the first occurrence of a id, if exists then returns the type

int removeLevel(SymbolsTable **symbolsTable);
int removeNode(LSE **list, TData *node);

int setValueToNode(LSE *list, char* name, Type type, int val);

void setTypeFunction(Type type);

int interpreter(LSE * list, Tree* bt);
int evalType(SymbolsTable* list, Tree* bt);
int evalValue(int a, int b, Token token);

void showTable(SymbolsTable *symbolsTable);
void showLevel(LSE *list);

int checkFunctionCall(ListFunction *functions, char* name, Tree *params);
void insertFunction(ListFunction **functions, Type type, char* name, Tree *params);

#endif