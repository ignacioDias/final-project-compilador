%{
#include <stdlib.h>
#include <stdio.h>
#include "include/tree.h"
#include "include/symbols_table.h"
#include "include/pseudo_assembly.h"
#include "include/assembly_generator.h"

int inFunction = 0;
char *activeFunction;
SymbolsTable* table;
AssemblyList *pseudoAssembly;
ListParams* params;
void setTypeFunction(Type type);

TData* checkForID(Tree *tree, Type type) {
    if(tree->info->token != T_ID)
        return tree->info;
    TData *newVar;
    if(inFunction) {
        newVar = findParam(params, tree->info->name, type, activeFunction);
        if(!newVar) {
            newVar = findVariable(table, tree->info->name, type);
        }
    } else {
        newVar = findVariable(table, tree->info->name, type);
    }
    if(!newVar) {
        perror("no declarated var 1\n"); 
        exit(1);
    }
    return newVar;
}
%}
%code requires {#include "include/tree.h"}
%code requires {#include "include/pseudo_assembly.h"}
%code requires {#include "include/symbols_table.h"}

%union{int i; int b; Tree *tree; char *s; TData *data;}

%token<data> INTV
%token<data> TRET
%token<data> TDECL
%token<data> TVOID
%token<data> TMAIN
%token<data> TR
%token<data> FAL
%token<data> TID
%token<data> TMENOR
%token<data> TMAYOR
%token<data> TIGUAL
%token<data> TMENOS
%token<data> TMAS
%token<data> TMULT
%token<data> TDIV
%token<data> TMOD
%token<data> TOR
%token<data> TNEG
%token<data> TAND
%token<data> EXTERN
%token<data> TWHILE
%token<data> TIF
%token<data> THEN
%token<data> TELSE
%token<data> TINT
%token<data> TBOOL
%token<data> TASIGN
%token<data> TPROGRAM

%type<tree> program
%type<tree> vars
%type<tree> var_decl
%type<tree> methods
%type<tree> method_decl
%type<tree> params
%type<tree> param
%type<tree> block
%type<tree> block1
%type<tree> statements
%type<tree> single_statement
%type<tree> method_call
%type<tree> method_call1
%type<tree> exprs
%type<tree> expr
%type<tree> literal
%type<tree> boolValue
%type<tree> id
%type<tree> ttype

%left TOR
%left TAND
%nonassoc TIGUAL TMAYOR TMENOR
%left TMAS TMENOS 
%left TMULT TDIV TMOD
%left UMINUS

%%
program1: {table = (SymbolsTable*)malloc(sizeof(SymbolsTable)); pseudoAssembly = (AssemblyList*)malloc(sizeof(AssemblyList)); LSE* newLevel = (LSE*)malloc(sizeof(LSE)); insertLevel(&table, newLevel); params = (ListParams*)malloc(sizeof(ListParams));}  program {identifyGlobal(pseudoAssembly); generateAssembly("prueba.txt"); removeLevel(&table); }
program: TPROGRAM '{' vars methods '}'  {$$ = newTree($1, $3, $4); evalType($$);  printTree($$); showTable(table); generatePseudoAssembly(&pseudoAssembly, $$); printAssemblyList(&pseudoAssembly); }
       |  TPROGRAM  '{' methods '}' {$$ = newTree($1, $3, NULL); evalType($$); printTree($$); showTable(table); generatePseudoAssembly(&pseudoAssembly, $$); printAssemblyList(&pseudoAssembly);}
       ;
vars: vars var_decl   {TData* data = newData(T_DECL, NO_TYPE, -1, "vars"); $$ = newTree(data, $1, $2);}
    | var_decl  {$$ = $1;}
    ;
var_decl:
    ttype id TASIGN expr ';' { if(insertElem(&table, newData($2->info->token, $1->info->type, $4->info->value, $2->info->name))) {

                                Tree *leftChild = newTree(newData(T_DECL, $1->info->type, -1, $2->info->name), $1, $2); $$ = newTree($3, leftChild, $4);
                            } else {
                                    perror("Re-declaration"); exit(1);} $4->info = checkForID($4, $1->info->type);}
    |ttype id ';' {if(insertElem(&table, newData($2->info->token, $1->info->type, 0, $2->info->name))){$$ = newTree(newData(T_DECL, NO_TYPE, 0, $2->info->name), $1, $2);} else {perror("var already exists");exit(1);}}
    ;



methods: methods method_decl { Tree *tree = newTree(newData(T_METHODS, NO_TYPE, -1, "methods"), $1, $2); $$ = tree; }
        | method_decl { $$ = $1; }
        ;
method_decl: ttype id '(' params ')' block {Tree *tree = newTree(newData(T_FUNCTION, $1->info->type, -1, $2->info->name), $4, $6); if(insertElem(&table, tree->info) && insertParams(&params, $2->info->name, $4)){ $$ = tree; } else {perror("wrong function declaration\n"); exit(1);} }
            | ttype id '(' params ')' EXTERN ';' { Tree *tree = newTree(newData(T_FUNCTION, $1->info->type, -1, $2->info->name), $4, newTree($6, NULL, NULL)); if(insertElem(&table, tree->info) && insertParams(&params, $2->info->name, $4)){ $$ = tree;} else {perror("wrong function declaration\n"); exit(1);} }
            | ttype id '('  ')' EXTERN ';' {Tree *tree = newTree(newData(T_FUNCTION, $1->info->type, -1, $2->info->name), NULL, newTree($5, NULL, NULL)); if(insertElem(&table, tree->info) && $1->info->type != NO_TYPE){ $$ = tree; } else {perror("wrong function declaration\n"); exit(1);} }
            | ttype id '(' ')' block {Tree *tree = newTree(newData(T_FUNCTION, $1->info->type, -1, $2->info->name), NULL, $5); if(insertElem(&table, tree->info)){ $$ = tree; } else {perror("wrong function declaration\n"); exit(1);} }
            ;
params: params ',' param  {$$ = newTree(newData(T_PARAMS, NO_TYPE, -1, "params"), $1, $3);}
        | param { $$ = $1; }
        ;

param: ttype id {TData *data = newData(T_PARAM, $1->info->type, -1, $2->info->name);  $$ = newTree(data, $1, $2); }
;
block: {LSE* newLevel = (LSE*)malloc(sizeof(LSE)); insertLevel(&table, newLevel);} block1 {removeLevel(&table); $$ = $2;}
block1: '{' vars statements '}'   {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "block"); Tree *tree = newTree(data, $2, $3); $$ = tree;}
     | '{' vars '}' {$$ = $2;}
     | '{' statements '}' {$$ = $2;}
     | '{' '}' {$$ = newTree(NULL, NULL, NULL);}
     ;

statements: statements single_statement {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "statements"); $$ = newTree(data, $1, $2);}
          | single_statement {$$ = $1;}
          ;

single_statement: id TASIGN expr ';' {$$ = newTree($2, $1, $3);}
                | method_call ';' {$$ = $1;}
                | TIF '(' expr ')' THEN block  {Tree *tree = newTree($1, $3, newTree($5, $6, NULL)); $$ = tree;}
                | TIF '(' expr ')' THEN block TELSE block {$$ = newTree($1, $3, newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body-if-else"), newTree($5, $6, NULL), newTree($7, $8, NULL)));}
                | TWHILE '(' expr ')' block {$$ = newTree($1, $3, $5);}
                | TRET expr ';' {$$ = newTree(newData(T_RET, -1, -1, "RET WITH VALUE"), $2, NULL);}
                | TRET ';' {$$ = newTree(newData(T_RET, -1, -1, "RET WITHOUT VALUE"), NULL, NULL);}
                | ';' {$$ = NULL;}
                | block {$$ = $1;}
                ;

method_call: { inFunction = 1; } method_call1 { inFunction = 0; $$ = $2; activeFunction = $2->info->name; }
            ;
method_call1: id '('exprs')' {TData* data = newData(T_METHODCALL, NO_TYPE, -1, $1->info->name); $$ = newTree(data, $3, NULL); }
            | id '(' ')' {TData* data = newData(T_METHODCALL, NO_TYPE, -1, $1->info->name); $$ = newTree(data, NULL, NULL);}
    ;
exprs: exprs ',' expr {TData* data = newData(T_EXPRS, NO_TYPE, -1, "exprs"); $$ = newTree(data, $1, $3);}
    | expr {$$ = $1;}
    ;

expr: 
     method_call {$$ = $1;}
    | literal {$$ = $1;}
    | expr TMAS expr    {$$ = newTree($2, $1, $3); $3->info = checkForID($3, INTEGER); $1->info = checkForID($1, INTEGER);}
    | expr TMENOS expr  {$$ = newTree($2, $1, $3); $3->info = checkForID($3, INTEGER); $1->info = checkForID($1, INTEGER);}
    | expr TDIV expr    {$$ = newTree($2, $1, $3); $3->info = checkForID($3, INTEGER); $1->info = checkForID($1, INTEGER);}
    | expr TMULT expr   {$$ = newTree($2, $1, $3); $3->info = checkForID($3, INTEGER); $1->info = checkForID($1, INTEGER);}
    | expr TAND expr    {$$ = newTree($2, $1, $3); $3->info = checkForID($3, BOOL); $1->info = checkForID($1, BOOL);}
    | expr TOR expr     {$$ = newTree($2, $1, $3); $3->info = checkForID($3, BOOL); $1->info = checkForID($1, BOOL);}
    | expr TMENOR expr  {$$ = newTree($2, $1, $3); $3->info = checkForID($3, INTEGER); $1->info = checkForID($1, INTEGER);}
    | expr TMAYOR expr  {$$ = newTree($2, $1, $3); $3->info = checkForID($3, INTEGER); $1->info = checkForID($1, INTEGER);}
    | expr TMOD expr    {$$ = newTree($2, $1, $3); $3->info = checkForID($3, INTEGER); $1->info = checkForID($1, INTEGER);}
    | expr TIGUAL expr  {$$ = newTree($2, $1, $3); $3->info = checkForID($3, INTEGER); $1->info = checkForID($1, INTEGER);}
    | id {$$ = $1; if((doesExist(table, $1->info->name) == -1)) {perror("no declarated var 2\n"); exit(1);} }
    | TMENOS expr %prec UMINUS  {$$ = newTree($1, $2, NULL); if($2->info->token == TID) {$2->info = findVariable(table, $2->info->name, INTEGER); if(!$2->info) {perror("no declarated var 3\n"); exit(1);}}}
    | TNEG expr %prec UMINUS {$$ = newTree($1, $2, NULL); if($2->info->token == TID) {$2->info = findVariable(table, $2->info->name, BOOL); if(!$2->info) {perror("no declarated var 4\n"); exit(1);}}}
    | '(' expr ')' {$$ = $2;}   
    ;

literal: boolValue {$$ = $1;}
        | INTV  {$$ = newTree($1, NULL, NULL); $$->info->type = INTEGER;}
        ;
boolValue: TR   {$$ = newTree($1, NULL, NULL); $$->info->value = 1; $$->info->type = BOOL;}
         | FAL  {$$ = newTree($1, NULL, NULL); $$->info->value = 0; $$->info->type = BOOL;}
         ;
id: TID     {$$ = newTree($1, NULL, NULL);}
    ;
ttype: TINT     {$$ = newTree($1, NULL, NULL); $$->info->type = INTEGER;}
    | TBOOL     {$$ = newTree($1, NULL, NULL); $$->info->type = BOOL;}
    | TVOID     {$$ = newTree($1, NULL, NULL); $$->info->type = VOID;}
    ;

