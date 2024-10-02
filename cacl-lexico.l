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
voidT void //TODO: PREGUNTAR
main "main()"
extern extern
ifC if
then then
els else
wh while
%%

{digito}+                     { 
                                TData *info = newData(INTV, INTEGER,atoi(yytext), yytext);
                                yylval.data = info;
                                printf("INT value : %d\n",atoi(yytext)); 
                                return INTV;}

{ret} 						    { 
                                TData *info = newData(TRET, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("RETURN : %s\n",yytext); 
                                return TRET;
                                }

{ifC} 						    { 
                                TData *info = newData(TIF, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("IF: %s\n",yytext); 
                                return TIF;
                                }

{then} 						    { 
                                TData *info = newData(THEN, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("THEN : %s\n",yytext); 
                                return THEN;}

{els} 						    { 
                                TData *info = newData(TELSE, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("ELSE: %s\n",yytext); 
                                return TELSE;}
{wh} 						    { 
                                TData *info = newData(TWHILE, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("WHILE: %s\n",yytext); 
                                return TWHILE;}
{type} 						{ 
                                Type type = NO_TYPE;
                                if(strcmp(yytext, "int") == 0) {
                                    type = INTEGER;
                                } else if(strcmp(yytext, "bool") == 0) {
                                    type = BOOL;
                                } else if(strcmp(yytext, "void") == 0) {
                                    type = VOID;
                                }
                                TData *info = newData(TTYPE, type, -1, yytext);
                                yylval.data = info;
                                printf("Decl : %s\n",yytext); 
                                return TTYPE;}
{voidT} 						{
                                TData *info = newData(TVOID, VOID, -1, yytext);
                                yylval.data = info;
                                printf("Void : %s\n",yytext); 
                                return TVOID;}		

{main} 						{ 
                                TData *info = newData(TMAIN, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("MAIN : %s\n",yytext); 
                                return TMAIN;}				

{tr}                        {   
                                TData *info = newData(TR, BOOL, 1, yytext);
                                yylval.data = info;
                                printf("TRUE: %s\n", yytext);
                                return TR;}
{fal}						{
                                TData *info = newData(FAL, BOOL, 0, yytext);
                                yylval.data = info;
                                printf("FALSE: %s\n",yytext);
                                return FAL;}
{extern}                    {
                                TData *info = newData(EXTERN, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return EXTERN;
                                }
{letra}({letra}|{digito}|"_")*    { 
                                TData *info = newData(TID, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("ID : %s\n",yytext);
                                return TID;}

"<"                       {  
                                TData *info = newData(TMENOR, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMENOR;}    
">"                       {  
                                TData *info = newData(TMAYOR, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMAYOR;}    
"=="                       {  
                                TData *info = newData(TIGUAL, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TIGUAL;}  
"-"                       {  
                                TData *info = newData(TMENOS, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMENOS;}    
"+"                       {  
                                TData *info = newData(TMAS, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMAS;}    
"*"                       {  
                                TData *info = newData(TMULT, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMULT;}    
"/"                       {  
                                TData *info = newData(TDIV, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TDIV;}    
"%"                       {  
                                TData *info = newData(TMOD, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TMOD;}    
"||"                       {  
                                TData *info = newData(TOR, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TOR;}
"!"                       {  
                                TData *info = newData(TNEG, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TNEG;}    
                                    
"&&"                       {  
                                TData *info = newData(TAND, NO_TYPE, -1, yytext);
                                yylval.data = info;
                                printf("%s\n",yytext);
                                return TAND;}    
                                                                                                                              

[;()={}]                   {  printf("%s\n",yytext);
                                  return *yytext;} //TODO: PREGUNTAR



.|\n                          ; /* ignore all the rest *///TODO: PREGUNTAR

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
