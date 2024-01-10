/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "CminusParser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/string_utils.h>

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD  "value"

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(const char*));

EXTERN(int,yylex,(void));

char *fileName;

SymTable symtab;

extern int yylineno;

extern FILE *yyin;

static int getValue(char *name);
static void setValue(char *name, int value);
char s[10] = "scanVal";


#line 98 "CminusParser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "CminusParser.h".  */
#ifndef YY_YY_CMINUSPARSER_H_INCLUDED
# define YY_YY_CMINUSPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    ELSE = 259,
    EXIT = 260,
    FOR = 261,
    IF = 262,
    INTEGER = 263,
    NOT = 264,
    OR = 265,
    READ = 266,
    WHILE = 267,
    WRITE = 268,
    LBRACE = 269,
    RBRACE = 270,
    LE = 271,
    LT = 272,
    GE = 273,
    GT = 274,
    EQ = 275,
    NE = 276,
    ASSIGN = 277,
    COMMA = 278,
    SEMICOLON = 279,
    LBRACKET = 280,
    RBRACKET = 281,
    LPAREN = 282,
    RPAREN = 283,
    PLUS = 284,
    TIMES = 285,
    ID = 286,
    VARID = 287,
    DIVIDE = 288,
    RETURN = 289,
    STRING = 290,
    INT = 291,
    MINUS = 292,
    INCLUDE = 293,
    HEADERSTRING = 294,
    ADDR = 295,
    NEWLINE = 296,
    DIVDE = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 90 "CminusParser.y" /* yacc.c:355  */
int value;
	char* name;
#line 92 "CminusParser.y" /* yacc.c:355  */
int exprVal;
#line 93 "CminusParser.y" /* yacc.c:355  */
char* theValue;
#line 95 "CminusParser.y" /* yacc.c:355  */
char* stringName;

#line 191 "CminusParser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMINUSPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "CminusParser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   110,   117,   122,   128,   134,   138,   144,
     149,   154,   160,   164,   170,   176,   183,   187,   194,   199,
     205,   209,   215,   221,   225,   229,   233,   237,   241,   245,
     251,   260,   264,   271,   277,   284,   290,   296,   302,   310,
     339,   360,   366,   372,   378,   382,   388,   393,   398,   403,
     410,   415,   420,   425,   430,   435,   440,   447,   452,   458,
     465,   470,   475,   482,   487,   491,   495,   502,   508,   514,
     521
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ELSE", "EXIT", "FOR", "IF",
  "INTEGER", "NOT", "OR", "READ", "WHILE", "WRITE", "LBRACE", "RBRACE",
  "LE", "LT", "GE", "GT", "EQ", "NE", "ASSIGN", "COMMA", "SEMICOLON",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "PLUS", "TIMES", "ID",
  "VARID", "DIVIDE", "RETURN", "STRING", "INT", "MINUS", "INCLUDE",
  "HEADERSTRING", "ADDR", "NEWLINE", "DIVDE", "$accept", "Program",
  "Headers", "Header", "Programbody", "Procedures", "ProcedureDecl",
  "ProcedureHead", "FunctionDecl", "ProcedureBody", "DeclList",
  "IdentifierList", "VarDecl", "Type", "Statement", "Assignment",
  "IfStatement", "TestAndThen", "Test", "WhileStatement", "WhileExpr",
  "WhileToken", "IOStatement", "ReturnStatement", "ExitStatement",
  "CompoundStatement", "StatementList", "Expr", "SimpleExpr", "AddExpr",
  "MulExpr", "Factor", "Variable", "StringConstant", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -54,   -27,    16,     2,   -54,   -54,   -54,    14,    61,
      14,    14,    15,   -54,   -54,   -54,   -54,   -54,    25,    47,
      67,    96,   -54,    98,    61,    63,    60,   -54,   -54,   -54,
     -54,   -54,    99,   -54,   -54,   -54,   -54,    36,    59,    14,
      69,   -54,    15,     4,    93,   -54,   100,   -54,    60,   105,
     108,    94,    97,    48,    60,    -1,    60,    27,   -54,     8,
      87,   -12,    56,   -54,   -54,   -54,    60,    61,   -54,   -54,
      60,    69,   103,    95,   101,   102,    69,   -54,    11,   108,
     -54,   110,   111,   107,   -54,    54,    87,    17,   112,    -1,
      -1,   -54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,   -54,    75,   -54,   113,   117,   -54,   -54,
     -54,   104,    60,   114,   -54,   -54,   -54,    87,    87,   -12,
     -12,   -12,   -12,   -12,   -12,    56,    56,   -54,   -54,   -54,
     -54,   -54,   -54,   115,    74,   -54,   119,   118,   121,   -54,
     -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,    22,     0,     0,    10,     5,     3,     7,    10,     0,
      13,    10,     0,     6,     1,     4,     2,     9,     0,     0,
       0,     0,    37,     0,     0,    67,     0,    11,    44,    23,
      24,    25,     0,    26,    27,    28,    29,     0,     0,    12,
       0,     8,     0,    20,     0,    18,     0,    42,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    67,    70,     0,
      46,    50,    57,    60,    63,    64,     0,     0,    15,    45,
       0,     0,    20,     0,     0,     0,     0,    16,     0,     0,
      33,     0,    69,     0,    43,     0,    49,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,    17,     0,     0,    19,    34,
      31,     0,     0,     0,    68,    66,    65,    48,    47,    53,
      54,    55,    56,    51,    52,    58,    59,    61,    62,    36,
      30,    21,    14,     0,     0,    40,     0,     0,     0,    39,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   132,   137,    82,   -54,   -54,   -54,   -54,
     133,   -38,    72,    -5,   -29,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -37,   125,   -47,   -53,    18,
      22,    -3,    -9,   -54,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    27,
      11,    44,    45,    12,    28,    29,    30,    49,    50,    31,
      67,    32,    33,    34,    35,    36,    37,    59,    60,    61,
      62,    63,    64,    83,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    78,    86,    18,    73,    40,    42,    85,    69,    87,
       1,    89,    13,    80,    89,    38,    14,    98,    90,   102,
      89,    90,     1,   104,    69,    99,    56,    90,    38,    74,
      57,    75,    91,    73,    71,    58,   117,   118,   103,   109,
       2,    19,   110,    20,    38,   115,    43,    21,    22,    23,
      24,    68,    54,    19,    88,    20,    46,    89,    38,    21,
      22,    23,    24,    84,    90,   134,    19,    25,    20,    55,
      26,    47,    21,    22,    23,    24,    89,    89,    89,    25,
     114,    70,    26,    90,    90,    90,   100,    56,    54,   101,
      17,    57,    25,    41,    48,    26,    58,   127,   128,   130,
      72,   129,   137,    92,    93,    94,    95,    96,    97,    79,
     119,   120,   121,   122,   123,   124,    76,    77,    76,   105,
     125,   126,    24,    51,   136,    52,    66,    75,    74,    81,
     107,   132,    82,   111,   112,   113,    15,   106,   135,   131,
     116,    16,   139,    39,   133,   140,    25,   138,   108,    53
};

static const yytype_uint8 yycheck[] =
{
       9,    48,    55,     8,    42,    10,    11,    54,    37,    56,
       8,     3,    39,    50,     3,    24,     0,    29,    10,    66,
       3,    10,     8,    70,    53,    37,    27,    10,    37,    25,
      31,    27,    24,    71,    39,    36,    89,    90,    67,    28,
      38,     5,    79,     7,    53,    28,    31,    11,    12,    13,
      14,    15,    25,     5,    27,     7,    31,     3,    67,    11,
      12,    13,    14,    15,    10,   112,     5,    31,     7,     9,
      34,    24,    11,    12,    13,    14,     3,     3,     3,    31,
      26,    22,    34,    10,    10,    10,    30,    27,    25,    33,
       8,    31,    31,    11,    27,    34,    36,   100,   101,    24,
      31,    28,    28,    16,    17,    18,    19,    20,    21,     4,
      92,    93,    94,    95,    96,    97,    23,    24,    23,    24,
      98,    99,    14,    27,   133,    27,    27,    27,    25,    35,
      28,    14,    35,    23,    23,    28,     4,    36,    24,    26,
      28,     4,    24,    10,    40,    24,    31,    28,    76,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    38,    44,    45,    46,    47,    48,    49,    50,
      51,    53,    56,    39,     0,    46,    47,    48,    56,     5,
       7,    11,    12,    13,    14,    31,    34,    52,    57,    58,
      59,    62,    64,    65,    66,    67,    68,    69,    75,    53,
      56,    48,    56,    31,    54,    55,    31,    24,    27,    60,
      61,    27,    27,    69,    25,     9,    27,    31,    36,    70,
      71,    72,    73,    74,    75,    77,    27,    63,    15,    57,
      22,    56,    31,    54,    25,    27,    23,    24,    70,     4,
      68,    35,    35,    76,    15,    70,    71,    70,    27,     3,
      10,    24,    16,    17,    18,    19,    20,    21,    29,    37,
      30,    33,    70,    57,    70,    24,    36,    28,    55,    28,
      68,    23,    23,    28,    26,    28,    28,    71,    71,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    28,
      24,    26,    14,    40,    70,    24,    75,    28,    28,    24,
      24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    47,    47,    48,
      48,    49,    50,    50,    51,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    59,    60,    61,    62,    63,    64,    65,    65,
      65,    66,    67,    68,    69,    69,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    76,
      77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     1,     2,     2,
       0,     2,     2,     1,     5,     2,     3,     4,     1,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     2,     2,     3,     3,     3,     1,     8,     7,
       5,     3,     2,     3,     1,     2,     1,     3,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     1,     3,     3,     1,     4,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 107 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Program> -> <Headers> <Programbody>\n");
		}
#line 1391 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "CminusParser.y" /* yacc.c:1646  */
    {
		//  printf("<Program> -> <Programbody>\n");
		}
#line 1399 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 118 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Headers> -> <Headers> <Header>\n");
		}
#line 1407 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 123 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Headers> -> <Header>\n");
		}
#line 1415 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Header> -> <INCLUDE> <HEADERSTRING>\n");
		}
#line 1423 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Program> -> <Procedures>\n");
		}
#line 1431 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 139 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Program> -> <DeclList> <Procedures>\n");
		}
#line 1439 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
		}
#line 1447 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Procedures> -> epsilon\n");
		}
#line 1455 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
		}
#line 1463 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 161 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
		}
#line 1471 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 165 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<ProcedureHead> -> <FunctionDecl>\n");
		}
#line 1479 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 171 "CminusParser.y" /* yacc.c:1646  */
    {
		//	printf("<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>\n"); 
		}
#line 1487 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<ProcedureBody> -> <StatementList> <RBR>\n");
		}
#line 1495 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 184 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
		}
#line 1503 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 188 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
	 	}
#line 1511 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 195 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<IdentifierList> -> <VarDecl>\n");
		}
#line 1519 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
		}
#line 1527 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 206 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<VarDecl> -> <IDENTIFIER\n");
		}
#line 1535 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 210 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
		}
#line 1543 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 216 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<Type> -> <INTEGER>\n");
		}
#line 1551 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 222 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<Statement> -> <Assignment>\n");
		}
#line 1559 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 226 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<Statement> -> <IfStatement>\n");
		}
#line 1567 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 230 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<Statement> -> <WhileStatement>\n");
		}
#line 1575 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 234 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Statement> -> <IOStatement>\n");
		}
#line 1583 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 238 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<Statement> -> <ReturnStatement>\n");
		}
#line 1591 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 242 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<Statement> -> <ExitStatement>\n");
		}
#line 1599 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 246 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<Statement> -> <CompoundStatement>\n");
		}
#line 1607 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 252 "CminusParser.y" /* yacc.c:1646  */
    {
		 char s[10];
		 strcpy(s, (yyvsp[-3].theValue));
		 setValue(s, (yyvsp[-1].exprVal)); //Stores variable
		 // printf("<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>\n");
		}
#line 1618 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 261 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
		}
#line 1626 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 265 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<IfStatement> -> <IF> <TestAndThen>\n");
		}
#line 1634 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 272 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
		}
#line 1642 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 278 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Test> -> <LP> <Expr> <RP>\n");
		}
#line 1650 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 285 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
		}
#line 1658 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 291 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
		}
#line 1666 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 297 "CminusParser.y" /* yacc.c:1646  */
    {
		//  printf("<WhileToken> -> <WHILE>\n");
		}
#line 1674 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 303 "CminusParser.y" /* yacc.c:1646  */
    {
		  char a[10];
		  scanf ("%s", &a); //Get value from the user
		  int n = atoi(a);	 
                  setValue((yyvsp[-2].theValue), n);
		 //  printf("<IOStatement> -> <READ> <LP> <STRING> <COMMA> <ADDR> <Variable> <RP> <SC>\n");
		}
#line 1686 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 311 "CminusParser.y" /* yacc.c:1646  */
    {
		   char q = '"';
		   char p = '%';
	           char n = 'n';
                   char s = 92;
                   int len = strlen((yyvsp[-4].stringName));

		  
		   removeChar((yyvsp[-4].stringName), q);
		   removeChar((yyvsp[-4].stringName), q);

		   //Check to see what extra tokens need to be removed

                   if ((yyvsp[-4].stringName)[strlen((yyvsp[-4].stringName))-1] == n && (yyvsp[-4].stringName)[strlen((yyvsp[-4].stringName))-2] == s && (yyvsp[-4].stringName)[strlen((yyvsp[-4].stringName))-4] == p ){
	
		        (yyvsp[-4].stringName)[len-6] = '\0';
			printf("%s%d\n", (yyvsp[-4].stringName), (yyvsp[-2].exprVal));
			
		   }else if (((yyvsp[-4].stringName)[strlen((yyvsp[-4].stringName))-1] == n && (yyvsp[-4].stringName)[strlen((yyvsp[-4].stringName))-2] == s)){
			(yyvsp[-4].stringName)[len-4] = '\0';
			printf("%s%d\n", (yyvsp[-4].stringName), (yyvsp[-2].exprVal));
		   }else {
			printf("%s%d", (yyvsp[-4].stringName), (yyvsp[-2].exprVal));
		   }
	
		  // printf("<IOStatement> -> <WRITE> <LP> <STRING> <COMMA> <Expr> <RP> <SC>\n");
		
		}
#line 1719 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 340 "CminusParser.y" /* yacc.c:1646  */
    {
		   char q = '"';
                   char p = '%';
                   char n = 'n';
		   char s = 92; 
		   int len = strlen((yyvsp[-2].name));

                   removeChar((yyvsp[-2].name), q);
                   removeChar((yyvsp[-2].name), q);
					 
		   //Checks to see what extra tokens need to be removed
 		   if ((yyvsp[-2].name)[strlen((yyvsp[-2].name))-1] == n && (yyvsp[-2].name)[strlen((yyvsp[-2].name))-2] == s){
		      (yyvsp[-2].name)[len-4] = '\0';
		      printf("%s\n", (yyvsp[-2].name));	
		   }else {
		       printf("%s", (yyvsp[-2].name));
		   }	
		}
#line 1742 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 361 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
		}
#line 1750 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 367 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<ExitStatement> -> <EXIT> <SC>\n");
		}
#line 1758 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 373 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
		}
#line 1766 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 379 "CminusParser.y" /* yacc.c:1646  */
    {		
		 // printf("<StatementList> -> <Statement>\n");
		}
#line 1774 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 383 "CminusParser.y" /* yacc.c:1646  */
    {		
		 // printf("<StatementList> -> <StatementList> <Statement>\n");
		}
#line 1782 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 389 "CminusParser.y" /* yacc.c:1646  */
    {
		 
		 // printf("<Expr> -> <SimpleExpr>\n");
		}
#line 1791 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 394 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.exprVal) = (yyvsp[-2].exprVal) || (yyvsp[0].value);
		 // printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
		}
#line 1800 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 399 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.exprVal) = (yyvsp[-2].exprVal) && (yyvsp[0].value);
		 // printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
		}
#line 1809 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 404 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.exprVal) = (!(yyvsp[0].value));
		 // printf("<Expr> -> <NOT> <SimpleExpr> \n");
		}
#line 1818 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 411 "CminusParser.y" /* yacc.c:1646  */
    {
		 // $$ = $1;
		// printf("<SimpleExpr> -> <AddExpr>\n");
		}
#line 1827 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 416 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = ((yyvsp[-2].value) == (yyvsp[0].value));
		 // printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
		}
#line 1836 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 421 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = ((yyvsp[-2].value) != (yyvsp[0].value));
		 // printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
		}
#line 1845 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 426 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = (yyvsp[-2].value) <= (yyvsp[0].value);
		 // printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
		}
#line 1854 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 431 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = (yyvsp[-2].value) < (yyvsp[0].value);
		  //printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
		}
#line 1863 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 436 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = (yyvsp[-2].value) >= (yyvsp[0].value);
		 // printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
		}
#line 1872 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 441 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = (yyvsp[-2].value) > (yyvsp[0].value);
		 // printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
		}
#line 1881 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 448 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval.value) = (yyvsp[0].value);
		 // printf("<AddExpr> -> <MulExpr>\n");
		}
#line 1890 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 453 "CminusParser.y" /* yacc.c:1646  */
    {

		 (yyval.value) = (yyvsp[-2].value) + (yyvsp[0].value);
		 // printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
		}
#line 1900 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 459 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = (yyvsp[-2].value) - (yyvsp[0].value);
		 // printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
		}
#line 1909 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 466 "CminusParser.y" /* yacc.c:1646  */
    {
		  //$$ = $1;
		 // printf("<MulExpr> -> <Factor>\n");
		}
#line 1918 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 471 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = (yyvsp[-2].value) * (yyvsp[0].value);
		  //printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
		}
#line 1927 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 476 "CminusParser.y" /* yacc.c:1646  */
    {
		 (yyval.value) = (yyvsp[-2].value) / (yyvsp[0].value);
		 // printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
		}
#line 1936 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 483 "CminusParser.y" /* yacc.c:1646  */
    { 
		 (yyval.value) = getValue((yyvsp[0].theValue)); //sends value back to expr
		 // printf("<Factor> -> <Variable>\n");
		}
#line 1945 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 488 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Factor> -> <Constant>\n");
		}
#line 1953 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 492 "CminusParser.y" /* yacc.c:1646  */
    {	
		  printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		}
#line 1961 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 496 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("<Factor> -> <LP> <Expr> <RP>\n");
		 (yyval.value) = (yyvsp[-1].exprVal);
		}
#line 1970 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 503 "CminusParser.y" /* yacc.c:1646  */
    {
		 // printf("ID is %s\n", $1);
		  (yyval.theValue) = (yyvsp[0].theValue);
		 // printf("<Variable> -> <IDENTIFIER>\n");
		}
#line 1980 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 509 "CminusParser.y" /* yacc.c:1646  */
    {
		  printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
               	}
#line 1988 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 515 "CminusParser.y" /* yacc.c:1646  */
    { 
		 // printf("<StringConstant> -> <STRING>\n");
			(yyval.name) = (yyvsp[0].stringName);
		}
#line 1997 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 522 "CminusParser.y" /* yacc.c:1646  */
    { 
		  (yyval.value) = (yyvsp[0].value);
		 // printf("<Constant> -> <INTCON>\n");
		}
#line 2006 "CminusParser.c" /* yacc.c:1646  */
    break;


#line 2010 "CminusParser.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 529 "CminusParser.y" /* yacc.c:1906  */



/********************C ROUTINES *********************************/

void yyerror(const char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,yylineno,s);
}

int yywrap() {
	return 1;
}

static void initialize(char* inputFileName) {
	yyin = fopen(inputFileName,"r");
        if (yyin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	/* uncomment this section for Project 2
	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);

	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
	} 
        */

	symtab = SymInit(SYMTABLE_SIZE);
	SymInitField(symtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);
}

static void finalize() {
    SymKillField(symtab,SYMTAB_VALUE_FIELD);
    SymKill(symtab);
    fclose(yyin);
    //fclose(stdout); //uncomment this line for Project 2
}

void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}


int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
        yyparse();
  
  	finalize();
  
  	return 0;
}



/**
 *
 * retrieve the value of a key
 *
 * @param name a C character string which is a key
 * @return the value of the key
 */
static int getValue(char *name)
{
  return (int)SymGetField(symtab, name, SYMTAB_VALUE_FIELD); 
}

/**
 *
 * Set the value for a key
 *
 * @param name a C character string which is a key
 * @param value the value of the key
 */
static void setValue(char *name, int value)
{
  SymPutField(symtab, name, SYMTAB_VALUE_FIELD, (Generic)value); 
}
/******************END OF C ROUTINES**********************/
