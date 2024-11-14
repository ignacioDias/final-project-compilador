#include "../libraries/tree.h"
#include "../libraries/symbols_table.h"
#include "../libraries/pseudoAssembly.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AssemblyList *program;

void handleBinaryOperation(TData* value1, TData* value2, Operation op, TData* temporary) {
    if(!value1 || !value2 || !temporary) {
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

void convert(Operation op, Tree* value1, Tree* value2, Tree* temporary) {
    Triple* value1Node = value1->info;
    Triple* value2Node;
    Triple* resSymbol = temporary->info;
    Triple* tripleValue2;

    if(value2) {
        value2Node = value2->info;
        tripleValue2 = getVar(value2->symbol->varname);
    }

    switch(op) {
        case ASIGN:
            if(tripleValue2){
                value1Node->value = tripleValue2->value;
                resSymbol = value1Node;
            } else {
                value1Node->value = value2Node->value;
                resSymbol = value1Node;
            }
            createInstallSequence(T_ASIGN, value1Node, value2Node, resSymbol);
            break;
        case MENOR:
        case MAYOR:
        case IGUAL:
        case MENOS:
        case SUMA:
        case MULT:
        case DIV:
        case MOD:
        case OR:
        case AND:
        case NEG:
        case IFF:
            handleBinaryOperation(tag, value1Node, value2Node, resSymbol);
            break;
        case EWHILE:
            if (value1Node->value == 1)
                resSymbol = value2->right->symbol;
            else
                resSymbol = NULL;
            handleBinaryOperation(T_WHILE, value1Node, value2Node, resSymbol);
            break;
    }
}

Triple *getVar(char* name) {
    if(!name || !program) {
        perror("Error: getVar");
        exit(1);
    }
    AssemblyList *current = program;
    while(current) {
        if(strcmp(current->info->temporary->name, name) == 0) {
            return current->info;
        }
        current = current->next;
    }
    return NULL;
}


