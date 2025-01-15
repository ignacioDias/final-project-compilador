#ifndef ASSEMBLYGENERATOR_H
#define ASSEMBLYGENERATOR_H

#include "symbols_table.h"
#include "pseudo_assembly.h"
#include <stdio.h>
#include <string.h>  
// Declaración de variables globales
extern int globalContext; // 1 valor por entorno, 0 significa contexto global
extern AssemblyList* globalVariables; // Las variables globales no pueden ser dinámicas
extern AssemblyList* linesOfCode;
extern FILE *outputFile;

// Prototipos de funciones
void intialize();
void identifyGlobal(AssemblyList *pseudoProgram);
void insertGlobal(Triple *global);
void generateAssembly(char* filename);
void generateDeclaration(AssemblyList *node, char* filename);
char* formatTriple(const Triple *triple);
void generateFunction(AssemblyList *node, char* filename);
void writeFile(char* fileName, char* text);

#endif // ASSEMBLY_GENERATOR_H
