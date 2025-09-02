#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef SYMBOLS_TABLE_H
#define SYMBOLS_TABLE_H
typedef enum TOKENS {
    VAR,
    EMAIN,
    VARINT,
    VARBOOL,
    CONSINT,
    CONSBOOL,
    PLUS,
    MINUS,
    PROD,
    EDIV,
    EMOD,
    EOR,
    EAND,
    ENOT,
    ASIGN,
    DECLARATION,
    SENTEN,
    EID,
    ERETURN,
    RETINT,
    RETBOL,
    RETVOID,
    EXTINT,
    EXTBOL,
    EXTVOID,
    EIF,
    ETHEN,
    EELSE,
    EWHILE,
    T_GREATER_THAN,
    T_LESS_THAN,
    EEQ,
    EFUNC,
    EFUNCEXTERN,
    EPROGRAM,
    EBLOQ,
    CALL_F,
    ARGS,
    PARAMINT,
    PARAMBOOL,
    OTHERS,
    BLOCK,
    BLOCK_FIN
} TOKENS;

char static string[45][41] = {"VAR","EMAIN","VARINT","VARBOOL","CONSINT","CONSBOOL","SUMA","RESTA","PROD","EDIV","EMOD","EOR","EAND","ENOT","ASIG","DECLARATION","SENTEN","EID","ERETURN","RETINT","RETBOL","RETVOID", "EXTINT",
    "EXTBOL", "EXTVOID","EIF","ETHEN","EELSE","EWHILE","T_GREATER_THAN","T_LESS_THAN","EEQ","EFUNC","EFUNCEXTERN","EPROGRAM","EBLOQ","CALL_F","ARGS", "PARAMINT", "PARAMBOOL","OTHERS","BLOCK","BLOCK_FIN"};

typedef struct TData {
    int id;
    TOKENS token;
    char* varname;     
    struct TData *next;
    int line;
    int value;
    int offset;
    struct TData *table;
} TData;

// Create and initialize a new symbol table entry
TData *createSymbol(char *name, TOKENS token, int size, int line);

// Get the current symbol table (scope stack head)
TData *getSymbolTable(void);

// Get the current scope depth
int getScopeDepth(void);

// Create a new scope and push it onto the scope stack
void pushScope(void);

// Look up a symbol by name in the current scope
TData *lookupInCurrentScope(char *name);

// Look up a symbol by name in a given symbol table (scope)
TData *lookupInScope(char *name, TData *scope);

// Install a symbol in the current scope
void installInCurrentScope(TData *symbol);

// Pop the current scope from the scope stack
void popScope(void);

// Install a parameter symbol in a function's symbol table
void installParameter(TData *param, TData *functionSymbol);

// Look up a symbol by name in all scopes (from innermost to outermost)
TData *lookupInAllScopes(char *name);

// Set the value of a symbol
void setSymbolValue(TData *symbol, int value);

// Get an array of parameter types for a function symbol
int *getParameterTypes(TData *functionSymbol);

// Count the number of parameters for a function symbol
int countFunctionArguments(TData *functionSymbol);

// Print the entire symbol table (all scopes and their entries)
void printSymbolTable(void);

// Set the stack offset for a symbol
void setSymbolOffset(TData *symbol, int offset);

#endif
