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


#line 79 "calc-sintaxis.tab.c"

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
  YYSYMBOL_statements = 47,                /* statements  */
  YYSYMBOL_single_statement = 48,          /* single_statement  */
  YYSYMBOL_method_call = 49,               /* method_call  */
  YYSYMBOL_exprs = 50,                     /* exprs  */
  YYSYMBOL_expr = 51,                      /* expr  */
  YYSYMBOL_literal = 52,                   /* literal  */
  YYSYMBOL_boolValue = 53,                 /* boolValue  */
  YYSYMBOL_id = 54,                        /* id  */
  YYSYMBOL_ttype = 55                      /* ttype  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

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
       0,    68,    68,    69,    70,    73,    74,    78,    79,    82,
      83,    86,    87,    90,    91,    94,    97,    98,    99,   100,
     103,   104,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   118,   120,   121,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     142,   143,   145,   146,   148,   150,   151,   152
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
  "params", "param", "block", "statements", "single_statement",
  "method_call", "exprs", "expr", "literal", "boolValue", "id", "ttype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-28)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,     0,    49,    93,   -28,   -28,    58,   -28,   -28,    25,
      29,   -28,   -28,    93,   -28,   -28,   108,   -28,    14,   -28,
     -28,     2,   -28,    41,    42,    69,   -28,   -28,   -28,    99,
      99,   -28,    99,   -28,   182,   -28,   -28,    45,    99,    99,
     108,    69,   -28,   -28,    56,   120,   -28,   -28,    69,   -28,
     -28,   -28,    99,    99,    94,   -28,   -28,   144,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   -28,   155,
     171,   -21,   -28,   -28,    47,   206,   -27,   231,    99,   -28,
      59,   -28,   197,   197,   197,   121,   121,   -28,   -28,   -28,
     242,   253,    53,    65,   -28,   -28,    99,   217,   -19,   -28,
      69,   -28,    53,   231,   -28,   -17,    59,   -28,    68,    62,
     -28,   -28,    53,   -28,   -28
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     1,     0,    57,    54,     0,
       0,    55,    56,     0,    19,    29,     0,     6,     0,    10,
      30,     0,    21,     0,     0,     0,    51,    52,    53,     0,
       0,    27,     0,    35,     0,    36,    50,    34,     0,     0,
       0,     0,    17,     5,     0,     0,     3,     9,     0,    18,
      20,    23,     0,     0,     0,    47,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     2,    16,     0,     0,     0,    33,     0,     8,
       0,    49,    43,    44,    46,    38,    37,    40,    39,    45,
      42,    41,     0,     0,    22,    31,     0,     0,     0,    14,
       0,    26,     0,    32,     7,     0,     0,    15,    24,     0,
      11,    13,     0,    12,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    97,   -13,    90,    30,   -28,     9,    -1,   -12,
      -5,    60,   -28,    -8,   -28,   -28,    -2,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    16,    17,    18,    19,    98,    99,    20,    21,
      22,    33,    76,    34,    35,    36,    37,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       4,    24,    41,    43,    45,   109,     6,    48,    78,    95,
      96,    24,     8,    79,    24,    13,    50,   105,   106,    24,
       7,    55,    56,    54,    57,     9,    10,    43,    45,    41,
      69,    70,     3,    48,    13,    49,    15,     1,    24,    71,
      50,    11,    12,    24,    75,    77,    74,    46,    47,     5,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      38,    26,     7,    23,    39,     7,    27,    28,     8,   100,
      97,    52,    29,    23,    47,    51,    23,    53,    30,     8,
      53,    23,    80,    11,    12,    13,    11,    12,   103,    72,
     102,   101,    31,    32,   112,   100,   113,     6,   107,     7,
      23,   108,    26,     8,   110,    23,    44,    27,    28,     8,
      40,   114,     6,    29,     7,   111,     9,    10,     8,    30,
      11,    12,     0,    78,     6,    13,    14,    15,    79,    80,
       8,     9,    10,     0,    32,    11,    12,    63,    64,    65,
      13,    42,    15,     9,    10,     0,     0,     0,     0,     0,
       0,     0,    13,    73,    15,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,    67,     0,     0,     0,
      81,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    92,    67,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,     0,     0,     0,    93,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    68,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,     0,
      94,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   104,    67,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    67,    58,    59,    60,    61,    62,    63,
      64,    65
};

static const yytype_int8 yycheck[] =
{
       1,     3,    13,    16,    16,    22,     4,    18,    29,    36,
      37,    13,    10,    34,    16,    32,    21,    36,    37,    21,
       6,    29,    30,    25,    32,    23,    24,    40,    40,    40,
      38,    39,    32,    44,    32,    33,    34,    30,    40,    41,
      45,    27,    28,    45,    52,    53,    48,    33,    18,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      35,     3,     6,     3,    35,     6,     8,     9,    10,    80,
      78,    29,    14,    13,    44,    34,    16,    35,    20,    10,
      35,    21,    35,    27,    28,    32,    27,    28,    96,    33,
      25,    92,    34,    35,    26,   106,    34,     4,   100,     6,
      40,   102,     3,    10,   105,    45,    16,     8,     9,    10,
      13,   112,     4,    14,     6,   106,    23,    24,    10,    20,
      27,    28,    -1,    29,     4,    32,    33,    34,    34,    35,
      10,    23,    24,    -1,    35,    27,    28,    16,    17,    18,
      32,    33,    34,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      36,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    36,    21,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    -1,    -1,    -1,    36,    11,    12,
      13,    14,    15,    16,    17,    18,    34,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    -1,
      34,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    34,    21,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    11,    12,    13,    14,    15,    16,
      17,    18
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    39,    32,    46,     0,     4,     6,    10,    23,
      24,    27,    28,    32,    33,    34,    40,    41,    42,    43,
      46,    47,    48,    49,    54,    55,     3,     8,     9,    14,
      20,    34,    35,    49,    51,    52,    53,    54,    35,    35,
      40,    55,    33,    41,    42,    47,    33,    43,    55,    33,
      48,    34,    29,    35,    54,    51,    51,    51,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    21,    34,    51,
      51,    54,    33,    33,    54,    51,    50,    51,    29,    34,
      35,    36,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    36,    36,    34,    36,    37,    51,    44,    45,
      55,    46,    25,    51,    34,    36,    37,    54,    46,    22,
      46,    45,    26,    34,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    46,    46,    46,    46,
      47,    47,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    55,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     2,     2,     1,     5,     3,     2,
       1,     6,     7,     3,     1,     2,     4,     3,     3,     2,
       2,     1,     4,     2,     6,     8,     5,     2,     3,     1,
       1,     4,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 68 "calc-sintaxis.y"
                                                   {Tree *tree = newTree((yyvsp[-4].data), (yyvsp[-2].tree), (yyvsp[-1].tree)); printTree(tree);}
#line 1220 "calc-sintaxis.tab.c"
    break;

  case 3: /* program: TPROGRAM '{' methods '}'  */
#line 69 "calc-sintaxis.y"
                                                    {Tree *tree = newTree((yyvsp[-3].data), (yyvsp[-1].tree), NULL); printTree(tree);}
#line 1226 "calc-sintaxis.tab.c"
    break;

  case 4: /* program: TPROGRAM block  */
#line 70 "calc-sintaxis.y"
                                               {Tree *tree = newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL); printTree(tree);}
#line 1232 "calc-sintaxis.tab.c"
    break;

  case 5: /* vars: vars var_decl  */
#line 73 "calc-sintaxis.y"
                      {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, ""); Tree *tree = newTree(data, (yyvsp[-1].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1238 "calc-sintaxis.tab.c"
    break;

  case 6: /* vars: var_decl  */
#line 74 "calc-sintaxis.y"
                {(yyval.tree) = (yyvsp[0].tree);}
#line 1244 "calc-sintaxis.tab.c"
    break;

  case 7: /* var_decl: ttype id TASIGN expr ';'  */
#line 78 "calc-sintaxis.y"
                             {Tree *leftChild = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "var declaration"), (yyvsp[-4].tree), (yyvsp[-3].tree)); Tree *tree = newTree((yyvsp[-2].data), leftChild, (yyvsp[-1].tree)); (yyval.tree) = tree;}
#line 1250 "calc-sintaxis.tab.c"
    break;

  case 8: /* var_decl: ttype id ';'  */
#line 79 "calc-sintaxis.y"
                  {(yyval.tree) = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "var declaration"), (yyvsp[-2].tree), (yyvsp[-1].tree));}
#line 1256 "calc-sintaxis.tab.c"
    break;

  case 9: /* methods: methods method_decl  */
#line 82 "calc-sintaxis.y"
                              {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "methods"); Tree *tree = newTree(data, (yyvsp[-1].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1262 "calc-sintaxis.tab.c"
    break;

  case 10: /* methods: method_decl  */
#line 83 "calc-sintaxis.y"
                       {(yyval.tree) = (yyvsp[0].tree);}
#line 1268 "calc-sintaxis.tab.c"
    break;

  case 11: /* method_decl: ttype id '(' params ')' block  */
#line 86 "calc-sintaxis.y"
                                           {Tree *tree = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body"), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = newTree((yyvsp[-4].tree)->info, (yyvsp[-5].tree), tree); }
#line 1274 "calc-sintaxis.tab.c"
    break;

  case 12: /* method_decl: ttype id '(' params ')' EXTERN ';'  */
#line 87 "calc-sintaxis.y"
                                                 {Tree *tree = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "body"), (yyvsp[-3].tree), NULL); (yyval.tree) = newTree((yyvsp[-5].tree)->info, (yyvsp[-6].tree), tree);}
#line 1280 "calc-sintaxis.tab.c"
    break;

  case 13: /* params: params ',' param  */
#line 90 "calc-sintaxis.y"
                          {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "params"); Tree *tree = newTree(data, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1286 "calc-sintaxis.tab.c"
    break;

  case 14: /* params: param  */
#line 91 "calc-sintaxis.y"
                {(yyval.tree) = (yyvsp[0].tree);}
#line 1292 "calc-sintaxis.tab.c"
    break;

  case 15: /* param: ttype id  */
#line 94 "calc-sintaxis.y"
                {(yyval.tree) = newTree(newData(T_YYUNDEF, NO_TYPE, -1, "params"), (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1298 "calc-sintaxis.tab.c"
    break;

  case 16: /* block: '{' vars statements '}'  */
#line 97 "calc-sintaxis.y"
                                 {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "block"); Tree *tree = newTree(data, (yyvsp[-2].tree), (yyvsp[-1].tree)); (yyval.tree) = tree;}
#line 1304 "calc-sintaxis.tab.c"
    break;

  case 17: /* block: '{' vars '}'  */
#line 98 "calc-sintaxis.y"
                    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1310 "calc-sintaxis.tab.c"
    break;

  case 18: /* block: '{' statements '}'  */
#line 99 "calc-sintaxis.y"
                          {(yyval.tree) = (yyvsp[-1].tree);}
#line 1316 "calc-sintaxis.tab.c"
    break;

  case 19: /* block: '{' '}'  */
#line 100 "calc-sintaxis.y"
               {(yyval.tree) = newTree(NULL, NULL, NULL);}
#line 1322 "calc-sintaxis.tab.c"
    break;

  case 20: /* statements: statements single_statement  */
#line 103 "calc-sintaxis.y"
                                        {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "statements"); (yyval.tree) = newTree(data, (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1328 "calc-sintaxis.tab.c"
    break;

  case 21: /* statements: single_statement  */
#line 104 "calc-sintaxis.y"
                             {(yyval.tree) = (yyvsp[0].tree);}
#line 1334 "calc-sintaxis.tab.c"
    break;

  case 22: /* single_statement: id TASIGN expr ';'  */
#line 107 "calc-sintaxis.y"
                                     {(yyval.tree) = newTree((yyvsp[-2].data), (yyvsp[-3].tree), (yyvsp[-1].tree));}
#line 1340 "calc-sintaxis.tab.c"
    break;

  case 23: /* single_statement: method_call ';'  */
#line 108 "calc-sintaxis.y"
                                  {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "single_statement"); (yyval.tree) = newTree(data, (yyvsp[-1].tree), NULL);}
#line 1346 "calc-sintaxis.tab.c"
    break;

  case 24: /* single_statement: TIF '(' expr ')' THEN block  */
#line 109 "calc-sintaxis.y"
                                               {Tree *tree = newTree((yyvsp[-5].data), (yyvsp[-3].tree), (yyvsp[0].tree)); printTree(tree);}
#line 1352 "calc-sintaxis.tab.c"
    break;

  case 25: /* single_statement: TIF '(' expr ')' THEN block TELSE block  */
#line 110 "calc-sintaxis.y"
                                                          {Tree *tree = newTree((yyvsp[-7].data), (yyvsp[-5].tree), newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree))); (yyval.tree) = tree;}
#line 1358 "calc-sintaxis.tab.c"
    break;

  case 26: /* single_statement: TWHILE '(' expr ')' block  */
#line 111 "calc-sintaxis.y"
                                            {Tree *tree = newTree((yyvsp[-4].data), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = tree;}
#line 1364 "calc-sintaxis.tab.c"
    break;

  case 27: /* single_statement: TRET ';'  */
#line 112 "calc-sintaxis.y"
                           {(yyval.tree) = newTree((yyvsp[-1].data), NULL, NULL);}
#line 1370 "calc-sintaxis.tab.c"
    break;

  case 28: /* single_statement: TRET expr ';'  */
#line 113 "calc-sintaxis.y"
                                {(yyval.tree) = newTree((yyvsp[-2].data), (yyvsp[-1].tree), NULL);}
#line 1376 "calc-sintaxis.tab.c"
    break;

  case 29: /* single_statement: ';'  */
#line 114 "calc-sintaxis.y"
                      {(yyval.tree) = NULL;}
#line 1382 "calc-sintaxis.tab.c"
    break;

  case 30: /* single_statement: block  */
#line 115 "calc-sintaxis.y"
                        {(yyval.tree) = (yyvsp[0].tree);}
#line 1388 "calc-sintaxis.tab.c"
    break;

  case 31: /* method_call: id '(' exprs ')'  */
#line 118 "calc-sintaxis.y"
                            {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "method_call"); (yyval.tree) = newTree(data, (yyvsp[-3].tree), (yyvsp[-1].tree));}
#line 1394 "calc-sintaxis.tab.c"
    break;

  case 32: /* exprs: exprs ',' expr  */
#line 120 "calc-sintaxis.y"
                      {TData* data = newData(T_YYUNDEF, NO_TYPE, -1, "exprs"); (yyval.tree) = newTree(data, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1400 "calc-sintaxis.tab.c"
    break;

  case 33: /* exprs: expr  */
#line 121 "calc-sintaxis.y"
           {(yyval.tree) = (yyvsp[0].tree);}
#line 1406 "calc-sintaxis.tab.c"
    break;

  case 34: /* expr: id  */
#line 124 "calc-sintaxis.y"
         {(yyval.tree) = (yyvsp[0].tree);}
#line 1412 "calc-sintaxis.tab.c"
    break;

  case 35: /* expr: method_call  */
#line 125 "calc-sintaxis.y"
                  {(yyval.tree) = (yyvsp[0].tree);}
#line 1418 "calc-sintaxis.tab.c"
    break;

  case 36: /* expr: literal  */
#line 126 "calc-sintaxis.y"
              {(yyval.tree) = (yyvsp[0].tree);}
#line 1424 "calc-sintaxis.tab.c"
    break;

  case 37: /* expr: expr TMAS expr  */
#line 127 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1430 "calc-sintaxis.tab.c"
    break;

  case 38: /* expr: expr TMENOS expr  */
#line 128 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1436 "calc-sintaxis.tab.c"
    break;

  case 39: /* expr: expr TDIV expr  */
#line 129 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1442 "calc-sintaxis.tab.c"
    break;

  case 40: /* expr: expr TMULT expr  */
#line 130 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1448 "calc-sintaxis.tab.c"
    break;

  case 41: /* expr: expr TAND expr  */
#line 131 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1454 "calc-sintaxis.tab.c"
    break;

  case 42: /* expr: expr TOR expr  */
#line 132 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1460 "calc-sintaxis.tab.c"
    break;

  case 43: /* expr: expr TMENOR expr  */
#line 133 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1466 "calc-sintaxis.tab.c"
    break;

  case 44: /* expr: expr TMAYOR expr  */
#line 134 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1472 "calc-sintaxis.tab.c"
    break;

  case 45: /* expr: expr TMOD expr  */
#line 135 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1478 "calc-sintaxis.tab.c"
    break;

  case 46: /* expr: expr TIGUAL expr  */
#line 136 "calc-sintaxis.y"
                        {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1484 "calc-sintaxis.tab.c"
    break;

  case 47: /* expr: TMENOS expr  */
#line 137 "calc-sintaxis.y"
                                {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL); }
#line 1490 "calc-sintaxis.tab.c"
    break;

  case 48: /* expr: TNEG expr  */
#line 138 "calc-sintaxis.y"
                             {(yyval.tree) = newTree((yyvsp[-1].data), (yyvsp[0].tree), NULL); }
#line 1496 "calc-sintaxis.tab.c"
    break;

  case 49: /* expr: '(' expr ')'  */
#line 139 "calc-sintaxis.y"
                   {(yyval.tree) = (yyvsp[-1].tree);}
#line 1502 "calc-sintaxis.tab.c"
    break;

  case 50: /* literal: boolValue  */
#line 142 "calc-sintaxis.y"
                   {(yyval.tree) = (yyvsp[0].tree);}
#line 1508 "calc-sintaxis.tab.c"
    break;

  case 51: /* literal: INTV  */
#line 143 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = INTEGER;}
#line 1514 "calc-sintaxis.tab.c"
    break;

  case 52: /* boolValue: TR  */
#line 145 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->value = 1; (yyval.tree)->info->type = BOOL;}
#line 1520 "calc-sintaxis.tab.c"
    break;

  case 53: /* boolValue: FAL  */
#line 146 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->value = 0; (yyval.tree)->info->type = BOOL;}
#line 1526 "calc-sintaxis.tab.c"
    break;

  case 54: /* id: TID  */
#line 148 "calc-sintaxis.y"
            {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); }
#line 1532 "calc-sintaxis.tab.c"
    break;

  case 55: /* ttype: TINT  */
#line 150 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = INTEGER;}
#line 1538 "calc-sintaxis.tab.c"
    break;

  case 56: /* ttype: TBOOL  */
#line 151 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = BOOL;}
#line 1544 "calc-sintaxis.tab.c"
    break;

  case 57: /* ttype: TVOID  */
#line 152 "calc-sintaxis.y"
                {(yyval.tree) = newTree((yyvsp[0].data), NULL, NULL); (yyval.tree)->info->type = VOID;}
#line 1550 "calc-sintaxis.tab.c"
    break;


#line 1554 "calc-sintaxis.tab.c"

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

