#include "../include/errors_manager.h"

bool isTypeAritmetic(TOKENS token) {
    return (token == PLUS || token == MINUS || token == PROD || token == CONSINT || token == EMOD || token == EDIV );
}
bool isTypeBool(TOKENS token) {
    return (token == EOR || token == EAND || token == ENOT || token == CONSBOOL || token == GREATER_THAN || token == LESS_THAN || token == EEQ);
}
bool esComparador(TOKENS tipo) {
    return tipo == GREATER_THAN || tipo == LESS_THAN || tipo == EEQ;
}

void errorCond(Tree *ar, bool* err) {
    TData* auxIzq = LookupInCurrentLevel(((ar->left)->symbol)->varname);
    TData* auxIzqGlob = LookupExternVar(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
         auxIzq = auxIzqGlob;
    }
    TOKENS tipoIzq = ((ar->left)->symbol)->token;
    if(!auxIzq){
        if(tipoIzq == CALL_F){
            TData *typeFunc = LookupExternVar((ar->left)->left->symbol->varname);
            if(typeFunc->token != RETBOL && typeFunc->token != EXTBOL){
                printf("\033[31mError de tipo en la funcion llamada \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if(!isTypeBool(tipoIzq) && !esComparador(tipoIzq)){
            printf("\033[31mError de tipo en la condicion \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }else{
        if(auxIzq->token != VARBOOL && auxIzq->token != PARAMBOOL){
            printf("\033[31mError de tipo en la variable usada en la condicion \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}

void errorNot(Tree* ar, bool* err) {
    TData* auxIzq = LookupInCurrentLevel(((ar->left)->symbol)->varname);
    TData* auxIzqGlob = LookupExternVar(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
         auxIzq = auxIzqGlob;
    }
    TOKENS tipoIzq = ((ar->left)->symbol)->token;
    if(!auxIzq && !isTypeBool(tipoIzq) && !esComparador(tipoIzq)){
        printf("\033[31mError de tipo, operacion no definida, dentro del NOT\033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    }else if(auxIzq){
        if (auxIzq->token != VARBOOL && auxIzq->token != PARAMBOOL){
            printf("\033[31mError de tipo en el valor en la negacion con NOT\033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}

void errorRet(Tree* ar,TOKENS token, bool* err){
    TData* auxIzq = LookupInCurrentLevel(((ar->left)->symbol)->varname);
    TData* auxIzqGlob = LookupExternVar(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
         auxIzq = auxIzqGlob;
    }
    TOKENS tipoActualIzq = ((ar->left)->symbol)->token;
    if(token == RETVOID ){
            printf("\033[31mError de tipo de retorno \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
    } else {
        if(!auxIzq){
            if(tipoActualIzq == CALL_F){
                TData *typeFunc = LookupExternVar((ar->left)->left->symbol->varname);
                if(typeFunc) {
                    if(((token == RETINT || token == EXTINT) && typeFunc->token != RETINT) || ((token == RETBOL || token == EXTBOL) && (typeFunc->token != RETBOL && typeFunc->token != EXTBOL))){
                        printf("\033[31mError de tipo de retorno, tipo de funcion invalido \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                        *err = true;
                    }
                }
            }else if(((token == RETINT || token == EXTINT) && !isTypeAritmetic(tipoActualIzq)) || ((token == RETBOL || token == EXTBOL) && !isTypeBool(tipoActualIzq) && !esComparador(tipoActualIzq))) {
                printf("\033[31mError de tipo de retorno, valor esperado de tipo incorrecto \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if((auxIzq && (auxIzq->token != VARBOOL && auxIzq->token != PARAMBOOL) && (token == RETBOL || token == EXTBOL)) || (auxIzq && (auxIzq->token != VARINT && auxIzq->token != PARAMINT) && (token == RETINT || token == EXTINT))){
            printf("\033[31mError de tipo de retorno, expresion de valor incorrecto \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}

void errorAsig(Tree *ar, bool *err){
    TData* auxDer = LookupInCurrentLevel(((ar->right)->symbol)->varname);
    TData* auxDerGlob = LookupExternVar(((ar->right)->symbol)->varname);
    if(!auxDer && auxDerGlob){
        auxDer = auxDerGlob;
    }
    TData* auxIzq = LookupInCurrentLevel(((ar->left)->symbol)->varname);
    TData* auxIzqGlob = LookupExternVar(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
         auxIzq = auxIzqGlob;
    }
    TOKENS tipoDer = ((ar->right)->symbol)->token;
    TOKENS tipoIzq = ((ar->left)->symbol)->token;
    bool errorIntDer = !isTypeAritmetic(tipoDer);
    bool errorBoolDer = !isTypeBool(tipoDer);
    bool errorCondDer = !esComparador(tipoDer);
    if(auxIzq == NULL && tipoIzq == EID) {
        printf("\033[33mVariable en asignacion no declarada \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    } else if(auxIzq != NULL && auxDer != NULL && (auxIzq->token  != auxDer->token) && !isVarCompatibleASIGN(auxIzq->token, auxDer->token)) {
        printf("\033[31mError de tipo en la asignacion, tipo incompatible \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    } else if(auxIzq != NULL && auxDer == NULL) {
        if (tipoDer == EID){
            printf("\033[33mVariable a asignar no declarada \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }else if(tipoDer == CALL_F){
            TData *typeFunc = LookupExternVar((ar->right)->left->symbol->varname);
            if(typeFunc) {
                if(((auxIzq->token == VARINT || auxIzq->token == PARAMINT) && (typeFunc->token != RETINT && typeFunc->token != EXTINT)) || ((auxIzq->token == VARBOOL || auxIzq->token == PARAMBOOL) && (typeFunc->token != RETBOL && typeFunc->token != EXTBOL))){
                    printf("\033[31mError de tipo en la asignacion, tipo de la funcion incompatible \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                    *err = true;
                }
            }
        }else if(((auxIzq->token == VARINT || auxIzq->token == PARAMINT) && errorIntDer) || ((auxIzq->token == VARBOOL || auxIzq->token == PARAMBOOL) && errorBoolDer)) {
            printf("\033[31mError de tipo, error de tipo en la asignacion \033[0m, error en la linea: %d\n", ((ar->right)->symbol)->line);
            *err = true;
        }
    }
}

bool isVarCompatibleASIGN (TOKENS tipoIzq, TOKENS tipoDer) {
    bool result  = (
        (tipoIzq == PARAMBOOL && tipoDer == PARAMBOOL) ||
        (tipoIzq == PARAMBOOL && tipoDer == VARBOOL) ||
        (tipoIzq == VARBOOL && tipoDer == PARAMBOOL) ||
        (tipoIzq == PARAMINT && tipoDer == VARINT) ||
        (tipoIzq == VARINT && tipoDer == PARAMINT) ||
        (tipoIzq == PARAMINT && tipoDer == PARAMINT)
    );
    return result;
}

void errorOpera(Tree *ar, TOKENS token, bool* err){
    TData* auxDer = LookupInCurrentLevel(((ar->right)->symbol)->varname);
    TData* auxDerGlob = LookupExternVar(((ar->right)->symbol)->varname);
    if(!auxDer && auxDerGlob){
        auxDer = auxDerGlob;
    }
    TData* auxIzq = LookupInCurrentLevel(((ar->left)->symbol)->varname);
    TData* auxIzqGlob = LookupExternVar(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
         auxIzq = auxIzqGlob;
    }
    TOKENS tipoDer = ((ar->right)->symbol)->token;
    TOKENS tipoIzq = ((ar->left)->symbol)->token;
    bool errorIntDer = !isTypeAritmetic(tipoDer);
    bool errorIzq = !isTypeAritmetic(tipoIzq);
    if(token == PLUS || token == MINUS || token == PROD || token == EMOD || token == EDIV) {
        evaluate_op_aritmeticos(ar, auxIzq, auxDer, err);
    } else if(token == EOR || token == EAND || token == ENOT){
        evaluate_op_booleanos(ar, auxIzq, auxDer, err);
    }else {
        evaluate_op_condiciones(ar, auxIzq, auxDer, err);
    }
}

void evaluate_op_condiciones(Tree* ar, TData* auxIzq, TData* auxDer, bool* err){
    int lineErrLeft = ((ar->left)->symbol)->line;
    TOKENS tipoDer = ((ar->right)->symbol)->token;
    TOKENS tipoIzq = ((ar->left)->symbol)->token;
    bool errorIntDer = !isTypeAritmetic(tipoDer);
    bool errorSintacticoDer = esComparador(tipoDer);
    bool errorIntIzq = !isTypeAritmetic(tipoIzq);
    bool errorSintacticoIzq = esComparador(tipoIzq);
    if(auxIzq && auxDer){
        if((auxIzq->token != VARINT && auxIzq->token != PARAMINT) || (auxDer->token != VARINT && auxDer->token != PARAMINT)){
            printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    } else if((auxIzq != NULL && auxDer == NULL) ^ (auxIzq == NULL && auxDer != NULL)) {
        if ((!auxDer && tipoDer == EID) ^ (!auxIzq && tipoIzq == EID)) {
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        } else if((!auxDer && tipoDer == CALL_F) ^ (!auxIzq && tipoIzq == CALL_F)){
            if(tipoDer == CALL_F){
                TData *typeFuncDer = LookupExternVar((ar->right)->left->symbol->varname);
                if(typeFuncDer) {
                    if(((auxIzq->token != VARINT && auxIzq->token != PARAMINT) || (typeFuncDer->token != RETINT && typeFuncDer->token != EXTINT))){
                        printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                        *err = true;
                    }
                }
            }else {
                TData *typeFuncIzq = LookupExternVar((ar->left)->left->symbol->varname);
                if(((auxDer->token != VARINT && auxDer->token != PARAMINT) || (typeFuncIzq->token != RETINT && typeFuncIzq->token != EXTINT))){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }else if((!auxDer && ((auxIzq->token != VARINT && auxIzq->token != PARAMINT) || errorIntDer)) ^ (!auxIzq && ((auxDer->token != VARINT && auxDer->token != PARAMINT) || errorIntIzq))) {
            if(!auxDer && errorSintacticoDer || !auxIzq && errorSintacticoIzq){
                printf("\033[31mError Sintactico \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }else{
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
    } else if(auxIzq == NULL && auxDer == NULL){
        if (tipoIzq == EID || tipoDer == EID){
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        if(tipoDer == CALL_F){
            TData *typeFuncDer = LookupExternVar((ar->right)->left->symbol->varname);
            if(typeFuncDer){
                if(typeFuncDer->token != RETINT && typeFuncDer->token != EXTINT){
                    printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }
        if(tipoIzq == CALL_F){
            TData *typeFuncIzq = LookupExternVar((ar->left)->left->symbol->varname);
            if(typeFuncIzq){
                if(typeFuncIzq->token != RETINT && typeFuncIzq->token != EXTINT){
                    printf("\033[31mError de tipo \033[0m, error en la linea: %d\n",lineErrLeft);
                    *err = true;
                }
            }
        }
        if((errorIntIzq && tipoIzq != CALL_F) || (errorIntDer &&  tipoDer != CALL_F)){
            if(errorSintacticoIzq || errorSintacticoDer){
                printf("\033[31mError Sintactico \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }else{
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
    }
}

void evaluate_op_booleanos(Tree* ar, TData* auxIzq, TData* auxDer, bool* err) {
    int lineErrLeft = ((ar->left)->symbol)->line;
    TOKENS tipoDer = ((ar->right)->symbol)->token;
    TOKENS tipoIzq = ((ar->left)->symbol)->token;
    bool errorBoolDer = !isTypeBool(tipoDer) && !esComparador(tipoDer);
    bool errorBoolIzq = !isTypeBool(tipoIzq) && !esComparador(tipoDer);
    if(auxIzq && auxDer){
        if((auxIzq->token != VARBOOL && auxIzq->token != PARAMBOOL) || (auxDer->token != VARBOOL && auxDer->token != PARAMBOOL)){
            printf("\033[31mError de tipo en operacion booleana \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    } else if((auxIzq != NULL && auxDer == NULL) ^ (auxIzq == NULL && auxDer != NULL)) {
        if ((!auxDer && tipoDer == EID) || (!auxIzq && tipoIzq == EID)) {
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        } else if((!auxDer && tipoDer == CALL_F) ^ (!auxIzq && tipoIzq == CALL_F)){
            if(tipoDer == CALL_F){
                TData *typeFuncDer = LookupExternVar((ar->right)->left->symbol->varname);
                if(typeFuncDer){
                    if(((auxIzq->token != VARBOOL && auxIzq->token != PARAMBOOL) || (typeFuncDer->token != RETBOL && typeFuncDer->token != EXTBOL))){
                        printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                        *err = true;
                    }
                }
            }else {
                TData *typeFuncIzq = LookupExternVar((ar->left)->left->symbol->varname);
                if(((auxDer->token != VARBOOL && auxDer->token != PARAMBOOL) || (typeFuncIzq->token != RETBOL && typeFuncIzq->token != EXTBOL))){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }else if((!auxDer && ((auxIzq->token != VARBOOL && auxIzq->token != PARAMBOOL) || errorBoolDer)) ^ (!auxIzq && ((auxDer->token != VARBOOL && auxDer->token != PARAMBOOL) || errorBoolIzq))) {
            printf("\033[31mError de tipo, valores de condicion incompatibles \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    } else if(auxIzq == NULL && auxDer == NULL){
        if (tipoIzq == EID || tipoDer == EID){
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        if(tipoDer == CALL_F){
            TData *typeFuncDer = LookupExternVar((ar->right)->left->symbol->varname);
            if(typeFuncDer){
                if(typeFuncDer->token != RETBOL && typeFuncDer->token != EXTBOL){
                    printf("\033[31mError de tipo, funcion de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }
        if(tipoIzq == CALL_F){
            TData *typeFuncIzq = LookupExternVar((ar->left)->left->symbol->varname);
            if(typeFuncIzq){
                if(typeFuncIzq->token != RETBOL && typeFuncIzq->token != EXTBOL){
                    printf("\033[31mError de tipo, funcion de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }
        if((errorBoolIzq && tipoIzq != CALL_F) || (errorBoolDer &&  tipoDer != CALL_F)){
            printf("\033[31mError de tipo, tipos de valores incompatibles \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    }
}

void evaluate_op_aritmeticos(Tree* ar, TData* auxIzq, TData* auxDer, bool* err) {
    TOKENS tipoDer = ((ar->right)->symbol)->token;
    TOKENS tipoIzq = ((ar->left)->symbol)->token;
    bool errorIntDer = !isTypeAritmetic(tipoDer);
    bool errorIzq = !isTypeAritmetic(tipoIzq);
    int lineErrLeft = ((ar->left)->symbol)->line;
    if(auxIzq && auxDer){
        if((auxIzq->token != VARINT && auxIzq->token != PARAMINT) || (auxDer->token != VARINT && auxDer->token != PARAMINT)) {
            printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    } else if(auxIzq == NULL && auxDer == NULL){
            if (tipoIzq == EID || tipoDer == EID){
                printf("\033[33mVariablexxx no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
            if(tipoDer == CALL_F){
                TData *typeFuncDer = LookupExternVar((ar->right)->left->symbol->varname);
                if(typeFuncDer){
                    if(typeFuncDer->token != RETINT && typeFuncDer->token != EXTINT){
                        printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                        *err = true;
                    }
                }
            }
            if(tipoIzq == CALL_F){
                TData *typeFuncIzq = LookupExternVar((ar->left)->left->symbol->varname);
                if(typeFuncIzq){
                    if(typeFuncIzq->token != RETINT && typeFuncIzq->token != EXTINT){
                        printf("\033[31mError de tipo \033[0m, error en la linea: %d\n",lineErrLeft);
                        *err = true;
                    }
                }
            }
            if((errorIzq && tipoIzq != CALL_F) || (errorIntDer &&  tipoDer != CALL_F)){
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        } else if((auxIzq != NULL && auxDer == NULL) ^ (auxIzq == NULL && auxDer != NULL)) {
            if ((!auxDer && tipoDer == EID) ^ (!auxIzq && tipoIzq == EID)){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", lineErrLeft);
                *err = true;
            } else if((!auxDer && tipoDer == CALL_F) ^ (!auxIzq && tipoIzq == CALL_F)){
                if(tipoDer == CALL_F) {
                    TData *typeFuncDer = LookupExternVar((ar->right)->left->symbol->varname);
                    if(typeFuncDer){
                        if(((auxIzq->token != VARINT && auxIzq->token != PARAMINT) || (typeFuncDer->token != RETINT && typeFuncDer->token != EXTINT))){
                            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                            *err = true;
                        }
                    }
                } else {
                    TData *typeFuncIzq = LookupExternVar((ar->left)->left->symbol->varname);
                    if(((auxDer->token != VARINT && auxDer->token != PARAMINT) || (typeFuncIzq->token != RETINT && typeFuncIzq->token != EXTINT))){
                        printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                        *err = true;
                    }
                }
            }else if((!auxDer && ((auxIzq->token != VARINT && auxIzq->token != PARAMINT) || errorIntDer)) ^ (!auxIzq &&((auxDer->token != VARINT && auxDer->token != PARAMINT) || errorIzq))) {
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                *err = true;
            }
        }
}

void errorCall(Tree *ar,  bool *err) {
    TData* func = LookupExternVar(ar->left->symbol->varname);
    int len = cantArguments(func);
    int index = 0;
    if (len >= 0) {
        int typesArg[len];
        recorrer(ar->right,typesArg, &index, len, ar->symbol->size, err);
        int i = 0;
        int *typesParam = typeParam(func);
        if(len == index) {
             for (int j = 0; j < len; j++) {
                bool bolCond1 = (typesParam[j] == PARAMBOOL) && (typesArg[j] == VARINT || typesArg[j] == CONSINT|| typesArg[j] == RETINT || typesArg[j] == EXTINT);
                bool bolCond4 = (typesParam[j] == PARAMINT ) && (typesArg[j] == VARBOOL || typesArg[j] == CONSBOOL || typesArg[j] == RETBOL || typesArg[j] == EXTBOL);
                if  ( bolCond1 || bolCond4) {
                    printf("\033[31mError de tipo en el argumento pasado \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                    *err = true;
                }
            }
        }else {
                printf("\033[31mError en la funcion llamada, cantidad de argumentos invalida \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
        }
    }
}

void recorrer(Tree *ar, int tipos[], int* index, int maxArg, int size, bool *err){
    if(!ar) 
        return;

    TOKENS tipoActual = ar->symbol->token;
    bool operArit = (tipoActual != PLUS && tipoActual != MINUS && tipoActual != PROD && tipoActual != EDIV && tipoActual != EMOD);
    bool operBool = (tipoActual != EOR && tipoActual != EAND && tipoActual != ENOT );
    bool operCondi = (tipoActual != GREATER_THAN && tipoActual != LESS_THAN && tipoActual != EEQ);
    bool ifNotType = (tipoActual != CALL_F && (operArit && operBool && operCondi));
    if(ifNotType) {
        if(ar->left != NULL){
            recorrer(ar->left, tipos, index, maxArg, size, err);
        }
        if(ar->right != NULL){
            recorrer(ar->right, tipos, index, maxArg, size, err);
        }
    }
    if(ar->symbol->token != ARGS && ar->symbol->token != EFUNC ){
        if(*index < maxArg) {
            TData* arg = LookupInCurrentLevel(ar->symbol->varname);
            TData* argGlob = LookupExternVar(ar->symbol->varname);

            if(!arg && argGlob){
                arg = argGlob;
            }
            if (arg == NULL) {
                bool operArit = (tipoActual == PLUS || tipoActual == MINUS || tipoActual == PROD || tipoActual == EDIV || tipoActual == EMOD);
                bool operBool = (tipoActual == EOR || tipoActual == EAND || tipoActual == ENOT );
                bool operCondi = (tipoActual == GREATER_THAN || tipoActual == LESS_THAN || tipoActual == EEQ);
                if(ar->symbol->token == CALL_F) {
                    TData *typeFunc = LookupExternVar(ar->left->symbol->varname);
                    if(typeFunc) {
                        if(!arg && argGlob){
                            arg = argGlob;
                        }
                        tipos[*index] = typeFunc->token;
                        (*index)++;
                    }
                }else if (ar->symbol->token == CONSINT || ar->symbol->token == CONSBOOL) {
                    tipos[*index] = ar->symbol->token;
                    (*index)++;

                }else if(operArit) {
                    tipos[*index] = VARINT;
                    (*index)++;
                }else if(operBool || operCondi){
                    tipos[*index] = VARBOOL;
                    (*index)++;
                }else{
                    printf("\033[31mArgumento no declarado \033[0m, error en la linea: %d\n", (ar->symbol)->line);
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