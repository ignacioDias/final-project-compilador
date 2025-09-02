#include <stdio.h>
#include <stdbool.h>
#include "tree.h"
#include "symbols_table.h"

#ifndef ERRORS_MANAGER_H
#define ERRORS_MANAGER_H

// Checks if a token is an arithmetic operator
bool isArithmeticToken(TOKENS token);

// Checks if a token is a boolean operator
bool isBooleanToken(TOKENS token);

// Checks if a token is a comparison operator
bool isComparisonToken(TOKENS token);

// Validates that a condition expression is boolean
void validateCondition(Tree *node, bool* errorFlag);

// Validates that a NOT operation is applied to a boolean
void validateNotOperation(Tree* node, bool* errorFlag);

// Validates that a return statement matches the expected type
void validateReturn(Tree* node, TOKENS expectedType, bool* errorFlag);

// Validates that an assignment is type-compatible
void validateAssignment(Tree *node, bool *errorFlag);

// Checks if assignment types are compatible (parameter/variable INT/BOOL)
bool isAssignmentTypeCompatible(TOKENS leftToken, TOKENS rightToken);

// Validates that an operation is type-compatible
void validateOperation(Tree *node, TOKENS operationToken, bool* errorFlag);

// Validates that a comparison operation is type-compatible
void validateComparisonOperation(Tree* node, TData* leftSymbol, TData* rightSymbol, bool* errorFlag);

// Validates that a boolean operation is type-compatible
void validateBooleanOperation(Tree* node, TData* leftSymbol, TData* rightSymbol, bool* errorFlag);

// Validates that an arithmetic operation is type-compatible
void validateArithmeticOperation(Tree* node, TData* leftSymbol, TData* rightSymbol, bool* errorFlag);

// Validates that function call arguments match parameter types
void validateFunctionCall(Tree *node, bool *errorFlag);

// Recursively collects argument types for function call validation
void collectArgumentTypes(Tree *node, int types[], int* index, int maxArgs, int size, bool *errorFlag);
#endif
