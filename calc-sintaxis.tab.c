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

#include <stdlib.h>
#include <stdio.h>
#include "include/tree.h"
#include "include/symbols_table.h"
#include "include/pseudo_assembly.h"

SymbolsTable* table;
SymbolsTable* parameters;
AssemblyList *pseudoAssembly;
void setTypeFunction(Type type);


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
  YYSYMBOL_INTV = 3,                       /* INTV  */
  YYSYMBOL_TRET = 4,                       /* TRET  */
  YYSYMBOL_TDECL = 5,                      /* TDECL  */
  YYSYMBOL_TVOID = 6,                      /* TVOID  */
  YYSYMBOL_TMAIN = 7,                      /* TMAIN  */
  YYSYMBOL_TR = 8,                         /* TR  */
  YYSYMBOL_FAL = 9,                        /* FAL  */
  YYSYMBOL_TID = 10,                       /* TID  */
  YYSYMBOL_TMENOR = 11,                    /* TMENOR  */
  YYSYMBOL_TMAYOR = 12,                    /* TMAYOR  */
  YYSYMBOL_TIGUAL = 13,                    /* TIGUAL  */
  YYSYMBOL_TMENOS = 14,                    /* TMENOS  */
  YYSYMBOL_TMAS = 15,                      /* TMAS  */
  YYSYMBOL_TMULT = 16,                     /* TMULT  */
  YYSYMBOL_TDIV = 17,                      /* TDIV  */
  YYSYMBOL_TMOD = 18,                      /* TMOD  */
  YYSYMBOL_TOR = 19,                       /* TOR  */
  YYSYMBOL_TNEG = 20,                      /* TNEG  */
  YYSYMBOL_TAND = 21,                      /* TAND  */
  YYSYMBOL_EXTERN = 22,                    /* EXTERN  */
  YYSYMBOL_TWHILE = 23,                    /* TWHILE  */
  YYSYMBOL_TIF = 24,                       /* TIF  */
  YYSYMBOL_THEN = 25,                      /* THEN  */
  YYSYMBOL_TELSE = 26,                     /* TELSE  */
  YYSYMBOL_TINT = 27,                      /* TINT  */
  YYSYMBOL_TBOOL = 28,                     /* TBOOL  */
  YYSYMBOL_TASIGN = 29,                    /* TASIGN  */
  YYSYMBOL_TPROGRAM = 30,                  /* TPROGRAM  */
  YYSYMBOL_UMINUS = 31,                    /* UMINUS  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_program1 = 39,                  /* program1  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_vars = 42,                      /* vars  */
  YYSYMBOL_var_decl = 43,                  /* var_decl  */
  YYSYMBOL_methods = 44,                   /* methods  */
  YYSYMBOL_method_decl = 45,               /* method_decl  */
  YYSYMBOL_params = 46,                    /* params  */
  YYSYMBOL_param = 47,                     /* param  */
  YYSYMBOL_block = 48,                     /* block  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_block1 = 50,                    /* block1  */
  YYSYMBOL_statements = 51,                /* statements  */
  YYSYMBOL_single_statement = 52,          /* single_statement  */
  YYSYMBOL_method_call = 53,               /* method_call  */
  YYSYMBOL_exprs = 54,                     /* exprs  */
  YYSYMBOL_expr = 55,                      /* expr  */
  YYSYMBOL_literal = 56,                   /* literal  */
  YYSYMBOL_boolValue = 57,                 /* boolValue  */
  YYSYMBOL_id = 58,                        /* id  */
  YYSYMBOL_ttype = 59                      /* ttype  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      35,    36,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    76,    77,    78,    80,    81,    84,    89,
      91,    92,    94,    95,    96,    97,    99,   100,   103,   105,
     105,   106,   107,   108,   109,   112,   113,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   126,   127,   129,   130,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   152,   153,   155,   156,
     158,   160,   161,   162
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
  "\"end of file\"", "error", "\"invalid token\"", "INTV", "TRET",
  "TDECL", "TVOID", "TMAIN", "TR", "FAL", "TID", "TMENOR", "TMAYOR",
  "TIGUAL", "TMENOS", "TMAS", "TMULT", "TDIV", "TMOD", "TOR", "TNEG",
  "TAND", "EXTERN", "TWHILE", "TIF", "THEN", "TELSE", "TINT", "TBOOL",
  "TASIGN", "TPROGRAM", "UMINUS", "'{'", "'}'", "';'", "'('", "')'", "','",
  "$accept", "program1", "$@1", "program", "vars", "var_decl", "methods",
  "method_decl", "params", "param", "block", "$@2", "block1", "statements",
  "single_statement", "method_call", "exprs", "expr", "literal",
  "boolValue", "id", "ttype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -86,     4,   -19,   -86,    13,   -86,    97,   -86,   -86,   -86,
      97,   -86,    23,   -86,     3,   -86,   136,   -86,   -86,     3,
     -86,   -26,   -86,   -12,    86,   -86,    16,   -86,   -86,   -86,
      86,    86,    86,   -86,   197,   -86,   -86,    11,    32,    61,
     -86,     3,   -86,   -86,   159,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,   -86,    39,    24,   -86,    29,
      41,    97,   -86,   -86,   142,   142,   142,    94,    94,   -86,
     -86,   -86,   257,   212,   -86,    79,   246,   -86,    95,   -86,
      34,   -86,   -86,   -86,    86,    57,    38,    45,   -86,   -86,
     103,   -86,   110,   -86,    54,   -17,     3,   -86,   246,   -86,
     221,    86,    86,   -86,   128,   -86,   -86,   -86,    86,    28,
     -86,   170,   186,   -86,   232,   -86,    77,   -86,   -86,   -86,
      78,   -86,   -86
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,    63,    61,    62,
       0,     7,     0,    11,     0,     6,     0,     5,    10,     0,
      60,     0,     4,     0,     0,     9,     0,    57,    58,    59,
       0,     0,     0,    40,     0,    41,    56,    52,    19,     0,
      17,     0,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     0,    15,     0,
      19,     0,    18,    55,    48,    49,    51,    43,    42,    45,
      44,    50,    47,    46,    37,     0,    39,    14,    19,    20,
       0,    12,    16,    36,     0,     0,     0,     0,    24,    34,
      19,    35,    19,    26,     0,     0,     0,    13,    38,    33,
       0,     0,     0,    22,    19,    23,    25,    28,     0,     0,
      32,     0,     0,    21,     0,    19,     0,    27,    31,    19,
      29,    19,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,   -86,    30,    -9,   107,     9,   -86,    74,
     -36,   -86,   -86,    49,   -85,   -64,   -86,   -15,   -86,   -86,
     -14,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     5,    10,    11,    12,    13,    39,    40,
      91,    59,    79,    92,    93,    33,    75,    34,    35,    36,
      37,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,    15,    58,    24,     3,    23,    19,   106,    25,    26,
      19,     4,   108,    20,    94,    42,    43,    44,    56,   106,
      41,    18,     7,    26,    81,    18,    94,    62,    94,     7,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      94,    76,    27,     8,     9,     6,    56,    28,    29,    20,
       8,     9,    38,    30,    57,    41,    17,    24,    77,    31,
      27,    78,    25,    80,    95,    28,    29,    20,    97,    98,
     100,    30,    96,   101,    32,    74,    95,    31,    95,   118,
     102,    15,   109,   120,    96,   122,   111,   112,   107,    27,
      95,    99,    32,   114,    28,    29,    20,    60,    61,    85,
      30,     7,   119,     7,   121,    20,    31,    85,    90,     7,
      50,    51,    52,    20,    85,    83,    84,    16,    86,    87,
      20,    32,     8,     9,     8,     9,    86,    87,    88,    89,
       8,     9,    85,    86,    87,    82,   103,    89,    20,   104,
       0,     0,     7,   105,    89,     0,     0,     0,     0,     0,
       0,    86,    87,    -1,    -1,    -1,    48,    49,    50,    51,
      52,   113,    89,     8,     9,     0,     0,     0,     0,    22,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    54,     0,     0,     0,    63,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,   115,    54,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,     0,
       0,     0,   116,    45,    46,    47,    48,    49,    50,    51,
      52,    55,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,    54,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,    54,     0,   110,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,   117,    54,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,    54
};

static const yytype_int8 yycheck[] =
{
      14,    10,    38,    29,     0,    19,    12,    92,    34,    35,
      16,    30,    29,    10,    78,    30,    31,    32,    35,   104,
      26,    12,     6,    35,    60,    16,    90,    41,    92,     6,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     104,    56,     3,    27,    28,    32,    35,     8,     9,    10,
      27,    28,    36,    14,    22,    61,    33,    29,    34,    20,
       3,    32,    34,    22,    78,     8,     9,    10,    34,    84,
      85,    14,    78,    35,    35,    36,    90,    20,    92,   115,
      35,    90,    96,   119,    90,   121,   101,   102,    34,     3,
     104,    34,    35,   108,     8,     9,    10,    36,    37,     4,
      14,     6,    25,     6,    26,    10,    20,     4,    78,     6,
      16,    17,    18,    10,     4,    36,    37,    10,    23,    24,
      10,    35,    27,    28,    27,    28,    23,    24,    33,    34,
      27,    28,     4,    23,    24,    61,    33,    34,    10,    90,
      -1,    -1,     6,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    11,    12,    13,    14,    15,    16,    17,
      18,    33,    34,    27,    28,    -1,    -1,    -1,    -1,    33,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    -1,    -1,    -1,    36,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    36,    21,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    -1,
      -1,    -1,    36,    11,    12,    13,    14,    15,    16,    17,
      18,    34,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    -1,    34,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    34,    21,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    40,     0,    30,    41,    32,     6,    27,    28,
      42,    43,    44,    45,    59,    43,    44,    33,    45,    59,
      10,    58,    33,    58,    29,    34,    35,     3,     8,     9,
      14,    20,    35,    53,    55,    56,    57,    58,    36,    46,
      47,    59,    55,    55,    55,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    21,    34,    35,    22,    48,    49,
      36,    37,    58,    36,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    36,    54,    55,    34,    32,    50,
      22,    48,    47,    36,    37,     4,    23,    24,    33,    34,
      42,    48,    51,    52,    53,    58,    59,    34,    55,    34,
      55,    35,    35,    33,    51,    33,    52,    34,    29,    58,
      34,    55,    55,    33,    55,    36,    36,    34,    48,    25,
      48,    26,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    40,    39,    41,    41,    42,    42,    43,    43,
      44,    44,    45,    45,    45,    45,    46,    46,    47,    49,
      48,    50,    50,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    59,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     5,     4,     2,     1,     5,     3,
       2,     1,     6,     7,     6,     5,     3,     1,     2,     0,
       2,     4,     3,     3,     2,     2,     1,     4,     2,     6,
       8,     5,     3,     2,     1,     1,     4,     3,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 76 "calc-sintaxis.y"
          {table = (SymbolsTable*)malloc(sizeof(SymbolsTable)); parameters = (SymbolsTable*)malloc(sizeof(SymbolsTable)); pseudoAssembly = (AssemblyList*)malloc(sizeof(AssemblyList)); LSE* newLevel = (LSE*)malloc(sizeof(LSE)); insertLevel(&table, newLevel); }
#line 1239 "calc-sintaxis.tab.c"
    break;

  case 3: /* program1: $@1 program  */
#line 76 "calc-sintaxis.y"
                                                                                                                                                                                                                                                                               {removeLevel(&table);}
#line 1245 "calc-sintaxis.tab.c"
    break;

  case 4: /* program: TPROGRAM '{' vars methods '}'  */
#line 77 "calc-sintaxis.y"
                                        {(yyval.tree) = newTree((yyvsp[-4].data), (yyvsp[-2].tree), (yyvsp[-1].tree)); evalType((yyval.tree));  printTree((yyval.tree)); showTable(table); generatePseudoAssembly(&pseudoAssembly, (yyval.tree)); printAssemblyList(&pseudoAssembly);}
#line 1251 "calc-sintaxis.tab.c"
    break;

  case 5: /* program: TPROGRAM '{' methods '}'  */
#line 78 "calc-sintaxis.y"
                                    {(yyval.tree) = newTree((yyvsp[-3].data), (yyvsp[-1].tree), NULL); evalType((yyval.tree)); printTree((yyval.tree)); showTable(table); generatePseudoAssembly(&pseudoAssembly, (yyval.tree)); printAssemblyList(&pseudoAssembly);}
#line 1257 "calc-sintaxis.tab.c"
    break;

  case 6: /* vars: vars var_decl  */
#line 80 "calc-sintaxis.y"
                      {TData* data = newData(T_DECL, NO_TYPE, -1, "vars"); (yyval.tree) = newTree(data, (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1263 "calc-sintaxis.tab.c"
    break;

  case 7: /* vars: var_decl  */
#line 81 "calc-sintaxis.y"
                {(yyval.tree) = (yyvsp[0].tree);}
#line 1269 "calc-sintaxis.tab.c"
    break;

  case 8: /* var_decl: ttype id TASIGN expr ';'  */
#line 84 "calc-sintaxis.y"
                             { if(insertElem(&table, newData((yyvsp[-3].tree)->info->token, (yyvsp[-4].tree)->info->type, (yyvsp[-1].tree)->info->value, (yyvsp[-3].tree)->info->name))) {

                                Tree *leftChild = newTree(newData(T_DECL, (yyvsp[-4].tree)->info->type, -1, (yyvsp[-3].tree)->info->name), (yyvsp[-4].tree), (yyvsp[-3].tree)); (yyval.tree) = newTree((yyvsp[-2].data), leftChild, (yyvsp[-1].tree));
                            } else {
                                    perror("Re-declaration"); exit(1);}}
#line 1279 "calc-sintaxis.tab.c"
    break;

  case 9: /* var_decl: ttype id ';'  */
#line 89 "calc-sintaxis.y"
                  {if(insertElem(&table, newData((yyvsp[-1].tree)->info->token, (yyvsp[-2].tree)->info->type, -1, (yyvsp[-1].tree)->info->name))){(yyval.tree) = newTree(newData(T_DECL, NO_TYPE, -1, (yyvsp[-1].tree)->info->name), (yyvsp[-2].tree), (yyvsp[-1].tree));} else {perror("var already exists");exit(1);}}
#line 1285 "calc-sintaxis.tab.c"
    break;

  case 10: /* methods: methods method_decl  */
#line 91 "calc-sintaxis.y"
                              {Tree *tree = newTree(newData(T_METHODS, NO_TYPE, -1, "methods"), (yyvsp[-1].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1291 "calc-sintaxis.tab.c"
    break;

  case 11: /* methods: method_decl  */
#line 92 "calc-sintaxis.y"
                       {(yyval.tree) = (yyvsp[0].tree);}
#line 1297 "calc-sintaxis.tab.c"
    break;

  case 12: /* method_decl: ttype id '(' params ')' block  */
#line 94 "calc-sintaxis.y"
                                           {Tree *tree = newTree(newData(T_FUNCTION, (yyvsp[-5].tree)->info->type, -1, (yyvsp[-4].tree)->info->name), (yyvsp[-2].tree), (yyvsp[0].tree)); if(insertElem(&table, tree->info)){ (yyval.tree) = tree; } else {perror("wrong function declaration\n"); exit(1);} }
#line 1303 "calc-sintaxis.tab.c"
    break;

  case 13: /* method_decl: ttype id '(' params ')' EXTERN ';'  */
#line 95 "calc-sintaxis.y"
                                                 { Tree *tree = newTree(newData(T_FUNCTION, (yyvsp[-6].tree)->info->type, -1, (yyvsp[-5].tree)->info->name), (yyvsp[-3].tree), newTree((yyvsp[-1].data), NULL, NULL)); if(insertElem(&table, tree->info)){ (yyval.tree) = tree;} else {perror("wrong function declaration\n"); exit(1);} }
#line 1309 "calc-sintaxis.tab.c"
    break;

  case 14: /* method_decl: ttype id '(' ')' EXTERN ';'  */
#line 96 "calc-sintaxis.y"
                                           {Tree *tree = newTree(newData(T_FUNCTION, (yyvsp[-5].tree)->info->type, -1, (yyvsp[-4].tree)->info->name), NULL, newTree((yyvsp[-1].data), NULL, NULL)); if(insertElem(&table, tree->info) && (yyvsp[-5].tree)->info->type != NO_TYPE){ (yyval.tree) = tree; } else {perror("wrong function declaration\n"); exit(1);} }
#line 1315 "calc-sintaxis.tab.c"
    break;

  case 15: /* method_decl: ttype id '(' ')' block  */
#line 97 "calc-sintaxis.y"
                                     {Tree *tree = newTree(newData(T_FUNCTION, (yyvsp[-4].tree)->info->type, -1, (yyvsp[-3].tree)->info->name), NULL, (yyvsp[0].tree)); if(insertElem(&table, tree->info)){ (yyval.tree) = tree; } else {perror("wrong function declaration\n"); exit(1);} }
#line 1321 "calc-sintaxis.tab.c"
    break;

  case 16: /* params: params ',' param  */
#line 99 "calc-sintaxis.y"
                          {TData* data = newData(T_PARAMS, NO_TYPE, -1, "params"); Tree *tree = newTree(data, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = tree; }
#line 1327 "calc-sintaxis.tab.c"
    break;

  case 17: /* params: param  */
#line 100 "calc-sintaxis.y"
                {(yyval.tree) = (yyvsp[0].tree); }
#line 1333 "calc-sintaxis.tab.c"
    break;

  case 18: /* param: ttype id  */
#line 103 "calc-sintaxis.y"
                {if(insertElem(&parameters, newData(T_PARAM, (yyvsp[-1].tree)->info->type,-1 ,(yyvsp[0].tree)->info->name))) {(yyval.tree) = newTree(newData(T_YYUNDEF, NO_TYPE, -1, (yyvsp[0].tree)->info->name), (yyvsp[-1].tree), (yyvsp[0].tree));} else {printf("The parameter does already exist");}}
#line 1339 "calc-sintaxis.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 105 "calc-sintaxis.y"
       {LSE* newLevel = (LSE*)malloc(sizeof(LSE)); insertLevel(&table, newLevel);}
#line 1345 "calc-sintaxis.tab.c"
    break;

  case 20: /* block: $@2 block1  */
#line 105 "calc-sintaxis.y"
                                                                                          {removeLevel(&table); (yyval.tree) = (yyvsp[0].tree);}
#line 1351 "calc-sintaxis.tab.c"
    break;

  case 21: /* block1: '{' vars statements '}'  */
#line 106 "calc-sintaxis.y"
                                  {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "block"); Tree *tree = newTree(data, (yyvsp[-2].tree), (yyvsp[-1].tree)); (yyval.tree) = tree;}
#line 1357 "calc-sintaxis.tab.c"
    break;

  case 22: /* block1: '{' vars '}'  */
#line 107 "calc-sintaxis.y"
                    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1363 "calc-sintaxis.tab.c"
    break;

  case 23: /* block1: '{' statements '}'  */
#line 108 "calc-sintaxis.y"
                          {(yyval.tree) = (yyvsp[-1].tree);}
#line 1369 "calc-sintaxis.tab.c"
    break;

  case 24: /* block1: '{' '}'  */
#line 109 "calc-sintaxis.y"
               {(yyval.tree) = newTree(NULL, NULL, NULL);}
#line 1375 "calc-sintaxis.tab.c"
    break;

  case 25: /* statements: statements single_statement  */
#line 112 "calc-sintaxis.y"
                                        {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "statements"); (yyval.tree) = newTree(data, (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1381 "calc-sintaxis.tab.c"
    break;

  case 26: /* statements: single_statement  */
#line 113 "calc-sintaxis.y"
                             {(yyval.tree) = (yyvsp[0].tree);}
#line 1387 "calc-sintaxis.tab.c"
    break;

  case 27: /* single_statement: id TASIGN expr ';'  */
#line 116 "calc-sintaxis.y"
                                     {(yyval.tree) = newTree((yyvsp[-2].data), (yyvsp[-3].tree), (yyvsp[-1].tree));}
#line 1393 "calc-sintaxis.tab.c"
    break;

  case 28: /* single_statement: method_call ';'  */
#line 117 "calc-sintaxis.y"
                                  {(yyval.tree) = (yyvsp[-1].tree);}
#line 1399 "calc-sintaxis.tab.c"
    break;

  case 29: /* single_statement: TIF '(' expr ')' THEN block  */
#line 118 "calc-sintaxis.y"
                                               {Tree *tree = newTree((yyvsp[-5].data), (yyvsp[-3].tree), newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL)); (yyval.tree) = tree;}
#line 1405 "calc-sintaxis.tab.c"
    break;

  case 30: /* single_statement: TIF '(' expr ')' THEN block TELSE block  */
#line 119 "calc-sintaxis.y"
                                                          {(yyval.tree) = newTree((yyvsp[-7].data), (yyvsp[-5].tree), newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body-if-else"), newTree((yyvsp[-3].data), (yyvsp[-2].tree), NULL), newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL)));}
#line 1411 "calc-sintaxis.tab.c"
    break;

  case 31: /* single_statement: TWHILE '(' expr ')' block  */
#line 120 "calc-sintaxis.y"
                                            {(yyval.tree) = newTree((yyvsp[-4].data), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1417 "calc-sintaxis.tab.c"
    break;

  case 32: /* single_statement: TRET expr ';'  */
#line 121 "calc-sintaxis.y"
                                {(yyval.tree) = newTree(newData(T_RET, -1, -1, "RET WITH VALUE"), (yyvsp[-1].tree), NULL);}
#line 1423 "calc-sintaxis.tab.c"
    break;

  case 33: /* single_statement: TRET ';'  */
#line 122 "calc-sintaxis.y"
                           {(yyval.tree) = newTree(newData(T_RET, -1, -1, "RET WITHOUT VALUE"), NULL, NULL);}
#line 1429 "calc-sintaxis.tab.c"
    break;

  case 34: /* single_statement: ';'  */
#line 123 "calc-sintaxis.y"
                      {(yyval.tree) = NULL;}
#line 1435 "calc-sintaxis.tab.c"
    break;

  case 35: /* single_statement: block  */
#line 124 "calc-sintaxis.y"
                        {(yyval.tree) = (yyvsp[0].tree);}
#line 1441 "calc-sintaxis.tab.c"
    break;

  case 36: /* method_call: id '(' exprs ')'  */
#line 126 "calc-sintaxis.y"
                            {TData* data = newData(T_METHODCALL, NO_TYPE, -1, (yyvsp[-3].tree)->info->name); (yyval.tree) = newTree(data, (yyvsp[-1].tree), NULL); }
#line 1447 "calc-sintaxis.tab.c"
    break;

  case 37: /* method_call: id '(' ')'  */
#line 127 "calc-sintaxis.y"
                         {TData* data = newData(T_METHODCALL, NO_TYPE, -1, (yyvsp[-2].tree)->info->name); (yyval.tree) = newTree(data, NULL, NULL);}
#line 1453 "calc-sintaxis.tab.c"
    break;

  case 38: /* exprs: exprs ',' expr  */
#line 129 "calc-sintaxis.y"
                      {TData* data = newData(T_EXPRS, NO_TYPE, -1, "exprs"); (yyval.tree) = newTree(data, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1459 "calc-sintaxis.tab.c"
    break;

  case 39: /* exprs: expr  */
#line 130 "calc-sintaxis.y"
           {(yyval.tree) = (yyvsp[0].tree);}
#line 1465 "calc-sintaxis.tab.c"
    break;

  case 40: /* expr: method_call  */
#line 134 "calc-sintaxis.y"
                 {(yyval.tree) = (yyvsp[0].tree);}
#line 1471 "calc-sintaxis.tab.c"
    break;

  case 41: /* expr: literal  */
#line 135 "calc-sintaxis.y"
              {(yyval.tree) = (yyvsp[0].tree);}
#line 1477 "calc-sintaxis.tab.c"
    break;

  case 42: /* expr: expr TMAS expr  */
#line 136 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1483 "calc-sintaxis.tab.c"
    break;

  case 43: /* expr: expr TMENOS expr  */
#line 137 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1489 "calc-sintaxis.tab.c"
    break;

  case 44: /* expr: expr TDIV expr  */
#line 138 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1495 "calc-sintaxis.tab.c"
    break;

  case 45: /* expr: expr TMULT expr  */
#line 139 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1501 "calc-sintaxis.tab.c"
    break;

  case 46: /* expr: expr TAND expr  */
#line 140 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1507 "calc-sintaxis.tab.c"
    break;

  case 47: /* expr: expr TOR expr  */
#line 141 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1513 "calc-sintaxis.tab.c"
    break;

  case 48: /* expr: expr TMENOR expr  */
#line 142 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1519 "calc-sintaxis.tab.c"
    break;

  case 49: /* expr: expr TMAYOR expr  */
#line 143 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1525 "calc-sintaxis.tab.c"
    break;

  case 50: /* expr: expr TMOD expr  */
#line 144 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1531 "calc-sintaxis.tab.c"
    break;

  case 51: /* expr: expr TIGUAL expr  */
#line 145 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1537 "calc-sintaxis.tab.c"
    break;

  case 52: /* expr: id  */
#line 146 "calc-sintaxis.y"
         {(yyval.tree) = (yyvsp[0].tree); if((doesExist(table, (yyvsp[0].tree)->info->name) == -1) && (doesExist(parameters, (yyvsp[0].tree)->info->name) == -1)) {perror("no declarated var\n"); exit(1);}}
#line 1543 "calc-sintaxis.tab.c"
    break;

  case 53: /* expr: TMENOS expr  */
#line 147 "calc-sintaxis.y"
                                {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL); }
#line 1549 "calc-sintaxis.tab.c"
    break;

  case 54: /* expr: TNEG expr  */
#line 148 "calc-sintaxis.y"
                             {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL); }
#line 1555 "calc-sintaxis.tab.c"
    break;

  case 55: /* expr: '(' expr ')'  */
#line 149 "calc-sintaxis.y"
                   {(yyval.tree) = (yyvsp[-1].tree);}
#line 1561 "calc-sintaxis.tab.c"
    break;

  case 56: /* literal: boolValue  */
#line 152 "calc-sintaxis.y"
                   {(yyval.tree) = (yyvsp[0].tree);}
#line 1567 "calc-sintaxis.tab.c"
    break;

  case 57: /* literal: INTV  */
#line 153 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = INTEGER;}
#line 1573 "calc-sintaxis.tab.c"
    break;

  case 58: /* boolValue: TR  */
#line 155 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->value = 1; (yyval.tree)->info->type = BOOL;}
#line 1579 "calc-sintaxis.tab.c"
    break;

  case 59: /* boolValue: FAL  */
#line 156 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->value = 0; (yyval.tree)->info->type = BOOL;}
#line 1585 "calc-sintaxis.tab.c"
    break;

  case 60: /* id: TID  */
#line 158 "calc-sintaxis.y"
            {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); }
#line 1591 "calc-sintaxis.tab.c"
    break;

  case 61: /* ttype: TINT  */
#line 160 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = INTEGER;}
#line 1597 "calc-sintaxis.tab.c"
    break;

  case 62: /* ttype: TBOOL  */
#line 161 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = BOOL;}
#line 1603 "calc-sintaxis.tab.c"
    break;

  case 63: /* ttype: TVOID  */
#line 162 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = VOID;}
#line 1609 "calc-sintaxis.tab.c"
    break;


#line 1613 "calc-sintaxis.tab.c"

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

