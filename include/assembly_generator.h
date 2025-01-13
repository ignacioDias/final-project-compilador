#ifndef ASSEMBLYGENERATOR_H
#define ASSEMBLYGENERATOR_H

#include "symbols_table.h"
#include "pseudo_assembly.h"
#include <stdio.h>

LSE *globalVariables;
FILE *outputFile;

void identifyGlobal(AssemblyList *pseudoProgram);
void insertGlobal(Triple *global);
void generateAssembly();
void insertNode();//insertGlobalVariable - insertFunction...
void handleFunctionDeclaration();
void handleParamsDefinition();
void handleFunctionCall();
void handleParamsCall();
void handleIf();
void handleWhile();

#endif