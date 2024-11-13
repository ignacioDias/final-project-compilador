#include "libraries/tree.h"
#include "libraries/symbols_table.h"
#include "libraries/pseudoAssembly.h"

AssemblyList *program;

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
void handleGenerateBinaryOperation(TData* value1, TData* value2, Operation op, TData* temporary) {
    Triple *newTriple = (Triple*)malloc(sizeof(Triple));
    newTriple->firstOperand = value1;
    newTriple->secondOperand = value2;
    newTriple->op = op;
    newTriple->temporary = temporary;
    insertNode(newTriple);
}
void handleGenerateIf(Triple* cond, AssemblyList *then, AssemblyList *elseBlock) {

}
void handleGenerateWhile(Triple* cond, AssemblyList *then) {
}
void handleGenerateFunc(Triple* ar) {

}

