#include "tree.h"
#include "symbols_table.h"
#include "pseudoAssembly.h"

void insertNode(AssemblyList **list, Triple *triple) {
    AssemblyList *newNode = (AssemblyList*)malloc(sizeof(AssemblyList));
    newNode->info = triple;
    newNode->next = list;
    (*list) = newNode;
}
void handleGenerateIf(AssemblyList **list, Triple* cond, AssemblyList *then, AssemblyList *elseBlock) {
    handleGenerateBinaryOperation(cond);
    AssemblyList *next;
    if(cond->temporary)
        next = then;
    else
        next = elseBlock;
    AssemblyList *aux = *list;
    while(aux->next) {
        aux = aux->next;
    }
    aux->next = next;
}
void handleGenerateWhile(AssemblyList **list, Triple* cond, AssemblyList *then) {
    handleGenerateBinaryOperation(cond);
    AssemblyList *aux = *list;
    while(aux->next) {
        aux = aux->next;
    }
    while(cond->temporary) {
        aux->next = then;
        handle(then);
        handleGenerateBinaryOperation(cond);
        aux = aux->next;
    }
}
void handle(AssemblyList *block);
void handleGenerateFunc(Triple* ar);

void handleGenerateBinaryOperation(Triple* ar) {
    ar->temporary = evalValue(ar->firstOperand, ar->secondOperand, ar->op);
}
int evalValue(TData* a, TData *b, Operation operation) {
    switch(operation) {
        case OR: 
        case SUMA:
            return (a->value) + (b->value);
            break;
        case MENOS:
            if(b)
                return (a->value) - (b->value);
            return -(a->value);
            break;
        case MOD:
            return (a->value) % (b->value);
            break;
        case AND:
        case MULT:
            return (a->value) * (b->value);
            break;
        case DIV:
            if((b->value) == 0) {
                perror("Arithmetic error: can't div by 0\n");
                exit(1);
            }
            return (a->value) / (b->value);
        case MENOR:
            return (a->value) < (b->value);
            break;
        case MAYOR:
            return (a->value) > ((b->value)->value);
            break;
        case NEG:
            return !(a->value);
            break;
        default:
                perror("Error: no operator\n");
                exit(1);
                break;
    }
}