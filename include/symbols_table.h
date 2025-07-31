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

typedef struct Parameter {
    char *id;
    Type type;
} Param;

typedef struct Params {
    Param *param;
    struct Params *next;
} ParamsList;
typedef struct Func {
    char* id;
    ParamsList *params;
    Type returnType;
} Function;

typedef struct MethodsList {
    Function *currentFunction;
    struct MethodsList *next;   
} FunctionsList;

extern FunctionsList** functionTable;  

int insertElem(SymbolsTable **SymbolsTable, TData *elem);
int insertLevel(SymbolsTable **symbolsTable, LSE *level);
TData *getNode(LSE *level, char* nom, Type type);
TData *findVariable(SymbolsTable *symbolsTable, char* nom, Type type);
Type doesExist(SymbolsTable *symbolsTable, char *name); //checks for the first occurrence of a id, if exists then returns the type

int removeLevel(SymbolsTable **symbolsTable);
int removeNode(LSE **list, TData *node);

int setValueToNode(LSE *list, char* name, Type type, int val);

void setTypeFunction(Type type);

int evalType(Tree* bt);
int evalValue(int a, int b, Token token);

void showTable(SymbolsTable *symbolsTable);
void showLevel(LSE *list);

int insertFunction(FunctionsList **table, Tree *newFunc);
ParamsList* treeToParamsList(Tree *tree);
int compareParams(ParamsList *a, ParamsList *b);

#endif