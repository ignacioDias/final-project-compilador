%{

#include <stdlib.h>
#include <stdio.h>

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

program: program '{' vars methods '}'
       |  program '{' methods '}'
       | program '{' vars '}'
       | '{' '}'
       ;

vars: vars var_decl 
    | var_decl
    ;

var_decl:
    ttype id '=' expr ';'
    ;

methods: methods method_decl 
        | method_decl
        ;

method_decl: ttype id '(' params ')' block
            | ttype id '(' params ')' EXTERN ';'
            ;

params: params ',' param
        | param
        ;

param: ttype id
;

block: '{' vars statements '}'
     | '{' vars '}'
     | '{' statements '}'
     | '{' '}'
     ;

statements: statements single_statement
          | single_statement
          ;

single_statement: id '=' expr ';'
                | method_call ';'
                | TIF '(' expr ')' THEN block
                | TIF '(' expr ')' THEN block TELSE block
                | TWHILE '(' expr ')' block
                | TRET ';'
                | TRET expr ';'
                | ';'
                | block
                ;

method_call: id '('exprs')'
    ;
exprs: exprs ',' expr
    | expr
    ;

expr: id
    | method_call
    | literal
    | expr TMAS expr
    | expr TMENOS expr
    | expr TDIV expr
    | expr TMULT expr
    | expr TAND expr
    | expr TOR expr
    | expr TMENOR expr
    | expr TMOD expr
    | expr TMAYOR expr
    | expr TIGUAL expr
    | TMENOS expr %prec UMINUS
    | TNEG expr %prec UMINUS
    | '(' expr ')'
    ;

literal: boolValue
        | INTV
        ;
boolValue: TR
         | FAL
         ;
id: TID
    ;
ttype: TINT
    | TBOOL
    | TVOID
    ;