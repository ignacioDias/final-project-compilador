#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbols_table.h"
#include "pseudo_assembly.h"

#ifndef ASSEMBLY_GENERATOR_H
#define ASSEMBLY_GENERATOR_H

void createFile();
void createWriteASM(PseudoAssembly* instruction);
void writeAsign(PseudoAssembly* instruction);
void writeReturn(PseudoAssembly* instruction);
void writeFunc(PseudoAssembly* instruction);
void writeOperation(TData* op1, TData* op2, TData* final, ASM tag);
void writeBooleanOp(TData* op1, TData* op2, TData* final, ASM tag);
void writeComparation(TData* op1, TData* op2, TData* final, ASM tag);

void writeVarGlobal(PseudoAssembly* instruction);
void writeIFF(PseudoAssembly* instruction);
void writeLabel(PseudoAssembly* instruction);
void writeJump(PseudoAssembly* instruction);
void writeLoadParam(PseudoAssembly* instruction, int cantParam);
void writeEndFunc(PseudoAssembly* instruction);
void writeLoadParamInFunc(PseudoAssembly* instruction);
void writeCallFunc(PseudoAssembly* instruction);
#endif
