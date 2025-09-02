/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calc-sintaxis.y"


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

#line 85 "calc-sintaxis.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "calc-sintaxis.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_TTRUE = 5,                      /* TTRUE  */
  YYSYMBOL_TFALSE = 6,                     /* TFALSE  */
  YYSYMBOL_TYPE_INT = 7,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_BOOL = 8,                  /* TYPE_BOOL  */
  YYSYMBOL_TYPE_VOID = 9,                  /* TYPE_VOID  */
  YYSYMBOL_TPLUS = 10,                     /* TPLUS  */
  YYSYMBOL_TTIMES = 11,                    /* TTIMES  */
  YYSYMBOL_TMINUS = 12,                    /* TMINUS  */
  YYSYMBOL_TDIV = 13,                      /* TDIV  */
  YYSYMBOL_TMOD = 14,                      /* TMOD  */
  YYSYMBOL_TASIGN = 15,                    /* TASIGN  */
  YYSYMBOL_TPAR_OP = 16,                   /* TPAR_OP  */
  YYSYMBOL_TPAR_CL = 17,                   /* TPAR_CL  */
  YYSYMBOL_TBRACE_OP = 18,                 /* TBRACE_OP  */
  YYSYMBOL_TBRACE_CL = 19,                 /* TBRACE_CL  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_GREATER_THAN = 23,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 24,                 /* LESS_THAN  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_PROGRAM = 26,                   /* PROGRAM  */
  YYSYMBOL_EXTERN = 27,                    /* EXTERN  */
  YYSYMBOL_THEN = 28,                      /* THEN  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_MAIN = 33,                      /* MAIN  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_main = 38,                      /* main  */
  YYSYMBOL_list_decls = 39,                /* list_decls  */
  YYSYMBOL_list_sents = 40,                /* list_sents  */
  YYSYMBOL_block = 41,                     /* block  */
  YYSYMBOL_sentencia = 42,                 /* sentencia  */
  YYSYMBOL_asignacion = 43,                /* asignacion  */
  YYSYMBOL_call_func = 44,                 /* call_func  */
  YYSYMBOL_declaracion = 45,               /* declaracion  */
  YYSYMBOL_argumento = 46,                 /* argumento  */
  YYSYMBOL_parametros = 47,                /* parametros  */
  YYSYMBOL_dec_parametro = 48,             /* dec_parametro  */
  YYSYMBOL_list_func = 49,                 /* list_func  */
  YYSYMBOL_declare_funcion = 50,           /* declare_funcion  */
  YYSYMBOL_expr = 51,                      /* expr  */
  YYSYMBOL_valor = 52,                     /* valor  */
  YYSYMBOL_retorno = 53,                   /* retorno  */
  YYSYMBOL_if_else = 54,                   /* if_else  */
  YYSYMBOL_while = 55                      /* while  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    79,    80,    81,    84,    85,    86,    89,
      90,    93,    94,    97,   100,   104,   105,   106,   107,   108,
     111,   115,   119,   120,   124,   125,   126,   130,   131,   132,
     135,   136,   139,   140,   143,   144,   145,   146,   147,   148,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   167,   168,   169,   173,   174,   177,
     180,   181,   187
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT", "TTRUE",
  "TFALSE", "TYPE_INT", "TYPE_BOOL", "TYPE_VOID", "TPLUS", "TTIMES",
  "TMINUS", "TDIV", "TMOD", "TASIGN", "TPAR_OP", "TPAR_CL", "TBRACE_OP",
  "TBRACE_CL", "OR", "AND", "NOT", "GREATER_THAN", "LESS_THAN", "EQ",
  "PROGRAM", "EXTERN", "THEN", "IF", "ELSE", "WHILE", "RETURN", "MAIN",
  "';'", "','", "$accept", "prog", "main", "list_decls", "list_sents",
  "block", "sentencia", "asignacion", "call_func", "declaracion",
  "argumento", "parametros", "dec_parametro", "list_func",
  "declare_funcion", "expr", "valor", "retorno", "if_else", "while", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,     8,    24,    99,   -77,     0,     1,     2,    36,    99,
     -77,   187,   -77,    -9,    61,    -7,    74,    77,    89,   -77,
      92,   -77,   187,    14,    15,   104,   -77,    21,   -77,    96,
      21,   -77,   107,    21,   110,   -77,   117,   127,   136,   -77,
     150,   152,   139,   124,   157,   162,   157,   163,   157,   -77,
     -77,   -77,    64,    21,    45,   -77,    65,   -77,    94,   -77,
     165,   -77,   -77,   197,   198,    45,    27,   168,   -77,   169,
     -77,   -77,   170,   171,    47,    52,   -77,   190,   191,    98,
     -77,   -77,   175,   -77,   -77,   -77,   -77,   -77,   -77,    98,
      98,    98,    98,   192,   -77,   -77,   -77,   206,    98,    98,
     -77,    50,   -77,   -77,    75,    34,   153,   105,   121,   -77,
     137,   -77,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,   -77,   -77,   -77,    98,   183,   157,   -77,   126,
     -77,   126,   -77,   -77,   158,   158,   179,   179,   174,   153,
     157,   -77,   182,   157,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       9,     0,    32,     0,     0,     0,     0,     0,     0,     3,
       0,    10,     0,     0,     0,     0,    33,    27,    22,     0,
      27,    23,     0,    27,     0,     5,     0,     0,     0,     4,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     2,
      30,    31,     0,    27,    11,     7,     0,     6,     0,     8,
       0,    34,    29,     0,     0,    11,     0,     0,    35,     0,
      36,    37,     0,     0,     0,     0,    14,     0,     0,     0,
      12,    15,     0,    16,    17,    18,    38,    39,    13,     0,
      24,     0,     0,    55,    54,    57,    58,     0,     0,     0,
      41,     0,    40,    19,     0,     0,    25,     0,     0,    56,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    59,    20,    21,     0,     0,     0,    53,    42,
      44,    43,    45,    46,    51,    50,    47,    48,    49,    26,
       0,    62,    60,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,    10,   159,   149,   -46,   -77,   -77,     6,    -8,
     -77,   -22,   -77,   207,    43,   -76,   -77,   -77,   -77,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,     9,    66,    55,    80,    81,   100,    10,
     105,    42,    43,    11,    12,   101,   102,    83,    84,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    21,    59,    13,    15,    17,    61,    27,    45,    30,
      68,    47,    70,   104,   106,   107,   108,    37,    38,    20,
       1,    25,   110,   111,     4,    28,     3,    31,    40,    41,
      75,    62,    36,    14,    16,    18,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    76,    14,    16,   139,
      75,   124,    63,    64,    26,    19,    77,    21,    78,    79,
     112,   113,   114,   115,   116,    26,    88,    89,    90,   125,
     117,   118,    82,   119,   120,   121,    77,    29,    78,    79,
      82,   141,    54,    54,   122,   112,   113,   114,   115,   116,
      32,    60,    67,    33,   142,   117,   118,   144,   119,   120,
     121,    93,    94,    95,    96,    34,     5,     6,     7,   123,
      97,    35,    54,    44,    98,   112,   113,   114,   115,   116,
      99,    69,   126,    39,    46,   117,   118,    48,   119,   120,
     121,   112,   113,   114,   115,   116,    49,   113,   127,   115,
     116,   117,   118,    27,   119,   120,   121,   112,   113,   114,
     115,   116,    30,    50,   128,    51,    52,   117,   118,    53,
     119,   120,   121,   112,   113,   114,   115,   116,   112,   113,
     114,   115,   116,   117,   118,    54,   119,   120,   121,    56,
      58,   119,   120,   121,   112,   113,   114,   115,   116,   112,
     113,   114,   115,   116,    23,    24,     7,   119,   120,    71,
      72,    73,    86,    87,    28,    31,    91,    92,    90,   103,
     109,   140,   143,    65,    74,     0,    22
};

static const yytype_int16 yycheck[] =
{
      46,     9,    48,     3,     3,     3,    52,    16,    30,    16,
      56,    33,    58,    89,    90,    91,    92,     3,     3,     9,
      26,    11,    98,    99,     0,    34,    18,    34,     7,     8,
       3,    53,    22,    33,    33,    33,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    19,    33,    33,   125,
       3,    17,     7,     8,    11,    19,    29,    65,    31,    32,
      10,    11,    12,    13,    14,    22,    19,    15,    16,    35,
      20,    21,    66,    23,    24,    25,    29,    16,    31,    32,
      74,   127,    18,    18,    34,    10,    11,    12,    13,    14,
      16,    27,    27,    16,   140,    20,    21,   143,    23,    24,
      25,     3,     4,     5,     6,    16,     7,     8,     9,    34,
      12,    19,    18,    17,    16,    10,    11,    12,    13,    14,
      22,    27,    17,    19,    17,    20,    21,    17,    23,    24,
      25,    10,    11,    12,    13,    14,    19,    11,    17,    13,
      14,    20,    21,    16,    23,    24,    25,    10,    11,    12,
      13,    14,    16,     3,    17,     3,    17,    20,    21,    35,
      23,    24,    25,    10,    11,    12,    13,    14,    10,    11,
      12,    13,    14,    20,    21,    18,    23,    24,    25,    17,
      17,    23,    24,    25,    10,    11,    12,    13,    14,    10,
      11,    12,    13,    14,     7,     8,     9,    23,    24,    34,
       3,     3,    34,    34,    34,    34,    16,    16,    16,    34,
       4,    28,    30,    54,    65,    -1,     9
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    37,    18,     0,     7,     8,     9,    38,    39,
      45,    49,    50,     3,    33,     3,    33,     3,    33,    19,
      38,    45,    49,     7,     8,    38,    50,    16,    34,    16,
      16,    34,    16,    16,    16,    19,    38,     3,     3,    19,
       7,     8,    47,    48,    17,    47,    17,    47,    17,    19,
       3,     3,    17,    35,    18,    41,    17,    41,    17,    41,
      27,    41,    47,     7,     8,    39,    40,    27,    41,    27,
      41,    34,     3,     3,    40,     3,    19,    29,    31,    32,
      42,    43,    44,    53,    54,    55,    34,    34,    19,    15,
      16,    16,    16,     3,     4,     5,     6,    12,    16,    22,
      44,    51,    52,    34,    51,    46,    51,    51,    51,     4,
      51,    51,    10,    11,    12,    13,    14,    20,    21,    23,
      24,    25,    34,    34,    17,    35,    17,    17,    17,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      28,    41,    41,    30,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    38,    38,    38,    39,
      39,    40,    40,    41,    41,    42,    42,    42,    42,    42,
      43,    44,    45,    45,    46,    46,    46,    47,    47,    47,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    53,
      54,    54,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     4,     5,     5,     5,     5,     5,     1,
       2,     0,     2,     4,     3,     1,     1,     1,     1,     2,
       4,     4,     3,     3,     0,     1,     3,     0,     1,     3,
       2,     2,     1,     2,     6,     6,     6,     7,     7,     7,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     1,     2,     1,     1,     3,
       6,     8,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: PROGRAM TBRACE_OP list_decls list_func main TBRACE_CL  */
#line 77 "calc-sintaxis.y"
                                                             { char * name = "PROGRAM_BLOCK"; Tree* aux= createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[-1].tree));
                                                              char * name1 = "PROGRAM"; compilador(createTreeWhitSymbol(name1,EPROGRAM,blockNum,yylineno,(yyvsp[-3].tree), aux));}
#line 1228 "calc-sintaxis.tab.c"
    break;

  case 3: /* prog: PROGRAM TBRACE_OP main TBRACE_CL  */
#line 79 "calc-sintaxis.y"
                                         {char * name = "PROGRAM"; compilador(createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,NULL, (yyvsp[-1].tree)));}
#line 1234 "calc-sintaxis.tab.c"
    break;

  case 4: /* prog: PROGRAM TBRACE_OP list_func main TBRACE_CL  */
#line 80 "calc-sintaxis.y"
                                                   {char * name = "PROGRAM"; compilador(createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[-1].tree)));}
#line 1240 "calc-sintaxis.tab.c"
    break;

  case 5: /* prog: PROGRAM TBRACE_OP list_decls main TBRACE_CL  */
#line 81 "calc-sintaxis.y"
                                                    {char * name = "PROGRAM"; compilador(createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[-1].tree)));}
#line 1246 "calc-sintaxis.tab.c"
    break;

  case 6: /* main: TYPE_BOOL MAIN TPAR_OP TPAR_CL block  */
#line 84 "calc-sintaxis.y"
                                            { char * name = "main";(yyval.tree) = createTreeWhitSymbol(name,RETBOL,blockNum,yylineno,(yyvsp[0].tree), NULL);}
#line 1252 "calc-sintaxis.tab.c"
    break;

  case 7: /* main: TYPE_INT MAIN TPAR_OP TPAR_CL block  */
#line 85 "calc-sintaxis.y"
                                            { char * name = "main";(yyval.tree) = createTreeWhitSymbol(name,RETINT,blockNum,yylineno,(yyvsp[0].tree), NULL);}
#line 1258 "calc-sintaxis.tab.c"
    break;

  case 8: /* main: TYPE_VOID MAIN TPAR_OP TPAR_CL block  */
#line 86 "calc-sintaxis.y"
                                            { char * name = "main";(yyval.tree) = createTreeWhitSymbol(name,RETVOID,blockNum,yylineno,(yyvsp[0].tree), NULL);}
#line 1264 "calc-sintaxis.tab.c"
    break;

  case 9: /* list_decls: declaracion  */
#line 89 "calc-sintaxis.y"
                                     {char * name = "DECLARACION"; (yyval.tree) = createTreeWhitSymbol(name,DECLARATION,blockNum,yylineno,(yyvsp[0].tree), NULL);}
#line 1270 "calc-sintaxis.tab.c"
    break;

  case 10: /* list_decls: list_decls declaracion  */
#line 90 "calc-sintaxis.y"
                                     {char * name = "DECLARACION"; (yyval.tree) = createTreeWhitSymbol(name,DECLARATION,blockNum,yylineno,(yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1276 "calc-sintaxis.tab.c"
    break;

  case 11: /* list_sents: %empty  */
#line 93 "calc-sintaxis.y"
                                                {(yyval.tree) = NULL;}
#line 1282 "calc-sintaxis.tab.c"
    break;

  case 12: /* list_sents: list_sents sentencia  */
#line 94 "calc-sintaxis.y"
                                                {char * name = "SENTENCIA"; (yyval.tree) = createTreeWhitSymbol(name,SENTEN,blockNum,yylineno,(yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1288 "calc-sintaxis.tab.c"
    break;

  case 13: /* block: TBRACE_OP list_decls list_sents TBRACE_CL  */
#line 97 "calc-sintaxis.y"
                                                  { char *name1 = "BLOCK_FIN"; Tree*aux = createTreeWhitSymbol(name1,BLOCK_FIN,blockNum,yylineno,NULL, NULL);
                                                    char *name2 = "BLOCK_INTERNO"; Tree*aux2 = createTreeWhitSymbol(name2,OTHERS,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[-1].tree));
                                                    char *name = "BLOCK"; (yyval.tree) = createTreeWhitSymbol(name,BLOCK,blockNum,yylineno,aux2, aux); }
#line 1296 "calc-sintaxis.tab.c"
    break;

  case 14: /* block: TBRACE_OP list_sents TBRACE_CL  */
#line 100 "calc-sintaxis.y"
                                                  { char *name1 = "BLOCK_FIN"; Tree*aux = createTreeWhitSymbol(name1,BLOCK_FIN,blockNum,yylineno,NULL, NULL);
                                                    char *name = "BLOCK"; (yyval.tree) = createTreeWhitSymbol(name,BLOCK,blockNum,yylineno,(yyvsp[-1].tree), aux); }
#line 1303 "calc-sintaxis.tab.c"
    break;

  case 15: /* sentencia: asignacion  */
#line 104 "calc-sintaxis.y"
                                                    {(yyval.tree) = (yyvsp[0].tree);}
#line 1309 "calc-sintaxis.tab.c"
    break;

  case 16: /* sentencia: retorno  */
#line 105 "calc-sintaxis.y"
                                                    {(yyval.tree) = (yyvsp[0].tree);}
#line 1315 "calc-sintaxis.tab.c"
    break;

  case 17: /* sentencia: if_else  */
#line 106 "calc-sintaxis.y"
                                                    {(yyval.tree) = (yyvsp[0].tree);}
#line 1321 "calc-sintaxis.tab.c"
    break;

  case 18: /* sentencia: while  */
#line 107 "calc-sintaxis.y"
                                                    {(yyval.tree) = (yyvsp[0].tree);}
#line 1327 "calc-sintaxis.tab.c"
    break;

  case 19: /* sentencia: call_func ';'  */
#line 108 "calc-sintaxis.y"
                                                    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1333 "calc-sintaxis.tab.c"
    break;

  case 20: /* asignacion: ID TASIGN expr ';'  */
#line 111 "calc-sintaxis.y"
                               {char * name = (yyvsp[-3].symbol)->varname;Tree* aux3 = createTreeWhitSymbol(name,EID,blockNum,yylineno,NULL, NULL);
                                    char * nameAsig = "asignacion";(yyval.tree) = createTreeWhitSymbol(nameAsig,ASIGN,1,yylineno,aux3, (yyvsp[-1].tree));}
#line 1340 "calc-sintaxis.tab.c"
    break;

  case 21: /* call_func: ID TPAR_OP argumento TPAR_CL  */
#line 115 "calc-sintaxis.y"
                                         {char * name = (yyvsp[-3].symbol)->varname;Tree* aux3 = createTreeWhitSymbol(name,EFUNC,blockNum,yylineno,NULL, NULL);
                                    char * nameCall = "LLAMADA_FUNC";(yyval.tree) = createTreeWhitSymbol(nameCall,CALL_F,blockNum,yylineno,aux3, (yyvsp[-1].tree));}
#line 1347 "calc-sintaxis.tab.c"
    break;

  case 22: /* declaracion: TYPE_INT ID ';'  */
#line 119 "calc-sintaxis.y"
                              {char * name = (yyvsp[-1].symbol)->varname; (yyval.tree) = createTreeWhitSymbol(name,VARINT,blockNum,yylineno,NULL, NULL);}
#line 1353 "calc-sintaxis.tab.c"
    break;

  case 23: /* declaracion: TYPE_BOOL ID ';'  */
#line 120 "calc-sintaxis.y"
                              {char * name = (yyvsp[-1].symbol)->varname;(yyval.tree) = createTreeWhitSymbol(name,VARBOOL,blockNum,yylineno,NULL, NULL);}
#line 1359 "calc-sintaxis.tab.c"
    break;

  case 24: /* argumento: %empty  */
#line 124 "calc-sintaxis.y"
                                   {(yyval.tree) = NULL;}
#line 1365 "calc-sintaxis.tab.c"
    break;

  case 25: /* argumento: expr  */
#line 125 "calc-sintaxis.y"
                                   {(yyval.tree) = (yyvsp[0].tree);}
#line 1371 "calc-sintaxis.tab.c"
    break;

  case 26: /* argumento: argumento ',' expr  */
#line 126 "calc-sintaxis.y"
                                   {char * name = "arguments"; (yyval.tree) = createTreeWhitSymbol(name,ARGS, blockNum, yylineno, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1377 "calc-sintaxis.tab.c"
    break;

  case 27: /* parametros: %empty  */
#line 130 "calc-sintaxis.y"
                                            {(yyval.tree) = NULL;}
#line 1383 "calc-sintaxis.tab.c"
    break;

  case 28: /* parametros: dec_parametro  */
#line 131 "calc-sintaxis.y"
                                            {(yyval.tree) = (yyvsp[0].tree);}
#line 1389 "calc-sintaxis.tab.c"
    break;

  case 29: /* parametros: dec_parametro ',' parametros  */
#line 132 "calc-sintaxis.y"
                                            {char * name = "PARAMETROS"; (yyval.tree) = createTreeWhitSymbol(name,DECLARATION,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1395 "calc-sintaxis.tab.c"
    break;

  case 30: /* dec_parametro: TYPE_INT ID  */
#line 135 "calc-sintaxis.y"
                             {char * name = (yyvsp[0].symbol)->varname; (yyval.tree) = createTreeWhitSymbol(name,PARAMINT,blockNum,yylineno,NULL, NULL);}
#line 1401 "calc-sintaxis.tab.c"
    break;

  case 31: /* dec_parametro: TYPE_BOOL ID  */
#line 136 "calc-sintaxis.y"
                              {char * name = (yyvsp[0].symbol)->varname;(yyval.tree) = createTreeWhitSymbol(name,PARAMBOOL,blockNum,yylineno,NULL, NULL);}
#line 1407 "calc-sintaxis.tab.c"
    break;

  case 32: /* list_func: declare_funcion  */
#line 139 "calc-sintaxis.y"
                                            {char * name = "LIS_FUNCION";(yyval.tree) = createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,(yyvsp[0].tree), NULL);}
#line 1413 "calc-sintaxis.tab.c"
    break;

  case 33: /* list_func: list_func declare_funcion  */
#line 140 "calc-sintaxis.y"
                                            {char * name = "LIS_FUNCION";(yyval.tree) = createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,(yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1419 "calc-sintaxis.tab.c"
    break;

  case 34: /* declare_funcion: TYPE_INT ID TPAR_OP parametros TPAR_CL block  */
#line 143 "calc-sintaxis.y"
                                                                        { char * nameAux = (yyvsp[-4].symbol)->varname; (yyval.tree) = createTreeWhitSymbol(nameAux, RETINT, blockNum, yylineno, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1425 "calc-sintaxis.tab.c"
    break;

  case 35: /* declare_funcion: TYPE_BOOL ID TPAR_OP parametros TPAR_CL block  */
#line 144 "calc-sintaxis.y"
                                                                        { char * nameAux = (yyvsp[-4].symbol)->varname; (yyval.tree) = createTreeWhitSymbol(nameAux, RETBOL, blockNum, yylineno, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1431 "calc-sintaxis.tab.c"
    break;

  case 36: /* declare_funcion: TYPE_VOID ID TPAR_OP parametros TPAR_CL block  */
#line 145 "calc-sintaxis.y"
                                                                        { char * nameAux = (yyvsp[-4].symbol)->varname; (yyval.tree) = createTreeWhitSymbol(nameAux, RETVOID, blockNum, yylineno, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1437 "calc-sintaxis.tab.c"
    break;

  case 37: /* declare_funcion: TYPE_INT ID TPAR_OP parametros TPAR_CL EXTERN ';'  */
#line 146 "calc-sintaxis.y"
                                                                        { char * name = (yyvsp[-5].symbol)->varname;(yyval.tree) = createTreeWhitSymbol(name,EXTINT,blockNum-1,yylineno,(yyvsp[-3].tree), NULL);}
#line 1443 "calc-sintaxis.tab.c"
    break;

  case 38: /* declare_funcion: TYPE_BOOL ID TPAR_OP parametros TPAR_CL EXTERN ';'  */
#line 147 "calc-sintaxis.y"
                                                                        { char * name = (yyvsp[-5].symbol)->varname;(yyval.tree) = createTreeWhitSymbol(name,EXTBOL,blockNum-1,yylineno,(yyvsp[-3].tree), NULL);}
#line 1449 "calc-sintaxis.tab.c"
    break;

  case 39: /* declare_funcion: TYPE_VOID ID TPAR_OP parametros TPAR_CL EXTERN ';'  */
#line 148 "calc-sintaxis.y"
                                                                        { char * name = (yyvsp[-5].symbol)->varname;(yyval.tree) = createTreeWhitSymbol(name,EXTVOID,blockNum-1,yylineno,(yyvsp[-3].tree), NULL);}
#line 1455 "calc-sintaxis.tab.c"
    break;

  case 40: /* expr: valor  */
#line 151 "calc-sintaxis.y"
                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1461 "calc-sintaxis.tab.c"
    break;

  case 41: /* expr: call_func  */
#line 152 "calc-sintaxis.y"
                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1467 "calc-sintaxis.tab.c"
    break;

  case 42: /* expr: expr TPLUS expr  */
#line 153 "calc-sintaxis.y"
                                 {char * name = "+"; (yyval.tree) = createTreeWhitSymbol(name,PLUS,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1473 "calc-sintaxis.tab.c"
    break;

  case 43: /* expr: expr TMINUS expr  */
#line 154 "calc-sintaxis.y"
                                {char * name = "-"; (yyval.tree) = createTreeWhitSymbol(name,MINUS,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1479 "calc-sintaxis.tab.c"
    break;

  case 44: /* expr: expr TTIMES expr  */
#line 155 "calc-sintaxis.y"
                                  {char * name = "*"; (yyval.tree) = createTreeWhitSymbol(name,PROD,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1485 "calc-sintaxis.tab.c"
    break;

  case 45: /* expr: expr TDIV expr  */
#line 156 "calc-sintaxis.y"
                           {char * name = "/"; (yyval.tree) = createTreeWhitSymbol(name,EDIV,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1491 "calc-sintaxis.tab.c"
    break;

  case 46: /* expr: expr TMOD expr  */
#line 157 "calc-sintaxis.y"
                              {char * name = "%"; (yyval.tree) = createTreeWhitSymbol(name,EMOD,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1497 "calc-sintaxis.tab.c"
    break;

  case 47: /* expr: expr GREATER_THAN expr  */
#line 158 "calc-sintaxis.y"
                                    {char * name = ">"; (yyval.tree) = createTreeWhitSymbol(name,GREATER_THAN,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1503 "calc-sintaxis.tab.c"
    break;

  case 48: /* expr: expr LESS_THAN expr  */
#line 159 "calc-sintaxis.y"
                                 {char * name = "<"; (yyval.tree) = createTreeWhitSymbol(name,LESS_THAN,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1509 "calc-sintaxis.tab.c"
    break;

  case 49: /* expr: expr EQ expr  */
#line 160 "calc-sintaxis.y"
                                {char * name = "=="; (yyval.tree) = createTreeWhitSymbol(name,EEQ,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1515 "calc-sintaxis.tab.c"
    break;

  case 50: /* expr: expr AND expr  */
#line 161 "calc-sintaxis.y"
                                {char * name = "&&"; (yyval.tree) = createTreeWhitSymbol(name,EAND,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1521 "calc-sintaxis.tab.c"
    break;

  case 51: /* expr: expr OR expr  */
#line 162 "calc-sintaxis.y"
                                {char * name = "||"; (yyval.tree) = createTreeWhitSymbol(name,EOR,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1527 "calc-sintaxis.tab.c"
    break;

  case 52: /* expr: NOT expr  */
#line 163 "calc-sintaxis.y"
                                {char * name = "!"; (yyval.tree) = createTreeWhitSymbol(name,ENOT,blockNum,yylineno,(yyvsp[0].tree), NULL);}
#line 1533 "calc-sintaxis.tab.c"
    break;

  case 53: /* expr: TPAR_OP expr TPAR_CL  */
#line 164 "calc-sintaxis.y"
                                {(yyval.tree) = (yyvsp[-1].tree);}
#line 1539 "calc-sintaxis.tab.c"
    break;

  case 54: /* valor: INT  */
#line 167 "calc-sintaxis.y"
                                {(yyval.tree) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1545 "calc-sintaxis.tab.c"
    break;

  case 55: /* valor: ID  */
#line 168 "calc-sintaxis.y"
                                {(yyval.tree) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1551 "calc-sintaxis.tab.c"
    break;

  case 56: /* valor: TMINUS INT  */
#line 169 "calc-sintaxis.y"
                                {int len = strlen((yyvsp[0].symbol)->varname); char* newVarname = (char*)malloc(len + 2);
                                 newVarname[0] = '-'; strcpy(newVarname + 1, (yyvsp[0].symbol)->varname);
                                 (yyvsp[0].symbol)->varname = newVarname;
                                 (yyvsp[0].symbol)->value = (yyvsp[0].symbol)->value * - 1; (yyval.tree) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1560 "calc-sintaxis.tab.c"
    break;

  case 57: /* valor: TTRUE  */
#line 173 "calc-sintaxis.y"
                                {(yyval.tree) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1566 "calc-sintaxis.tab.c"
    break;

  case 58: /* valor: TFALSE  */
#line 174 "calc-sintaxis.y"
                                {(yyval.tree) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1572 "calc-sintaxis.tab.c"
    break;

  case 59: /* retorno: RETURN expr ';'  */
#line 177 "calc-sintaxis.y"
                         {char * name = "return";(yyval.tree) = createTreeWhitSymbol(name,ERETURN,blockNum,yylineno,(yyvsp[-1].tree), NULL);}
#line 1578 "calc-sintaxis.tab.c"
    break;

  case 60: /* if_else: IF TPAR_OP expr TPAR_CL THEN block  */
#line 180 "calc-sintaxis.y"
                                            {char * name = "if_then"; (yyval.tree) = createTreeWhitSymbol(name,EIF,blockNum,yylineno,(yyvsp[-3].tree), (yyvsp[0].tree));}
#line 1584 "calc-sintaxis.tab.c"
    break;

  case 61: /* if_else: IF TPAR_OP expr TPAR_CL THEN block ELSE block  */
#line 181 "calc-sintaxis.y"
                                                       { char * name = "then"; char * name2 = "else";
                                                         Tree* aux_else = createTreeWhitSymbol(name2,EELSE,blockNum,yylineno,(yyvsp[0].tree), NULL);
                                                         Tree* aux_then = createTreeWhitSymbol(name,ETHEN,blockNum,yylineno,(yyvsp[-2].tree), aux_else);
                                                         char * name3 = "if_else"; (yyval.tree) = createTreeWhitSymbol(name3,EIF,blockNum,yylineno,(yyvsp[-5].tree), aux_then);}
#line 1593 "calc-sintaxis.tab.c"
    break;

  case 62: /* while: WHILE TPAR_OP expr TPAR_CL block  */
#line 187 "calc-sintaxis.y"
                                        {char * name = "while"; (yyval.tree) = createTreeWhitSymbol(name,EWHILE,blockNum,yylineno,(yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1599 "calc-sintaxis.tab.c"
    break;


#line 1603 "calc-sintaxis.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 190 "calc-sintaxis.y"


void compilador(Tree* tree){
    buildSymbolTable(tree);
    checkMissingReturnError();
    if(hasSemanticError()) {
       freeTree(tree);
       exit(1);
    }
    generateThreeAddressCode(tree);
    printPseudoAssemblyInstructions();
    generateAssemblerOutput();
    freePseudoAssemblyInstructions();
    freeTree(tree);
}

Tree* createTreeWhitSymbol(char * name,TOKENS token,int size, int line, Tree *l, Tree *r){
    TData* aux = createSymbol(name,token,0,yylineno);
    return createTree(aux,l,r);
}
