#include "../include/errors_manager.h"

bool isTypeAritmetic(TOKENS token) {
    return (token == PLUS || token == MINUS || token == PROD || token == CONSINT || token == EMOD || token == EDIV);
}

bool isTypeBool(TOKENS token) {
    return (token == EOR || token == EAND || token == ENOT || token == CONSBOOL || token == T_GREATER_THAN || token == T_LESS_THAN || token == EEQ);
}

bool esComparador(TOKENS tipo) {
    return (tipo == T_GREATER_THAN || tipo == T_LESS_THAN || tipo == EEQ);
}

void errorCondition(Tree *tree, bool* err) {
    TData* auxLeft = LookupInCurrentLevel(tree->left->symbol->varname);
    TData* auxIzqGlob = LookupExternVar(tree->left->symbol->varname);
    if (!auxLeft && auxIzqGlob) auxLeft = auxIzqGlob;
    TOKENS tokenLeft = tree->left->symbol->token;

    if (!auxLeft) {
        if (tokenLeft == CALL_F) {
            TData *typeFunc = LookupExternVar(tree->left->left->symbol->varname);
            if (typeFunc && typeFunc->token != RETBOL && typeFunc->token != EXTBOL) {
                printf("\033[31mError de tipo en la funcion llamada \033[0m, error en la linea: %d\n", tree->left->symbol->line);
                *err = true;
            }
        } else if (!isTypeBool(tokenLeft) && !esComparador(tokenLeft)) {
            printf("\033[31mError de tipo en la condicion \033[0m, error en la linea: %d\n", tree->left->symbol->line);
            *err = true;
        }
    } else if (auxLeft->token != VARBOOL && auxLeft->token != PARAMBOOL) {
        printf("\033[31mError de tipo en la variable usada en la condicion \033[0m, error en la linea: %d\n", tree->left->symbol->line);
        *err = true;
    }
}

void errorNot(Tree* tree, bool* err) {
    TData* auxLeft = LookupInCurrentLevel(tree->left->symbol->varname);
    TData* auxIzqGlob = LookupExternVar(tree->left->symbol->varname);
    if (!auxLeft && auxIzqGlob) auxLeft = auxIzqGlob;
    TOKENS tokenLeft = tree->left->symbol->token;

    if (!auxLeft && !isTypeBool(tokenLeft) && !esComparador(tokenLeft)) {
        printf("\033[31mError de tipo, operacion no definida, dentro del NOT\033[0m, error en la linea: %d\n", tree->left->symbol->line);
        *err = true;
    } else if (auxLeft && auxLeft->token != VARBOOL && auxLeft->token != PARAMBOOL) {
        printf("\033[31mError de tipo en el valor en la negacion con NOT\033[0m, error en la linea: %d\n", tree->left->symbol->line);
        *err = true;
    }
}

void errorReturn(Tree* tree, TOKENS token, bool* err) {
    TData* auxLeft = LookupInCurrentLevel(tree->left->symbol->varname);
    TData* auxIzqGlob = LookupExternVar(tree->left->symbol->varname);
    if (!auxLeft && auxIzqGlob) auxLeft = auxIzqGlob;
    TOKENS currentTokenLeft = tree->left->symbol->token;

    if (token == RETVOID) {
        printf("\033[31mError de tipo de retorno \033[0m, error en la linea: %d\n", tree->left->symbol->line);
        *err = true;
        return;
    }

    if (!auxLeft) {
        if (currentTokenLeft == CALL_F) {
            TData *typeFunc = LookupExternVar(tree->left->left->symbol->varname);
            if (typeFunc) {
                bool badInt = (token == RETINT || token == EXTINT) && typeFunc->token != RETINT;
                bool badBool = (token == RETBOL || token == EXTBOL) && (typeFunc->token != RETBOL && typeFunc->token != EXTBOL);
                if (badInt || badBool) {
                    printf("\033[31mError de tipo de retorno, tipo de funcion invalido \033[0m, error en la linea: %d\n", tree->left->symbol->line);
                    *err = true;
                }
            }
        } else if (((token == RETINT || token == EXTINT) && !isTypeAritmetic(currentTokenLeft)) ||
                   ((token == RETBOL || token == EXTBOL) && !isTypeBool(currentTokenLeft) && !esComparador(currentTokenLeft))) {
            printf("\033[31mError de tipo de retorno, valor esperado de tipo incorrecto \033[0m, error en la linea: %d\n", tree->left->symbol->line);
            *err = true;
        }
    } else if (((auxLeft->token != VARBOOL && auxLeft->token != PARAMBOOL) && (token == RETBOL || token == EXTBOL)) ||
               ((auxLeft->token != VARINT && auxLeft->token != PARAMINT) && (token == RETINT || token == EXTINT))) {
        printf("\033[31mError de tipo de retorno, expresion de valor incorrecto \033[0m, error en la linea: %d\n", tree->left->symbol->line);
        *err = true;
    }
}

void errorAsign(Tree *tree, bool *err) {
    TData* auxRight = LookupInCurrentLevel(tree->right->symbol->varname);
    TData* auxRightGlob = LookupExternVar(tree->right->symbol->varname);
    if (!auxRight && auxRightGlob) auxRight = auxRightGlob;
    TData* auxLeft = LookupInCurrentLevel(tree->left->symbol->varname);
    TData* auxIzqGlob = LookupExternVar(tree->left->symbol->varname);
    if (!auxLeft && auxIzqGlob) auxLeft = auxIzqGlob;

    TOKENS tokenRight = tree->right->symbol->token;
    TOKENS tokenLeft = tree->left->symbol->token;
    bool errorIntRight = !isTypeAritmetic(tokenRight);
    bool errorBoolRight = !isTypeBool(tokenRight);

    if (!auxLeft && tokenLeft == EID) {
        printf("\033[33mVariable en asignacion no declarada \033[0m, error en la linea: %d\n", tree->left->symbol->line);
        *err = true;
    } else if (auxLeft && auxRight && auxLeft->token != auxRight->token && !isVarCompatibleASIGN(auxLeft->token, auxRight->token)) {
        printf("\033[31mError de tipo en la asignacion, tipo incompatible \033[0m, error en la linea: %d\n", tree->left->symbol->line);
        *err = true;
    } else if (auxLeft && !auxRight) {
        if (tokenRight == EID) {
            printf("\033[33mVariable a asignar no declarada \033[0m, error en la linea: %d\n", tree->left->symbol->line);
            *err = true;
        } else if (tokenRight == CALL_F) {
            TData *typeFunc = LookupExternVar(tree->right->left->symbol->varname);
            if (typeFunc) {
                bool badInt = (auxLeft->token == VARINT || auxLeft->token == PARAMINT) && (typeFunc->token != RETINT && typeFunc->token != EXTINT);
                bool badBool = (auxLeft->token == VARBOOL || auxLeft->token == PARAMBOOL) && (typeFunc->token != RETBOL && typeFunc->token != EXTBOL);
                if (badInt || badBool) {
                    printf("\033[31mError de tipo en la asignacion, tipo de la funcion incompatible \033[0m, error en la linea: %d\n", tree->left->symbol->line);
                    *err = true;
                }
            }
        } else if (((auxLeft->token == VARINT || auxLeft->token == PARAMINT) && errorIntRight) ||
                   ((auxLeft->token == VARBOOL || auxLeft->token == PARAMBOOL) && errorBoolRight)) {
            printf("\033[31mError de tipo, error de tipo en la asignacion \033[0m, error en la linea: %d\n", tree->right->symbol->line);
            *err = true;
        }
    }
}

bool isVarCompatibleASIGN(TOKENS tokenLeft, TOKENS tokenRight) {
    return
        (tokenLeft == PARAMBOOL && tokenRight == PARAMBOOL) ||
        (tokenLeft == PARAMBOOL && tokenRight == VARBOOL) ||
        (tokenLeft == VARBOOL && tokenRight == PARAMBOOL) ||
        (tokenLeft == PARAMINT && tokenRight == VARINT) ||
        (tokenLeft == VARINT && tokenRight == PARAMINT) ||
        (tokenLeft == PARAMINT && tokenRight == PARAMINT);
}

void errorOperation(Tree *tree, TOKENS token, bool* err) {
    TData* auxRight = LookupInCurrentLevel(tree->right->symbol->varname);
    TData* auxRightGlob = LookupExternVar(tree->right->symbol->varname);
    if (!auxRight && auxRightGlob) auxRight = auxRightGlob;
    TData* auxLeft = LookupInCurrentLevel(tree->left->symbol->varname);
    TData* auxIzqGlob = LookupExternVar(tree->left->symbol->varname);
    if (!auxLeft && auxIzqGlob) auxLeft = auxIzqGlob;

    if (token == PLUS || token == MINUS || token == PROD || token == EMOD || token == EDIV) {
        evaluate_op_aritmetics(tree, auxLeft, auxRight, err);
    } else if (token == EOR || token == EAND || token == ENOT) {
        evaluate_op_booleans(tree, auxLeft, auxRight, err);
    } else {
        evaluate_op_cond(tree, auxLeft, auxRight, err);
    }
}

void evaluate_op_cond(Tree* tree, TData* auxLeft, TData* auxRight, bool* err) {
    int lineErrLeft = tree->left->symbol->line;
    TOKENS tokenRight = tree->right->symbol->token;
    TOKENS tokenLeft = tree->left->symbol->token;
    bool errorIntRight = !isTypeAritmetic(tokenRight);
    bool sintaticErrRight = esComparador(tokenRight);
    bool errorIntIzq = !isTypeAritmetic(tokenLeft);
    bool errorSintacticoIzq = esComparador(tokenLeft);

    if (auxLeft && auxRight) {
        if ((auxLeft->token != VARINT && auxLeft->token != PARAMINT) ||
            (auxRight->token != VARINT && auxRight->token != PARAMINT)) {
            printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        return;
    }

    if ((auxLeft && !auxRight) ^ (!auxLeft && auxRight)) {
        if ((!auxRight && tokenRight == EID) ^ (!auxLeft && tokenLeft == EID)) {
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        } else if ((!auxRight && tokenRight == CALL_F) ^ (!auxLeft && tokenLeft == CALL_F)) {
            if (tokenRight == CALL_F) {
                TData *dataFunLeft = LookupExternVar(tree->right->left->symbol->varname);
                if (dataFunLeft &&
                    ((auxLeft->token != VARINT && auxLeft->token != PARAMINT) ||
                     (dataFunLeft->token != RETINT && dataFunLeft->token != EXTINT))) {
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            } else {
                TData *dataFunLeft = LookupExternVar(tree->left->left->symbol->varname);
                if ((auxRight->token != VARINT && auxRight->token != PARAMINT) ||
                    (dataFunLeft->token != RETINT && dataFunLeft->token != EXTINT)) {
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        } else if ((!auxRight && ((auxLeft->token != VARINT && auxLeft->token != PARAMINT) || errorIntRight)) ^
                   (!auxLeft && ((auxRight->token != VARINT && auxRight->token != PARAMINT) || errorIntIzq))) {
            if ((!auxRight && sintaticErrRight) || (!auxLeft && errorSintacticoIzq)) {
                printf("\033[31mError Sintactico \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            } else {
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        return;
    }

    if (!auxLeft && !auxRight) {
        if (tokenLeft == EID || tokenRight == EID) {
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        if (tokenRight == CALL_F) {
            TData *dataFunLeft = LookupExternVar(tree->right->left->symbol->varname);
            if (dataFunLeft && dataFunLeft->token != RETINT && dataFunLeft->token != EXTINT) {
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if (tokenLeft == CALL_F) {
            TData *dataFunLeft = LookupExternVar(tree->left->left->symbol->varname);
            if (dataFunLeft && dataFunLeft->token != RETINT && dataFunLeft->token != EXTINT) {
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if ((errorIntIzq && tokenLeft != CALL_F) || (errorIntRight && tokenRight != CALL_F)) {
            if (errorSintacticoIzq || sintaticErrRight) {
                printf("\033[31mError Sintactico \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            } else {
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
    }
}

void evaluate_op_booleans(Tree* tree, TData* auxLeft, TData* auxRight, bool* err) {
    int lineErrLeft = tree->left->symbol->line;
    TOKENS tokenRight = tree->right->symbol->token;
    TOKENS tokenLeft = tree->left->symbol->token;
    bool errorBoolRight = !isTypeBool(tokenRight) && !esComparador(tokenRight);
    bool errorBoolLeft = !isTypeBool(tokenLeft) && !esComparador(tokenRight);

    if (auxLeft && auxRight) {
        if ((auxLeft->token != VARBOOL && auxLeft->token != PARAMBOOL) ||
            (auxRight->token != VARBOOL && auxRight->token != PARAMBOOL)) {
            printf("\033[31mError de tipo en operacion booleana \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        return;
    }

    if ((auxLeft && !auxRight) ^ (!auxLeft && auxRight)) {
        if ((!auxRight && tokenRight == EID) || (!auxLeft && tokenLeft == EID)) {
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        } else if ((!auxRight && tokenRight == CALL_F) ^ (!auxLeft && tokenLeft == CALL_F)) {
            if (tokenRight == CALL_F) {
                TData *dataFunLeft = LookupExternVar(tree->right->left->symbol->varname);
                if (dataFunLeft &&
                    ((auxLeft->token != VARBOOL && auxLeft->token != PARAMBOOL) ||
                     (dataFunLeft->token != RETBOL && dataFunLeft->token != EXTBOL))) {
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            } else {
                TData *dataFunLeft = LookupExternVar(tree->left->left->symbol->varname);
                if ((auxRight->token != VARBOOL && auxRight->token != PARAMBOOL) ||
                    (dataFunLeft->token != RETBOL && dataFunLeft->token != EXTBOL)) {
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        } else if ((!auxRight && ((auxLeft->token != VARBOOL && auxLeft->token != PARAMBOOL) || errorBoolRight)) ^
                   (!auxLeft && ((auxRight->token != VARBOOL && auxRight->token != PARAMBOOL) || errorBoolLeft))) {
            printf("\033[31mError de tipo, valores de condicion incompatibles \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        return;
    }

    if (!auxLeft && !auxRight) {
        if (tokenLeft == EID || tokenRight == EID) {
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        if (tokenRight == CALL_F) {
            TData *dataFunLeft = LookupExternVar(tree->right->left->symbol->varname);
            if (dataFunLeft && dataFunLeft->token != RETBOL && dataFunLeft->token != EXTBOL) {
                printf("\033[31mError de tipo, funcion de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if (tokenLeft == CALL_F) {
            TData *dataFunLeft = LookupExternVar(tree->left->left->symbol->varname);
            if (dataFunLeft && dataFunLeft->token != RETBOL && dataFunLeft->token != EXTBOL) {
                printf("\033[31mError de tipo, funcion de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if ((errorBoolLeft && tokenLeft != CALL_F) || (errorBoolRight && tokenRight != CALL_F)) {
            printf("\033[31mError de tipo, tipos de valores incompatibles \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    }
}

void evaluate_op_aritmetics(Tree* tree, TData* auxLeft, TData* auxRight, bool* err) {
    TOKENS tokenRight = tree->right->symbol->token;
    TOKENS tokenLeft = tree->left->symbol->token;
    bool errorIntRight = !isTypeAritmetic(tokenRight);
    bool errorLeft = !isTypeAritmetic(tokenLeft);
    int lineErrLeft = tree->left->symbol->line;

    if (auxLeft && auxRight) {
        if ((auxLeft->token != VARINT && auxLeft->token != PARAMINT) ||
            (auxRight->token != VARINT && auxRight->token != PARAMINT)) {
            printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        return;
    }

    if (!auxLeft && !auxRight) {
        if (tokenLeft == EID || tokenRight == EID) {
            printf("\033[33mVariablexxx no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        if (tokenRight == CALL_F) {
            TData *dataFunLeft = LookupExternVar(tree->right->left->symbol->varname);
            if (dataFunLeft && dataFunLeft->token != RETINT && dataFunLeft->token != EXTINT) {
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if (tokenLeft == CALL_F) {
            TData *dataFunLeft = LookupExternVar(tree->left->left->symbol->varname);
            if (dataFunLeft && dataFunLeft->token != RETINT && dataFunLeft->token != EXTINT) {
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if ((errorLeft && tokenLeft != CALL_F) || (errorIntRight && tokenRight != CALL_F)) {
            printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        return;
    }

    if ((auxLeft && !auxRight) ^ (!auxLeft && auxRight)) {
        if ((!auxRight && tokenRight == EID) ^ (!auxLeft && tokenLeft == EID)) {
            printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", lineErrLeft);
            *err = true;
        } else if ((!auxRight && tokenRight == CALL_F) ^ (!auxLeft && tokenLeft == CALL_F)) {
            if (tokenRight == CALL_F) {
                TData *dataFunLeft = LookupExternVar(tree->right->left->symbol->varname);
                if (dataFunLeft &&
                    ((auxLeft->token != VARINT && auxLeft->token != PARAMINT) ||
                     (dataFunLeft->token != RETINT && dataFunLeft->token != EXTINT))) {
                    printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                    *err = true;
                }
            } else {
                TData *dataFunLeft = LookupExternVar(tree->left->left->symbol->varname);
                if ((auxRight->token != VARINT && auxRight->token != PARAMINT) ||
                    (dataFunLeft->token != RETINT && dataFunLeft->token != EXTINT)) {
                    printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        } else if ((!auxRight && ((auxLeft->token != VARINT && auxLeft->token != PARAMINT) || errorIntRight)) ^
                   (!auxLeft && ((auxRight->token != VARINT && auxRight->token != PARAMINT) || errorLeft))) {
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
            *err = true;
        }
    }
}

void errorCall(Tree *tree, bool *err) {
    TData* func = LookupExternVar(tree->left->symbol->varname);
    int len = cantArguments(func);
    int index = 0;
    if (len >= 0) {
        int typesArg[len];
        recorrer(tree->right, typesArg, &index, len, 1, err);
        int *typesParam = typeParam(func);
        if (len == index) {
            for (int j = 0; j < len; j++) {
                bool badBool = (typesParam[j] == PARAMBOOL) && (typesArg[j] == VARINT || typesArg[j] == CONSINT || typesArg[j] == RETINT || typesArg[j] == EXTINT);
                bool badInt = (typesParam[j] == PARAMINT) && (typesArg[j] == VARBOOL || typesArg[j] == CONSBOOL || typesArg[j] == RETBOL || typesArg[j] == EXTBOL);
                if (badBool || badInt) {
                    printf("\033[31mError de tipo en el argumento pasado \033[0m, error en la linea: %d\n", tree->left->symbol->line);
                    *err = true;
                }
            }
        } else {
            printf("\033[31mError en la funcion llamada, cantidad de argumentos invalida \033[0m, error en la linea: %d\n", tree->left->symbol->line);
            *err = true;
        }
        free(typesParam);
    }
}

void recorrer(Tree *tree, int tipos[], int* index, int maxArg, int size, bool *err) {
    if (!tree) return;

    TOKENS tokenActual = tree->symbol->token;
    bool operArit = (tokenActual != PLUS && tokenActual != MINUS && tokenActual != PROD && tokenActual != EDIV && tokenActual != EMOD);
    bool operBool = (tokenActual != EOR && tokenActual != EAND && tokenActual != ENOT);
    bool operCondi = (tokenActual != T_GREATER_THAN && tokenActual != T_LESS_THAN && tokenActual != EEQ);
    bool ifNotType = (tokenActual != CALL_F && (operArit && operBool && operCondi));

    if (ifNotType) {
        if (tree->left) recorrer(tree->left, tipos, index, maxArg, size, err);
        if (tree->right) recorrer(tree->right, tipos, index, maxArg, size, err);
    }

    if (tree->symbol->token != ARGS && tree->symbol->token != EFUNC) {
        if (*index < maxArg) {
            TData* arg = LookupInCurrentLevel(tree->symbol->varname);
            TData* argGlob = LookupExternVar(tree->symbol->varname);
            if (!arg && argGlob) arg = argGlob;

            if (!arg) {
                bool operArit2 = (tokenActual == PLUS || tokenActual == MINUS || tokenActual == PROD || tokenActual == EDIV || tokenActual == EMOD);
                bool operBool2 = (tokenActual == EOR || tokenActual == EAND || tokenActual == ENOT);
                bool operCondi2 = (tokenActual == T_GREATER_THAN || tokenActual == T_LESS_THAN || tokenActual == EEQ);
                if (tree->symbol->token == CALL_F) {
                    TData *typeFunc = LookupExternVar(tree->left->symbol->varname);
                    if (typeFunc) {
                        tipos[*index] = typeFunc->token;
                        (*index)++;
                    }
                } else if (tree->symbol->token == CONSINT || tree->symbol->token == CONSBOOL) {
                    tipos[*index] = tree->symbol->token;
                    (*index)++;
                } else if (operArit2) {
                    tipos[*index] = VARINT;
                    (*index)++;
                } else if (operBool2 || operCondi2) {
                    tipos[*index] = VARBOOL;
                    (*index)++;
                } else {
                    printf("\033[31mArgumento no declarado \033[0m, error en la linea: %d\n", tree->symbol->line);
                    *err = true;
                }
            } else {
                tipos[*index] = arg->token;
                (*index)++;
            }
        } else {
            *err = true;
            (*index)++;
        }
    }
}