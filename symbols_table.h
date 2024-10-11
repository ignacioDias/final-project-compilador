#ifndef SYMBOLS_TABLE_H
#define SYMBOLS_TABLE_H
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct List {
    TData *info; 
    struct List *next;
} LSE;
typedef struct NodeList {
    struct SymbolsTable *child;
    struct NodeList *next;   
} NodeList;

typedef struct Table {
    LSE* currentLevel;
    struct NodeList *next;
} SymbolsTable;


int insert(LSE **list, TData *elem);
int set(LSE *list, char* name, int val);
TData* doesExist(SymbolsTable *list, char* nom);
TData* isInThisEnvironment(LSE *list, char* nom);
int interpreter(LSE * list, Tree* bt);
int checkType(LSE* lse, Tree* tree);
int evalType(LSE* list, Tree* bt);
int evalValue(int a, int b, Token token);
void showTable(LSE *list);
#endif