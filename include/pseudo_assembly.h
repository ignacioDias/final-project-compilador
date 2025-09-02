#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#ifndef PSEUDO_ASSEMBLY_H
#define PSEUDO_ASSEMBLY_H

typedef enum ASM {
    T_ASIGN, T_RETURN,
    T_IF, T_WHILE,
    T_OR, T_NOT, T_AND,
    T_EQUAL, T_GREATER, T_LESS,
    T_PLUS, T_MINUS, T_MOD, T_PROD, T_DIV,
    T_LABEL, T_JUMP, T_END_FUN, T_LOAD_PARAM,
    T_IFF, T_RET , T_WF, T_FUNC, T_CALL, T_INFO,T_REQUIRED_PARAM,T_GLOBAL
}ASM;

char static tagName[42][42] = {
    "ASIGN", "RETURN",
    "IF", "WHILE",
    "OR", "NOT", "AND",
    "EQUAL", "GREATER", "LESS",
    "PLUS", "MINUS", "MOD", "PROD", "DIV",
    "T_LABEL", "T_JUMP", "END_FUN", "LOAD_PARAM",
    "T_IFF", "T_RET","T_WF","T_FUNC", "T_CALL","T_INFO","T_REQUIRED_PARAM","T_GLOBAL"
};

typedef struct PseudoAssembly {
    ASM tag;
    TData* op1;
    TData* op2;
    TData* result;
    struct PseudoAssembly* next;
} PseudoAssembly;

// Add a new pseudo-assembly instruction to the instruction list
void addPseudoAssemblyInstruction(ASM opcode, TData* operand1, TData* operand2, TData* result);

// Add a comparison operation instruction
void addComparisonOperation(TOKENS operation, TData* operand1, TData* operand2, TData* result);

// Add a boolean operation instruction
void addBooleanOperation(TOKENS operation, TData* operand1, TData* operand2, TData* result);

// Add an arithmetic operation instruction
void addArithmeticOperation(TOKENS operation, TData* operand1, TData* operand2, TData* result);

// Translate an AST operation to pseudo-assembly instructions
void translateASTOperation(TOKENS operation, Tree* leftNode, Tree* rightNode, Tree* resultNode);

// Find a result symbol in the instruction list by name
TData *findInstructionResult(char *name);

// Generate pseudo-assembly instructions from an AST and reverse the instruction list
void generateThreeAddressCode(Tree* astRoot);

// Generate pseudo-assembly instructions for global variables
void generateGlobalVariableInstructions(void);

// Recursively generate pseudo-assembly instructions from an AST
void generateCode(Tree* node);

// Handle code generation for return operations
void handleReturnOperation(Tree* node);

// Handle code generation for the main function
void handleMainFunction(Tree* node);

// Recursively process arithmetic, boolean, and comparison operations in the AST
void processOperations(Tree* node);

// Recursively process function calls in the AST
void processFunctionCalls(Tree* node);

// Recursively generate parameter load instructions for function calls
void generateParameterLoadInstructions(Tree* node);

// Create a pseudo-assembly instruction for loading a parameter
void createParameterLoadInstruction(TData* symbol);

// Concatenate two pseudo-assembly instruction lists
void concatenateInstructionLists(PseudoAssembly *list1, PseudoAssembly *list2);

// Handle code generation for function definitions
void handleFunctionDefinition(Tree* node);

// Recursively process required parameters for a function
void processRequiredParameters(Tree* node);

// Create a pseudo-assembly instruction for a function call
void createFunctionCallInstruction(TData* functionName, TData* tempResult);

// Create a pseudo-assembly instruction for function start
void createFunctionStartInstruction(TData* functionSymbol);

// Create a pseudo-assembly instruction for function end
void createFunctionEndInstruction(TData* functionSymbol);

// Handle code generation for IF statements
void handleIfStatement(Tree* node);

// Handle code generation for WHILE statements
void handleWhileStatement(Tree* node);

// Handle code generation for binary operations
void handleBinaryOperation(Tree* node);

// Handle code generation for unary operations
void handleUnaryOperation(Tree* node);

// Reverse the pseudo-assembly instruction list
void invertASM(PseudoAssembly **list);

// Free all pseudo-assembly instructions
void freePseudoAssemblyInstructions(void);

// Print all pseudo-assembly instructions for debugging
void printPseudoAssemblyInstructions(void);

// Create a pseudo-assembly instruction for a false branch label (used in IF/WHILE)
PseudoAssembly* createFalseBranchLabel(ASM opcode, TData* condition);

// Create a pseudo-assembly jump instruction
PseudoAssembly* createJumpInstruction(void);

// Generate a unique label name for pseudo-assembly instructions
char* generateUniqueLabelName(void);

// Create and append a label instruction to the instruction list
void createLabelInstruction(char* labelName);

// Create a pseudo-assembly return instruction
void createReturnInstruction(TData* functionSymbol);

// Create a pseudo-assembly instruction for required parameters
void createRequiredParameterInstruction(TData* paramSymbol);

// Generate the final assembler output from pseudo-assembly instructions
void generateAssemblerOutput(void);


#endif
