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

program: program '{' vars methods '}'             {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "program"); Tree *tree = newTree(data, $2, $3); showTree(tree);}
       |  program '{' methods '}'                  {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "program"); Tree *tree = newTree(data, $1, $3); showTree(tree);}
       | program '{' vars '}'                        {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "program"); Tree *tree = newTree(data, $1, $3); showTree(tree);}
       | '{' '}'                                     {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "program"); Tree *tree = newTree(data, NULL, NULL); showTree(tree);}
       ;

vars: vars var_decl   {TData* data = newData(T, NO_TYPE, -1, "program"); Tree *tree = newTree(data, $1, $3); showTree(tree);}
    | var_decl  {$$ = $1;}
    ;

var_decl:
    ttype id '=' expr ';'
    ;

methods: methods method_decl 
        | method_decl  {$$ = $1;}
        ;

method_decl: ttype id '(' params ')' block
            | ttype id '(' params ')' EXTERN ';'
            ;

params: params ',' param
        | param {$$ = $1;}
        ;

param: ttype id
;

block: '{' vars statements '}' 
     | '{' vars '}' {$$ = $2;}
     | '{' statements '}' {$$ = $2;}
     | '{' '}'
     ;

statements: statements single_statement {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "statements"); $$ = newTree(data, $1, $3);}
          | single_statement {$$ = $1;}
          ;

single_statement: id '=' expr ';' {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "single_statement"); $$ = newTree(data, $1, $3);}
                | method_call ';' {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "single_statement"); $$ = newTree(data, $1, NULL);}
                | TIF '(' expr ')' THEN block
                | TIF '(' expr ')' THEN block TELSE block
                | TWHILE '(' expr ')' block 
                | TRET ';' {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "single_statement"); $$ = newTree(data, $1, NULL);}
                | TRET expr ';' {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "single_statement"); $$ = newTree(data, $1, $2);}
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
    | expr TMAS expr    {TData* data = newData(T_SUMA, INTEGER, 0, "suma"); $$ = newTree(data, $1, $3); }
    | expr TMENOS expr  {TData* data = newData(T_RESTA, INTEGER, 0, "resta"); $$ = newTree(data, $1, $3); }
    | expr TDIV expr    {TData* data = newData(T_DIV, INTEGER, 0, "división"); $$ = newTree(data, $1, $3); }
    | expr TMULT expr   {TData* data = newData(T_MULT, INTEGER, 0, "multiplicación"); $$ = newTree(data, $1, $3); }
    | expr TAND expr    {TData* data = newData(T_AND, BOOL, 0, "and"); $$ = newTree(data, $1, $3); }
    | expr TOR expr     {TData* data = newData(T_OR, BOOL, 0, "or"); $$ = newTree(data, $1, $3); }
    | expr TMENOR expr  {TData* data = newData(T_MENOR, BOOL, 0, "menor"); $$ = newTree(data, $1, $3); }
    | expr TMAYOR expr  {TData* data = newData(T_MAYOR, BOOL, 0, "mayor"); $$ = newTree(data, $1, $3); }
    | expr TMOD expr    {TData* data = newData(T_MOD, INTEGER, 0, "módulo"); $$ = newTree(data, $1, $3); }
    | expr TIGUAL expr  {TData* data = newData(T_RESTA, BOOL, 0, "equals"); $$ = newTree(data, $1, $3); }
    | TMENOS expr %prec UMINUS  {TData* data = newData(T_RESTA, INTEGER, 0, "negativo"); $$ = newTree(data, $1, $3); }
    | TNEG expr %prec UMINUS {TData* data = newData(T_NEG, BOOL, 0, "negación"); $$ = newTree(data, $1, $3); }
    | '(' expr ')' {$$ = $2;}   
    ;

literal: boolValue {$$ = $1;}
        | INTV  {$$ = newTree($1); $$->info->type = INTEGER;}
        ;
boolValue: TR   {$$ = newTree($1); $$->info->value = True; $$->info->type = BOOL;}
         | FAL  {$$ = newTree($1); $$->info->value = False; $$->info->type = BOOL;}
         ;
id: TID
    ;
ttype: TINT     {$$ = newTree($1); $$->info->type = INTEGER;}
    | TBOOL     {$$ = newTree($1); $$->info->type = BOOL;}
    | TVOID     {$$ = newTree($1); $$->info->type = VOID;}
    ;