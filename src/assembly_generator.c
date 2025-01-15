#include "../include/pseudo_assembly.h"
#include "../include/assembly_generator.h"
#include <stdio.h>

int globalContext = 0; 
AssemblyList* globalVariables; 
AssemblyList* linesOfCode;
FILE *outputFile;

void intialize() {
    globalVariables = (AssemblyList*)malloc(sizeof(AssemblyList));
    linesOfCode = (AssemblyList*)malloc(sizeof(AssemblyList));
}
void identifyGlobal(AssemblyList *pseudoProgram) { 
    if(!pseudoProgram)
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
    while(aux) {
        switch((aux->info)->op) {
            case ASIGN:
                generateDeclaration(aux, fileName);
                break;
            case FUN_DECL:
                generateFunction(aux, fileName);
                break;
            default:
                perror("Error: unexpected token in global context\n");
                exit(1);
                break;
        }
        aux = aux->next;
    }
}
void generateDeclaration(AssemblyList *node, char* fileName) {
    AssemblyList *aux = node;
    char *text = formatTriple(aux->info);
    writeFile(fileName, text);    
}
char* formatTriple(const Triple *triple) { //TODO: TEST
    // Obtener valores de los campos necesarios
    const char *tempName = triple->temporary->name;
    int firstValue = triple->firstOperand->value;
    // Calcular el tamaño necesario para el string resultante
    size_t size = strlen(tempName) + strlen(":\n.long ") + 12 + 1; // 12 para el entero (máximo 32 bits) + nulo
    char *result = (char *)malloc(size);
    if (result == NULL) {
        fprintf(stderr, "Error al asignar memoria.\n");
        return NULL;
    }
    // Construir la cadena
    snprintf(result, size, "%s:\n.long %d", tempName, firstValue);
    return result;
}
void generateFunction(AssemblyList *node, char* fileName) {

}
void writeFile(char* fileName, char* text) {
    char fullPath[256]; // Buffer para almacenar la ruta completa
    // Crear la ruta completa (carpeta + nombre del archivo)
    snprintf(fullPath, sizeof(fullPath), "%s/%s", "assembly_files", fileName);
    outputFile = fopen(fullPath, "a");
    if(!outputFile) {
        perror("Error: could not open file\n");
        exit(1);
    }
    fprintf(outputFile, "%s", text);
    fclose(outputFile);

}