#include "../include/tree.h"
#include "../include/symbolsTable.h"
#include "../include/pseudoAssembly.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AssemblyList *program;
void handleBinaryOperation(TData* value1, TData* value2, Operation op, TData* temporary) {
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
    if(!tree)
        return;
    Token operation = tree->info->token;
    switch(operation) {
        case T_RET:
            handleBinaryOperation(tree->hi->info, tree->hd->info, RET, tree->info);
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
            if(tree->hd->info->value == 0) {
                perror("Error: Division by zero");
                exit(1);
            }
            handleBinaryOperation(tree->hi->info, tree->hd->info, DIV, tree->info);
            break;
        case T_MOD:
            if(tree->hd->info->value == 0) {
                perror("Error: Division by zero");
                exit(1);
            }
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
            handleBinaryOperation(tree->hd->info, NULL, ASIGN, tree->hi->info);
            break;
        default:
            generatePseudoAssembly(tree->hi);
            generatePseudoAssembly(tree->hd);
            break;
    }
}    
void handleIf(Tree *tree) {
    TData *iffLabel = generateNewLabel();
    TData *elseLabel = generateNewLabel();
    handleBinaryOperation(tree->hi->info, NULL, IFF, iffLabel); //IFF cond _ LABEL
    generatePseudoAssembly(tree->hd->hi); //BODY THEN
    if(tree->hd->hd) {
        handleBinaryOperation(NULL, NULL, JUMP, elseLabel); //JUMP _ _ LABEL2
        handleBinaryOperation(NULL, NULL, LABEL, iffLabel); // TAG_LABEL _ _ LABEL
        generatePseudoAssembly(tree->hd->hd); //CUERPO ELSE
        handleBinaryOperation(NULL, NULL, LABEL, elseLabel); //TAG_LABEL _ _ LABEL2
    } else {
        handleBinaryOperation(NULL, NULL, LABEL, iffLabel);
    }
}
void handleWhile(Tree *tree) {
    TData *firstLabel = generateNewLabel();
    TData *falseWhileLabel = generateNewLabel();
    handleBinaryOperation(NULL, NULL, LABEL, firstLabel); //LABEL USED FOR ITERATING
    handleBinaryOperation(tree->hi->info, NULL, WHILEF, falseWhileLabel);  //CHECK WHILE CONDITION
    generatePseudoAssembly(tree->hd); //BODY OF WHILE
    handleBinaryOperation(NULL, NULL, JUMP, firstLabel); //JUMP TO THE FIRST LABEL, ITERATION
    handleBinaryOperation(NULL, NULL, LABEL, falseWhileLabel); //LABEL USED FOR FALSE CONDITION

}
TData *generateNewLabel() {
    return newData(T_YYUNDEF, NO_TYPE, -1, generateNewIDForLabel());
}

char* generateNewIDForLabel() {
    // Determinar el tamaño necesario para el string resultante
    // "L" + dígitos de currentLabel + '\0'
    int size = snprintf(NULL, 0, "L%d", currentLabel) + 1;
    // Reservar memoria para el string resultante
    char* result = (char*)malloc(size);
    // Generar el string en la memoria reservada
    if (result != NULL) {
        snprintf(result, size, "L%d", currentLabel);
    }
    currentLabel++;
    return result; 
}
void printAssemblyList() {
    AssemblyList *current = program;
    while (current != NULL) {
        Triple *triple = current->info;
        printf("%s %s %s %s\n",
               operationToString(triple->op),
               triple->firstOperand ? triple->firstOperand : "_",
               triple->secondOperand ? triple->secondOperand : "_",
               triple->temporary ? triple->temporary : "_");
        current = current->next;
    }
}
const char *operationToString(Operation op) {
    switch (op) {
        case MENOR: return "MENOR";
        case MAYOR: return "MAYOR";
        case IGUAL: return "IGUAL";
        case MENOS: return "MENOS";
        case SUMA: return "SUMA";
        case MULT: return "MULT";
        case DIV: return "DIV";
        case MOD: return "MOD";
        case OR: return "OR";
        case AND: return "AND";
        case NEG: return "NEG";
        case ASIGN: return "ASIGN";
        case WHILEF: return "WHILEF";
        case IFF: return "T_IFF";
        case LABEL: return "T_LABEL";
        case JUMP: return "T_JUMP";
        case RET: return "RET";
        default: return "UNKNOWN";
    }
}
