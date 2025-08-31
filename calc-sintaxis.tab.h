/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CALC_SINTAXIS_TAB_H_INCLUDED
# define YY_YY_CALC_SINTAXIS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INT = 259,                     /* INT  */
    TTRUE = 260,                   /* TTRUE  */
    TFALSE = 261,                  /* TFALSE  */
    TYPE_INT = 262,                /* TYPE_INT  */
    TYPE_BOOL = 263,               /* TYPE_BOOL  */
    TYPE_VOID = 264,               /* TYPE_VOID  */
    TPLUS = 265,                   /* TPLUS  */
    TTIMES = 266,                  /* TTIMES  */
    TMINUS = 267,                  /* TMINUS  */
    TDIV = 268,                    /* TDIV  */
    TMOD = 269,                    /* TMOD  */
    TASIGN = 270,                  /* TASIGN  */
    TPAR_OP = 271,                 /* TPAR_OP  */
    TPAR_CL = 272,                 /* TPAR_CL  */
    TBRACE_OP = 273,               /* TBRACE_OP  */
    TBRACE_CL = 274,               /* TBRACE_CL  */
    OR = 275,                      /* OR  */
    AND = 276,                     /* AND  */
    NOT = 277,                     /* NOT  */
    GREATER_THAN = 278,            /* GREATER_THAN  */
    LESS_THAN = 279,               /* LESS_THAN  */
    EQ = 280,                      /* EQ  */
    PROGRAM = 281,                 /* PROGRAM  */
    EXTERN = 282,                  /* EXTERN  */
    THEN = 283,                    /* THEN  */
    IF = 284,                      /* IF  */
    ELSE = 285,                    /* ELSE  */
    WHILE = 286,                   /* WHILE  */
    RETURN = 287,                  /* RETURN  */
    MAIN = 288                     /* MAIN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "calc-sintaxis.y"

    TData* symbol;
    Tree *tree;

#line 102 "calc-sintaxis.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CALC_SINTAXIS_TAB_H_INCLUDED  */
