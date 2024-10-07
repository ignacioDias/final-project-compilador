%{

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

%}
%code requires {#include "tree.h"}

%union{int i; int b; Tree *tree; char *s; TData *data}

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

program: TPROGRAM '{' vars methods '}'             {Tree *tree = newTree($1, $3, $4); printTree(tree);}
       |  TPROGRAM '{' methods '}'                  {Tree *tree = newTree($1, $3, NULL); printTree(tree);}
       | TPROGRAM block                        {Tree *tree = newTree($1, $2, NULL); printTree(tree);}
       ;

vars: vars var_decl   {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, ""); Tree *tree = newTree(data, $1, $2); $$ = tree;}
    | var_decl  {$$ = $1;}
    ;

var_decl:
    ttype id TASIGN expr ';' {Tree *leftChild = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "var declaration"), $1, $2); Tree *tree = newTree($3, leftChild, $4); $$ = tree;}
    |ttype id ';' {$$ = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "var declaration"), $1, $2);}
    ;

methods: methods method_decl  {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "methods"); Tree *tree = newTree(data, $1, $2); $$ = tree;}
        | method_decl  {$$ = $1;}
        ;

method_decl: ttype id '(' params ')' block {Tree *tree = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body"), $4, $6); $$ = newTree($2->info, $1, tree); }
            | ttype id '(' params ')' EXTERN ';' {Tree *tree = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body"), $4, NULL); $$ = newTree($2->info, $1, tree);}
            ;

params: params ',' param  {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "params"); Tree *tree = newTree(data, $1, $3); $$ = tree;}
        | param {$$ = $1;}
        ;

param: ttype id {$$ = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "params"), $1, $2);}
;

block: '{' vars statements '}'   {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "block"); Tree *tree = newTree(data, $2, $3); $$ = tree;}
     | '{' vars '}' {$$ = $2;}
     | '{' statements '}' {$$ = $2;}
     | '{' '}' {$$ = newTree(NULL, NULL, NULL);}
     ;

statements: statements single_statement {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "statements"); $$ = newTree(data, $1, $2);}
          | single_statement {$$ = $1;}
          ;

single_statement: id TASIGN expr ';' {$$ = newTree($2, $1, $3);}
                | method_call ';' {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "single_statement"); $$ = newTree(data, $1, NULL);}
                | TIF '(' expr ')' THEN block  {Tree *tree = newTree($1, $3, $6); printTree(tree);}
                | TIF '(' expr ')' THEN block TELSE block {Tree *tree = newTree($1, $3, newTree($7, $6, $8)); $$ = tree;}
                | TWHILE '(' expr ')' block {Tree *tree = newTree($1, $3, $5); $$ = tree;}
                | TRET ';' {$$ = newTree($1, NULL, NULL);}
                | TRET expr ';' {$$ = newTree($1, $2, NULL);}
                | ';' {$$ = NULL;}
                | block {$$ = $1;}
                ;

method_call: id '('exprs')' {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "method_call"); $$ = newTree(data, $1, $3);}
    ;
exprs: exprs ',' expr {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "exprs"); $$ = newTree(data, $1, $3);}
    | expr {$$ = $1;}
    ;

expr: id {$$ = $1;}
    | method_call {$$ = $1;}
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