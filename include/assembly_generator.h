#ifndef ASSEMBLYGENERATOR_H
#define ASSEMBLYGENERATOR_H

#include "symbols_table.h"
#include "pseudo_assembly.h"
#include <stdio.h>
#include <string.h>  
#include <stdint.h>
// Declaración de variables globales
extern int globalContext; //0 significa contexto global
extern AssemblyList* globalVariables; // Las variables globales no pueden ser dinámicas
extern AssemblyList* linesOfCode;

// Prototipos de funciones
void intialize();
void identifyGlobal(AssemblyList *pseudoProgram);
void insertGlobal(Triple *global);
void generateAssembly(char* fileName);
void generateDeclaration(AssemblyList *node, char* fileName);
char* formatTripleForDeclarations(const Triple *triple);
int isAnOperation(Token token);
void generateFunction(AssemblyList *node, char* fileName);
AssemblyList* getFunction(AssemblyList *node);
void formatBodyOfFunction(AssemblyList *node, char* fileName);
void writeFile(char* fileName, char* text);

#endif // ASSEMBLY_GENERATOR_H
