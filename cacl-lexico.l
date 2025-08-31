%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/tree.h"
#include "include/symbols_table.h"
#include "calc-sintaxis.tab.h"

int yyparse();
void yyerror();
void current_token(TOKENS token_symbol);

%}

%option noyywrap
%option yylineno

letra [a-zA-Z_]
digito [0-9]

%%

"extern"         			{ return EXTERN; }
"Program"                   { return PROGRAM; }
"main"						{ return MAIN; }
"return"                    { return RETURN; }

"if"         				{ return IF;   }
"then"                      { return THEN; }
"else"       				{ return ELSE; }
"while"                 	{ return WHILE; }



"void"                      { return TYPE_VOID; }
"int"                       { return TYPE_INT;  } 
"bool"                      { return TYPE_BOOL; }
"true"						{ current_token(CONSBOOL); return TTRUE;  }
"false"						{ current_token(CONSBOOL); return TFALSE; }


{digito}+     				{ current_token(CONSINT); return INT; }

{letra}({letra}|{digito})*  { yylval.symbol = CreateSymbol(strdup(yytext),EID,0,yylineno); return ID; }


"||"                        { return OR;  }
"&&"                        { return AND; }
"!"                   		{ return NOT; }
"=="                   		{ return EQ;  }
">"                   		{ return GREATER_THAN; }
"<"                   		{ return LESS_THAN; }


"="                         { return TASIGN; }
"-"                         { return TMINUS;     }
"+"                         { return TPLUS;       }
"*"                         { return TTIMES;       }
"/"                         { return TDIV;  }
"%"                         { return TMOD;     }

"("                         { return TPAR_OP;   }
")"                         { return TPAR_CL;   }
"{"                         { return TBRACE_OP; }
"}"                         { return TBRACE_CL; }

"//".*						
"/*"([^*]|[*][^/])*"*/"  	


[;,]                        { return *yytext; }

[#\$]                       { return -1; }

.|\n                      ; /** ignore **/

%%

void current_token(TOKENS token_symbol) {
	yylval.symbol = CreateSymbol(strdup(yytext),token_symbol,1,yylineno);
	if (token_symbol == CONSINT)
		setValue(yylval.symbol, atoi(yytext));
	else
		if(strcmp("true",strdup(yytext)) == 0){
			setValue(yylval.symbol, 1);
		}else {
			setValue(yylval.symbol, 0);
		}
}

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
