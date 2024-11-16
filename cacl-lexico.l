%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "calc-sintaxis.tab.h"
#include "libraries/tree.h"
%}

%option noyywrap
%option yylineno

letra [a-zA-Z]      
digito [0-9]   
intT integer
boolT bool
tr true 
fal false 
ret return
voidT void 
extern extern
ifC if
then then
els else
wh while
prog program
%%

{digito}+                     { 
                                TData *info = newData(T_INTV, INTEGER,atoi(yytext), strdup(yytext));
                                yylval.data = info;
                                printf("INT value : %d\n",atoi(yytext)); 
                                return INTV;}

{ret} 						    { 
                                TData *info = newData(T_RET, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("RETURN : %s\n",yytext); 
                                return TRET;
                                }

{ifC} 						    { 
                                TData *info = newData(T_IF, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("IF: %s\n",yytext); 
                                return TIF;
                                }

{then} 						    { 
                                TData *info = newData(T_THEN, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("THEN : %s\n",yytext); 
                                return THEN;}

{els} 						    { 
                                TData *info = newData(T_ELSE, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("ELSE: %s\n",yytext); 
                                return TELSE;}
{wh} 						    { 
                                TData *info = newData(T_WHILE, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("WHILE: %s\n",yytext); 
                                return TWHILE;}
{voidT} 						{
                                TData *info = newData(T_VOID, VOID, -1, strdup(yytext));
                                yylval.data = info;
                                printf("Void : %s\n",yytext); 
                                return TVOID;}	
{intT} 						{
                                TData *info = newData(T_INT, 1, -1, strdup(yytext));
                                yylval.data = info;
                                printf("Void : %s\n",yytext); 
                                return TINT;}	
{boolT} 						{
                                TData *info = newData(T_BOOL, BOOL, -1, strdup(yytext));
                                yylval.data = info;
                                printf("Void : %s\n",yytext); 
                                return TBOOL;}	 
{prog} 						{
                                TData *info = newData(T_PROGRAM, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("Void : %s\n",yytext); 
                                return T_PROGRAM;}                               				

{tr}                        {   
                                TData *info = newData(T_TRUE, BOOL, 1, strdup(yytext));
                                yylval.data = info;
                                printf("TRUE: %s\n", yytext);
                                return TR;}
{fal}						{
                                TData *info = newData(T_FAL, BOOL, 0, strdup(yytext));
                                yylval.data = info;
                                printf("FALSE: %s\n",yytext);
                                return FAL;}
{extern}                    {
                                TData *info = newData(T_EXTERN, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return EXTERN;
                                }
{letra}({letra}|{digito}|"_")*    { 
                                // yyval.data = (char*)
                                TData *info = newData(T_ID, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("ID : %s\n",yytext);
                                return TID;}

"<"                       {  
                                TData *info = newData(T_MENOR, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMENOR;}    
">"                       {  
                                TData *info = newData(T_MAYOR, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMAYOR;}    
"=="                       {  
                                TData *info = newData(T_IGUAL, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TIGUAL;}  
"-"                       {  
                                TData *info = newData(T_MENOS, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMENOS;}    
"+"                       {  
                                TData *info = newData(T_MAS, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMAS;}    
"*"                       {  
                                TData *info = newData(T_MULT, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMULT;}    
"/"                       {  
                                TData *info = newData(T_DIV, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TDIV;}    
"%"                       {  
                                TData *info = newData(T_MOD, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMOD;}    
"||"                       {  
                                TData *info = newData(T_OR, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TOR;}
"!"                       {  
                                TData *info = newData(T_NEG, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TNEG;}    
                                    
"&&"                       {  
                                TData *info = newData(T_AND, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TAND;}    
                                                                                                                              
"="                         {
                                TData *info = newData(T_ASIGN, NO_TYPE, -1, strdup(yytext));
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TASIGN;

                            }

[;()={},]                   {       
                                printf("%s\n",yytext);
                               return *yytext;} 



" "|\t|\n                          ; /* ignore all the rest */
.                           {yyerror();}
%%

void yyerror(){
	printf("%s%d\n","-> ERROR Sintactico en la linea: ",yylineno);
}

int main(int argc,char *argv[]){
	++argv,--argc;
	if (argc > 0)
		yyin = fopen(argv[0],"r");
	else
		yyin = stdin;

	yyparse();

}
