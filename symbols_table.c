#include "tree.h"
#include "symbols_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
        case T_MAS:
            return a + b;
            break;
        case T_MENOS:
            return a - b;
            break;
        case T_MULT:
            return a * b;
            break;
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
        case T_ID:
            return a;
            break;
        default:
            return -1;
            break;
    }
}

int interpreter(LSE * list, Tree * bt) { //TODO: TERMINAR
    if(!bt || !list)
        return -1;
    switch(bt->info->token) {
        case T_INTV:
        case T_TRUE:
        case T_FAL:
        case T_ID:
            return bt->info->value;
            break;
        case T_MENOS: 
            bt->info->value = evalValue(interpreter(list, bt->hi), interpreter(list, bt->hd), T_MENOS);
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
        case T_RET:
            bt->info->value = interpreter(list, bt->hi);
            printf("value return: %d\n", bt->info->value);
            return bt->info->value;
        default:
            return -1;
            break; 
    }
}

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
int checkType(LSE *list, Tree* tree) { //TODO: TERMINAR
    if(!tree)
        return -1;
    TData* info = get(list, tree->info->name);
    switch (info->type) {
    case T_MULT:
    case T_MENOS:
    case T_MAS:
        tree->info->type = INTEGER; 
        int cond = checkType(list, tree->hi) && checkType(list, tree->hd) && tree->hi->info->type == INTEGER == tree->hd->info->type;
        if(cond == 0) {
            printf("Error: tipos incorrectos en %s y %s.\n", tree->hi->info->name, tree->hd->info->name);
        }
        return cond;
        break;
    case T_MAYOR:
    case T_MENOR:
    case T_IGUAL:
        tree->info->type = BOOL; 
        int cond = checkType(list, tree->hi) && checkType(list, tree->hd) && tree->hi->info->type == BOOL == tree->hd->info->type;
        if(cond == 0) {
            printf("Error: tipos incorrectos en %s y %s.\n", tree->hi->info->name, tree->hd->info->name);
        }
        return cond;
        break;
    case T_RET:
        int ret = checkType(list, tree->hi);
        tree->info->type = tree->hi->info->type;
        return ret;
        break;
    case T_INTV:
        return 1;
        break;
    case T_MAIN:
        tree->info->type = tree->hi->info->type;
        return checkType(list, tree->hi);
        break;
    default:
        return 0;
        break;
    }
}