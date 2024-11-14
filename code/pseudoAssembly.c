#include "../libraries/tree.h"
#include "../libraries/symbols_table.h"
#include "../libraries/pseudoAssembly.h"
#include <stdio.h>
#include <stdlib.h>

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


