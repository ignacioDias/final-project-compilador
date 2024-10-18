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
#include "tree.h"
#include "symbols_table.h"

SymbolsTable* table;


#line 82 "calc-sintaxis.tab.c"

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
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_vars = 40,                      /* vars  */
  YYSYMBOL_var_decl = 41,                  /* var_decl  */
  YYSYMBOL_methods = 42,                   /* methods  */
  YYSYMBOL_method_decl = 43,               /* method_decl  */
  YYSYMBOL_params = 44,                    /* params  */
  YYSYMBOL_param = 45,                     /* param  */
  YYSYMBOL_block = 46,                     /* block  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_block1 = 48,                    /* block1  */
  YYSYMBOL_statements = 49,                /* statements  */
  YYSYMBOL_single_statement = 50,          /* single_statement  */
  YYSYMBOL_method_call = 51,               /* method_call  */
  YYSYMBOL_exprs = 52,                     /* exprs  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_literal = 54,                   /* literal  */
  YYSYMBOL_boolValue = 55,                 /* boolValue  */
  YYSYMBOL_id = 56,                        /* id  */
  YYSYMBOL_ttype = 57                      /* ttype  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

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
       0,    73,    73,    74,    77,    78,    82,    83,    86,    87,
      90,    91,    94,    95,    98,   100,   100,   101,   102,   103,
     104,   107,   108,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   122,   124,   125,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   146,   147,   149,   150,   152,   154,   155,   156
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
  "$accept", "program", "vars", "var_decl", "methods", "method_decl",
  "params", "param", "block", "$@1", "block1", "statements",
  "single_statement", "method_call", "exprs", "expr", "literal",
  "boolValue", "id", "ttype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,     5,    44,    15,   -78,   -78,   -78,   -78,    15,   -78,
      39,   -78,    36,   -78,   102,   -78,   -78,    36,   -78,    61,
     -78,   -20,    79,   -78,    15,   -78,   -78,   -78,    79,    79,
      79,   -78,   163,   -78,   -78,    26,    47,   -78,    36,   -78,
     -78,   125,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,   -78,    79,    41,    15,   -78,   -78,   178,   178,
     178,    11,    11,   -78,   -78,   -78,   223,   234,    66,   212,
      40,   -78,    59,   -78,   -78,    79,   -78,    88,   -78,   212,
       4,    62,    78,   -78,   -78,   100,   -78,    -1,   -78,    83,
     -10,    36,   -78,   187,    79,    79,   -78,     7,   -78,   -78,
     -78,    79,    42,   -78,   136,   152,   -78,   198,   -78,    93,
     -78,   -78,   -78,    94,   -78,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,    58,    56,    57,     0,     5,
       0,     9,     0,     4,     0,     3,     8,     0,    55,     0,
       2,     0,     0,     7,     0,    52,    53,    54,     0,     0,
       0,    36,     0,    37,    51,    35,     0,    13,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,    15,     0,    14,    50,    44,    45,
      47,    39,    38,    41,    40,    46,    43,    42,     0,    34,
       0,    10,     0,    12,    32,     0,    11,    15,    16,    33,
       0,     0,     0,    20,    30,    15,    31,    15,    22,     0,
       0,     0,    28,     0,     0,     0,    18,    15,    19,    21,
      24,     0,     0,    29,     0,     0,    17,     0,    15,     0,
      23,    27,    15,    25,    15,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,    48,    -7,   111,    95,   -78,    71,   -50,   -78,
     -78,    46,   -77,   -17,   -78,     6,   -78,   -78,   -12,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,     9,    10,    11,    36,    37,    86,    72,
      78,    87,    88,    31,    68,    32,    33,    34,    35,    12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,    13,    17,    80,    71,    21,    17,    25,     1,    18,
      99,    80,    26,    27,    18,    24,    38,    18,    28,   101,
      99,     5,    81,    82,    29,    53,    56,    47,    48,    49,
      81,    82,    98,    84,    39,    40,    41,     3,    92,    30,
     106,    84,     6,     7,     4,     5,    18,    38,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   111,    69,
      89,    53,   113,    70,   115,    90,     6,     7,    89,    91,
      89,    22,    15,    90,    76,    90,    23,    91,    13,   102,
      89,    79,    25,    54,    55,    90,    93,    26,    27,    18,
      22,    77,    80,    28,     5,    23,    24,    94,    18,    29,
     104,   105,    74,    75,    80,    16,     5,   107,     5,    16,
      18,    81,    82,    95,    30,     6,     7,   100,   112,    14,
     114,    83,    84,    81,    82,    85,    73,     6,     7,     6,
       7,    97,     0,    96,    84,    20,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,    51,     0,     0,
       0,    57,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,   108,    51,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     0,    51,     0,     0,     0,   109,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    52,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,    51,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    51,
       0,   103,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,   110,    51,    42,    43,    44,    45,    46,    47,
      48,    49,     0,     0,    51,    42,    43,    44,    45,    46,
      47,    48,    49
};

static const yytype_int8 yycheck[] =
{
      12,     8,    10,     4,    54,    17,    14,     3,    30,    10,
      87,     4,     8,     9,    10,    35,    24,    10,    14,    29,
      97,     6,    23,    24,    20,    35,    38,    16,    17,    18,
      23,    24,    33,    34,    28,    29,    30,    32,    34,    35,
      33,    34,    27,    28,     0,     6,    10,    55,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,   108,    53,
      77,    35,   112,    22,   114,    77,    27,    28,    85,    77,
      87,    29,    33,    85,    34,    87,    34,    85,    85,    91,
      97,    75,     3,    36,    37,    97,    80,     8,     9,    10,
      29,    32,     4,    14,     6,    34,    35,    35,    10,    20,
      94,    95,    36,    37,     4,    10,     6,   101,     6,    14,
      10,    23,    24,    35,    35,    27,    28,    34,    25,     8,
      26,    33,    34,    23,    24,    77,    55,    27,    28,    27,
      28,    85,    -1,    33,    34,    33,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    -1,    -1,
      -1,    36,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    36,    21,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    -1,    -1,    -1,    36,    11,
      12,    13,    14,    15,    16,    17,    18,    34,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    34,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    34,    21,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    11,    12,    13,    14,    15,
      16,    17,    18
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    39,    32,     0,     6,    27,    28,    40,    41,
      42,    43,    57,    41,    42,    33,    43,    57,    10,    56,
      33,    56,    29,    34,    35,     3,     8,     9,    14,    20,
      35,    51,    53,    54,    55,    56,    44,    45,    57,    53,
      53,    53,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    21,    34,    35,    36,    37,    56,    36,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    52,    53,
      22,    46,    47,    45,    36,    37,    34,    32,    48,    53,
       4,    23,    24,    33,    34,    40,    46,    49,    50,    51,
      56,    57,    34,    53,    35,    35,    33,    49,    33,    50,
      34,    29,    56,    34,    53,    53,    33,    53,    36,    36,
      34,    46,    25,    46,    26,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    47,    46,    48,    48,    48,
      48,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    56,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     2,     1,     5,     3,     2,     1,
       6,     7,     3,     1,     2,     0,     2,     4,     3,     3,
       2,     2,     1,     4,     2,     6,     8,     5,     2,     3,
       1,     1,     4,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* program: TPROGRAM '{' vars methods '}'  */
#line 73 "calc-sintaxis.y"
                                                   {Tree *tree = newTree((yyvsp[-4].data), (yyvsp[-2].tree), (yyvsp[-1].tree)); evalType(table, tree); printTree(tree);}
#line 1222 "calc-sintaxis.tab.c"
    break;

  case 3: /* program: TPROGRAM '{' methods '}'  */
#line 74 "calc-sintaxis.y"
                                                    {Tree *tree = newTree((yyvsp[-3].data), (yyvsp[-1].tree), NULL); evalType(table, tree); printTree(tree);}
#line 1228 "calc-sintaxis.tab.c"
    break;

  case 4: /* vars: vars var_decl  */
#line 77 "calc-sintaxis.y"
                      {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "vars"); Tree *tree = newTree(data, (yyvsp[-1].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1234 "calc-sintaxis.tab.c"
    break;

  case 5: /* vars: var_decl  */
#line 78 "calc-sintaxis.y"
                {(yyval.tree) = (yyvsp[0].tree);}
#line 1240 "calc-sintaxis.tab.c"
    break;

  case 6: /* var_decl: ttype id TASIGN expr ';'  */
#line 82 "calc-sintaxis.y"
                             {Tree *leftChild = newTree(newData(TDECL, NO_TYPE, -1, "var declaration + asign"), (yyvsp[-4].tree), (yyvsp[-3].tree)); Tree *tree = newTree((yyvsp[-2].data), leftChild, (yyvsp[-1].tree)); (yyval.tree) = tree; if(checkVarExists(table, (yyvsp[-3].tree)) {error("Re-declaration"); exit(1);} else {;})}
#line 1246 "calc-sintaxis.tab.c"
    break;

  case 7: /* var_decl: ttype id ';'  */
#line 83 "calc-sintaxis.y"
                  {TData *declVar = newData(TDECL, NO_TYPE, -1, "var declaration"); if(insertElem(table, declVar)) (yyval.tree) = newTree(declVar, (yyvsp[-2].tree), (yyvsp[-1].tree)); else {perror("variable already declarated\n"); exit(1);}}
#line 1252 "calc-sintaxis.tab.c"
    break;

  case 8: /* methods: methods method_decl  */
#line 86 "calc-sintaxis.y"
                              {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "methods"); Tree *tree = newTree(data, (yyvsp[-1].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1258 "calc-sintaxis.tab.c"
    break;

  case 9: /* methods: method_decl  */
#line 87 "calc-sintaxis.y"
                       {(yyval.tree) = (yyvsp[0].tree);}
#line 1264 "calc-sintaxis.tab.c"
    break;

  case 10: /* method_decl: ttype id '(' params ')' block  */
#line 90 "calc-sintaxis.y"
                                           {Tree *tree = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body"), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = newTree((yyvsp[-4].tree)->info, (yyvsp[-5].tree), tree); }
#line 1270 "calc-sintaxis.tab.c"
    break;

  case 11: /* method_decl: ttype id '(' params ')' EXTERN ';'  */
#line 91 "calc-sintaxis.y"
                                                 {Tree *tree = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body"), (yyvsp[-3].tree), NULL); (yyval.tree) = newTree((yyvsp[-5].tree)->info, (yyvsp[-6].tree), tree);}
#line 1276 "calc-sintaxis.tab.c"
    break;

  case 12: /* params: params ',' param  */
#line 94 "calc-sintaxis.y"
                          {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "params"); Tree *tree = newTree(data, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1282 "calc-sintaxis.tab.c"
    break;

  case 13: /* params: param  */
#line 95 "calc-sintaxis.y"
                {(yyval.tree) = (yyvsp[0].tree);}
#line 1288 "calc-sintaxis.tab.c"
    break;

  case 14: /* param: ttype id  */
#line 98 "calc-sintaxis.y"
                {(yyval.tree) = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "params"), (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1294 "calc-sintaxis.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 100 "calc-sintaxis.y"
       {LSE* newLevel = (LSE*)malloc(sizeof(LSE)); insertLevel(table, newLevel);}
#line 1300 "calc-sintaxis.tab.c"
    break;

  case 16: /* block: $@1 block1  */
#line 100 "calc-sintaxis.y"
                                                                                         {removeLevel(table); (yyval.tree) = (yyvsp[0].tree);}
#line 1306 "calc-sintaxis.tab.c"
    break;

  case 17: /* block1: '{' vars statements '}'  */
#line 101 "calc-sintaxis.y"
                                  {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "block"); Tree *tree = newTree(data, (yyvsp[-2].tree), (yyvsp[-1].tree)); (yyval.tree) = tree;}
#line 1312 "calc-sintaxis.tab.c"
    break;

  case 18: /* block1: '{' vars '}'  */
#line 102 "calc-sintaxis.y"
                    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1318 "calc-sintaxis.tab.c"
    break;

  case 19: /* block1: '{' statements '}'  */
#line 103 "calc-sintaxis.y"
                          {(yyval.tree) = (yyvsp[-1].tree);}
#line 1324 "calc-sintaxis.tab.c"
    break;

  case 20: /* block1: '{' '}'  */
#line 104 "calc-sintaxis.y"
               {(yyval.tree) = newTree(NULL, NULL, NULL);}
#line 1330 "calc-sintaxis.tab.c"
    break;

  case 21: /* statements: statements single_statement  */
#line 107 "calc-sintaxis.y"
                                        {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "statements"); (yyval.tree) = newTree(data, (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1336 "calc-sintaxis.tab.c"
    break;

  case 22: /* statements: single_statement  */
#line 108 "calc-sintaxis.y"
                             {(yyval.tree) = (yyvsp[0].tree);}
#line 1342 "calc-sintaxis.tab.c"
    break;

  case 23: /* single_statement: id TASIGN expr ';'  */
#line 111 "calc-sintaxis.y"
                                     {(yyval.tree) = newTree((yyvsp[-2].data), (yyvsp[-3].tree), (yyvsp[-1].tree));}
#line 1348 "calc-sintaxis.tab.c"
    break;

  case 24: /* single_statement: method_call ';'  */
#line 112 "calc-sintaxis.y"
                                  {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "single_statement"); (yyval.tree) = newTree(data, (yyvsp[-1].tree), NULL);}
#line 1354 "calc-sintaxis.tab.c"
    break;

  case 25: /* single_statement: TIF '(' expr ')' THEN block  */
#line 113 "calc-sintaxis.y"
                                               {Tree *tree = newTree((yyvsp[-5].data), (yyvsp[-3].tree), newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL)); (yyval.tree) = tree;}
#line 1360 "calc-sintaxis.tab.c"
    break;

  case 26: /* single_statement: TIF '(' expr ')' THEN block TELSE block  */
#line 114 "calc-sintaxis.y"
                                                          {Tree *tree = newTree((yyvsp[-7].data), (yyvsp[-5].tree), newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body-if-else"), newTree((yyvsp[-3].data), (yyvsp[-2].tree), NULL), newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL))); (yyval.tree) = tree;}
#line 1366 "calc-sintaxis.tab.c"
    break;

  case 27: /* single_statement: TWHILE '(' expr ')' block  */
#line 115 "calc-sintaxis.y"
                                            {Tree *tree = newTree((yyvsp[-4].data), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1372 "calc-sintaxis.tab.c"
    break;

  case 28: /* single_statement: TRET ';'  */
#line 116 "calc-sintaxis.y"
                           {(yyval.tree) = newTree((yyvsp[-1].data), NULL, NULL);}
#line 1378 "calc-sintaxis.tab.c"
    break;

  case 29: /* single_statement: TRET expr ';'  */
#line 117 "calc-sintaxis.y"
                                {(yyval.tree) = newTree((yyvsp[-2].data), (yyvsp[-1].tree), NULL);}
#line 1384 "calc-sintaxis.tab.c"
    break;

  case 30: /* single_statement: ';'  */
#line 118 "calc-sintaxis.y"
                      {(yyval.tree) = NULL;}
#line 1390 "calc-sintaxis.tab.c"
    break;

  case 31: /* single_statement: block  */
#line 119 "calc-sintaxis.y"
                        {(yyval.tree) = (yyvsp[0].tree);}
#line 1396 "calc-sintaxis.tab.c"
    break;

  case 32: /* method_call: id '(' exprs ')'  */
#line 122 "calc-sintaxis.y"
                            {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "method_call"); (yyval.tree) = newTree(data, (yyvsp[-3].tree), (yyvsp[-1].tree));}
#line 1402 "calc-sintaxis.tab.c"
    break;

  case 33: /* exprs: exprs ',' expr  */
#line 124 "calc-sintaxis.y"
                      {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "exprs"); (yyval.tree) = newTree(data, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1408 "calc-sintaxis.tab.c"
    break;

  case 34: /* exprs: expr  */
#line 125 "calc-sintaxis.y"
           {(yyval.tree) = (yyvsp[0].tree);}
#line 1414 "calc-sintaxis.tab.c"
    break;

  case 35: /* expr: id  */
#line 128 "calc-sintaxis.y"
         {(yyval.tree) = (yyvsp[0].tree);}
#line 1420 "calc-sintaxis.tab.c"
    break;

  case 36: /* expr: method_call  */
#line 129 "calc-sintaxis.y"
                  {(yyval.tree) = (yyvsp[0].tree);}
#line 1426 "calc-sintaxis.tab.c"
    break;

  case 37: /* expr: literal  */
#line 130 "calc-sintaxis.y"
              {(yyval.tree) = (yyvsp[0].tree);}
#line 1432 "calc-sintaxis.tab.c"
    break;

  case 38: /* expr: expr TMAS expr  */
#line 131 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1438 "calc-sintaxis.tab.c"
    break;

  case 39: /* expr: expr TMENOS expr  */
#line 132 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1444 "calc-sintaxis.tab.c"
    break;

  case 40: /* expr: expr TDIV expr  */
#line 133 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1450 "calc-sintaxis.tab.c"
    break;

  case 41: /* expr: expr TMULT expr  */
#line 134 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1456 "calc-sintaxis.tab.c"
    break;

  case 42: /* expr: expr TAND expr  */
#line 135 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1462 "calc-sintaxis.tab.c"
    break;

  case 43: /* expr: expr TOR expr  */
#line 136 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1468 "calc-sintaxis.tab.c"
    break;

  case 44: /* expr: expr TMENOR expr  */
#line 137 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1474 "calc-sintaxis.tab.c"
    break;

  case 45: /* expr: expr TMAYOR expr  */
#line 138 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1480 "calc-sintaxis.tab.c"
    break;

  case 46: /* expr: expr TMOD expr  */
#line 139 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1486 "calc-sintaxis.tab.c"
    break;

  case 47: /* expr: expr TIGUAL expr  */
#line 140 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1492 "calc-sintaxis.tab.c"
    break;

  case 48: /* expr: TMENOS expr  */
#line 141 "calc-sintaxis.y"
                                {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL); }
#line 1498 "calc-sintaxis.tab.c"
    break;

  case 49: /* expr: TNEG expr  */
#line 142 "calc-sintaxis.y"
                             {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL); }
#line 1504 "calc-sintaxis.tab.c"
    break;

  case 50: /* expr: '(' expr ')'  */
#line 143 "calc-sintaxis.y"
                   {(yyval.tree) = (yyvsp[-1].tree);}
#line 1510 "calc-sintaxis.tab.c"
    break;

  case 51: /* literal: boolValue  */
#line 146 "calc-sintaxis.y"
                   {(yyval.tree) = (yyvsp[0].tree);}
#line 1516 "calc-sintaxis.tab.c"
    break;

  case 52: /* literal: INTV  */
#line 147 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = INTEGER;}
#line 1522 "calc-sintaxis.tab.c"
    break;

  case 53: /* boolValue: TR  */
#line 149 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->value = 1; (yyval.tree)->info->type = BOOL;}
#line 1528 "calc-sintaxis.tab.c"
    break;

  case 54: /* boolValue: FAL  */
#line 150 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->value = 0; (yyval.tree)->info->type = BOOL;}
#line 1534 "calc-sintaxis.tab.c"
    break;

  case 55: /* id: TID  */
#line 152 "calc-sintaxis.y"
            {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); }
#line 1540 "calc-sintaxis.tab.c"
    break;

  case 56: /* ttype: TINT  */
#line 154 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = INTEGER;}
#line 1546 "calc-sintaxis.tab.c"
    break;

  case 57: /* ttype: TBOOL  */
#line 155 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = BOOL;}
#line 1552 "calc-sintaxis.tab.c"
    break;

  case 58: /* ttype: TVOID  */
#line 156 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = VOID;}
#line 1558 "calc-sintaxis.tab.c"
    break;


#line 1562 "calc-sintaxis.tab.c"

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

