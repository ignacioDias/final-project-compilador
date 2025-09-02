#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbols_table.h"
#include "pseudo_assembly.h"

#ifndef ASSEMBLY_GENERATOR_H
#define ASSEMBLY_GENERATOR_H

// Create and open the output assembly file
void createOutputFile(void);

// Write a string to the output assembly file
void writeToOutputFile(char* text);

// Generate assembly code from the pseudo-assembly instruction list
void generateAssemblyFromPseudo(PseudoAssembly* instruction);

// Write global variable declaration to assembly
void writeGlobalVariable(PseudoAssembly* instruction);

// Write function prologue to assembly
void writeFunctionPrologue(PseudoAssembly* instruction);

// Write function epilogue to assembly
void writeFunctionEpilogue(PseudoAssembly* instruction);

// Write parameter loading for function definition (stack/register)
void writeFunctionParameterLoad(PseudoAssembly* instruction);

// Write parameter loading for function call (stack/register)
void writeFunctionCallParameter(PseudoAssembly* instruction, int paramIndex);

// Write assignment operation to assembly
void writeAssignment(PseudoAssembly* instruction);

// Write return statement to assembly
void writeReturnStatement(PseudoAssembly* instruction);

// Write conditional jump for IF/WHILE statements
void writeConditionalJump(PseudoAssembly* instruction);

// Write label to assembly
void writeLabel(PseudoAssembly* instruction);

// Write unconditional jump to assembly
void writeJump(PseudoAssembly* instruction);

// Write function call to assembly
void writeFunctionCall(PseudoAssembly* instruction);

// Write arithmetic operation to assembly
void writeArithmeticOperation(TData* op1, TData* op2, TData* result, ASM opcode);

// Write boolean operation to assembly
void writeBooleanOperation(TData* op1, TData* op2, TData* result, ASM opcode);

// Write comparison operation to assembly
void writeComparisonOperation(TData* op1, TData* op2, TData* result, ASM opcode);
#endif
