%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "calc-sintaxis.tab.h"

%}

%option noyywrap
%option yylineno

letra [a-zA-Z]      
digito [0-9]   
type int|bool
tr true 
fal false 
ret return
voidT void
main "main()"
extern extern
ifC if
then then
els else
wh while
%%

{digito}+                     { 
                                printf("INT value : %d\n",atoi(yytext)); 
                                return INTV;}

{ret} 						    { 
                                printf("Retorno : %s\n",yytext); 
                                return TRET;}

{ifC} 						    { 
                                printf("Retorno : %s\n",yytext); 
                                return TIF;}

{then} 						    { 
                                printf("Retorno : %s\n",yytext); 
                                return THEN;}

{els} 						    { 
                                printf("Retorno : %s\n",yytext); 
                                return TELSE;}
{wh} 						    { 
                                printf("Retorno : %s\n",yytext); 
                                return TWHILE;}
{type} 						{ 
                                printf("Decl : %s\n",yytext); 
                                return TTYPE;}

{voidT} 						{
                                printf("Void : %s\n",yytext); 
                                return TVOID;}		

{main} 						{ 
                                printf("MAIN : %s\n",yytext); 
                                return TMAIN;}				

{tr}                        {   printf("TRUE: %s\n", yytext);
                                return TR;}
{fal}						{
                                    printf("FALSE: %s\n",yytext);
                                    return FAL;}
{extern}                    {
                                printf("%s\n",yytext);
                                return EXTERN;
                                }
{letra}({letra}|{digito}|"_")*    { 
                                printf("ID : %s\n",yytext);
                                return TID;}

"<"                       {  
                                printf("%s\n",yytext);
                                return TMENOR;}    
">"                       {  
                                printf("%s\n",yytext);
                                return TMAYOR;}    
"=="                       {  
                                printf("%s\n",yytext);
                                return TIGUAL;}  
"-"                       {  
                                printf("%s\n",yytext);
                                return TMENOS;}    
"+"                       {  
                                printf("%s\n",yytext);
                                return TMAS;}    
"*"                       {  
                                printf("%s\n",yytext);
                                return TMULT;}    
"/"                       {  
                                printf("%s\n",yytext);
                                return TDIV;}    
"%"                       {  
                                printf("%s\n",yytext);
                                return TMOD;}    
"||"                       {  
                                printf("%s\n",yytext);
                                return TOR;}
"!"                       {  
                                printf("%s\n",yytext);
                                return TNEG;}    
                                    
"&&"                       {  
                                printf("%s\n",yytext);
                                return TAND;}    
                                                                                                                              

[+*;()={}]                   {  printf("%s\n",yytext);
                                  return *yytext;}



.|\n                          ; /* ignore all the rest */

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
