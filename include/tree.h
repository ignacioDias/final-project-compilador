#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbols_table.h"
#ifndef TREE_H
#define TREE_H

typedef struct BinaryTree {
    struct TData *symbol;
    struct BinaryTree *left;
    struct BinaryTree *right;
} Tree;

Tree* createTree(TData* symbol, Tree *l, Tree *r);

void showTreeDot(Tree* tree,FILE* file);
void printDot(Tree* tree, const char* filename);
void elimArbol(Tree* tree);

void createTable(Tree* tree);

bool getError();
void retError();

#endif
