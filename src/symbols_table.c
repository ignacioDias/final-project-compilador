#include "../include/symbols_table.h"

// Global pointer to the head of the symbol table (scope stack)
TData *symbolTableHead = NULL;

// Counter for unique symbol IDs
int symbolIdCounter = 0;

// Counter for current scope depth
int scopeDepth = 0;

// Create and initialize a new symbol table entry
TData *createSymbol(char *name, TOKENS token, int size, int line) {
    TData *newSymbol = (TData *)malloc(sizeof(TData));
    if (!newSymbol) return NULL;
    newSymbol->id = symbolIdCounter++;
    newSymbol->varname = name;
    newSymbol->token = token;
    newSymbol->line = line;
    newSymbol->value = 0;
    newSymbol->table = NULL;
    newSymbol->offset = 0;
    newSymbol->next = NULL;
    return newSymbol;
}

// Get the current symbol table (scope stack head)
TData *getSymbolTable() {
    return symbolTableHead;
}

// Get the current scope depth
int getScopeDepth() {
    return scopeDepth;
}

// Create a new scope and push it onto the scope stack
void pushScope() {
    char *scopeName = "SCOPE";
    scopeDepth++;
    TData *scopeSymbol = createSymbol(scopeName, OTHERS, 0, 0);
    if (!scopeSymbol) {
        printf("Error: could not allocate memory for scope\n");
        exit(1);
    }
    scopeSymbol->next = symbolTableHead;
    symbolTableHead = scopeSymbol;
}

// Look up a symbol by name in the current scope
TData *lookupInCurrentScope(char *name) {
    if (!name || !symbolTableHead) return NULL;
    TData *entry = symbolTableHead->table;
    while (entry) {
        if (strcmp(name, entry->varname) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

// Look up a symbol by name in a given symbol table (scope)
TData *lookupInScope(char *name, TData *scope) {
    if (!name || !scope) return NULL;
    TData *entry = scope->table;
    while (entry) {
        if (strcmp(name, entry->varname) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

// Install a symbol in the current scope
void installInCurrentScope(TData *symbol) {
    if (!symbol || !symbolTableHead) return;
    if (lookupInCurrentScope(symbol->varname) == NULL) {
        symbol->next = symbolTableHead->table;
        symbolTableHead->table = symbol;
    } else {
        printf("Symbol already exists, error at line: %d\n", symbol->line);
        exit(1);
    }
}

// Pop the current scope from the scope stack
void popScope() {
    if (!symbolTableHead) return;
    TData *toDelete = symbolTableHead;
    symbolTableHead = symbolTableHead->next;
    scopeDepth--;
    free(toDelete);
}

// Install a parameter symbol in a function's symbol table
void installParameter(TData *param, TData *functionSymbol) {
    if (!param || !functionSymbol) return;
    if (lookupInScope(param->varname, functionSymbol) == NULL) {
        param->next = functionSymbol->table;
        functionSymbol->table = param;
    } else {
        printf("Parameter already exists, error at line: %d\n", param->line);
        exit(1);
    }
}

// Look up a symbol by name in all scopes (from innermost to outermost)
TData *lookupInAllScopes(char *name) {
    if (!name) return NULL;
    TData *scope = symbolTableHead;
    while (scope) {
        TData *found = lookupInScope(name, scope);
        if (found) return found;
        scope = scope->next;
    }
    return NULL;
}

// Set the value of a symbol
void setSymbolValue(TData *symbol, int value) {
    if (symbol) {
        symbol->value = value;
    } else {
        printf("Error: symbol is NULL\n");
    }
}

// Get an array of parameter types for a function symbol
int *getParameterTypes(TData *functionSymbol) {
    int count = countFunctionArguments(functionSymbol);
    int *types = (int *)malloc(count * sizeof(int));
    if (!types) return NULL;
    int index = count - 1;
    TData *entry = functionSymbol ? functionSymbol->table : NULL;
    while (entry) {
        if (entry->token == PARAMINT || entry->token == PARAMBOOL) {
            types[index--] = entry->token;
        }
        entry = entry->next;
    }
    return types;
}

// Count the number of parameters for a function symbol
int countFunctionArguments(TData *functionSymbol) {
    int count = 0;
    TData *entry = functionSymbol ? functionSymbol->table : NULL;
    while (entry) {
        if (entry->token == PARAMBOOL || entry->token == PARAMINT) {
            count++;
        }
        entry = entry->next;
    }
    return count;
}

// Print the entire symbol table (all scopes and their entries)
void printSymbolTable() {
    TData *scope = symbolTableHead;
    printf("SYMBOL TABLE\n");
    printf("| Name   | Type   | Offset | Value |\n");
    while (scope) {
        printf("| %s |", scope->varname);
        printf(" %s |", string[scope->token]);
        printf(" %d |", scope->offset);
        printf(" %d |\n", scope->value);
        if (scope->table) {
            TData *entry = scope->table;
            while (entry) {
                printf("| %s |", entry->varname);
                printf(" %s |", string[entry->token]);
                printf(" %d |", entry->offset);
                printf(" %d |\n", entry->value);
                entry = entry->next;
            }
        }
        scope = scope->next;
    }
}

// Set the stack offset for a symbol
void setSymbolOffset(TData *symbol, int offset) {
    if (symbol) {
        symbol->offset = offset;
    }
}