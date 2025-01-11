#ifndef ASSEMBLYGENERATOR_H
#define ASSEMBLYGENERATOR_H

#include "symbols_table.h"
#include <cstdio>

LSE *globalVariables;

FILE *outputFile;

void handleBinaryOperation();
void insertNode();
void generatePseudoAssembly();
void handleFunctionDeclaration();
void handleParamsDefinition();
void handleFunctionCall();
void handleParamsCall();
void handleIf();
void handleWhile();

#endif