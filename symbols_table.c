#include "tree.h"
#include "symbols_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Type curretFunctionType = NO_TYPE;

int insert(LSE **list, TData* elem) {
    if(get(*list, elem->name))
        return -1;
    if(*list == NULL) {
        *list = (LSE*)malloc(sizeof(LSE));
        (*list)->info = elem;
    } else {
        LSE *aux = (LSE*)malloc(sizeof(LSE));
        aux->info = elem;
        aux->next = *list;
        *list = aux;
    }
    return 1;
}

int set(LSE *list, char* name, int val) {
    TData* elem = get(list, name);
    if(elem != NULL){
        LSE * l = list;
        while(l->next != NULL) {
            if(strcmp((l->info)->name, name) == 0) {
                (l->info)->value = val;
                return 1;
            }
            l = l->next;
        }
        return 0;
    }    
}

int evalValue(int a, int b, Token token) {
    switch(token) {
        case T_OR: 
        case T_MAS:
            return a + b;
            break;
        case T_MENOS:
            return a - b;
            break;
        case T_MOD:
            return a % b;
            break;
        case T_AND:
        case T_MULT:
            return a * b;
            break;
        case T_DIV:
            if(b == 0) {
                perror("Arithmetic error: can't div by 0\n");
                exit(1);
            }
            return a / b;
        case T_MENOR:
            return a < b;
            break;
        case T_MAYOR:
            return a > b;
            break;
        case T_IGUAL:
            return a == b;
            break;
        case T_TRUE:
            return 1;
            break;
        case T_FAL:
            return 0;
            break;
        case T_INTV:
            return a;
            break;
        case T_NEG:
            return !a;
            break;
        default:
                perror("Error: no operator\n");
                exit(1);
                break;
    }
}

int interpreter(LSE* list, Tree* bt) { //TODO: TERMINAR
    if(!bt || !list)
        return -1;
    switch(bt->info->token) {
        case T_INTV:
        case T_TRUE:
        case T_FAL:
            return bt->info->value;
            break;
        case T_MENOS: 
            if(bt->hd)
                bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_MENOS);
            else
                bt->info->value = evalValue(0, interpreter(list, bt->hi), T_MENOS);
            return bt->info->value;
            break;
        case T_NEG:
            bt->info->value = evalValue(interpreter(list, bt->hi), 0, T_NEG);
            return bt->info->value;
            break;
        case T_MULT:
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_MULT);
            return bt->info->value;
            break;
        case T_MAS:
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_MAS);
            return bt->info->value;
            break;
        case T_DIV: 
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_DIV);
            return bt->info->value;
            break;
        case T_MAYOR: 
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_MAYOR);
            return bt->info->value;
            break;
        case T_MENOR: 
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_MENOR);
            return bt->info->value;
            break;
        case T_IGUAL: 
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_IGUAL);
            return bt->info->value;
            break;
        case T_AND: 
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_AND);
            return bt->info->value;
            break;
        case T_OR: 
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_OR);
            return bt->info->value;
            break;
        case T_RET:
            bt->info->value = interpreter(list, bt->hi);
            printf("value return: %d\n", bt->info->value);
            return bt->info->value;
        case T_ASIGN:
            TData* node = get(list, bt->info->name);
            int value = interpreter(list, bt->hd);
            if(!node || !evalType(node->type, value)) {
                perror("Asign error: Var asign error\n");
                exit(1);
            }
            bt->info->value = value;
            return value;
            break;
        case T_DECL:
            if(get(list, bt->info->name)) {
                perror("Declaration error: Var already exists\n");
                exit(1);
            } else {
                bt->hi->info->value = interpreter(list, bt->hd);
                bt->info->value = bt->hi->info->value;
                return bt->info->value;
            }
            break;
        
        default:
            return -1;
            break; 
    }
}

int evalType(LSE* list, Tree* bt) { //TODO: TERMINAR
    if(!bt || !list)
        return -1;
    switch(bt->info->token) {
        case T_VOID:
            return bt->info->type == VOID;
        case T_ID:
            return bt->info->type == NO_TYPE;
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
        case T_MOD: 
        case T_MULT:
        case T_MAS:
        case T_DIV: 
            if(bt->hd) {
                if(evalType(list, bt->hi) && evalType(list, bt->hd) && bt->hd->info->type == INTEGER == bt->hi->info->type) {
                    bt->info->type = INTEGER;
                    return 1;
                }
                perror("Type error: integer expected\n");
                exit(1);
                return 0;
            } else {
                if(evalType(list, bt->hi) && bt->hi->info->type == INTEGER) {
                    bt->info->type = INTEGER;
                    return 1;
                }
                perror("Type error: integer expected\n");
                exit(1);
                return 0;
            }
            break;

        case T_AND: 
        case T_OR: 
            if(evalType(list, bt->hi) && evalType(list, bt->hd) && bt->hd->info->type == BOOL == bt->hi->info->type) {
                    bt->info->type = BOOL;
                    return 1;
            }
            perror("Type error: integer expected\n");
            exit(1);
            return 0;
            break;
        case T_NEG:
            if(evalType(list, bt->hi) && bt->hi->info->type == BOOL) {
                    bt->info->type = BOOL;
                    return 1;
                }
                perror("Type error: bool expected\n");
                exit(1);
                return 0;
        case T_MAYOR: 
        case T_MENOR: 
        case T_IGUAL: 
            if(evalType(list, bt->hi) && evalType(list, bt->hd) && bt->hd->info->type == bt->hi->info->type)
                return 1;
            perror("Type error: same type expected in comparator\n");
            exit(1);
            break;
        case T_RET:
            if(bt->hi) {
                if(evalType(list, bt->hi) && bt->hi->info->type == curretFunctionType != VOID) {
                    bt->info->type = bt->hd->info->type;
                    return 1;
                }
                perror("Type error: wrong return\n");
                exit(1);
            }
            if(curretFunctionType == VOID)
                return 1;
            perror("Type error: return expected\n");
            exit(1);
            break;
        case T_ASIGN:
            if(evalType(list, bt->hi) && evalType(list, bt->hd) && bt->hi->info->type == bt->hd->info->type) {
                bt->info->type = bt->hi->info->type;
                return 1;
            }
            break;
        case T_DECL:
            if(bt->hd->info->type != NO_TYPE) {
                perror("Declaration error: ID wrong type\n");
                exit(1);
                break;
            }
            if(evalType(list, bt->hi) && evalType(list, bt->hd)) {
                bt->info->type = bt->hi->info->type;
                return 1;
            }
            perror("Declaration error: missing something?\n");
            exit(1);
            break;
        case T_IF:
        case T_WHILE:
            return evalType(list, bt->hi) && evalType(list, bt->hd);
        default:
            return -1;
            break; 
    }
}
/*
    T_MAIN = 262,             
    T_THEN = 280,             
    T_ELSE = 281,             
    T_PROGRAM = 285,  
*/


TData* get(LSE *list, char* nom) {
    LSE *aux = list;
    while(aux != NULL) {
        if(strcmp(nom, (aux->info)->name) == 0)
            break;
        aux = aux->next;
    }
    return aux;
}

void showTable(LSE *list) {
    LSE* aux = list;
    while(aux != NULL) {
        printf("\nType: %d, var: %s\n", aux->info->type, aux->info->name);
        aux = aux->next;
    }
}