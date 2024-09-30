%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "calc-sintaxis.tab.h" 
#include "tree.h"
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


%%

{digito}+                     { 
                                printf("INT : %d\n",atoi(yytext)); 
                                return INT;}

{ret} 						    { 
                                printf("Retorno : %s\n",yytext); 
                                return TRET;}

{type} 						{ 
                                printf("Decl : %s\n",yytext); 
                                return TDECL;}

{voidT} 						{
                                printf("Void : %s\n",yytext); 
                                return TVOID;}		

{main} 						{ 
                                printf("MAIN : %s\n",yytext); 
                                return TMAIN;}				

{tr}|{fal}						{
                                    printf("BOOL: %s\n",yytext);
                                    return BOOLV;}

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
