#include "../include/pseudo_assembly.h"
#include "../include/assembly_generator.h"
#include <stdio.h>
#include <stdint.h>
#define DIRECTORY "assembly_files"

int globalContext = 0; 
AssemblyList* globalVariables; 
AssemblyList* linesOfCode;

void intialize() {
    globalVariables = (AssemblyList*)malloc(sizeof(AssemblyList));
    linesOfCode = (AssemblyList*)malloc(sizeof(AssemblyList));
}
void identifyGlobal(AssemblyList *pseudoProgram) { 
    if(!pseudoProgram || !pseudoProgram->info)
        return;
    switch((pseudoProgram->info)->op) {
        case ASIGN:
            //ver si es una declaracion, si es así y es global, se inserta 
            if(!globalContext) {
                insertGlobal(pseudoProgram->info);
            }
            break;
        case FUN_DECL:
            if(!globalContext) {
                insertGlobal(pseudoProgram->info);
            }
            globalContext++;
            break;
        
        case END_FUNC:
            globalContext--;
            break;
    }
    identifyGlobal(pseudoProgram->next);
}
void insertGlobal(Triple *global) {
    if(!globalVariables) {
        globalVariables = (AssemblyList*)malloc(sizeof(AssemblyList));
        globalVariables->info = global;
        return;
    }
    AssemblyList *currentLine = (AssemblyList*)malloc(sizeof(AssemblyList));
    currentLine->info = global;
    AssemblyList *aux = globalVariables;
    while(aux->next) {
        aux = aux->next;
    }
    aux->next = currentLine;
}

void generateAssembly(char* fileName) {
    AssemblyList *aux = globalVariables;
    while(aux && aux->info) {
        switch((aux->info)->op) {
            case ASIGN:
            if(!checkIfIsGlobal(aux->info, globalVariables)) {
                // insertGlobal(pseudoProgram->info);
            }
            break;
            case FUN_DECL:

            break;
        }
        aux = aux->next;
    }
}
void generateDeclaration(AssemblyList *node, char* fileName) {
    AssemblyList *aux = node;
    char *text = formatTripleForDeclarations(aux->info);
    writeFile(fileName, text);    
}
char* formatTripleForDeclarations(const Triple *triple) { //TODO: TEST
    const char *tempName = triple->temporary->name;
    int firstValue = triple->firstOperand->value;
    // Si el tipo es bool, ajustar el valor a 0 o 1
    if (triple->firstOperand->type == T_BOOL) {
        firstValue = (firstValue != 0) ? 1 : 0; // 1 para true, 0 para false
    } else if(isAnOperation(triple->firstOperand->token)) {
        firstValue = triple->firstOperand->value;
    }
    // Calcular el tamaño necesario para el string resultante
    size_t size = strlen(tempName) + strlen(":\n\t.long ") + 12 + 1; // 12 para el entero (máximo 32 bits) + nulo
    char *result = (char *)malloc(size);
    if (result == NULL) {
        fprintf(stderr, "Error al asignar memoria.\n");
        return NULL;
    }
    if (firstValue < 0) {
        uint32_t unsignedValue = (uint32_t)firstValue; // Convert to 32-bit unsigned integer
        snprintf(result, size, "%s:\n\t.long %u", tempName, unsignedValue);
    } else {
        snprintf(result, size, "%s:\n\t.long %u", tempName, (uint32_t)firstValue);
    }
    // Construir la cadena
    return result;
}
int isAnOperation(Token token) {
    return token == T_MENOS || token == T_MAS || token == T_MULT || token == T_DIV || token == T_MOD;
}
void generateFunction(AssemblyList *node, char* fileName) {
    AssemblyList *bodyFunction = (AssemblyList*)malloc(sizeof(AssemblyList));
    bodyFunction = getFunction(node);
    if(!bodyFunction) {
        perror("Error: function not found\n");
        exit(1);
    }
    formatBodyOfFunction(bodyFunction, fileName);
}
AssemblyList* getFunction(AssemblyList *node) {
    AssemblyList *aux = linesOfCode;
    AssemblyList *body = (AssemblyList*)malloc(sizeof(AssemblyList));
    AssemblyList *auxBody = body;
    while(aux && aux->info->temporary->name != node->info->temporary->name)
        aux = aux->next;
    do {
        auxBody->info = aux->info;
        auxBody->next = (AssemblyList*)malloc(sizeof(AssemblyList));
        auxBody = auxBody->next;
        aux = aux->next;
    } while(aux && aux->info->op != END_FUNC);
    if(aux && aux->info->op == END_FUNC) {
        auxBody->info = aux->info;
        auxBody->next = (AssemblyList*)malloc(sizeof(AssemblyList));
        auxBody = auxBody->next;
    }
    return body;
}
void formatBodyOfFunction(AssemblyList *node, char* fileName) {
    char *bodyText;
    int currentParam = 1;
    //TODO: IMPLEMENTAR VALORES QUE CUENTEN LA CANTIDAD DE BLOQUES DETERMINADOS PARA VER SI UN CIERRE ES PARA EL DE INTERÉS O NO
    AssemblyList *aux = node;
    int cycles = 0;
    while(aux) {
        switch(aux->info->op) {
            case ASIGN:
            case WHILEF:
                // cycles += generateWhile(aux, fileName);
                break;
            case IFF:
                // cycles += generateIf(aux, fileName);
                break;
            case LABEL:
            case JUMP:
            case RET:
            case FUN_CALL:
                // cycles += generateFunCall(aux, fileName);
            case FUN_DECL:
            case END_FUNC:
            case REQUIRED_PARAM:
            case LOAD_PARAM:
                //  mov     dword ptr [rbp - 4 * currentParam++], edi
            default:
            break;
        }
        while(cycles--) {
            aux = aux->next;
        }
        // formatBodyOfFunction(aux, fileName);
    }
    writeFile(fileName, bodyText);
}
// int generateFunCall(AssemblyList *node, char* fileName) {
//     char *text = "";
//     formatBody(fileName, text);
//     return 1;
// }
// int generateWhile(AssemblyList *node, char* fileName) {
//     int cantMovements = 0;
//     AssemblyList *aux = node->next;
//     char *label = node->info->temporary->name;
//     while(aux) {
//         switch(aux->info->op) {
//             case ASIGN:
//             case WHILEF:
//                 cantMovements += generateWhile(aux, fileName);
//                 break;
//             case IFF:
//                 cantMovements += generateIf(aux, fileName);
//                 break;
//             case LABEL:
//                 if(aux->info->temporary->name == label) {
//                     char *text = "";
//                     writeFile(fileName, text);
//                     return cantMovements;
//                 }
//             case JUMP:
//             case RET:
//             case FUN_CALL:
//                 cantMovements += generateFunCall(aux, fileName);
//             case FUN_DECL:
//             case END_FUNC:
//             case REQUIRED_PARAM:
//             case LOAD_PARAM:
//                 //  mov     dword ptr [rbp - 4 * currentParam++], edi
//             default:
//             break;
//         }
//         aux = aux->next;
//         cantMovements++;
//     }
//     if(!aux) {
//         perror("Error: unexpected end of function\n");
//         exit(1);
//     }
//     return cantMovements;
// }
void writeFile(char* fileName, char* text) {
    char fullPath[256]; // Buffer para almacenar la ruta completa
    // Crear la ruta completa (carpeta + nombre del archivo)
    snprintf(fullPath, sizeof(fullPath), "%s/%s", DIRECTORY, fileName);
    FILE *outputFile = fopen(fullPath, "a");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(outputFile, "%s\n", text);
    fclose(outputFile);
}