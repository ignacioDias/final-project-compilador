#include "../include/tree.h"
#include "../include/symbols_table.h"
#include "../include/pseudo_assembly.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentLabel = 1;

void handleBinaryOperation(AssemblyList **program, TData* value1, TData* value2, Operation op, TData* temporary) {
    Triple *newTriple = (Triple*)malloc(sizeof(Triple));
    newTriple->firstOperand = value1;
    newTriple->secondOperand = value2;
    newTriple->op = op;
    newTriple->temporary = temporary;
    insertNode(program, newTriple);
}

void insertNode(AssemblyList **program, Triple *triple) {
    if(!(*program)) {
        *program = (AssemblyList*)malloc(sizeof(AssemblyList));
        (*program)->info = triple;
    } else {
        AssemblyList *newNode = (AssemblyList*)malloc(sizeof(AssemblyList));
        newNode->info = triple;
        newNode->next = newNode;
        *program = newNode;
    }
}
void generatePseudoAssembly(AssemblyList *program, Tree *tree) {
    if(!tree)
        return;
    switch(tree->info->token) {
        case T_RET:
            if(tree->hi)
                handleBinaryOperation(&program, NULL, NULL, RET, tree->hi->info); // RETURN _  _  RET_VALUE
            else
                handleBinaryOperation(&program, NULL, NULL, RET, NULL); // RETURN _  _  _ // return;
            break;
        case T_MENOR:
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, MENOR, tree->info);
            break;
        case T_MAYOR:
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, MAYOR, tree->info);
            break;
        case T_IGUAL:
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, IGUAL, tree->info);
            break;
        case T_MENOS:
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, MENOS, tree->info);
            break;
        case T_MAS:
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, SUMA, tree->info);
            break;
        case T_MULT:
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, MULT, tree->info);
            break;
        case T_DIV:
        case T_MOD:
            if(tree->hd->info->value == 0) {
                perror("Error: Division by zero");
                exit(1);
            }
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, tree->info->token, tree->info);
            break;
        case T_OR:
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, OR, tree->info);
            break;
        case T_NEG:
            handleBinaryOperation(&program, tree->hi->info, NULL, NEG, tree->info);
            break;
        case T_AND:
            handleBinaryOperation(&program, tree->hi->info, tree->hd->info, MENOR, tree->info);
            break;
        case T_WHILE:
            handleWhile(program, tree);
            break;
        case T_IF:
            handleIf(program, tree);
            break;
        case T_FUNCTION:
            handleFunctionCall(program, tree);
            break;
        case T_METHODCALL:
            handleFunctionDeclaration(program, tree);
            break;
        case T_ASIGN:
            handleBinaryOperation(&program, tree->hd->info, NULL, ASIGN, tree->hi->info);
            break;
        default:
            generatePseudoAssembly(program, tree->hi);
            generatePseudoAssembly(program, tree->hd);
            break;
    }
}    
void handleFunctionDeclaration(AssemblyList *program, Tree *tree) {
    handleBinaryOperation(&program, NULL, NULL, FUN_DECL, tree->info); //FUN_DECL _ _ NAME
    handleParamsDefinition(tree->hi);
    generatePseudoAssembly(program, tree->hd);
    handleBinaryOperation(&program, NULL, NULL, END_FUNC, tree->info); // END_FUN _ _ NAME
    
}
void handleParamsDefinition(Tree *tree) {
    if(tree) {

    }
}
TData* getReturn(Tree *functionBody) {
    if(!functionBody)
        return NULL;
    Tree *aux = functionBody;
    
}
void handleFunctionCall(AssemblyList *program, Tree *tree) {
    if(tree->hi)
        handleParamsCall(tree->hi);
    //T_CALL NAME _ CALLED_FUNC
    handleBinaryOperation(&program, tree->info, NULL, FUN_CALL, newData(T_FUNCTION, NO_TYPE, -1, tree->info->name));
}
void handleParamsCall(Tree *tree) {

}
void handleIf(AssemblyList *program, Tree *tree) {
    TData *iffLabel = generateNewLabel();
    TData *elseLabel = generateNewLabel();
    handleBinaryOperation(&program, tree->hi->info, NULL, IFF, iffLabel); //IFF cond _ LABEL
    generatePseudoAssembly(program, tree->hd->hi); //BODY THEN
    if(tree->hd->hd) {
        handleBinaryOperation(&program, NULL, NULL, JUMP, elseLabel); //JUMP _ _ LABEL2
        handleBinaryOperation(&program, NULL, NULL, LABEL, iffLabel); // TAG_LABEL _ _ LABEL
        generatePseudoAssembly(program, tree->hd->hd); //CUERPO ELSE
        handleBinaryOperation(&program, NULL, NULL, LABEL, elseLabel); //TAG_LABEL _ _ LABEL2
    } else {
        handleBinaryOperation(&program, NULL, NULL, LABEL, iffLabel);
    }
}
void handleWhile(AssemblyList *program, Tree *tree) {
    TData *firstLabel = generateNewLabel();
    TData *falseWhileLabel = generateNewLabel();
    handleBinaryOperation(&program, NULL, NULL, LABEL, firstLabel); //LABEL USED FOR ITERATING
    handleBinaryOperation(&program, tree->hi->info, NULL, WHILEF, falseWhileLabel);  //CHECK WHILE CONDITION, IF FALSE, JUMP TO END
    generatePseudoAssembly(program, tree->hd); //BODY OF WHILE
    handleBinaryOperation(&program, NULL, NULL, JUMP, firstLabel); //JUMP TO THE FIRST LABEL, ITERATION
    handleBinaryOperation(&program, NULL, NULL, LABEL, falseWhileLabel); //LABEL USED FOR FALSE CONDITION

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
void printAssemblyList(AssemblyList *program) {
    if (!program) {
        printf("PSEUDO ASSEMBLY NULL\n");
        return;
    }
    AssemblyList *current = program;
    while (current != NULL) {
        if (!current->info) {
            printf("Invalid instruction: NULL info\n");
            current = current->next;
            continue;
        }
        Triple *triple = current->info;
        printf("%s %s %s %s\n",
               operationToString(triple->op),
               triple->firstOperand ? (triple->firstOperand->name ? triple->firstOperand->name : "_") : "_",
               triple->secondOperand ? (triple->secondOperand->name ? triple->secondOperand->name : "_") : "_",
               triple->temporary ? (triple->temporary->name ? triple->temporary->name : "_") : "_");
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
