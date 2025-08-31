#include <stdio.h>
#include <stdbool.h>
#include "tree.h"
#include "symbols_table.h"

#ifndef ERRORS_MANAGER_H
#define ERRORS_MANAGER_H

void errorAsign(Tree *ar, bool* err);
void errorNot(Tree* ar, bool* err);
void errorCondition(Tree *ar, bool* err);
void errorOperation(Tree *ar, TOKENS type, bool* err);
void errorReturn(Tree* ar, TOKENS type, bool* err);
void evaluate_op_cond(Tree* ar, TData* auxIzq, TData* auxDer, bool* err);
void evaluate_op_booleans(Tree* ar, TData* auxIzq, TData* auxDer, bool* err);
void evaluate_op_aritmetics(Tree* ar, TData* auxIzq, TData* auxDer, bool* err);

bool isVarCompatibleASIGN (TOKENS tipoIzq, TOKENS tipoDer);

void errorCall(Tree *ar,  bool *err);
void recorrer(Tree *ar, int tipos[], int* index, int maxArg, int size, bool *err);
#endif
