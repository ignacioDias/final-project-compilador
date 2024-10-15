#ifndef SYMBOLS_TABLE_H
#define SYMBOLS_TABLE_H
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct List {
    TData *info; 
    struct List *next;
} LSE;
typedef struct Stack {
    LSE *info;
    struct Stack *next;   
} SymbolsTable;

int insertElem(LSE **list, TData *elem);
int insertLevel(SymbolsTable **symbolsTable, LSE *level);

TData *getNode(LSE *level, char* nom);

int removeLevel(SymbolsTable **symbolsTable);
int removeNode(LSE **list, TData *node);

int setValueToNode(LSE *list, char* name, int val);

int interpreter(LSE * list, Tree* bt);
int evalType(SymbolsTable* list, Tree* bt);
int evalValue(int a, int b, Token token);

void showTable(SymbolsTable *symbolsTable);
void showLevel(LSE *list);

#endif