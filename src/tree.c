#include "../include/tree.h"
#include "../include/symbols_table.h"
#include "../include/errors_manager.h"

// Error flag for semantic analysis
bool semanticError = false;

// Tracks the expected return type for functions
TOKENS expectedReturnType = RETVOID;

// Pointer to the current function symbol
TData *currentFunctionSymbol = NULL;

// Stack offset for local variables
int localVarOffset = -16;

// Block and scope counters
int blockCount = -1;
bool insideConditionalBlock = false;
int returnCount = 0;
int returnCountInBlock = 0;
int conditionalBlockCount = 0;

// Tracks if a return error has occurred
bool missingReturnError = false;

// Create a new tree node
Tree* createTree(TData* symbol, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    if (!node) return NULL;
    node->symbol = symbol;
    node->left = left;
    node->right = right;
    return node;
}

// Update the symbol of a tree node
void updateTreeNode(Tree* node, TData* symbol) {
    if (node) node->symbol = symbol;
}

// Recursively free the tree and its symbols
void freeTree(Tree* node) {
    if (!node) return;
    if (node->symbol) {
        free(node->symbol);
        node->symbol = NULL;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// Build the symbol table and perform semantic analysis
void buildSymbolTable(Tree* node) {
    if (!node) return;

    TOKENS token = node->symbol->token;

    // Handle program scope
    if (token == EPROGRAM) {
        pushScope();
        installInCurrentScope(node->symbol);
    }

    // Handle function and extern declarations
    if (token == RETINT || token == RETBOL || token == RETVOID) {
        returnCount = 0;
        localVarOffset = -16;
        blockCount++;
        currentFunctionSymbol = node->symbol;
        installInCurrentScope(node->symbol);
        pushScope();
    } else if (token == EXTVOID || token == EXTINT || token == EXTBOL) {
        currentFunctionSymbol = node->symbol;
        installInCurrentScope(node->symbol);
        pushScope();
    }

    // Handle conditional and loop blocks
    if (token == EIF || token == EWHILE || token == EELSE) {
        conditionalBlockCount++;
        insideConditionalBlock = true;
        blockCount++;
        pushScope();
        installInCurrentScope(node->symbol);
    }

    // Handle variable and parameter declarations
    if (token == VARBOOL || token == VARINT) {
        if (getScopeDepth() != 1) {
            node->symbol->offset = localVarOffset;
            localVarOffset -= 16;
        }
        installInCurrentScope(node->symbol);
    }
    if (token == PARAMINT || token == PARAMBOOL) {
        node->symbol->offset = localVarOffset;
        localVarOffset -= 16;
        installInCurrentScope(node->symbol);
        installParameter(node->symbol, currentFunctionSymbol);
    }
    if (token == EID) {
        TData* foundSymbol = lookupInAllScopes(node->symbol->varname);
        if (foundSymbol) {
            node->symbol->offset = foundSymbol->offset;
        }
    }

    // Handle block end and return error checking
    if (token == BLOCK_FIN) {
        if (blockCount > 0) blockCount--;
        if (blockCount == 0 && !insideConditionalBlock) {
            currentFunctionSymbol->offset = localVarOffset;
            localVarOffset = -16;
        }
        if (insideConditionalBlock && conditionalBlockCount == 1) {
            insideConditionalBlock = false;
            conditionalBlockCount--;
        } else if (insideConditionalBlock && conditionalBlockCount > 1) {
            conditionalBlockCount--;
        } else if (missingReturnError && returnCount != 2) {
            printf("\033[31mMissing return statement at line \033[0m %d\n", node->symbol->line - 1);
            semanticError = true;
        } else if (missingReturnError && returnCount == 2) {
            missingReturnError = false;
        }
        popScope();
        returnCountInBlock = 0;
    }

    // Handle binary operations and semantic checks
    if (node->right && node->left) {
        TOKENS opToken = node->symbol->token;
        bool isArithmetic = (opToken == PLUS || opToken == MINUS || opToken == PROD || opToken == EDIV || opToken == EMOD);
        bool isBoolean = (opToken == EOR || opToken == EAND || opToken == ENOT);
        bool isComparison = (opToken == T_GREATER_THAN || opToken == T_LESS_THAN || opToken == EEQ);
        if (opToken == ASIGN) {
            validateAssignment(node, &semanticError);
        } else if (isArithmetic || isBoolean || isComparison) {
            node->symbol->offset = localVarOffset;
            localVarOffset -= 16;
            validateOperation(node, opToken, &semanticError);
        } else if (opToken == EIF || opToken == EWHILE) {
            validateCondition(node, &semanticError);
        }
    }

    // Track expected return type for functions
    if (node->symbol->token == RETVOID) {
        expectedReturnType = node->symbol->token;
        missingReturnError = false;
    }
    if (node->symbol->token == RETINT || node->symbol->token == RETBOL ||
        node->symbol->token == EXTBOL || node->symbol->token == RETINT) {
        expectedReturnType = node->symbol->token;
        missingReturnError = true;
    }

    // Handle function calls and argument checks
    if (node->symbol->token == CALL_F) {
        TData* foundFunc = lookupInAllScopes(node->left->symbol->varname);
        if (foundFunc) {
            node->symbol->offset = localVarOffset;
            localVarOffset -= 16;
            validateFunctionCall(node, &semanticError);
        } else {
            printf("\033[31mFunction does not exist\033[0m, error at line:%d\n", node->left->symbol->line);
            semanticError = true;
        }
    }

    // Recursively process left and right subtrees
    if (node->left) {
        if (node->symbol->token == ERETURN && insideConditionalBlock) {
            if (returnCountInBlock == 0) returnCount++;
            returnCountInBlock++;
            validateReturn(node, expectedReturnType, &semanticError);
        } else if (node->symbol->token == ERETURN && returnCount == 2) {
            missingReturnError = false;
            validateReturn(node, expectedReturnType, &semanticError);
        } else if (node->symbol->token == ERETURN) {
            missingReturnError = false;
            validateReturn(node, expectedReturnType, &semanticError);
        }
        if (node->symbol->token == ENOT) {
            node->symbol->offset = localVarOffset;
            localVarOffset -= 16;
            validateNotOperation(node, &semanticError);
        }
        buildSymbolTable(node->left);
    }
    if (node->right) {
        buildSymbolTable(node->right);
    }
}

// Print error if a return statement is missing in a function
void checkMissingReturnError(void) {
    if (missingReturnError) {
        printf("\033[31mMissing return statement\033[0m\n");
        semanticError = true;
    }
}

// Returns true if a semantic error was detected
bool hasSemanticError(void) {
    return semanticError;
}
