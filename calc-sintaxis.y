%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/tree.h"
#include "include/pseudo_assembly.h"

// Compiler entry point: builds symbol table, checks errors, generates code
void compile(Tree *syntaxTree);

// Helper to create a tree node with a symbol
Tree* createTreeWithSymbol(char *name, TOKENS token, int size, int line, Tree *left, Tree *right);

extern int yylineno; // Current line number from lexer
int blockCounter = 0; // Tracks block nesting for unique IDs
%}

%union {
    TData* symbol;
    Tree *tree;
}

/* Token declarations for identifiers and literals */
%token <symbol> ID

/* Data type tokens */
%token <symbol> INT
%token <symbol> TTRUE
%token <symbol> TFALSE
%token TYPE_INT
%token TYPE_BOOL
%token TYPE_VOID

/* Operator and symbol tokens */
%token TPLUS
%token TTIMES
%token TMINUS
%token TDIV
%token TMOD
%token TASIGN
%token TPAR_OP
%token TPAR_CL
%token TBRACE_OP
%token TBRACE_CL
%token OR
%token AND
%token NOT
%token GREATER_THAN
%token LESS_THAN
%token EQ

/* Reserved keywords */
%token PROGRAM
%token EXTERN
%token THEN
%token IF
%token ELSE
%token WHILE
%token RETURN
%token MAIN

/* Operator precedences */
%left OR AND                // ||, &&
%left EQ                    // ==
%left GREATER_THAN LESS_THAN     // >,<
%left TPLUS TMINUS           // +, -
%left TTIMES TDIV TMOD // *, /, %
%right NOT                  // Negation is right-associative

/* Non-terminal types */
%type <tree> program main return_stmt
%type <tree> function_call expression
%type <tree> assignment value argument
%type <tree> declaration statement parameter_declaration function_declaration
%type <tree> declaration_list statement_list function_list parameters
%type <tree> if_else_stmt while_stmt block

%%

/* Program structure: main, declarations, functions */
program:
      PROGRAM TBRACE_OP declaration_list function_list main TBRACE_CL {
          char *blockName = "PROGRAM_BLOCK";
          Tree* blockTree = createTreeWithSymbol(blockName, OTHERS, blockCounter, yylineno, $4, $5);
          char *programName = "PROGRAM";
          compile(createTreeWithSymbol(programName, EPROGRAM, blockCounter, yylineno, $3, blockTree));
      }
    | PROGRAM TBRACE_OP main TBRACE_CL {
          char *programName = "PROGRAM";
          compile(createTreeWithSymbol(programName, EPROGRAM, blockCounter, yylineno, NULL, $3));
      }
    | PROGRAM TBRACE_OP function_list main TBRACE_CL {
          char *programName = "PROGRAM";
          compile(createTreeWithSymbol(programName, EPROGRAM, blockCounter, yylineno, $3, $4));
      }
    | PROGRAM TBRACE_OP declaration_list main TBRACE_CL {
          char *programName = "PROGRAM";
          compile(createTreeWithSymbol(programName, EPROGRAM, blockCounter, yylineno, $3, $4));
      }
    ;

/* Main function definition */
main:
      TYPE_BOOL MAIN TPAR_OP TPAR_CL block {
          char *mainName = "main";
          $$ = createTreeWithSymbol(mainName, RETBOL, blockCounter, yylineno, $5, NULL);
      }
    | TYPE_INT MAIN TPAR_OP TPAR_CL block {
          char *mainName = "main";
          $$ = createTreeWithSymbol(mainName, RETINT, blockCounter, yylineno, $5, NULL);
      }
    | TYPE_VOID MAIN TPAR_OP TPAR_CL block {
          char *mainName = "main";
          $$ = createTreeWithSymbol(mainName, RETVOID, blockCounter, yylineno, $5, NULL);
      }
    ;

/* List of variable declarations */
declaration_list:
      declaration {
          char *declName = "DECLARATION";
          $$ = createTreeWithSymbol(declName, DECLARATION, blockCounter, yylineno, $1, NULL);
      }
    | declaration_list declaration {
          char *declName = "DECLARATION";
          $$ = createTreeWithSymbol(declName, DECLARATION, blockCounter, yylineno, $1, $2);
      }
    ;

/* List of statements */
statement_list:
      /* empty */ { $$ = NULL; }
    | statement_list statement {
          char *stmtName = "STATEMENT";
          $$ = createTreeWithSymbol(stmtName, SENTEN, blockCounter, yylineno, $1, $2);
      }
    ;

/* Block of code (with or without declarations) */
block:
      TBRACE_OP declaration_list statement_list TBRACE_CL {
          char *blockEndName = "BLOCK_END";
          Tree* blockEnd = createTreeWithSymbol(blockEndName, BLOCK_FIN, blockCounter, yylineno, NULL, NULL);
          char *internalBlockName = "BLOCK_INTERNAL";
          Tree* internalBlock = createTreeWithSymbol(internalBlockName, OTHERS, blockCounter, yylineno, $2, $3);
          char *blockName = "BLOCK";
          $$ = createTreeWithSymbol(blockName, BLOCK, blockCounter, yylineno, internalBlock, blockEnd);
      }
    | TBRACE_OP statement_list TBRACE_CL {
          char *blockEndName = "BLOCK_END";
          Tree* blockEnd = createTreeWithSymbol(blockEndName, BLOCK_FIN, blockCounter, yylineno, NULL, NULL);
          char *blockName = "BLOCK";
          $$ = createTreeWithSymbol(blockName, BLOCK, blockCounter, yylineno, $2, blockEnd);
      }
    ;

/* Statement types */
statement:
      assignment { $$ = $1; }
    | return_stmt { $$ = $1; }
    | if_else_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | function_call ';' { $$ = $1; }
    ;

/* Assignment statement */
assignment:
      ID TASIGN expression ';' {
          char *varName = $1->varname;
          Tree* idNode = createTreeWithSymbol(varName, EID, blockCounter, yylineno, NULL, NULL);
          char *assignName = "ASSIGNMENT";
          $$ = createTreeWithSymbol(assignName, ASIGN, 1, yylineno, idNode, $3);
      }
    ;

/* Function call statement */
function_call:
      ID TPAR_OP argument TPAR_CL {
          char *funcName = $1->varname;
          Tree* funcNode = createTreeWithSymbol(funcName, EFUNC, blockCounter, yylineno, NULL, NULL);
          char *callName = "FUNCTION_CALL";
          $$ = createTreeWithSymbol(callName, CALL_F, blockCounter, yylineno, funcNode, $3);
      }
    ;

/* Variable declaration */
declaration:
      TYPE_INT ID ';' {
          char *varName = $2->varname;
          $$ = createTreeWithSymbol(varName, VARINT, blockCounter, yylineno, NULL, NULL);
      }
    | TYPE_BOOL ID ';' {
          char *varName = $2->varname;
          $$ = createTreeWithSymbol(varName, VARBOOL, blockCounter, yylineno, NULL, NULL);
      }
    ;

/* Argument list for function calls */
argument:
      /* empty */ { $$ = NULL; }
    | expression { $$ = $1; }
    | argument ',' expression {
          char *argsName = "ARGUMENTS";
          $$ = createTreeWithSymbol(argsName, ARGS, blockCounter, yylineno, $1, $3);
      }
    ;

/* Parameter list for function definitions */
parameters:
      /* empty */ { $$ = NULL; }
    | parameter_declaration { $$ = $1; }
    | parameter_declaration ',' parameters {
          char *paramsName = "PARAMETERS";
          $$ = createTreeWithSymbol(paramsName, DECLARATION, blockCounter, yylineno, $1, $3);
      }
    ;

/* Parameter declaration */
parameter_declaration:
      TYPE_INT ID {
          char *paramName = $2->varname;
          $$ = createTreeWithSymbol(paramName, PARAMINT, blockCounter, yylineno, NULL, NULL);
      }
    | TYPE_BOOL ID {
          char *paramName = $2->varname;
          $$ = createTreeWithSymbol(paramName, PARAMBOOL, blockCounter, yylineno, NULL, NULL);
      }
    ;

/* List of function declarations */
function_list:
      function_declaration {
          char *funcListName = "FUNCTION_LIST";
          $$ = createTreeWithSymbol(funcListName, OTHERS, blockCounter, yylineno, $1, NULL);
      }
    | function_list function_declaration {
          char *funcListName = "FUNCTION_LIST";
          $$ = createTreeWithSymbol(funcListName, OTHERS, blockCounter, yylineno, $1, $2);
      }
    ;

/* Function declaration (regular or extern) */
function_declaration:
      TYPE_INT ID TPAR_OP parameters TPAR_CL block {
          char *funcName = $2->varname;
          $$ = createTreeWithSymbol(funcName, RETINT, blockCounter, yylineno, $4, $6);
      }
    | TYPE_BOOL ID TPAR_OP parameters TPAR_CL block {
          char *funcName = $2->varname;
          $$ = createTreeWithSymbol(funcName, RETBOL, blockCounter, yylineno, $4, $6);
      }
    | TYPE_VOID ID TPAR_OP parameters TPAR_CL block {
          char *funcName = $2->varname;
          $$ = createTreeWithSymbol(funcName, RETVOID, blockCounter, yylineno, $4, $6);
      }
    | TYPE_INT ID TPAR_OP parameters TPAR_CL EXTERN ';' {
          char *funcName = $2->varname;
          $$ = createTreeWithSymbol(funcName, EXTINT, blockCounter-1, yylineno, $4, NULL);
      }
    | TYPE_BOOL ID TPAR_OP parameters TPAR_CL EXTERN ';' {
          char *funcName = $2->varname;
          $$ = createTreeWithSymbol(funcName, EXTBOL, blockCounter-1, yylineno, $4, NULL);
      }
    | TYPE_VOID ID TPAR_OP parameters TPAR_CL EXTERN ';' {
          char *funcName = $2->varname;
          $$ = createTreeWithSymbol(funcName, EXTVOID, blockCounter-1, yylineno, $4, NULL);
      }
    ;

/* Expressions (arithmetic, boolean, function calls, etc.) */
expression:
      value { $$ = $1; }
    | function_call { $$ = $1; }
    | expression TPLUS expression {
          char *plusName = "+";
          $$ = createTreeWithSymbol(plusName, PLUS, blockCounter, yylineno, $1, $3);
      }
    | expression TMINUS expression {
          char *minusName = "-";
          $$ = createTreeWithSymbol(minusName, MINUS, blockCounter, yylineno, $1, $3);
      }
    | expression TTIMES expression {
          char *timesName = "*";
          $$ = createTreeWithSymbol(timesName, PROD, blockCounter, yylineno, $1, $3);
      }
    | expression TDIV expression {
          char *divName = "/";
          $$ = createTreeWithSymbol(divName, EDIV, blockCounter, yylineno, $1, $3);
      }
    | expression TMOD expression {
          char *modName = "%";
          $$ = createTreeWithSymbol(modName, EMOD, blockCounter, yylineno, $1, $3);
      }
    | expression GREATER_THAN expression {
          char *gtName = ">";
          $$ = createTreeWithSymbol(gtName, GREATER_THAN, blockCounter, yylineno, $1, $3);
      }
    | expression LESS_THAN expression {
          char *ltName = "<";
          $$ = createTreeWithSymbol(ltName, LESS_THAN, blockCounter, yylineno, $1, $3);
      }
    | expression EQ expression {
          char *eqName = "==";
          $$ = createTreeWithSymbol(eqName, EEQ, blockCounter, yylineno, $1, $3);
      }
    | expression AND expression {
          char *andName = "&&";
          $$ = createTreeWithSymbol(andName, EAND, blockCounter, yylineno, $1, $3);
      }
    | expression OR expression {
          char *orName = "||";
          $$ = createTreeWithSymbol(orName, EOR, blockCounter, yylineno, $1, $3);
      }
    | NOT expression {
          char *notName = "!";
          $$ = createTreeWithSymbol(notName, ENOT, blockCounter, yylineno, $2, NULL);
      }
    | TPAR_OP expression TPAR_CL { $$ = $2; }
    ;

/* Value nodes: literals, identifiers, unary minus */
value:
      INT { $$ = createTree($1, NULL, NULL); }
    | ID { $$ = createTree($1, NULL, NULL); }
    | TMINUS INT {
          int len = strlen($2->varname);
          char* newVarname = (char*)malloc(len + 2);
          newVarname[0] = '-';
          strcpy(newVarname + 1, $2->varname);
          $2->varname = newVarname;
          $2->value = $2->value * -1;
          $$ = createTree($2, NULL, NULL);
      }
    | TTRUE { $$ = createTree($1, NULL, NULL); }
    | TFALSE { $$ = createTree($1, NULL, NULL); }
    ;

/* Return statement */
return_stmt:
      RETURN expression ';' {
          char *returnName = "return";
          $$ = createTreeWithSymbol(returnName, ERETURN, blockCounter, yylineno, $2, NULL);
      }
    ;

/* If-Else statement */
if_else_stmt:
      IF TPAR_OP expression TPAR_CL THEN block {
          char *ifThenName = "if_then";
          $$ = createTreeWithSymbol(ifThenName, EIF, blockCounter, yylineno, $3, $6);
      }
    | IF TPAR_OP expression TPAR_CL THEN block ELSE block {
          char *thenName = "then";
          char *elseName = "else";
          Tree* elseNode = createTreeWithSymbol(elseName, EELSE, blockCounter, yylineno, $8, NULL);
          Tree* thenNode = createTreeWithSymbol(thenName, ETHEN, blockCounter, yylineno, $6, elseNode);
          char *ifElseName = "if_else";
          $$ = createTreeWithSymbol(ifElseName, EIF, blockCounter, yylineno, $3, thenNode);
      }
    ;

/* While statement */
while_stmt:
      WHILE TPAR_OP expression TPAR_CL block {
          char *whileName = "while";
          $$ = createTreeWithSymbol(whileName, EWHILE, blockCounter, yylineno, $3, $5);
      }
    ;

%%

/**
 * Compiler entry point: builds symbol table, checks for semantic errors,
 * generates pseudo-assembly and final assembly code, and frees memory.
 */
void compile(Tree* syntaxTree){
    buildSymbolTable(syntaxTree);
    checkMissingReturnError();
    if(hasSemanticError()) {
       freeTree(syntaxTree);
       exit(1);
    }
    generateThreeAddressCode(syntaxTree);
    printPseudoAssemblyInstructions();
    generateAssemblerOutput();
    freePseudoAssemblyInstructions();
    freeTree(syntaxTree);
}

/**
 * Helper to create a tree node with a symbol.
 * Allocates a symbol and attaches left/right children.
 */
Tree* createTreeWithSymbol(char *name, TOKENS token, int size, int line, Tree *left, Tree *right){
    TData* symbol = createSymbol(name, token, 0, yylineno);
    return createTree(symbol, left, right);
}