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

// Create a new tree node
Tree* createTree(TData* symbol, Tree *left, Tree *right);

// Update the symbol of a tree node
void updateTreeNode(Tree* node, TData* symbol);

// Recursively free the tree and its symbols
void freeTree(Tree* node);

// Build the symbol table and perform semantic analysis
void buildSymbolTable(Tree* node);

// Print error if a return statement is missing in a function
void checkMissingReturnError(void);

// Returns true if a semantic error was detected
bool hasSemanticError(void);
#endif
