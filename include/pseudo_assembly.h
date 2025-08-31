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
void createInstallSequence(ASM tag, TData* op1, TData* op2, TData* result);
void invertASM(PseudoAssembly ** list);
void printAsembler();
void deleteInstructions();
void generateCode(Tree* tree);
void handleGenerateIF(Tree* tree);
void handleGenerateWhile(Tree* tree);
void handleGenerateBinaryOperation(Tree* tree);
void handleUnaryOp(Tree* tree);
void handleGenerateFunc(Tree* tree);
void generateThreeDir(Tree* tree);
void createRetTag(TData* func);
void generateLoadParams(Tree* tree);
void has_Call_Func(Tree* tree);
void has_Operation(Tree* tree);
void createSentenThreeDir(ASM tag , TData* func);
void handleGenerateMain(Tree* tree);
void createTagLoad(TData* symbol);
void createCall_Func(TData* nameFunc, TData* tempResult);
PseudoAssembly* createTagForFalse(ASM tag, TData* condition);
PseudoAssembly* createJump();
void createAndAppendTagLabel(char* nameLabel);
char* generateNameLabel();
void handleGenerateOpReturn(Tree* tree);
void requireParams(Tree* tree);
void createCodRequiredParam(TData* param);
void generateVarGlobals();

void operComparate(TOKENS tag,TData* op1, TData* op2, TData* res);
void operAritmetic(TOKENS tag,TData* op1, TData* op2, TData* res);

void  traslate(TOKENS tag, Tree* op1, Tree* op2, Tree* res);
struct TData *LookupVar(char * name);



void generateAssembler();

#endif
