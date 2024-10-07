#ifndef SYMBOLS_TABLE_H
#define SYMBOLS_TABLE_H
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct List {
    TData *info; //TODO: HACER LIST<TDATA> con stack
    struct List *next;
} LSE;
int insert(LSE **list, TData *elem);
int set(LSE *list, char* name, int val);
TData* get(LSE *list, char* nom);
int interpreter(LSE * list, Tree* bt);
int checkType(LSE* lse, Tree* tree);
int evalValue(int a, int b, Token token);
void showTable(LSE *list);
#endif