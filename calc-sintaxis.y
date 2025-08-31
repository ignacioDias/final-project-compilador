%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/tree.h"
#include "include/pseudo_assembly.h"
void compilador(Tree *tree);
Tree* createTreeWhitSymbol(char * name,TOKENS token,int size, int line, Tree *l, Tree *r);
extern int yylineno;
int blockNum = 0;
%}

%union {
    TData* symbol;
    Tree *tree;
}

/*declaraciones*/
%token <symbol> ID

/* tipos de datos */
%token <symbol> INT
%token <symbol> TTRUE
%token <symbol> TFALSE
%token TYPE_INT
%token TYPE_BOOL
%token TYPE_VOID

/* simbolos */
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

/* palabras reservadas */
%token PROGRAM
%token EXTERN
%token THEN
%token IF
%token ELSE
%token WHILE
%token RETURN
%token MAIN


/* presedencias */
%left OR AND                // ||, &&
%left EQ                    // ==
%left GREATER_THAN LESS_THAN     // >,<
%left TPLUS TMINUS           // +, -
%left TTIMES TDIV TMOD // *, /, %
%right NOT                  // La negación es asociativa a la derecha

/*Types*/
%type <tree> prog main retorno
%type <tree> call_func expr
%type <tree> asignacion valor argumento
%type <tree> declaracion sentencia dec_parametro declare_funcion
%type <tree> list_decls list_sents list_func parametros
%type <tree> if_else while block

%%

prog: PROGRAM TBRACE_OP list_decls list_func main TBRACE_CL  { char * name = "PROGRAM_BLOCK"; Tree* aux= createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,$4, $5);
                                                              char * name1 = "PROGRAM"; compilador(createTreeWhitSymbol(name1,EPROGRAM,blockNum,yylineno,$3, aux));}
    | PROGRAM TBRACE_OP  main TBRACE_CL  {char * name = "PROGRAM"; compilador(createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,NULL, $3));}
    | PROGRAM TBRACE_OP  list_func main TBRACE_CL  {char * name = "PROGRAM"; compilador(createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,$3, $4));}
    | PROGRAM TBRACE_OP list_decls  main TBRACE_CL  {char * name = "PROGRAM"; compilador(createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,$3, $4));}
    ;

main: TYPE_BOOL MAIN TPAR_OP TPAR_CL block  { char * name = "main";$$ = createTreeWhitSymbol(name,RETBOL,blockNum,yylineno,$5, NULL);}
    | TYPE_INT MAIN TPAR_OP TPAR_CL block   { char * name = "main";$$ = createTreeWhitSymbol(name,RETINT,blockNum,yylineno,$5, NULL);}
    | TYPE_VOID MAIN TPAR_OP TPAR_CL block  { char * name = "main";$$ = createTreeWhitSymbol(name,RETVOID,blockNum,yylineno,$5, NULL);}
    ;

list_decls: declaracion              {char * name = "DECLARACION"; $$ = createTreeWhitSymbol(name,DECLARATION,blockNum,yylineno,$1, NULL);}
          | list_decls declaracion   {char * name = "DECLARACION"; $$ = createTreeWhitSymbol(name,DECLARATION,blockNum,yylineno,$1, $2);}
          ;

list_sents:                                     {$$ = NULL;}
          |list_sents sentencia                 {char * name = "SENTENCIA"; $$ = createTreeWhitSymbol(name,SENTEN,blockNum,yylineno,$1, $2);}
          ;

block: TBRACE_OP list_decls list_sents TBRACE_CL  { char *name1 = "BLOCK_FIN"; Tree*aux = createTreeWhitSymbol(name1,BLOCK_FIN,blockNum,yylineno,NULL, NULL);
                                                    char *name2 = "BLOCK_INTERNO"; Tree*aux2 = createTreeWhitSymbol(name2,OTHERS,blockNum,yylineno,$2, $3);
                                                    char *name = "BLOCK"; $$ = createTreeWhitSymbol(name,BLOCK,blockNum,yylineno,aux2, aux); }
     | TBRACE_OP list_sents TBRACE_CL             { char *name1 = "BLOCK_FIN"; Tree*aux = createTreeWhitSymbol(name1,BLOCK_FIN,blockNum,yylineno,NULL, NULL);
                                                    char *name = "BLOCK"; $$ = createTreeWhitSymbol(name,BLOCK,blockNum,yylineno,$2, aux); }
     ;

sentencia: asignacion                               {$$ = $1;}
         | retorno                                  {$$ = $1;}
         | if_else                                  {$$ = $1;}
         | while                                    {$$ = $1;}
         | call_func ';'                            {$$ = $1;}
         ;

asignacion: ID TASIGN expr ';' {char * name = $1->varname;Tree* aux3 = createTreeWhitSymbol(name,EID,blockNum,yylineno,NULL, NULL);
                                    char * nameAsig = "asignacion";$$ = createTreeWhitSymbol(nameAsig,ASIGN,1,yylineno,aux3, $3);}
          ;

call_func : ID TPAR_OP argumento TPAR_CL {char * name = $1->varname;Tree* aux3 = createTreeWhitSymbol(name,EFUNC,blockNum,yylineno,NULL, NULL);
                                    char * nameCall = "LLAMADA_FUNC";$$ = createTreeWhitSymbol(nameCall,CALL_F,blockNum,yylineno,aux3, $3);}
          ;

declaracion: TYPE_INT ID ';'  {char * name = $2->varname; $$ = createTreeWhitSymbol(name,VARINT,blockNum,yylineno,NULL, NULL);}
           | TYPE_BOOL ID ';' {char * name = $2->varname;$$ = createTreeWhitSymbol(name,VARBOOL,blockNum,yylineno,NULL, NULL);}
           ;


argumento:                         {$$ = NULL;}
         | expr                    {$$ = $1;}
         | argumento ',' expr      {char * name = "arguments"; $$ = createTreeWhitSymbol(name,ARGS, blockNum, yylineno, $1, $3);}
         ;


parametros:                                 {$$ = NULL;}
          | dec_parametro                   {$$ = $1;}
          | dec_parametro ',' parametros    {char * name = "PARAMETROS"; $$ = createTreeWhitSymbol(name,DECLARATION,blockNum,yylineno,$1, $3);}
          ;

dec_parametro : TYPE_INT ID  {char * name = $2->varname; $$ = createTreeWhitSymbol(name,PARAMINT,blockNum,yylineno,NULL, NULL);}
              | TYPE_BOOL ID  {char * name = $2->varname;$$ = createTreeWhitSymbol(name,PARAMBOOL,blockNum,yylineno,NULL, NULL);}
              ;



list_func: declare_funcion                  {char * name = "LIS_FUNCION";$$ = createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,$1, NULL);}                //modificar esto
         | list_func declare_funcion        {char * name = "LIS_FUNCION";$$ = createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,$1, $2);}                //modificar esto
         ;

declare_funcion: TYPE_INT ID TPAR_OP parametros TPAR_CL block           { char * nameAux = $2->varname; $$ = createTreeWhitSymbol(nameAux, RETINT, blockNum, yylineno, $4, $6);}
               | TYPE_BOOL ID TPAR_OP parametros TPAR_CL block          { char * nameAux = $2->varname; $$ = createTreeWhitSymbol(nameAux, RETBOL, blockNum, yylineno, $4, $6);}
               | TYPE_VOID ID TPAR_OP parametros TPAR_CL block          { char * nameAux = $2->varname; $$ = createTreeWhitSymbol(nameAux, RETVOID, blockNum, yylineno, $4, $6);}
               | TYPE_INT ID TPAR_OP parametros TPAR_CL EXTERN ';'      { char * name = $2->varname;$$ = createTreeWhitSymbol(name,EXTINT,blockNum-1,yylineno,$4, NULL);}
               | TYPE_BOOL ID TPAR_OP parametros TPAR_CL EXTERN ';'     { char * name = $2->varname;$$ = createTreeWhitSymbol(name,EXTBOL,blockNum-1,yylineno,$4, NULL);}
               | TYPE_VOID ID TPAR_OP parametros TPAR_CL EXTERN ';'     { char * name = $2->varname;$$ = createTreeWhitSymbol(name,EXTVOID,blockNum-1,yylineno,$4, NULL);}
               ;


expr: valor                     {$$ = $1;}
    | call_func                 {$$ = $1;}
    | expr TPLUS expr            {char * name = "+"; $$ = createTreeWhitSymbol(name,PLUS,blockNum,yylineno,$1, $3);}
    | expr TMINUS expr          {char * name = "-"; $$ = createTreeWhitSymbol(name,MINUS,blockNum,yylineno,$1, $3);}
    | expr TTIMES expr            {char * name = "*"; $$ = createTreeWhitSymbol(name,PROD,blockNum,yylineno,$1, $3);}
    | expr TDIV expr       {char * name = "/"; $$ = createTreeWhitSymbol(name,EDIV,blockNum,yylineno,$1, $3);}
    | expr TMOD expr          {char * name = "%"; $$ = createTreeWhitSymbol(name,EMOD,blockNum,yylineno,$1, $3);}
    | expr GREATER_THAN expr        {char * name = ">"; $$ = createTreeWhitSymbol(name,GREATER_THAN,blockNum,yylineno,$1, $3);}
    | expr LESS_THAN expr        {char * name = "<"; $$ = createTreeWhitSymbol(name,LESS_THAN,blockNum,yylineno,$1, $3);}
    | expr EQ expr              {char * name = "=="; $$ = createTreeWhitSymbol(name,EEQ,blockNum,yylineno,$1, $3);}
    | expr AND expr             {char * name = "&&"; $$ = createTreeWhitSymbol(name,EAND,blockNum,yylineno,$1, $3);}
    | expr OR expr              {char * name = "||"; $$ = createTreeWhitSymbol(name,EOR,blockNum,yylineno,$1, $3);}
    | NOT expr                  {char * name = "!"; $$ = createTreeWhitSymbol(name,ENOT,blockNum,yylineno,$2, NULL);}
    | TPAR_OP expr TPAR_CL      {$$ = $2;}
    ;


valor: INT                      {$$ = createTree($1, NULL, NULL);}
     | ID                       {$$ = createTree($1, NULL, NULL);}
     | TMINUS INT               {int len = strlen($2->varname); char* newVarname = (char*)malloc(len + 2);
                                 newVarname[0] = '-'; strcpy(newVarname + 1, $2->varname);
                                 $2->varname = newVarname;
                                 $2->value = $2->value * - 1; $$ = createTree($2, NULL, NULL);}
     | TTRUE                    {$$ = createTree($1, NULL, NULL);}
     | TFALSE                   {$$ = createTree($1, NULL, NULL);}
     ;

retorno: RETURN expr ';' {char * name = "return";$$ = createTreeWhitSymbol(name,ERETURN,blockNum,yylineno,$2, NULL);}
       ;

if_else: IF TPAR_OP expr TPAR_CL THEN block {char * name = "if_then"; $$ = createTreeWhitSymbol(name,EIF,blockNum,yylineno,$3, $6);}
       | IF TPAR_OP expr TPAR_CL THEN block ELSE block { char * name = "then"; char * name2 = "else";
                                                         Tree* aux_else = createTreeWhitSymbol(name2,EELSE,blockNum,yylineno,$8, NULL);
                                                         Tree* aux_then = createTreeWhitSymbol(name,ETHEN,blockNum,yylineno,$6, aux_else);
                                                         char * name3 = "if_else"; $$ = createTreeWhitSymbol(name3,EIF,blockNum,yylineno,$3, aux_then);}
       ;

while: WHILE TPAR_OP expr TPAR_CL block {char * name = "while"; $$ = createTreeWhitSymbol(name,EWHILE,blockNum,yylineno,$3, $5);}
     ;

%%

void compilador(Tree* ar){
    printDot(ar,"output/Arbol.dot");
    createTable(ar);
    retError();
    if(getError()) {
       elimArbol(ar);
       exit(1);
    }
    generateThreeDir(ar);
    printAsembler();
    generateAssembler();
    deleteInstructions();
    elimArbol(ar);
}

Tree* createTreeWhitSymbol(char * name,TOKENS token,int size, int line, Tree *l, Tree *r){
    TData* aux = CreateSymbol(name,token,0,yylineno);
    return createTree(aux,l,r);
}

