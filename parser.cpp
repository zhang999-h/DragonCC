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
#line 2 "parser.y"

    #include<string>
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.hpp"
    #include"ast.h"
    #include "define.h"
    #include <memory>
    #include <cstring>
    #include <stdarg.h>
    using namespace std;
    extern int yylineno;
    extern int yylex();
    extern void yyerror(const char *s);
    extern void initFileName(char *name);
    char filename[100];
    unique_ptr<CompUnitAST> root;

#line 90 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_GTE = 6,                        /* GTE  */
  YYSYMBOL_LTE = 7,                        /* LTE  */
  YYSYMBOL_GT = 8,                         /* GT  */
  YYSYMBOL_LT = 9,                         /* LT  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_NEQ = 11,                       /* NEQ  */
  YYSYMBOL_INTTYPE = 12,                   /* INTTYPE  */
  YYSYMBOL_FLOATTYPE = 13,                 /* FLOATTYPE  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_CONST = 15,                     /* CONST  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 21,                  /* CONTINUE  */
  YYSYMBOL_LP = 22,                        /* LP  */
  YYSYMBOL_RP = 23,                        /* RP  */
  YYSYMBOL_LB = 24,                        /* LB  */
  YYSYMBOL_RB = 25,                        /* RB  */
  YYSYMBOL_LC = 26,                        /* LC  */
  YYSYMBOL_RC = 27,                        /* RC  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_MINUS = 32,                     /* MINUS  */
  YYSYMBOL_ADD = 33,                       /* ADD  */
  YYSYMBOL_MUL = 34,                       /* MUL  */
  YYSYMBOL_DIV = 35,                       /* DIV  */
  YYSYMBOL_MOD = 36,                       /* MOD  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_LOWER_THAN_ELSE = 39,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_Program = 41,                   /* Program  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_DeclDef = 43,                   /* DeclDef  */
  YYSYMBOL_Decl = 44,                      /* Decl  */
  YYSYMBOL_BType = 45,                     /* BType  */
  YYSYMBOL_VoidType = 46,                  /* VoidType  */
  YYSYMBOL_DefList = 47,                   /* DefList  */
  YYSYMBOL_Def = 48,                       /* Def  */
  YYSYMBOL_Arrays = 49,                    /* Arrays  */
  YYSYMBOL_InitVal = 50,                   /* InitVal  */
  YYSYMBOL_InitValList = 51,               /* InitValList  */
  YYSYMBOL_FuncDef = 52,                   /* FuncDef  */
  YYSYMBOL_FuncFParamList = 53,            /* FuncFParamList  */
  YYSYMBOL_FuncFParam = 54,                /* FuncFParam  */
  YYSYMBOL_Block = 55,                     /* Block  */
  YYSYMBOL_BlockItemList = 56,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 57,                 /* BlockItem  */
  YYSYMBOL_Stmt = 58,                      /* Stmt  */
  YYSYMBOL_SelectStmt = 59,                /* SelectStmt  */
  YYSYMBOL_IterationStmt = 60,             /* IterationStmt  */
  YYSYMBOL_ReturnStmt = 61,                /* ReturnStmt  */
  YYSYMBOL_Exp = 62,                       /* Exp  */
  YYSYMBOL_Cond = 63,                      /* Cond  */
  YYSYMBOL_LVal = 64,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 65,                /* PrimaryExp  */
  YYSYMBOL_Number = 66,                    /* Number  */
  YYSYMBOL_UnaryExp = 67,                  /* UnaryExp  */
  YYSYMBOL_Call = 68,                      /* Call  */
  YYSYMBOL_UnaryOp = 69,                   /* UnaryOp  */
  YYSYMBOL_FuncCParamList = 70,            /* FuncCParamList  */
  YYSYMBOL_MulExp = 71,                    /* MulExp  */
  YYSYMBOL_AddExp = 72,                    /* AddExp  */
  YYSYMBOL_RelExp = 73,                    /* RelExp  */
  YYSYMBOL_EqExp = 74,                     /* EqExp  */
  YYSYMBOL_LAndExp = 75,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 76                     /* LOrExp  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   119,   123,   130,   134,   141,   147,   156,
     159,   165,   171,   175,   182,   188,   193,   198,   205,   209,
     217,   221,   224,   231,   235,   242,   249,   255,   262,   271,
     275,   282,   288,   294,   304,   307,   314,   318,   325,   329,
     336,   340,   346,   351,   355,   359,   364,   369,   374,   382,
     387,   396,   404,   408,   414,   420,   426,   430,   438,   442,
     446,   453,   458,   466,   470,   474,   482,   486,   494,   497,
     500,   506,   510,   517,   521,   527,   533,   542,   546,   552,
     561,   565,   571,   577,   583,   592,   596,   602,   611,   615,
     623,   627
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "GTE", "LTE", "GT", "LT", "EQ", "NEQ", "INTTYPE", "FLOATTYPE", "VOID",
  "CONST", "RETURN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "LP",
  "RP", "LB", "RB", "LC", "RC", "COMMA", "SEMICOLON", "NOT", "ASSIGN",
  "MINUS", "ADD", "MUL", "DIV", "MOD", "AND", "OR", "LOWER_THAN_ELSE",
  "$accept", "Program", "CompUnit", "DeclDef", "Decl", "BType", "VoidType",
  "DefList", "Def", "Arrays", "InitVal", "InitValList", "FuncDef",
  "FuncFParamList", "FuncFParam", "Block", "BlockItemList", "BlockItem",
  "Stmt", "SelectStmt", "IterationStmt", "ReturnStmt", "Exp", "Cond",
  "LVal", "PrimaryExp", "Number", "UnaryExp", "Call", "UnaryOp",
  "FuncCParamList", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,  -127,  -127,  -127,    63,    19,   118,  -127,  -127,    45,
      53,  -127,    55,  -127,  -127,   -11,    61,  -127,    40,    -2,
      66,     3,   192,   156,    25,    55,  -127,    12,  -127,    73,
      74,     0,  -127,  -127,  -127,    14,   192,  -127,  -127,  -127,
      82,  -127,  -127,  -127,  -127,  -127,   192,    37,    69,   144,
    -127,  -127,   192,   156,  -127,    73,    31,    93,  -127,    87,
      73,    63,   176,    94,    98,  -127,  -127,   192,   192,   192,
     192,   192,  -127,  -127,    89,    99,  -127,  -127,    73,   188,
     116,   120,   123,   126,  -127,  -127,  -127,    55,  -127,   124,
    -127,  -127,  -127,  -127,  -127,   129,   136,   143,  -127,  -127,
    -127,  -127,    59,  -127,  -127,  -127,  -127,    37,    37,  -127,
     156,  -127,  -127,  -127,   140,   192,   192,  -127,  -127,  -127,
    -127,  -127,   192,   148,  -127,   192,  -127,  -127,   150,    69,
     194,   152,   138,   145,   161,   158,    94,  -127,    48,   192,
     192,   192,   192,   192,   192,   192,   192,    48,  -127,   167,
      69,    69,    69,    69,   194,   194,   152,   138,  -127,    48,
    -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    11,     0,     0,     2,     4,     5,     0,
       0,     6,     0,     1,     3,    17,     0,    12,     0,    17,
       0,     0,     0,     0,    16,     0,     8,     0,     7,     0,
       0,     0,    29,    61,    62,    56,     0,    70,    69,    68,
       0,    59,    63,    60,    73,    64,     0,    77,    54,     0,
      15,    20,     0,     0,    13,     0,     0,     0,    26,    31,
       0,     0,     0,    57,     0,    18,    65,     0,     0,     0,
       0,     0,    21,    24,     0,     0,    14,    28,     0,     0,
       0,     0,     0,     0,    34,    40,    38,     0,    45,     0,
      36,    39,    47,    48,    46,     0,    59,     0,    25,    30,
      66,    71,     0,    58,    74,    75,    76,    79,    78,    22,
       0,    19,    27,    53,     0,     0,     0,    44,    43,    35,
      37,    42,     0,    32,    67,     0,    23,    52,     0,    80,
      85,    88,    90,    55,     0,     0,    33,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    49,
      81,    82,    83,    84,    86,    87,    89,    91,    51,     0,
      50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   184,   -50,     4,  -127,   182,   179,   -32,
     -44,  -127,  -127,   178,   146,   -23,  -127,   122,  -126,  -127,
    -127,  -127,   -22,    96,   -55,  -127,  -127,    17,  -127,  -127,
    -127,    64,   -98,    21,    68,    70,  -127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    30,    10,    16,    17,    24,
      50,    74,    11,    31,    32,    88,    89,    90,    91,    92,
      93,    94,    95,   128,    41,    42,    43,    44,    45,    46,
     102,    47,    48,   130,   131,   132,   133
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    51,    96,    63,     9,    73,    58,    86,    12,    76,
       9,    21,   149,    22,    64,     1,     2,   129,   129,    13,
      23,   158,    22,    60,     1,     2,    29,    51,    61,    23,
      75,    51,    77,   160,    96,    55,    62,    98,    22,    86,
     101,   150,   151,   152,   153,   129,   129,   129,   129,    52,
      15,    33,    34,    35,    78,   112,    53,   114,    18,    61,
      19,    87,    27,    66,    79,    80,   126,    81,    82,    83,
      36,    67,    68,    69,    57,     1,     2,    85,    37,    59,
      38,    39,   124,    96,   104,   105,   106,   125,    51,    25,
      26,   136,    96,    87,    25,    28,    33,    34,    35,    57,
     135,    70,    71,   137,    96,     1,     2,    65,     4,    79,
      80,    97,    81,    82,    83,    36,   109,   110,    52,    57,
      84,   103,    85,    37,   111,    38,    39,    33,    34,    35,
       1,     2,     3,     4,   107,   108,     1,     2,   115,     4,
      79,    80,   116,    81,    82,    83,    36,    33,    34,    35,
      57,   119,   117,    85,    37,   118,    38,    39,   121,    33,
      34,    35,   143,   144,   154,   155,    36,   122,   123,   127,
      49,    72,    22,   138,    37,   145,    38,    39,    36,    33,
      34,    35,    49,   146,   147,   159,    37,   148,    38,    39,
      14,    33,    34,    35,    20,    33,    34,    35,    36,   100,
     139,   140,   141,   142,    54,    56,    37,    99,    38,    39,
      36,   120,   134,   156,    36,     0,   157,   113,    37,     0,
      38,    39,    37,     0,    38,    39
};

static const yytype_int16 yycheck[] =
{
      22,    23,    57,    35,     0,    49,    29,    57,     4,    53,
       6,    22,   138,    24,    36,    12,    13,   115,   116,     0,
      31,   147,    24,    23,    12,    13,    23,    49,    28,    31,
      52,    53,    55,   159,    89,    23,    22,    60,    24,    89,
      62,   139,   140,   141,   142,   143,   144,   145,   146,    24,
       5,     3,     4,     5,    23,    78,    31,    79,     5,    28,
       5,    57,    22,    46,    16,    17,   110,    19,    20,    21,
      22,    34,    35,    36,    26,    12,    13,    29,    30,     5,
      32,    33,    23,   138,    67,    68,    69,    28,   110,    28,
      29,   123,   147,    89,    28,    29,     3,     4,     5,    26,
     122,    32,    33,   125,   159,    12,    13,    25,    15,    16,
      17,    24,    19,    20,    21,    22,    27,    28,    24,    26,
      27,    23,    29,    30,    25,    32,    33,     3,     4,     5,
      12,    13,    14,    15,    70,    71,    12,    13,    22,    15,
      16,    17,    22,    19,    20,    21,    22,     3,     4,     5,
      26,    27,    29,    29,    30,    29,    32,    33,    29,     3,
       4,     5,    10,    11,   143,   144,    22,    31,    25,    29,
      26,    27,    24,    23,    30,    37,    32,    33,    22,     3,
       4,     5,    26,    38,    23,    18,    30,    29,    32,    33,
       6,     3,     4,     5,    12,     3,     4,     5,    22,    23,
       6,     7,     8,     9,    25,    27,    30,    61,    32,    33,
      22,    89,   116,   145,    22,    -1,   146,    29,    30,    -1,
      32,    33,    30,    -1,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    14,    15,    41,    42,    43,    44,    45,
      46,    52,    45,     0,    43,     5,    47,    48,     5,     5,
      47,    22,    24,    31,    49,    28,    29,    22,    29,    23,
      45,    53,    54,     3,     4,     5,    22,    30,    32,    33,
      62,    64,    65,    66,    67,    68,    69,    71,    72,    26,
      50,    62,    24,    31,    48,    23,    53,    26,    55,     5,
      23,    28,    22,    49,    62,    25,    67,    34,    35,    36,
      32,    33,    27,    50,    51,    62,    50,    55,    23,    16,
      17,    19,    20,    21,    27,    29,    44,    45,    55,    56,
      57,    58,    59,    60,    61,    62,    64,    24,    55,    54,
      23,    62,    70,    23,    67,    67,    67,    71,    71,    27,
      28,    25,    55,    29,    62,    22,    22,    29,    29,    27,
      57,    29,    31,    25,    23,    28,    50,    29,    63,    72,
      73,    74,    75,    76,    63,    62,    49,    62,    23,     6,
       7,     8,     9,    10,    11,    37,    38,    23,    29,    58,
      72,    72,    72,    72,    73,    73,    74,    75,    58,    18,
      58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    47,    47,    48,    48,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    60,    61,    61,    62,    63,    64,    64,    65,    65,
      65,    66,    66,    67,    67,    67,    68,    68,    69,    69,
      69,    70,    70,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    73,    73,    73,    74,    74,    74,    75,    75,
      76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     3,     1,
       1,     1,     1,     3,     4,     3,     2,     1,     3,     4,
       1,     2,     3,     3,     1,     6,     5,     6,     5,     1,
       3,     2,     4,     5,     2,     3,     1,     2,     1,     1,
       1,     4,     2,     2,     2,     1,     1,     1,     1,     5,
       7,     5,     3,     2,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     1,     1,
       1,     1,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3
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
  case 2: /* Program: CompUnit  */
#line 113 "parser.y"
           {
    root = unique_ptr<CompUnitAST>((yyvsp[0].compUnit));
  }
#line 1280 "parser.cpp"
    break;

  case 3: /* CompUnit: CompUnit DeclDef  */
#line 119 "parser.y"
                   {
    (yyval.compUnit) = (yyvsp[-1].compUnit);
    (yyval.compUnit)->declDefList.push_back(unique_ptr<DeclDefAST>((yyvsp[0].declDef)));
  }
#line 1289 "parser.cpp"
    break;

  case 4: /* CompUnit: DeclDef  */
#line 123 "parser.y"
          {
    (yyval.compUnit) = new CompUnitAST();
    (yyval.compUnit)->declDefList.push_back(unique_ptr<DeclDefAST>((yyvsp[0].declDef)));
  }
#line 1298 "parser.cpp"
    break;

  case 5: /* DeclDef: Decl  */
#line 130 "parser.y"
       {
    (yyval.declDef) = new DeclDefAST();
    (yyval.declDef)->Decl = unique_ptr<DeclAST>((yyvsp[0].decl));
  }
#line 1307 "parser.cpp"
    break;

  case 6: /* DeclDef: FuncDef  */
#line 134 "parser.y"
          {
    (yyval.declDef) = new DeclDefAST();
    (yyval.declDef)->funcDef = unique_ptr<FuncDefAST>((yyvsp[0].funcDef));
  }
#line 1316 "parser.cpp"
    break;

  case 7: /* Decl: CONST BType DefList SEMICOLON  */
#line 141 "parser.y"
                                {
    (yyval.decl) = new DeclAST();
    (yyval.decl)->isConst = true;
    (yyval.decl)->bType = (yyvsp[-2].ty);
    (yyval.decl)->defList.swap((yyvsp[-1].defList)->list);
  }
#line 1327 "parser.cpp"
    break;

  case 8: /* Decl: BType DefList SEMICOLON  */
#line 147 "parser.y"
                          {
    (yyval.decl) = new DeclAST();
    (yyval.decl)->isConst = false;
    (yyval.decl)->bType = (yyvsp[-2].ty);
    (yyval.decl)->defList.swap((yyvsp[-1].defList)->list);
  }
#line 1338 "parser.cpp"
    break;

  case 9: /* BType: INTTYPE  */
#line 156 "parser.y"
          {
    (yyval.ty) = TYPE_INT;
  }
#line 1346 "parser.cpp"
    break;

  case 10: /* BType: FLOATTYPE  */
#line 159 "parser.y"
            {
    (yyval.ty) = TYPE_FLOAT;
  }
#line 1354 "parser.cpp"
    break;

  case 11: /* VoidType: VOID  */
#line 165 "parser.y"
       {
    (yyval.ty) = TYPE_VOID;
  }
#line 1362 "parser.cpp"
    break;

  case 12: /* DefList: Def  */
#line 171 "parser.y"
      {
    (yyval.defList) = new DefListAST();
    (yyval.defList)->list.push_back(unique_ptr<DefAST>((yyvsp[0].def)));
  }
#line 1371 "parser.cpp"
    break;

  case 13: /* DefList: DefList COMMA Def  */
#line 175 "parser.y"
                    {
    (yyval.defList) = (yyvsp[-2].defList);
    (yyval.defList)->list.push_back(unique_ptr<DefAST>((yyvsp[0].def)));
  }
#line 1380 "parser.cpp"
    break;

  case 14: /* Def: ID Arrays ASSIGN InitVal  */
#line 182 "parser.y"
                           {
    (yyval.def) = new DefAST();
    (yyval.def)->id = unique_ptr<string>((yyvsp[-3].id_name));
    (yyval.def)->arrays.swap((yyvsp[-2].arrays)->list);
    (yyval.def)->initVal = unique_ptr<InitValAST>((yyvsp[0].initVal));
  }
#line 1391 "parser.cpp"
    break;

  case 15: /* Def: ID ASSIGN InitVal  */
#line 188 "parser.y"
                    {
    (yyval.def) = new DefAST();
    (yyval.def)->id = unique_ptr<string>((yyvsp[-2].id_name));
    (yyval.def)->initVal = unique_ptr<InitValAST>((yyvsp[0].initVal));
  }
#line 1401 "parser.cpp"
    break;

  case 16: /* Def: ID Arrays  */
#line 193 "parser.y"
            {
    (yyval.def) = new DefAST();
    (yyval.def)->id = unique_ptr<string>((yyvsp[-1].id_name));
    (yyval.def)->arrays.swap((yyvsp[0].arrays)->list);
  }
#line 1411 "parser.cpp"
    break;

  case 17: /* Def: ID  */
#line 198 "parser.y"
     {
    (yyval.def) = new DefAST();
    (yyval.def)->id = unique_ptr<string>((yyvsp[0].id_name));
  }
#line 1420 "parser.cpp"
    break;

  case 18: /* Arrays: LB Exp RB  */
#line 205 "parser.y"
            {
    (yyval.arrays) = new ArraysAST();
    (yyval.arrays)->list.push_back(unique_ptr<AddExpAST>((yyvsp[-1].addExp)));
  }
#line 1429 "parser.cpp"
    break;

  case 19: /* Arrays: Arrays LB Exp RB  */
#line 209 "parser.y"
                   {
    (yyval.arrays) = (yyvsp[-3].arrays);
    (yyval.arrays)->list.push_back(unique_ptr<AddExpAST>((yyvsp[-1].addExp)));
  }
#line 1438 "parser.cpp"
    break;

  case 20: /* InitVal: Exp  */
#line 217 "parser.y"
      {
    (yyval.initVal) = new InitValAST();
    (yyval.initVal)->exp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
  }
#line 1447 "parser.cpp"
    break;

  case 21: /* InitVal: LC RC  */
#line 221 "parser.y"
        {
    (yyval.initVal) = new InitValAST();
  }
#line 1455 "parser.cpp"
    break;

  case 22: /* InitVal: LC InitValList RC  */
#line 224 "parser.y"
                    {
    (yyval.initVal) = new InitValAST();
    (yyval.initVal)->initValList.swap((yyvsp[-1].initValList)->list);
  }
#line 1464 "parser.cpp"
    break;

  case 23: /* InitValList: InitValList COMMA InitVal  */
#line 231 "parser.y"
                            {
    (yyval.initValList) = (yyvsp[-2].initValList);
    (yyval.initValList)->list.push_back(unique_ptr<InitValAST>((yyvsp[0].initVal)));
  }
#line 1473 "parser.cpp"
    break;

  case 24: /* InitValList: InitVal  */
#line 235 "parser.y"
          {
    (yyval.initValList) = new InitValListAST();
    (yyval.initValList)->list.push_back(unique_ptr<InitValAST>((yyvsp[0].initVal)));
  }
#line 1482 "parser.cpp"
    break;

  case 25: /* FuncDef: BType ID LP FuncFParamList RP Block  */
#line 242 "parser.y"
                                      {
    (yyval.funcDef) = new FuncDefAST();
    (yyval.funcDef)->funcType = (yyvsp[-5].ty);
    (yyval.funcDef)->id = unique_ptr<string>((yyvsp[-4].id_name));
    (yyval.funcDef)->funcFParamList.swap((yyvsp[-2].FuncFParamList)->list);
    (yyval.funcDef)->block = unique_ptr<BlockAST>((yyvsp[0].block));
  }
#line 1494 "parser.cpp"
    break;

  case 26: /* FuncDef: BType ID LP RP Block  */
#line 249 "parser.y"
                       {
    (yyval.funcDef) = new FuncDefAST();
    (yyval.funcDef)->funcType = (yyvsp[-4].ty);
    (yyval.funcDef)->id = unique_ptr<string>((yyvsp[-3].id_name));
    (yyval.funcDef)->block = unique_ptr<BlockAST>((yyvsp[0].block));
  }
#line 1505 "parser.cpp"
    break;

  case 27: /* FuncDef: VoidType ID LP FuncFParamList RP Block  */
#line 255 "parser.y"
                                         {
    (yyval.funcDef) = new FuncDefAST();
    (yyval.funcDef)->funcType = (yyvsp[-5].ty);
    (yyval.funcDef)->id = unique_ptr<string>((yyvsp[-4].id_name));
    (yyval.funcDef)->funcFParamList.swap((yyvsp[-2].FuncFParamList)->list);
    (yyval.funcDef)->block = unique_ptr<BlockAST>((yyvsp[0].block));
  }
#line 1517 "parser.cpp"
    break;

  case 28: /* FuncDef: VoidType ID LP RP Block  */
#line 262 "parser.y"
                          {
    (yyval.funcDef) = new FuncDefAST();
    (yyval.funcDef)->funcType = (yyvsp[-4].ty);
    (yyval.funcDef)->id = unique_ptr<string>((yyvsp[-3].id_name));
    (yyval.funcDef)->block = unique_ptr<BlockAST>((yyvsp[0].block));
  }
#line 1528 "parser.cpp"
    break;

  case 29: /* FuncFParamList: FuncFParam  */
#line 271 "parser.y"
             {
    (yyval.FuncFParamList) = new FuncFParamListAST();
    (yyval.FuncFParamList)->list.push_back(unique_ptr<FuncFParamAST>((yyvsp[0].funcFParam)));
  }
#line 1537 "parser.cpp"
    break;

  case 30: /* FuncFParamList: FuncFParamList COMMA FuncFParam  */
#line 275 "parser.y"
                                  {
    (yyval.FuncFParamList) = (yyvsp[-2].FuncFParamList);
    (yyval.FuncFParamList)->list.push_back(unique_ptr<FuncFParamAST>((yyvsp[0].funcFParam)));
  }
#line 1546 "parser.cpp"
    break;

  case 31: /* FuncFParam: BType ID  */
#line 282 "parser.y"
           {
    (yyval.funcFParam) = new FuncFParamAST();
    (yyval.funcFParam)->bType = (yyvsp[-1].ty);
    (yyval.funcFParam)->id = unique_ptr<string>((yyvsp[0].id_name));
    (yyval.funcFParam)->isArray = false;
  }
#line 1557 "parser.cpp"
    break;

  case 32: /* FuncFParam: BType ID LB RB  */
#line 288 "parser.y"
                 {
    (yyval.funcFParam) = new FuncFParamAST();
    (yyval.funcFParam)->bType = (yyvsp[-3].ty);
    (yyval.funcFParam)->id = unique_ptr<string>((yyvsp[-2].id_name));
    (yyval.funcFParam)->isArray = true;
  }
#line 1568 "parser.cpp"
    break;

  case 33: /* FuncFParam: BType ID LB RB Arrays  */
#line 294 "parser.y"
                        {
    (yyval.funcFParam) = new FuncFParamAST();
    (yyval.funcFParam)->bType = (yyvsp[-4].ty);
    (yyval.funcFParam)->id = unique_ptr<string>((yyvsp[-3].id_name));
    (yyval.funcFParam)->isArray = true;
    (yyval.funcFParam)->arrays.swap((yyvsp[0].arrays)->list);
  }
#line 1580 "parser.cpp"
    break;

  case 34: /* Block: LC RC  */
#line 304 "parser.y"
        {
    (yyval.block) = new BlockAST();
  }
#line 1588 "parser.cpp"
    break;

  case 35: /* Block: LC BlockItemList RC  */
#line 307 "parser.y"
                      {
    (yyval.block) = new BlockAST();
    (yyval.block)->blockItemList.swap((yyvsp[-1].blockItemList)->list);
  }
#line 1597 "parser.cpp"
    break;

  case 36: /* BlockItemList: BlockItem  */
#line 314 "parser.y"
            {
    (yyval.blockItemList) = new BlockItemListAST();
    (yyval.blockItemList)->list.push_back(unique_ptr<BlockItemAST>((yyvsp[0].blockItem)));
  }
#line 1606 "parser.cpp"
    break;

  case 37: /* BlockItemList: BlockItemList BlockItem  */
#line 318 "parser.y"
                          {
    (yyval.blockItemList) = (yyvsp[-1].blockItemList);
    (yyval.blockItemList)->list.push_back(unique_ptr<BlockItemAST>((yyvsp[0].blockItem)));
  }
#line 1615 "parser.cpp"
    break;

  case 38: /* BlockItem: Decl  */
#line 325 "parser.y"
       {
    (yyval.blockItem) = new BlockItemAST();
    (yyval.blockItem)->decl = unique_ptr<DeclAST>((yyvsp[0].decl));
  }
#line 1624 "parser.cpp"
    break;

  case 39: /* BlockItem: Stmt  */
#line 329 "parser.y"
       {
    (yyval.blockItem) = new BlockItemAST();
    (yyval.blockItem)->stmt = unique_ptr<StmtAST>((yyvsp[0].stmt));
  }
#line 1633 "parser.cpp"
    break;

  case 40: /* Stmt: SEMICOLON  */
#line 336 "parser.y"
            {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = SEMI;
  }
#line 1642 "parser.cpp"
    break;

  case 41: /* Stmt: LVal ASSIGN Exp SEMICOLON  */
#line 340 "parser.y"
                            {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = ASS;
    (yyval.stmt)->lVal = unique_ptr<LValAST>((yyvsp[-3].lVal));
    (yyval.stmt)->exp = unique_ptr<AddExpAST>((yyvsp[-1].addExp));
  }
#line 1653 "parser.cpp"
    break;

  case 42: /* Stmt: Exp SEMICOLON  */
#line 346 "parser.y"
                {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = EXP;
    (yyval.stmt)->exp = unique_ptr<AddExpAST>((yyvsp[-1].addExp));
  }
#line 1663 "parser.cpp"
    break;

  case 43: /* Stmt: CONTINUE SEMICOLON  */
#line 351 "parser.y"
                     {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = CONT;
  }
#line 1672 "parser.cpp"
    break;

  case 44: /* Stmt: BREAK SEMICOLON  */
#line 355 "parser.y"
                  {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = BRE;
  }
#line 1681 "parser.cpp"
    break;

  case 45: /* Stmt: Block  */
#line 359 "parser.y"
        {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = BLK;
    (yyval.stmt)->block = unique_ptr<BlockAST>((yyvsp[0].block));
  }
#line 1691 "parser.cpp"
    break;

  case 46: /* Stmt: ReturnStmt  */
#line 364 "parser.y"
             {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = RET;
    (yyval.stmt)->returnStmt = unique_ptr<ReturnStmtAST>((yyvsp[0].returnStmt));
  }
#line 1701 "parser.cpp"
    break;

  case 47: /* Stmt: SelectStmt  */
#line 369 "parser.y"
             {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = SEL;
    (yyval.stmt)->selectStmt = unique_ptr<SelectStmtAST>((yyvsp[0].selectStmt));
  }
#line 1711 "parser.cpp"
    break;

  case 48: /* Stmt: IterationStmt  */
#line 374 "parser.y"
                {
    (yyval.stmt) = new StmtAST();
    (yyval.stmt)->sType = ITER;
    (yyval.stmt)->iterationStmt = unique_ptr<IterationStmtAST>((yyvsp[0].iterationStmt));
  }
#line 1721 "parser.cpp"
    break;

  case 49: /* SelectStmt: IF LP Cond RP Stmt  */
#line 382 "parser.y"
                                           {
    (yyval.selectStmt) = new SelectStmtAST();
    (yyval.selectStmt)->cond = unique_ptr<LOrExpAST>((yyvsp[-2].lOrExp));
    (yyval.selectStmt)->ifStmt = unique_ptr<StmtAST>((yyvsp[0].stmt));
  }
#line 1731 "parser.cpp"
    break;

  case 50: /* SelectStmt: IF LP Cond RP Stmt ELSE Stmt  */
#line 387 "parser.y"
                               {
    (yyval.selectStmt) = new SelectStmtAST();
    (yyval.selectStmt)->cond = unique_ptr<LOrExpAST>((yyvsp[-4].lOrExp));
    (yyval.selectStmt)->ifStmt = unique_ptr<StmtAST>((yyvsp[-2].stmt));
    (yyval.selectStmt)->elseStmt = unique_ptr<StmtAST>((yyvsp[0].stmt));
  }
#line 1742 "parser.cpp"
    break;

  case 51: /* IterationStmt: WHILE LP Cond RP Stmt  */
#line 396 "parser.y"
                        {
    (yyval.iterationStmt) = new IterationStmtAST();
    (yyval.iterationStmt)->cond = unique_ptr<LOrExpAST>((yyvsp[-2].lOrExp));
    (yyval.iterationStmt)->stmt = unique_ptr<StmtAST>((yyvsp[0].stmt));
  }
#line 1752 "parser.cpp"
    break;

  case 52: /* ReturnStmt: RETURN Exp SEMICOLON  */
#line 404 "parser.y"
                       {
    (yyval.returnStmt) = new ReturnStmtAST();
    (yyval.returnStmt)->exp = unique_ptr<AddExpAST>((yyvsp[-1].addExp));
  }
#line 1761 "parser.cpp"
    break;

  case 53: /* ReturnStmt: RETURN SEMICOLON  */
#line 408 "parser.y"
                   {
    (yyval.returnStmt) = new ReturnStmtAST();
  }
#line 1769 "parser.cpp"
    break;

  case 54: /* Exp: AddExp  */
#line 414 "parser.y"
         {
    (yyval.addExp) = (yyvsp[0].addExp);
  }
#line 1777 "parser.cpp"
    break;

  case 55: /* Cond: LOrExp  */
#line 420 "parser.y"
         {
    (yyval.lOrExp) = (yyvsp[0].lOrExp);
  }
#line 1785 "parser.cpp"
    break;

  case 56: /* LVal: ID  */
#line 426 "parser.y"
     {
    (yyval.lVal) = new LValAST();
    (yyval.lVal)->id = unique_ptr<string>((yyvsp[0].id_name));
  }
#line 1794 "parser.cpp"
    break;

  case 57: /* LVal: ID Arrays  */
#line 430 "parser.y"
            {
    (yyval.lVal) = new LValAST();
    (yyval.lVal)->id = unique_ptr<string>((yyvsp[-1].id_name));
    (yyval.lVal)->arrays.swap((yyvsp[0].arrays)->list);
  }
#line 1804 "parser.cpp"
    break;

  case 58: /* PrimaryExp: LP Exp RP  */
#line 438 "parser.y"
            {
    (yyval.primaryExp) = new PrimaryExpAST();
    (yyval.primaryExp)->exp = unique_ptr<AddExpAST>((yyvsp[-1].addExp));
  }
#line 1813 "parser.cpp"
    break;

  case 59: /* PrimaryExp: LVal  */
#line 442 "parser.y"
       {
    (yyval.primaryExp) = new PrimaryExpAST();
    (yyval.primaryExp)->lval = unique_ptr<LValAST>((yyvsp[0].lVal));
  }
#line 1822 "parser.cpp"
    break;

  case 60: /* PrimaryExp: Number  */
#line 446 "parser.y"
         {
    (yyval.primaryExp) = new PrimaryExpAST();
    (yyval.primaryExp)->number = unique_ptr<NumberAST>((yyvsp[0].number));
  }
#line 1831 "parser.cpp"
    break;

  case 61: /* Number: INT  */
#line 453 "parser.y"
      {
    (yyval.number) = new NumberAST();
    (yyval.number)->isInt = true;
    (yyval.number)->intval = (yyvsp[0].int_val);
  }
#line 1841 "parser.cpp"
    break;

  case 62: /* Number: FLOAT  */
#line 458 "parser.y"
        {
    (yyval.number) = new NumberAST();
    (yyval.number)->isInt = false;
    (yyval.number)->floatval = (yyvsp[0].float_val);
  }
#line 1851 "parser.cpp"
    break;

  case 63: /* UnaryExp: PrimaryExp  */
#line 466 "parser.y"
             {
    (yyval.unaryExp) = new UnaryExpAST();
    (yyval.unaryExp)->primaryExp = unique_ptr<PrimaryExpAST>((yyvsp[0].primaryExp));
  }
#line 1860 "parser.cpp"
    break;

  case 64: /* UnaryExp: Call  */
#line 470 "parser.y"
       {
    (yyval.unaryExp) = new UnaryExpAST();
    (yyval.unaryExp)->call = unique_ptr<CallAST>((yyvsp[0].call));
  }
#line 1869 "parser.cpp"
    break;

  case 65: /* UnaryExp: UnaryOp UnaryExp  */
#line 474 "parser.y"
                   {
    (yyval.unaryExp) = new UnaryExpAST();
    (yyval.unaryExp)->op = (yyvsp[-1].op);
    (yyval.unaryExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
  }
#line 1879 "parser.cpp"
    break;

  case 66: /* Call: ID LP RP  */
#line 482 "parser.y"
           {
    (yyval.call) = new CallAST();
    (yyval.call)->id = unique_ptr<string>((yyvsp[-2].id_name));
  }
#line 1888 "parser.cpp"
    break;

  case 67: /* Call: ID LP FuncCParamList RP  */
#line 486 "parser.y"
                          {
    (yyval.call) = new CallAST();
    (yyval.call)->id = unique_ptr<string>((yyvsp[-3].id_name));
    (yyval.call)->funcCParamList.swap((yyvsp[-1].funcCParamList)->list);
  }
#line 1898 "parser.cpp"
    break;

  case 68: /* UnaryOp: ADD  */
#line 494 "parser.y"
      {
    (yyval.op) = UOP_ADD;
  }
#line 1906 "parser.cpp"
    break;

  case 69: /* UnaryOp: MINUS  */
#line 497 "parser.y"
        {
    (yyval.op) = UOP_MINUS;
  }
#line 1914 "parser.cpp"
    break;

  case 70: /* UnaryOp: NOT  */
#line 500 "parser.y"
      {
    (yyval.op) = UOP_NOT;
  }
#line 1922 "parser.cpp"
    break;

  case 71: /* FuncCParamList: Exp  */
#line 506 "parser.y"
      {
    (yyval.funcCParamList) = new FuncCParamListAST();
    (yyval.funcCParamList)->list.push_back(unique_ptr<AddExpAST>((yyvsp[0].addExp)));
  }
#line 1931 "parser.cpp"
    break;

  case 72: /* FuncCParamList: FuncCParamList COMMA Exp  */
#line 510 "parser.y"
                           {
    (yyval.funcCParamList) = (FuncCParamListAST*) (yyvsp[-2].funcCParamList);
    (yyval.funcCParamList)->list.push_back(unique_ptr<AddExpAST>((yyvsp[0].addExp)));
  }
#line 1940 "parser.cpp"
    break;

  case 73: /* MulExp: UnaryExp  */
#line 517 "parser.y"
           {
    (yyval.mulExp) = new MulExpAST();
    (yyval.mulExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
  }
#line 1949 "parser.cpp"
    break;

  case 74: /* MulExp: MulExp MUL UnaryExp  */
#line 521 "parser.y"
                      {
    (yyval.mulExp) = new MulExpAST();
    (yyval.mulExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[-2].mulExp));
    (yyval.mulExp)->op = MOP_MUL;
    (yyval.mulExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
  }
#line 1960 "parser.cpp"
    break;

  case 75: /* MulExp: MulExp DIV UnaryExp  */
#line 527 "parser.y"
                      {
    (yyval.mulExp) = new MulExpAST();
    (yyval.mulExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[-2].mulExp));
    (yyval.mulExp)->op = MOP_DIV;
    (yyval.mulExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
  }
#line 1971 "parser.cpp"
    break;

  case 76: /* MulExp: MulExp MOD UnaryExp  */
#line 533 "parser.y"
                      {
    (yyval.mulExp) = new MulExpAST();
    (yyval.mulExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[-2].mulExp));
    (yyval.mulExp)->op = MOP_MOD;
    (yyval.mulExp)->unaryExp = unique_ptr<UnaryExpAST>((yyvsp[0].unaryExp));
  }
#line 1982 "parser.cpp"
    break;

  case 77: /* AddExp: MulExp  */
#line 542 "parser.y"
         {
    (yyval.addExp) = new AddExpAST();
    (yyval.addExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[0].mulExp));
  }
#line 1991 "parser.cpp"
    break;

  case 78: /* AddExp: AddExp ADD MulExp  */
#line 546 "parser.y"
                    {
    (yyval.addExp) = new AddExpAST();
    (yyval.addExp)->addExp = unique_ptr<AddExpAST>((yyvsp[-2].addExp));
    (yyval.addExp)->op = AOP_ADD;
    (yyval.addExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[0].mulExp));
  }
#line 2002 "parser.cpp"
    break;

  case 79: /* AddExp: AddExp MINUS MulExp  */
#line 552 "parser.y"
                      {
    (yyval.addExp) = new AddExpAST();
    (yyval.addExp)->addExp = unique_ptr<AddExpAST>((yyvsp[-2].addExp));
    (yyval.addExp)->op = AOP_MINUS;
    (yyval.addExp)->mulExp = unique_ptr<MulExpAST>((yyvsp[0].mulExp));
  }
#line 2013 "parser.cpp"
    break;

  case 80: /* RelExp: AddExp  */
#line 561 "parser.y"
         {
    (yyval.relExp) = new RelExpAST();
    (yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
  }
#line 2022 "parser.cpp"
    break;

  case 81: /* RelExp: RelExp GTE AddExp  */
#line 565 "parser.y"
                    {
    (yyval.relExp) = new RelExpAST();
    (yyval.relExp)->relExp = unique_ptr<RelExpAST>((yyvsp[-2].relExp));
    (yyval.relExp)->op = ROP_GTE;
    (yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
  }
#line 2033 "parser.cpp"
    break;

  case 82: /* RelExp: RelExp LTE AddExp  */
#line 571 "parser.y"
                    {
    (yyval.relExp) = new RelExpAST();
    (yyval.relExp)->relExp = unique_ptr<RelExpAST>((yyvsp[-2].relExp));
    (yyval.relExp)->op = ROP_LTE;
    (yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
  }
#line 2044 "parser.cpp"
    break;

  case 83: /* RelExp: RelExp GT AddExp  */
#line 577 "parser.y"
                   {
    (yyval.relExp) = new RelExpAST();
    (yyval.relExp)->relExp = unique_ptr<RelExpAST>((yyvsp[-2].relExp));
    (yyval.relExp)->op = ROP_GT;
    (yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
  }
#line 2055 "parser.cpp"
    break;

  case 84: /* RelExp: RelExp LT AddExp  */
#line 583 "parser.y"
                   {
    (yyval.relExp) = new RelExpAST();
    (yyval.relExp)->relExp = unique_ptr<RelExpAST>((yyvsp[-2].relExp));
    (yyval.relExp)->op = ROP_LT;
    (yyval.relExp)->addExp = unique_ptr<AddExpAST>((yyvsp[0].addExp));
  }
#line 2066 "parser.cpp"
    break;

  case 85: /* EqExp: RelExp  */
#line 592 "parser.y"
         {
    (yyval.eqExp) = new EqExpAST();
    (yyval.eqExp)->relExp = unique_ptr<RelExpAST>((yyvsp[0].relExp));
  }
#line 2075 "parser.cpp"
    break;

  case 86: /* EqExp: EqExp EQ RelExp  */
#line 596 "parser.y"
                  {
    (yyval.eqExp) = new EqExpAST();
    (yyval.eqExp)->eqExp = unique_ptr<EqExpAST>((yyvsp[-2].eqExp));
    (yyval.eqExp)->op = EOP_EQ;
    (yyval.eqExp)->relExp = unique_ptr<RelExpAST>((yyvsp[0].relExp));
  }
#line 2086 "parser.cpp"
    break;

  case 87: /* EqExp: EqExp NEQ RelExp  */
#line 602 "parser.y"
                   {
    (yyval.eqExp) = new EqExpAST();
    (yyval.eqExp)->eqExp = unique_ptr<EqExpAST>((yyvsp[-2].eqExp));
    (yyval.eqExp)->op = EOP_NEQ;
    (yyval.eqExp)->relExp = unique_ptr<RelExpAST>((yyvsp[0].relExp));
  }
#line 2097 "parser.cpp"
    break;

  case 88: /* LAndExp: EqExp  */
#line 611 "parser.y"
        {
    (yyval.lAndExp) = new LAndExpAST();
    (yyval.lAndExp)->eqExp = unique_ptr<EqExpAST>((yyvsp[0].eqExp));
  }
#line 2106 "parser.cpp"
    break;

  case 89: /* LAndExp: LAndExp AND EqExp  */
#line 615 "parser.y"
                    {
    (yyval.lAndExp) = new LAndExpAST();
    (yyval.lAndExp)->lAndExp = unique_ptr<LAndExpAST>((yyvsp[-2].lAndExp));
    (yyval.lAndExp)->eqExp = unique_ptr<EqExpAST>((yyvsp[0].eqExp));
  }
#line 2116 "parser.cpp"
    break;

  case 90: /* LOrExp: LAndExp  */
#line 623 "parser.y"
          {
    (yyval.lOrExp) = new LOrExpAST();
    (yyval.lOrExp)->lAndExp = unique_ptr<LAndExpAST>((yyvsp[0].lAndExp));
  }
#line 2125 "parser.cpp"
    break;

  case 91: /* LOrExp: LOrExp OR LAndExp  */
#line 627 "parser.y"
                    {
    (yyval.lOrExp) = new LOrExpAST();
    (yyval.lOrExp)->lOrExp = unique_ptr<LOrExpAST>((yyvsp[-2].lOrExp));
    (yyval.lOrExp)->lAndExp = unique_ptr<LAndExpAST>((yyvsp[0].lAndExp));
  }
#line 2135 "parser.cpp"
    break;


#line 2139 "parser.cpp"

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

#line 634 "parser.y"


void initFileName(char *name) {
  strcpy(filename, name);
}

void yyerror(const char* fmt) {
  printf("%s:%d ", filename, yylloc.first_line);
  printf("%s\n", fmt);
}
