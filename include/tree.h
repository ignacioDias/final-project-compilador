#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbols_table.h"
#ifndef AST_H
#define AST_H

typedef struct AST {
    struct TData *symbol;
    struct AST *left;
    struct AST *right;
} Tree;

Tree* createTree(TData* symbol, Tree *l, Tree *r);

void showTreeDot(Tree* tree,FILE* file);
void printDot(Tree* tree, const char* filename);
void elimArbol(Tree* tree);

void createTable(Tree* tree);
void typeError(Tree* tree);
void evaluate(Tree* tree);

bool getError();
void retError();

#endif
