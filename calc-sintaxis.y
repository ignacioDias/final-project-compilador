%{

#include <stdlib.h>
#include <stdio.h>

%}
%token INT
%token TRET
%token TDECL
%token TVOID
%token TMAIN
%token BOOLV
%token TID
%token TMENOR
%token TMAYOR
%token TIGUAL
%token TMENOS
%token TMAS
%token TMULT
%token TDIV
%token TMOD
%token TOR
%token TNEG
%token TAND

%%

program: program '{' vars methods '}'
       |  program '{' methods '}'
       | program '{' vars '}'
       | program '{' '}'
       ;

vars: vars var_decl 
    | var_decl
    ;

var_decl:
    type id '=' expr ';'
    ;

methods: methods method_decl 
        | method_decl
        ;

method_decl: type id '(' params ')' block
            | type id '(' params ')' extern ';'
            ;

params: param ', ' params
        | param
        ;

param: type id
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
                | method_call
                | IF '(' expr ')' THEN block
                | IF '(' expr ')' THEN block ELSE block
                | WHILE '(' expr ')' block
                | RETURN ';'
                | RETURN expr ';'
                | ';'
                | block
                ;

method_call: id '('exprs')'
    ;
exprs: exprs expr ', '
    | expr
    ;

expr: id
    | method_call
    | literal
    | expr bin_op expr
    | TMENOS expr
    | TNEG expr
    | '(' expr ')'
    ;

bin_op: arit_op
        | rel_op
        | cond_op
        ;

arit_op: TMAS
        | TMENOS
        | TMULT
        | TDIV
        | TMOD
        ;
    
rel_op: TMENOR
        | TMAYOR
        | TIGUAL
        ;

cond_op: TAND
        | TOR
        ;

literal: BOOLV
        | INT
        ;

id: TID
    ;
type: TTYPE
    | TVOID
    ;