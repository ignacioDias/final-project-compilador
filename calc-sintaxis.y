%{
#include <stdlib.h>
#include <stdio.h>
#include "include/tree.h"
#include "include/symbols_table.h"
#include "include/pseudo_assembly.h"

SymbolsTable* table;
SymbolsTable* parameters;
AssemblyList *pseudoAssembly;
void setTypeFunction(Type type);

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
program1: {table = (SymbolsTable*)malloc(sizeof(SymbolsTable)); parameters = (SymbolsTable*)malloc(sizeof(SymbolsTable)); pseudoAssembly = (AssemblyList*)malloc(sizeof(AssemblyList)); LSE* newLevel = (LSE*)malloc(sizeof(LSE)); insertLevel(&table, newLevel); }  program   {removeLevel(&table);}
program: TPROGRAM '{' vars methods '}'  {$$ = newTree($1, $3, $4); evalType($$);  printTree($$); showTable(table); generatePseudoAssembly(&pseudoAssembly, $$); printAssemblyList(&pseudoAssembly);}
       |  TPROGRAM  '{' methods '}' {$$ = newTree($1, $3, NULL); evalType($$); printTree($$); showTable(table); generatePseudoAssembly(&pseudoAssembly, $$); printAssemblyList(&pseudoAssembly);}
       ;
vars: vars var_decl   {TData* data = newData(T_DECL, NO_TYPE, -1, "vars"); $$ = newTree(data, $1, $2);}
    | var_decl  {$$ = $1;}
    ;
var_decl:
    ttype id TASIGN expr ';' { if(insertElem(&table, newData($2->info->token, $1->info->type, $4->info->value, $2->info->name))) {

                                Tree *leftChild = newTree(newData(T_DECL, $1->info->type, -1, "var declaration + asign"), $1, $2); $$ = newTree($3, leftChild, $4);
                            } else {
                                    perror("Re-declaration"); exit(1);}}
    |ttype id ';' {if(insertElem(&table, newData($2->info->token, $1->info->type, -1, $2->info->name))){$$ = newTree(newData(T_DECL, NO_TYPE, -1, "var declaration"), $1, $2);} else {perror("var already exists");exit(1);}}
    ;
methods: methods method_decl  {Tree *tree = newTree(newData(T_METHODS, NO_TYPE, -1, "methods"), $1, $2); $$ = tree;}
        | method_decl  {$$ = $1;}
        ;
method_decl: ttype id '(' params ')' block {Tree *tree = newTree(newData(T_FUNCTION, $1->info->type, -1, $2->info->name), $4, $6); if(insertElem(&table, tree->info)){ $$ = tree; } else {perror("wrong function declaration\n"); exit(1);} }
            | ttype id '(' params ')' EXTERN ';' { Tree *tree = newTree(newData(T_FUNCTION, $1->info->type, -1, $2->info->name), $4, NULL); if(insertElem(&table, tree->info)){ $$ = tree;} else {perror("wrong function declaration\n"); exit(1);} }
            | ttype id '('  ')' EXTERN ';' {Tree *tree = newTree(newData(T_FUNCTION, $1->info->type, -1, $2->info->name), NULL, NULL); if(insertElem(&table, tree->info) && $1->info->type != NO_TYPE){ $$ = tree; } else {perror("wrong function declaration\n"); exit(1);} }
            | ttype id '(' ')' block {Tree *tree = newTree(newData(T_FUNCTION, $1->info->type, -1, $2->info->name), NULL, $5); if(insertElem(&table, tree->info)){ $$ = tree; } else {perror("wrong function declaration\n"); exit(1);} }
            ;
params: params ',' param  {TData* data = newData(T_PARAMS, NO_TYPE, -1, "params"); Tree *tree = newTree(data, $1, $3); $$ = tree; }
        | param {$$ = $1; }
        ;

param: ttype id {if(insertElem(&parameters, newData(T_PARAM, $1->info->type,-1 ,$2->info->name))) {$$ = newTree(newData(T_YYUNDEF, NO_TYPE, -1, $2->info->name), $1, $2);} else {printf("The parameter does already exist");}}
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
method_call: id '('exprs')' {TData* data = newData(T_METHODCALL, NO_TYPE, -1, $1->info->name); $$ = newTree(data, $3, NULL); }
            | id '(' ')' {TData* data = newData(T_METHODCALL, NO_TYPE, -1, $1->info->name); $$ = newTree(data, NULL, NULL);}
    ;
exprs: exprs ',' expr {TData* data = newData(T_EXPRS, NO_TYPE, -1, "exprs"); $$ = newTree(data, $1, $3);}
    | expr {$$ = $1;}
    ;

expr: 
     method_call {$$ = $1;}
    | literal {$$ = $1;}
    | expr TMAS expr    {$$ = newTree($2, $1, $3); }
    | expr TMENOS expr  {$$ = newTree($2, $1, $3); }
    | expr TDIV expr    {$$ = newTree($2, $1, $3); }
    | expr TMULT expr   {$$ = newTree($2, $1, $3); }
    | expr TAND expr    {$$ = newTree($2, $1, $3); }
    | expr TOR expr     {$$ = newTree($2, $1, $3); }
    | expr TMENOR expr  {$$ = newTree($2, $1, $3); }
    | expr TMAYOR expr  {$$ = newTree($2, $1, $3); }
    | expr TMOD expr    {$$ = newTree($2, $1, $3); }
    | expr TIGUAL expr  {$$ = newTree($2, $1, $3); }
    | id {$$ = $1; if((doesExist(table, $1->info->name) == -1) && (doesExist(parameters, $1->info->name) == -1)) {perror("no declarated var\n"); exit(1);}}
    | TMENOS expr %prec UMINUS  {$$ = newTree($1, $2, NULL); }
    | TNEG expr %prec UMINUS {$$ = newTree($1, $2, NULL); }
    | '(' expr ')' {$$ = $2;}   
    ;

literal: boolValue {$$ = $1;}
        | INTV  {$$ = newTree($1, NULL, NULL); $$->info->type = INTEGER;}
        ;
boolValue: TR   {$$ = newTree($1, NULL, NULL); $$->info->value = 1; $$->info->type = BOOL;}
         | FAL  {$$ = newTree($1, NULL, NULL); $$->info->value = 0; $$->info->type = BOOL;}
         ;
id: TID     {$$ = newTree($1, NULL, NULL); }
    ;
ttype: TINT     {$$ = newTree($1, NULL, NULL); $$->info->type = INTEGER;}
    | TBOOL     {$$ = newTree($1, NULL, NULL); $$->info->type = BOOL;}
    | TVOID     {$$ = newTree($1, NULL, NULL); $$->info->type = VOID;}
    ;