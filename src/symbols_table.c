#include "../include/tree.h"
#include "../include/symbols_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Type curretFunctionType = NO_TYPE;
ListFunction *functions;

int insertElem(SymbolsTable **symbolsTable, TData* elem) {
    if(getNode((*symbolsTable)->info, elem->name, elem->type)) {
        return 0;
    }
    LSE *aux = (*symbolsTable)->info;
    LSE* node = (LSE*)malloc(sizeof(LSE));
    node->info = elem;
    node->next = aux; 
    (*symbolsTable)->info = node;
    return 1;
}
int insertParams(ListParams **parameteres, char *functionName, Tree *params) {
    ListParams *newNode = (ListParams*)malloc(sizeof(ListParams));
    newNode->functionName = functionName;
    newNode->params = params;
    newNode->next = *parameteres;
    *parameteres = newNode;
}
int insertLevel(SymbolsTable **symbolsTable, LSE *level) {
    SymbolsTable* node = (SymbolsTable*)malloc(sizeof(SymbolsTable));
    node->info = level;
    node->next = *symbolsTable; 
    *symbolsTable = node; 
    return 1;
}

int setValueToNode(LSE *list, char* name, Type type, int val) {
    TData* elem = getNode(list, name, type);
    if(!elem)
        return 0;
    elem->value = val;
    return 1;
}

int evalType(Tree* bt) {
    if(!bt)
        return 1;
    switch(bt->info->token) {
        case T_VOID:
            return bt->info->type == VOID;
        case T_ID:
            return 1;
            break;
        case T_INTV:
        case T_INT:
            return bt->info->type == INTEGER;
            break;
        case T_TRUE:
        case T_FAL:
        case T_BOOL:
            return bt->info->type == BOOL;
            break;
        case T_MENOS: 
            if(bt->hd) {
                if(evalType(bt->hi) && evalType(bt->hd) && (bt->hd->info->type == INTEGER) && (bt->hi->info->type == INTEGER)) {
                    bt->info->type = INTEGER;
                    return 1;
                    break;
                }
                perror("Type error: integer expected\n");
                exit(1);
                return 0;
            } else {
                if(evalType(bt->hi) && bt->hi->info->type == INTEGER) {
                    bt->info->type = INTEGER;
                    return 1;
                    break;
                }
                perror("Type error: integer expected\n");
                exit(1);
                return 0;
            }
            break;
        case T_MOD: 
        case T_MULT:
        case T_MAS:
        case T_DIV: 
            if(evalType(bt->hi) && evalType(bt->hd) && (bt->hd->info->type == INTEGER) && (bt->hi->info->type == INTEGER)) {
                bt->info->type = INTEGER;
                return 1;
                break;
            }
            perror("Type error: integer expected\n");
            exit(1);
            return 0;
            break;
        case T_FUNCTION:
            curretFunctionType = bt->info->type;
            if(!insertFunction(&functions, bt->info->type, bt->info->name, bt->hi))
                return 0;
            if(bt->hd && bt->hi) 
                return evalType(bt->hi) && evalType(bt->hd);
            if(bt->hd)
                return evalType(bt->hd);
            if(bt->hi)
                return evalType(bt->hi);
            curretFunctionType = NO_TYPE;
            return bt->info->type == VOID;
        case T_METHODCALL:
            return checkFunctionCall(functions, bt->info->name, bt->hi) && evalType(bt->hi);
            break;
        case T_AND: 
        case T_OR: 
            if(evalType(bt->hi) && evalType(bt->hd) && (bt->hd->info->type == BOOL) && (bt->hi->info->type == BOOL)) {
                    bt->info->type = BOOL;
                    return 1;
            }
            perror("Type error: integer expected\n");
            exit(1);
            return 0;
            break;
        case T_NEG:
            if(evalType(bt->hi) && bt->hi->info->type == BOOL) {
                    bt->info->type = BOOL;
                    return 1;
                }
                perror("Type error: bool expected\n");
                exit(1);
                return 0;
        case T_MAYOR: 
        case T_MENOR: 
        case T_IGUAL: 
            if(evalType(bt->hi) && evalType(bt->hd) && bt->hd->info->type == bt->hi->info->type) {
                bt->info->type = BOOL;
                return 1;
            }
            perror("Type error: same type expected in comparator\n");
            exit(1);
            return 0;
            break;
        case T_RET:
            if(bt->hi) {
                if(evalType(bt->hi) && (bt->hi->info->type == curretFunctionType) && (curretFunctionType != VOID) && (curretFunctionType != NO_TYPE)) {
                    bt->info->type = bt->hi->info->type;
                    curretFunctionType = NO_TYPE;
                    return 1;
                }
                perror("Type error: wrong return\n");
                exit(1);
                return 0;
            }
            if(curretFunctionType == VOID) {
                curretFunctionType = NO_TYPE;
                return 1;
            }
            perror("Type error: return expected\n");
            exit(1);
            return 0;
            break;
        case T_ASIGN:
            if(evalType(bt->hi) && evalType(bt->hd) && bt->hi->info->type == bt->hd->info->type) {
                bt->info->type = bt->hi->info->type;
                return 1;
            }
            perror("Type error: same type expected in assignment\n");
            exit(1);
            return 0;
            break;
        case T_DECL:
            if(evalType(bt->hi) && evalType(bt->hd)) {
                bt->info->type = bt->hi->info->type;
                return 1;
            }
            perror("Declaration error: missing something?\n");
            exit(1);
            return 0;
            break;
        case T_IF:
        case T_WHILE:
            return evalType(bt->hi) && evalType(bt->hd);
            break;
        case T_THEN:
            return evalType(bt->hi);
            break;
        case T_ELSE:
            return evalType(bt->hi);
            break;
        case T_PROGRAM:
            if(bt->hd) {
                return evalType(bt->hi) && evalType(bt->hd);
            }
            return evalType(bt->hi);
            break;
        case T_METHODS:
        case T_PARAMS:
            return evalType(bt->hi) && evalType(bt->hd);
            break;
        case T_PARAM:
            return evalType(bt->hi);
            break;
        default:
            return 0;
            break; 
    }
}

TData *getNode(LSE *level, char* nom, Type type) {
    LSE *aux = level;
    while(aux != NULL && aux->info != NULL) {
        if(type == aux->info->type && strcmp(nom, (aux->info)->name) == 0)
            break;
        aux = aux->next;
    }
    if(!aux) {
        return NULL;
    }
    return aux->info;
}
TData *findVariable(SymbolsTable *symbolsTable, char* nom, Type type) {
    SymbolsTable *aux = symbolsTable;
    while(aux != NULL && aux->info != NULL) {
        TData *currentVar = getNode(aux->info, nom, type);
        if(currentVar)
            return currentVar;
        aux = aux->next;
    }
    return NULL;
}
Type doesExist(SymbolsTable *symbolsTable, char *name) {
    SymbolsTable *aux = symbolsTable;
    while(aux && aux->info) {
        for(int type = 0; type < 4; type++) {
            if(getNode(aux->info, name, type))
                return type;
        }
        aux = aux->next;
    }
    return -1; //not found
}
void showLevel(LSE *list) {
    LSE* aux = list;
    while(aux != NULL && aux->info != NULL) {
        printf("\nType: %d, var: %s\n", aux->info->type, aux->info->name);
        aux = aux->next;
    }
}
void showTable(SymbolsTable *symbolsTable) {
    SymbolsTable *aux = symbolsTable;
    while(aux) {
        showLevel(aux->info);
        printf("------------------------------\n");
        aux = aux->next;
    }
}

int removeLevel(SymbolsTable **symbolsTable) {
    (*symbolsTable) = (*symbolsTable)->next;    
    return 0;
}

int removeNode(LSE **list, TData *node) {

    LSE *aux = *list;
    LSE *aux2 = aux;
    if(aux->info == node) {
        *list = (*list)->next;
        return 1;
    }
    while(aux) {
        if(aux->info == node) {
            aux2->next = aux->next; 
            return 1;
        }
        aux2 = aux;
        aux = aux->next;
    }
    return 0;
}

int insertFunction(ListFunction **functions, Type type, char* name, Tree *params) {
    if(functionExists(*functions, type, name, params))
        return 0;
    ListFunction *newNode = (ListFunction*)malloc(sizeof(ListFunction));
    newNode->name = name;
    newNode->type = type;
    newNode->params = params;
    newNode->next = *functions;
    *functions = newNode;
}
int functionExists(ListFunction *functions, Type type, char* name, Tree *params) {
    ListFunction *aux = functions;
    while(aux) {
        if(strcmp(aux->name, name) == 0 && aux->type == type && checkParams(aux->params, params))
            return 1;
        aux = aux->next;
    }
    return 0;
}
int checkFunctionCall(ListFunction *functions, char* name, Tree *params) {
    ListFunction *aux = functions->next;
    while(aux) {
        if(strcmp(aux->name, name) == 0) {
            if(checkParams(aux->params, params))
                return 1;
        }
        aux = aux->next;
    }
     
}
int checkParams(Tree* paramsFunction, Tree* paramsCall) {
    Tree *aux = paramsFunction;
    Tree *auxCall = paramsCall;
    if (!aux && !auxCall)
        return 1;
    if(!aux || !auxCall)
        return 0;
    if(aux->info->token == T_PARAM && auxCall->info->token == T_PARAM) {
        return aux->info->type == auxCall->info->type && checkParams(aux->hi, auxCall->hi);
    }
    return checkParams(aux->hi, auxCall->hi) && checkParams(aux->hd, auxCall->hd);
}
