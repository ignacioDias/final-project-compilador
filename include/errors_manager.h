#include <stdio.h>
#include <stdbool.h>
#include "tree.h"
#include "symbols_table.h"

#ifndef ERRORS_H
#define ERRORS_H

void errorAsig(Tree *ar, bool* err);
void errorNot(Tree* ar, bool* err);
void errorCond(Tree *ar, bool* err);
void errorOpera(Tree *ar, TOKENS type, bool* err);
void errorRet(Tree* ar, TOKENS type, bool* err);
void evaluate_op_condiciones(Tree* ar, TData* auxIzq, TData* auxDer, bool* err);
void evaluate_op_booleanos(Tree* ar, TData* auxIzq, TData* auxDer, bool* err);
void evaluate_op_aritmeticos(Tree* ar, TData* auxIzq, TData* auxDer, bool* err);

bool isVarCompatibleASIGN (TOKENS tipoIzq, TOKENS tipoDer);

void errorCall(Tree *ar,  bool *err);
void recorrer(Tree *ar, int tipos[], int* index, int maxArg, int size, bool *err);
#endif
