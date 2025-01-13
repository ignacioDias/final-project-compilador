#include "../include/pseudo_assembly.h"
#include "../include/assembly_generator.h"
#include <stdio.h>
int globalContext = 0; // 1 value per environment, 0 means global context

void identifyGlobal(AssemblyList *pseudoProgram) { 
    if(!pseudoProgram)
        return;
    switch((pseudoProgram->info)->op) {
        case ASIGN:
            //ver si es una declaracion, si es así y es global, se inserta 
        case WHILEF:
            globalContext++;

            break;
        case IFF:
        case LABEL:
        case JUMP:
        case FUN_DECL:
            globalContext++;
            //Tengo que añadir un enviroment, así que habría que pushear al stack
            //acá la idea es generar el código interno del método, tengo que recorrer todo de vuelta
            //pero ver que global context sea 0 para insertarlo como metodo global, ver qué pasa si no es global
            if(globalContext == 1) {
                insertGlobal(pseudoProgram->info);
            }
            // generateCode(pseudoAssembly->info);
            break;
        case END_FUNC:
            globalContext--;
            //Tengo que sacar un enviroment, así que habría que sacar del stack
            break;
    }
}
void insertGlobal(Triple *global) {

}

void generateAssembly() {
    //for globalVar in globalVariables
    //if(globalVar->op == ASIGN) {generateDeclaration(globalVar);}
    //elseif(globalVar->op == FUN_DECL {generateFunction(globalVar);})
    //else -> exception
}
void writeFile(char* filename, AssemblyList **program) {
    outputFile = fopen(filename, "w");
    if (!outputFile) {
        printf("Error opening file!\n");
        return;
    }
    printAssemblyList(program);
    fclose(outputFile);
}