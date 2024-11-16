#include "../libraries/tree.h"
#include "../libraries/symbols_table.h"
#include "../libraries/pseudoAssembly.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AssemblyList *program;

void handleBinaryOperation(TData* value1, TData* value2, Operation op, TData* temporary) {
    if(!value1 || !temporary) {
        perror("Error: Invalid operands");
        exit(1);
    }
    if((op == DIV || op == MOD) && value2->value == 0) {
        perror("Error: Division by zero");
        exit(1);
    }
    Triple *newTriple = (Triple*)malloc(sizeof(Triple));
    newTriple->firstOperand = value1;
    newTriple->secondOperand = value2;
    newTriple->op = op;
    newTriple->temporary = temporary;
    insertNode(newTriple);
}

void insertNode(Triple *triple) {
    if(!program) {
        program = (AssemblyList*)malloc(sizeof(AssemblyList));
        program->info = triple;
    } else {
        AssemblyList *newNode = (AssemblyList*)malloc(sizeof(AssemblyList));
        newNode->info = triple;
        newNode->next = newNode;
        program = newNode;
    }
}

void generatePseudoAssembly(Tree *tree) {
    Token operation = tree->info->token;
    switch(operation) {
        case T_RET:
            handleReturn(tree->info, tree->hd);
            break;
        case T_MENOR:
            handleBinaryOperation(tree->hi->info, tree->hd->info, MENOR, tree->info);
            break;
        case T_MAYOR:
            handleBinaryOperation(tree->hi->info, tree->hd->info, MAYOR, tree->info);
            break;
        case T_IGUAL:
            handleBinaryOperation(tree->hi->info, tree->hd->info, IGUAL, tree->info);
            break;
        case T_MENOS:
            handleBinaryOperation(tree->hi->info, tree->hd->info, MENOS, tree->info);
            break;
        case T_MAS:
            handleBinaryOperation(tree->hi->info, tree->hd->info, SUMA, tree->info);
            break;
        case T_MULT:
            handleBinaryOperation(tree->hi->info, tree->hd->info, MULT, tree->info);
            break;
        case T_DIV:
            handleBinaryOperation(tree->hi->info, tree->hd->info, DIV, tree->info);
            break;
        case T_MOD:
            handleBinaryOperation(tree->hi->info, tree->hd->info, MOD, tree->info);
            break;
        case T_OR:
            handleBinaryOperation(tree->hi->info, tree->hd->info, OR, tree->info);
            break;
        case T_NEG:
            handleBinaryOperation(tree->hi->info, NULL, NEG, tree->info);
            break;
        case T_AND:
            handleBinaryOperation(tree->hi->info, tree->hd->info, MENOR, tree->info);
            break;
        case T_WHILE:
            handleWhile(tree);
            break;
        case T_IF:
            handleIf(tree);
            break;
        case T_ASIGN:
            handleAsign(tree);
            break;
        default:
            generatePseudoAssembly(tree->hi);
            generatePseudoAssembly(tree->hd);
            break;
        }
    }    
void handleAsign(Tree *tree) {
    
}
void handleIf(Tree *tree) {

}
void handleWhile(Tree *tree) {

}
void handleReturn(TData *ret, Tree *tree) {

}