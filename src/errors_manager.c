#include "../include/errors_manager.h"

// Check if token is an arithmetic type
bool isArithmeticToken(TOKENS token) {
    return (token == PLUS || token == MINUS || token == PROD || token == CONSINT || token == EMOD || token == EDIV);
}

// Check if token is a boolean type
bool isBooleanToken(TOKENS token) {
    return (token == EOR || token == EAND || token == ENOT || token == CONSBOOL || token == T_GREATER_THAN || token == T_LESS_THAN || token == EEQ);
}

// Check if token is a comparison operator
bool isComparisonToken(TOKENS token) {
    return (token == T_GREATER_THAN || token == T_LESS_THAN || token == EEQ);
}

// Semantic error: condition must be boolean
void validateCondition(Tree *node, bool* errorFlag) {
    TData* leftSymbol = lookupInCurrentScope(node->left->symbol->varname);
    TData* leftSymbolGlobal = lookupInAllScopes(node->left->symbol->varname);
    if (!leftSymbol && leftSymbolGlobal) leftSymbol = leftSymbolGlobal;
    TOKENS leftToken = node->left->symbol->token;

    if (!leftSymbol) {
        if (leftToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->left->left->symbol->varname);
            if (funcType && funcType->token != RETBOL && funcType->token != EXTBOL) {
                printf("\033[31mType error in called function\033[0m, error at line: %d\n", node->left->symbol->line);
                *errorFlag = true;
            }
        } else if (!isBooleanToken(leftToken) && !isComparisonToken(leftToken)) {
            printf("\033[31mType error in condition\033[0m, error at line: %d\n", node->left->symbol->line);
            *errorFlag = true;
        }
    } else if (leftSymbol->token != VARBOOL && leftSymbol->token != PARAMBOOL) {
        printf("\033[31mType error in variable used in condition\033[0m, error at line: %d\n", node->left->symbol->line);
        *errorFlag = true;
    }
}

// Semantic error: NOT operation must be boolean
void validateNotOperation(Tree* node, bool* errorFlag) {
    TData* leftSymbol = lookupInCurrentScope(node->left->symbol->varname);
    TData* leftSymbolGlobal = lookupInAllScopes(node->left->symbol->varname);
    if (!leftSymbol && leftSymbolGlobal) leftSymbol = leftSymbolGlobal;
    TOKENS leftToken = node->left->symbol->token;

    if (!leftSymbol && !isBooleanToken(leftToken) && !isComparisonToken(leftToken)) {
        printf("\033[31mType error, undefined operation in NOT\033[0m, error at line: %d\n", node->left->symbol->line);
        *errorFlag = true;
    } else if (leftSymbol && leftSymbol->token != VARBOOL && leftSymbol->token != PARAMBOOL) {
        printf("\033[31mType error in value for NOT operation\033[0m, error at line: %d\n", node->left->symbol->line);
        *errorFlag = true;
    }
}

// Semantic error: return type must match function declaration
void validateReturn(Tree* node, TOKENS expectedType, bool* errorFlag) {
    TData* leftSymbol = lookupInCurrentScope(node->left->symbol->varname);
    TData* leftSymbolGlobal = lookupInAllScopes(node->left->symbol->varname);
    if (!leftSymbol && leftSymbolGlobal) leftSymbol = leftSymbolGlobal;
    TOKENS leftToken = node->left->symbol->token;

    if (expectedType == RETVOID) {
        printf("\033[31mReturn type error\033[0m, error at line: %d\n", node->left->symbol->line);
        *errorFlag = true;
        return;
    }

    if (!leftSymbol) {
        if (leftToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->left->left->symbol->varname);
            if (funcType) {
                bool invalidInt = (expectedType == RETINT || expectedType == EXTINT) && funcType->token != RETINT;
                bool invalidBool = (expectedType == RETBOL || expectedType == EXTBOL) && (funcType->token != RETBOL && funcType->token != EXTBOL);
                if (invalidInt || invalidBool) {
                    printf("\033[31mReturn type error, invalid function type\033[0m, error at line: %d\n", node->left->symbol->line);
                    *errorFlag = true;
                }
            }
        } else if (((expectedType == RETINT || expectedType == EXTINT) && !isArithmeticToken(leftToken)) ||
                   ((expectedType == RETBOL || expectedType == EXTBOL) && !isBooleanToken(leftToken) && !isComparisonToken(leftToken))) {
            printf("\033[31mReturn type error, expected value of incorrect type\033[0m, error at line: %d\n", node->left->symbol->line);
            *errorFlag = true;
        }
    } else if (((leftSymbol->token != VARBOOL && leftSymbol->token != PARAMBOOL) && (expectedType == RETBOL || expectedType == EXTBOL)) ||
               ((leftSymbol->token != VARINT && leftSymbol->token != PARAMINT) && (expectedType == RETINT || expectedType == EXTINT))) {
        printf("\033[31mReturn type error, incorrect value expression\033[0m, error at line: %d\n", node->left->symbol->line);
        *errorFlag = true;
    }
}

// Semantic error: assignment type must match
void validateAssignment(Tree *node, bool *errorFlag) {
    TData* rightSymbol = lookupInCurrentScope(node->right->symbol->varname);
    TData* rightSymbolGlobal = lookupInAllScopes(node->right->symbol->varname);
    if (!rightSymbol && rightSymbolGlobal) rightSymbol = rightSymbolGlobal;
    TData* leftSymbol = lookupInCurrentScope(node->left->symbol->varname);
    TData* leftSymbolGlobal = lookupInAllScopes(node->left->symbol->varname);
    if (!leftSymbol && leftSymbolGlobal) leftSymbol = leftSymbolGlobal;

    TOKENS rightToken = node->right->symbol->token;
    TOKENS leftToken = node->left->symbol->token;
    bool invalidIntRight = !isArithmeticToken(rightToken);
    bool invalidBoolRight = !isBooleanToken(rightToken);

    if (!leftSymbol && leftToken == EID) {
        printf("\033[33mVariable in assignment not declared\033[0m, error at line: %d\n", node->left->symbol->line);
        *errorFlag = true;
    } else if (leftSymbol && rightSymbol && leftSymbol->token != rightSymbol->token && !isAssignmentTypeCompatible(leftSymbol->token, rightSymbol->token)) {
        printf("\033[31mType error in assignment, incompatible types\033[0m, error at line: %d\n", node->left->symbol->line);
        *errorFlag = true;
    } else if (leftSymbol && !rightSymbol) {
        if (rightToken == EID) {
            printf("\033[33mVariable to assign not declared\033[0m, error at line: %d\n", node->left->symbol->line);
            *errorFlag = true;
        } else if (rightToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->right->left->symbol->varname);
            if (funcType) {
                bool invalidInt = (leftSymbol->token == VARINT || leftSymbol->token == PARAMINT) && (funcType->token != RETINT && funcType->token != EXTINT);
                bool invalidBool = (leftSymbol->token == VARBOOL || leftSymbol->token == PARAMBOOL) && (funcType->token != RETBOL && funcType->token != EXTBOL);
                if (invalidInt || invalidBool) {
                    printf("\033[31mType error in assignment, incompatible function type\033[0m, error at line: %d\n", node->left->symbol->line);
                    *errorFlag = true;
                }
            }
        } else if (((leftSymbol->token == VARINT || leftSymbol->token == PARAMINT) && invalidIntRight) ||
                   ((leftSymbol->token == VARBOOL || leftSymbol->token == PARAMBOOL) && invalidBoolRight)) {
            printf("\033[31mType error in assignment\033[0m, error at line: %d\n", node->right->symbol->line);
            *errorFlag = true;
        }
    }
}

// Check if assignment types are compatible (parameter/variable INT/BOOL)
bool isAssignmentTypeCompatible(TOKENS leftToken, TOKENS rightToken) {
    return
        (leftToken == PARAMBOOL && rightToken == PARAMBOOL) ||
        (leftToken == PARAMBOOL && rightToken == VARBOOL) ||
        (leftToken == VARBOOL && rightToken == PARAMBOOL) ||
        (leftToken == PARAMINT && rightToken == VARINT) ||
        (leftToken == VARINT && rightToken == PARAMINT) ||
        (leftToken == PARAMINT && rightToken == PARAMINT);
}

// Semantic error: operation type must match operands
void validateOperation(Tree *node, TOKENS operationToken, bool* errorFlag) {
    TData* rightSymbol = lookupInCurrentScope(node->right->symbol->varname);
    TData* rightSymbolGlobal = lookupInAllScopes(node->right->symbol->varname);
    if (!rightSymbol && rightSymbolGlobal) rightSymbol = rightSymbolGlobal;
    TData* leftSymbol = lookupInCurrentScope(node->left->symbol->varname);
    TData* leftSymbolGlobal = lookupInAllScopes(node->left->symbol->varname);
    if (!leftSymbol && leftSymbolGlobal) leftSymbol = leftSymbolGlobal;

    if (operationToken == PLUS || operationToken == MINUS || operationToken == PROD || operationToken == EMOD || operationToken == EDIV) {
        validateArithmeticOperation(node, leftSymbol, rightSymbol, errorFlag);
    } else if (operationToken == EOR || operationToken == EAND || operationToken == ENOT) {
        validateBooleanOperation(node, leftSymbol, rightSymbol, errorFlag);
    } else {
        validateComparisonOperation(node, leftSymbol, rightSymbol, errorFlag);
    }
}

// Validate comparison operation types
void validateComparisonOperation(Tree* node, TData* leftSymbol, TData* rightSymbol, bool* errorFlag) {
    int line = node->left->symbol->line;
    TOKENS rightToken = node->right->symbol->token;
    TOKENS leftToken = node->left->symbol->token;
    bool invalidIntRight = !isArithmeticToken(rightToken);
    bool isRightComparison = isComparisonToken(rightToken);
    bool invalidIntLeft = !isArithmeticToken(leftToken);
    bool isLeftComparison = isComparisonToken(leftToken);

    if (leftSymbol && rightSymbol) {
        if ((leftSymbol->token != VARINT && leftSymbol->token != PARAMINT) ||
            (rightSymbol->token != VARINT && rightSymbol->token != PARAMINT)) {
            printf("\033[31mType error\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
        return;
    }

    if ((leftSymbol && !rightSymbol) ^ (!leftSymbol && rightSymbol)) {
        if ((!rightSymbol && rightToken == EID) ^ (!leftSymbol && leftToken == EID)) {
            printf("\033[33mVariable not declared\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        } else if ((!rightSymbol && rightToken == CALL_F) ^ (!leftSymbol && leftToken == CALL_F)) {
            if (rightToken == CALL_F) {
                TData *funcType = lookupInAllScopes(node->right->left->symbol->varname);
                if (funcType &&
                    ((leftSymbol->token != VARINT && leftSymbol->token != PARAMINT) ||
                     (funcType->token != RETINT && funcType->token != EXTINT))) {
                    printf("\033[31mType error, called function is incorrect type\033[0m, error at line: %d\n", line);
                    *errorFlag = true;
                }
            } else {
                TData *funcType = lookupInAllScopes(node->left->left->symbol->varname);
                if ((rightSymbol->token != VARINT && rightSymbol->token != PARAMINT) ||
                    (funcType->token != RETINT && funcType->token != EXTINT)) {
                    printf("\033[31mType error, called function is incorrect type\033[0m, error at line: %d\n", line);
                    *errorFlag = true;
                }
            }
        } else if ((!rightSymbol && ((leftSymbol->token != VARINT && leftSymbol->token != PARAMINT) || invalidIntRight)) ^
                   (!leftSymbol && ((rightSymbol->token != VARINT && rightSymbol->token != PARAMINT) || invalidIntLeft))) {
            if ((!rightSymbol && isRightComparison) || (!leftSymbol && isLeftComparison)) {
                printf("\033[31mSyntax error\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            } else {
                printf("\033[31mType error\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            }
        }
        return;
    }

    if (!leftSymbol && !rightSymbol) {
        if (leftToken == EID || rightToken == EID) {
            printf("\033[33mVariable not declared\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
        if (rightToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->right->left->symbol->varname);
            if (funcType && funcType->token != RETINT && funcType->token != EXTINT) {
                printf("\033[31mType error\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            }
        }
        if (leftToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->left->left->symbol->varname);
            if (funcType && funcType->token != RETINT && funcType->token != EXTINT) {
                printf("\033[31mType error\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            }
        }
        if ((invalidIntLeft && leftToken != CALL_F) || (invalidIntRight && rightToken != CALL_F)) {
            if (isLeftComparison || isRightComparison) {
                printf("\033[31mSyntax error\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            } else {
                printf("\033[31mType error\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            }
        }
    }
}

// Validate boolean operation types
void validateBooleanOperation(Tree* node, TData* leftSymbol, TData* rightSymbol, bool* errorFlag) {
    int line = node->left->symbol->line;
    TOKENS rightToken = node->right->symbol->token;
    TOKENS leftToken = node->left->symbol->token;
    bool invalidBoolRight = !isBooleanToken(rightToken) && !isComparisonToken(rightToken);
    bool invalidBoolLeft = !isBooleanToken(leftToken) && !isComparisonToken(rightToken);

    if (leftSymbol && rightSymbol) {
        if ((leftSymbol->token != VARBOOL && leftSymbol->token != PARAMBOOL) ||
            (rightSymbol->token != VARBOOL && rightSymbol->token != PARAMBOOL)) {
            printf("\033[31mType error in boolean operation\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
        return;
    }

    if ((leftSymbol && !rightSymbol) ^ (!leftSymbol && rightSymbol)) {
        if ((!rightSymbol && rightToken == EID) || (!leftSymbol && leftToken == EID)) {
            printf("\033[33mVariable not declared\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        } else if ((!rightSymbol && rightToken == CALL_F) ^ (!leftSymbol && leftToken == CALL_F)) {
            if (rightToken == CALL_F) {
                TData *funcType = lookupInAllScopes(node->right->left->symbol->varname);
                if (funcType &&
                    ((leftSymbol->token != VARBOOL && leftSymbol->token != PARAMBOOL) ||
                     (funcType->token != RETBOL && funcType->token != EXTBOL))) {
                    printf("\033[31mType error, called function is incorrect type\033[0m, error at line: %d\n", line);
                    *errorFlag = true;
                }
            } else {
                TData *funcType = lookupInAllScopes(node->left->left->symbol->varname);
                if ((rightSymbol->token != VARBOOL && rightSymbol->token != PARAMBOOL) ||
                    (funcType->token != RETBOL && funcType->token != EXTBOL)) {
                    printf("\033[31mType error, called function is incorrect type\033[0m, error at line: %d\n", line);
                    *errorFlag = true;
                }
            }
        } else if ((!rightSymbol && ((leftSymbol->token != VARBOOL && leftSymbol->token != PARAMBOOL) || invalidBoolRight)) ^
                   (!leftSymbol && ((rightSymbol->token != VARBOOL && rightSymbol->token != PARAMBOOL) || invalidBoolLeft))) {
            printf("\033[31mType error, incompatible condition values\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
        return;
    }

    if (!leftSymbol && !rightSymbol) {
        if (leftToken == EID || rightToken == EID) {
            printf("\033[33mVariable not declared\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
        if (rightToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->right->left->symbol->varname);
            if (funcType && funcType->token != RETBOL && funcType->token != EXTBOL) {
                printf("\033[31mType error, function of incorrect type\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            }
        }
        if (leftToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->left->left->symbol->varname);
            if (funcType && funcType->token != RETBOL && funcType->token != EXTBOL) {
                printf("\033[31mType error, function of incorrect type\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            }
        }
        if ((invalidBoolLeft && leftToken != CALL_F) || (invalidBoolRight && rightToken != CALL_F)) {
            printf("\033[31mType error, incompatible value types\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
    }
}

// Validate arithmetic operation types
void validateArithmeticOperation(Tree* node, TData* leftSymbol, TData* rightSymbol, bool* errorFlag) {
    TOKENS rightToken = node->right->symbol->token;
    TOKENS leftToken = node->left->symbol->token;
    bool invalidIntRight = !isArithmeticToken(rightToken);
    bool invalidIntLeft = !isArithmeticToken(leftToken);
    int line = node->left->symbol->line;

    if (leftSymbol && rightSymbol) {
        if ((leftSymbol->token != VARINT && leftSymbol->token != PARAMINT) ||
            (rightSymbol->token != VARINT && rightSymbol->token != PARAMINT)) {
            printf("\033[31mType error\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
        return;
    }

    if (!leftSymbol && !rightSymbol) {
        if (leftToken == EID || rightToken == EID) {
            printf("\033[33mVariable not declared\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
        if (rightToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->right->left->symbol->varname);
            if (funcType && funcType->token != RETINT && funcType->token != EXTINT) {
                printf("\033[31mType error\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            }
        }
        if (leftToken == CALL_F) {
            TData *funcType = lookupInAllScopes(node->left->left->symbol->varname);
            if (funcType && funcType->token != RETINT && funcType->token != EXTINT) {
                printf("\033[31mType error\033[0m, error at line: %d\n", line);
                *errorFlag = true;
            }
        }
        if ((invalidIntLeft && leftToken != CALL_F) || (invalidIntRight && rightToken != CALL_F)) {
            printf("\033[31mType error\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
        return;
    }

    if ((leftSymbol && !rightSymbol) ^ (!leftSymbol && rightSymbol)) {
        if ((!rightSymbol && rightToken == EID) ^ (!leftSymbol && leftToken == EID)) {
            printf("\033[33mVariable not declared\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        } else if ((!rightSymbol && rightToken == CALL_F) ^ (!leftSymbol && leftToken == CALL_F)) {
            if (rightToken == CALL_F) {
                TData *funcType = lookupInAllScopes(node->right->left->symbol->varname);
                if (funcType &&
                    ((leftSymbol->token != VARINT && leftSymbol->token != PARAMINT) ||
                     (funcType->token != RETINT && funcType->token != EXTINT))) {
                    printf("\033[31mType error\033[0m, error at line: %d\n", line);
                    *errorFlag = true;
                }
            } else {
                TData *funcType = lookupInAllScopes(node->left->left->symbol->varname);
                if ((rightSymbol->token != VARINT && rightSymbol->token != PARAMINT) ||
                    (funcType->token != RETINT && funcType->token != EXTINT)) {
                    printf("\033[31mType error\033[0m, error at line: %d\n", line);
                    *errorFlag = true;
                }
            }
        } else if ((!rightSymbol && ((leftSymbol->token != VARINT && leftSymbol->token != PARAMINT) || invalidIntRight)) ^
                   (!leftSymbol && ((rightSymbol->token != VARINT && rightSymbol->token != PARAMINT) || invalidIntLeft))) {
            printf("\033[31mType error\033[0m, error at line: %d\n", line);
            *errorFlag = true;
        }
    }
}

// Semantic error: function call argument types must match parameter types
void validateFunctionCall(Tree *node, bool *errorFlag) {
    TData* functionSymbol = lookupInAllScopes(node->left->symbol->varname);
    int paramCount = countFunctionArguments(functionSymbol);
    int argIndex = 0;
    if (paramCount >= 0) {
        int argTypes[paramCount];
        collectArgumentTypes(node->right, argTypes, &argIndex, paramCount, 1, errorFlag);
        int *paramTypes = getParameterTypes(functionSymbol);
        if (paramCount == argIndex) {
            for (int j = 0; j < paramCount; j++) {
                bool badBool = (paramTypes[j] == PARAMBOOL) && (argTypes[j] == VARINT || argTypes[j] == CONSINT || argTypes[j] == RETINT || argTypes[j] == EXTINT);
                bool badInt = (paramTypes[j] == PARAMINT) && (argTypes[j] == VARBOOL || argTypes[j] == CONSBOOL || argTypes[j] == RETBOL || argTypes[j] == EXTBOL);
                if (badBool || badInt) {
                    printf("\033[31mType error in passed argument\033[0m, error at line: %d\n", node->left->symbol->line);
                    *errorFlag = true;
                }
            }
        } else {
            printf("\033[31mFunction call error, invalid number of arguments\033[0m, error at line: %d\n", node->left->symbol->line);
            *errorFlag = true;
        }
        free(paramTypes);
    }
}

// Recursively collect argument types for function call validation
void collectArgumentTypes(Tree *node, int types[], int* index, int maxArgs, int size, bool *errorFlag) {
    if (!node) return;

    TOKENS currentToken = node->symbol->token;
    bool notArithmetic = (currentToken != PLUS && currentToken != MINUS && currentToken != PROD && currentToken != EDIV && currentToken != EMOD);
    bool notBoolean = (currentToken != EOR && currentToken != EAND && currentToken != ENOT);
    bool notComparison = (currentToken != T_GREATER_THAN && currentToken != T_LESS_THAN && currentToken != EEQ);
    bool isNotType = (currentToken != CALL_F && (notArithmetic && notBoolean && notComparison));

    if (isNotType) {
        if (node->left) collectArgumentTypes(node->left, types, index, maxArgs, size, errorFlag);
        if (node->right) collectArgumentTypes(node->right, types, index, maxArgs, size, errorFlag);
    }

    if (node->symbol->token != ARGS && node->symbol->token != EFUNC) {
        if (*index < maxArgs) {
            TData* argSymbol = lookupInCurrentScope(node->symbol->varname);
            TData* argSymbolGlobal = lookupInAllScopes(node->symbol->varname);
            if (!argSymbol && argSymbolGlobal) argSymbol = argSymbolGlobal;

            if (!argSymbol) {
                bool isArithmetic = (currentToken == PLUS || currentToken == MINUS || currentToken == PROD || currentToken == EDIV || currentToken == EMOD);
                bool isBoolean = (currentToken == EOR || currentToken == EAND || currentToken == ENOT);
                bool isComparison = (currentToken == T_GREATER_THAN || currentToken == T_LESS_THAN || currentToken == EEQ);
                if (node->symbol->token == CALL_F) {
                    TData *funcType = lookupInAllScopes(node->left->symbol->varname);
                    if (funcType) {
                        types[*index] = funcType->token;
                        (*index)++;
                    }
                } else if (node->symbol->token == CONSINT || node->symbol->token == CONSBOOL) {
                    types[*index] = node->symbol->token;
                    (*index)++;
                } else if (isArithmetic) {
                    types[*index] = VARINT;
                    (*index)++;
                } else if (isBoolean || isComparison) {
                    types[*index] = VARBOOL;
                    (*index)++;
                } else {
                    printf("\033[31mArgument not declared\033[0m, error at line: %d\n", node->symbol->line);
                    *errorFlag = true;
                }
            } else {
                types[*index] = argSymbol->token;
                (*index)++;
            }
        } else {
            *errorFlag = true;
            (*index)++;
        }
    }
}