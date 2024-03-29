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
#define SYMTAB_VALUE_FIELD     "value"

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(const char*));

EXTERN(int,yylex,(void));

char *fileName;
char *instrString;
char *stringString;
char *memString;
int stringCount = 0;
int memCount = 0;

char registers[14][10] = {"%rax", "%rbx", "%rcx", "%rdx", "%rdi", "%rsi", "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};

char inUse[14][6];

SymTable symtab;

extern int yylineno;

extern FILE *yyin;

static int getValue(char *name);
static void setValue(char *name, int value);
char* getRegister(char* c);
void setRegister(char* c);
void freeRegister(char*c); 

#line 108 "CminusParser.c" /* yacc.c:339  */

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
    i = 276,
    NE = 277,
    ASSIGN = 278,
    COMMA = 279,
    SEMICOLON = 280,
    LBRACKET = 281,
    RBRACKET = 282,
    LPAREN = 283,
    RPAREN = 284,
    PLUS = 285,
    TIMES = 286,
    IDENTIFIER = 287,
    DIVIDE = 288,
    RETURN = 289,
    STRING = 290,
    INTCON = 291,
    MINUS = 292,
    INCLUDE = 293,
    HEADERSTRING = 294,
    ADDR = 295,
    DIVDE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 98 "CminusParser.y" /* yacc.c:355  */

	char*	name;
	int     val;

#line 195 "CminusParser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMINUSPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 212 "CminusParser.c" /* yacc.c:358  */

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
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   111,   117,   122,   128,   134,   138,   144,
     149,   154,   160,   164,   170,   176,   183,   187,   194,   199,
     205,   209,   215,   221,   225,   229,   233,   237,   241,   245,
     251,   264,   268,   275,   281,   288,   294,   300,   306,   353,
     390,   425,   431,   437,   443,   447,   453,   458,   487,   516,
     537,   542,   577,   612,   646,   686,   726,   763,   768,   796,
     827,   832,   861,   897,   902,   907,   911,   918,   923,   929,
     936
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ELSE", "EXIT", "FOR", "IF",
  "INTEGER", "NOT", "OR", "READ", "WHILE", "WRITE", "LBRACE", "RBRACE",
  "LE", "LT", "GE", "GT", "EQ", "i", "NE", "ASSIGN", "COMMA", "SEMICOLON",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "PLUS", "TIMES",
  "IDENTIFIER", "DIVIDE", "RETURN", "STRING", "INTCON", "MINUS", "INCLUDE",
  "HEADERSTRING", "ADDR", "DIVDE", "$accept", "Program", "Headers",
  "Header", "Programbody", "Procedures", "ProcedureDecl", "ProcedureHead",
  "FunctionDecl", "ProcedureBody", "DeclList", "IdentifierList", "VarDecl",
  "Type", "Statement", "Assignment", "IfStatement", "TestAndThen", "Test",
  "WhileStatement", "WhileExpr", "WhileToken", "IOStatement",
  "ReturnStatement", "ExitStatement", "CompoundStatement", "StatementList",
  "Expr", "SimpleExpr", "AddExpr", "MulExpr", "Factor", "Variable",
  "StringConstant", "Constant", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -73,   -18,    43,     2,   -73,   -73,   -73,    42,    62,
      42,    42,    38,   -73,   -73,   -73,   -73,   -73,    49,    64,
      67,    72,   -73,    78,    62,    76,    55,   -73,   -73,   -73,
     -73,   -73,    86,   -73,   -73,   -73,   -73,    34,    99,    42,
      91,   -73,    38,    26,    32,   -73,    97,   -73,    55,   122,
     113,    94,    95,    48,    55,   -16,    55,    73,   -73,    82,
      93,    -8,    57,   -73,   -73,   -73,    55,    62,   -73,   -73,
      55,    91,   102,    80,    96,   104,    91,   -73,    22,   113,
     -73,   107,   110,   106,   -73,     8,    93,    68,   108,   -16,
     -16,   -73,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,    69,   -73,    83,   -73,   109,   124,   -73,   -73,
     -73,   100,    55,   114,   -73,   -73,   -73,    93,    93,    -8,
      -8,    -8,    -8,    -8,    -8,    57,    57,   -73,   -73,   -73,
     -73,   -73,   -73,   111,    74,   -73,   112,   117,   119,   -73,
     -73
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
     -73,   -73,   -73,   141,   142,     6,   -73,   -73,   -73,   -73,
     137,   -38,    75,    -5,   -29,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -37,   125,   -47,   -53,    24,
     -72,   -70,    -9,   -73,   -73
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
       1,    89,    56,    80,    17,    38,    57,    41,    90,   102,
      58,    13,    98,   104,    69,    89,   125,   126,    38,    99,
     127,   128,    90,    73,    71,   114,   117,   118,   103,    19,
       2,    20,   110,    14,    38,    21,    22,    23,    24,    68,
       1,   109,    74,    19,    75,    20,    76,    77,    38,    21,
      22,    23,    24,    84,    55,   134,    25,    19,    26,    20,
      43,    89,    89,    21,    22,    23,    24,    89,    90,    90,
      25,    46,    26,    56,    90,    89,    89,    57,   100,    47,
     101,    58,    90,    90,    25,    48,    26,   115,   129,    54,
      51,    88,    54,   137,    76,   105,    52,    91,   130,    92,
      93,    94,    95,    96,    66,    97,   119,   120,   121,   122,
     123,   124,    70,    72,   136,    75,    79,    24,    74,    81,
      82,   111,   106,   107,   112,   113,   131,   116,   132,   135,
     133,   138,   139,    25,   140,    15,    16,    39,     0,    53,
       0,   108
};

static const yytype_int16 yycheck[] =
{
       9,    48,    55,     8,    42,    10,    11,    54,    37,    56,
       8,     3,    28,    50,     8,    24,    32,    11,    10,    66,
      36,    39,    30,    70,    53,     3,    98,    99,    37,    37,
     100,   101,    10,    71,    39,    27,    89,    90,    67,     5,
      38,     7,    79,     0,    53,    11,    12,    13,    14,    15,
       8,    29,    26,     5,    28,     7,    24,    25,    67,    11,
      12,    13,    14,    15,     9,   112,    32,     5,    34,     7,
      32,     3,     3,    11,    12,    13,    14,     3,    10,    10,
      32,    32,    34,    28,    10,     3,     3,    32,    31,    25,
      33,    36,    10,    10,    32,    28,    34,    29,    29,    26,
      28,    28,    26,    29,    24,    25,    28,    25,    25,    16,
      17,    18,    19,    20,    28,    22,    92,    93,    94,    95,
      96,    97,    23,    32,   133,    28,     4,    14,    26,    35,
      35,    24,    36,    29,    24,    29,    27,    29,    14,    25,
      40,    29,    25,    32,    25,     4,     4,    10,    -1,    24,
      -1,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    38,    43,    44,    45,    46,    47,    48,    49,
      50,    52,    55,    39,     0,    45,    46,    47,    55,     5,
       7,    11,    12,    13,    14,    32,    34,    51,    56,    57,
      58,    61,    63,    64,    65,    66,    67,    68,    74,    52,
      55,    47,    55,    32,    53,    54,    32,    25,    28,    59,
      60,    28,    28,    68,    26,     9,    28,    32,    36,    69,
      70,    71,    72,    73,    74,    76,    28,    62,    15,    56,
      23,    55,    32,    53,    26,    28,    24,    25,    69,     4,
      67,    35,    35,    75,    15,    69,    70,    69,    28,     3,
      10,    25,    16,    17,    18,    19,    20,    22,    30,    37,
      31,    33,    69,    56,    69,    25,    36,    29,    54,    29,
      67,    24,    24,    29,    27,    29,    29,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    29,
      25,    27,    14,    40,    69,    25,    74,    29,    29,    25,
      25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    46,    46,    47,
      47,    48,    49,    49,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    59,    60,    61,    62,    63,    64,    64,
      64,    65,    66,    67,    68,    68,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    73,    73,    73,    73,    74,    74,    75,
      76
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
#line 108 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Program> -> <Headers> <Programbody>\n");
		}
#line 1397 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 112 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Program> -> <Programbody>\n");
		}
#line 1405 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 118 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Headers> -> <Headers> <Header>\n");
		}
#line 1413 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 123 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Headers> -> <Header>\n");
		}
#line 1421 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Header> -> <INCLUDE> <HEADERSTRING>\n");
		}
#line 1429 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Program> -> <Procedures>\n");
		}
#line 1437 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 139 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Program> -> <DeclList> <Procedures>\n");
		}
#line 1445 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
		}
#line 1453 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Procedures> -> epsilon\n");
		}
#line 1461 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
		}
#line 1469 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 161 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
		}
#line 1477 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 165 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ProcedureHead> -> <FunctionDecl>\n");
		}
#line 1485 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 171 "CminusParser.y" /* yacc.c:1646  */
    {
			//printf("<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>\n"); 
		}
#line 1493 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ProcedureBody> -> <StatementList> <RBR>\n");
		}
#line 1501 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 184 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
		}
#line 1509 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 188 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
	 	}
#line 1517 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 195 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<IdentifierList> -> <VarDecl>\n");
		}
#line 1525 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
		}
#line 1533 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 206 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<VarDecl> -> <IDENTIFIER\n");
		}
#line 1541 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 210 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
		}
#line 1549 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 216 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Type> -> <INTEGER>\n");
		}
#line 1557 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 222 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Statement> -> <Assignment>\n");
		}
#line 1565 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 226 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Statement> -> <IfStatement>\n");
		}
#line 1573 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 230 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Statement> -> <WhileStatement>\n");
		}
#line 1581 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 234 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Statement> -> <IOStatement>\n");
		}
#line 1589 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 238 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Statement> -> <ReturnStatement>\n");
		}
#line 1597 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 242 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Statement> -> <ExitStatement>\n");
		}
#line 1605 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 246 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //printf("<Statement> -> <CompoundStatement>\n");
		}
#line 1613 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 252 "CminusParser.y" /* yacc.c:1646  */
    { 
		  setRegister((yyvsp[-3].name));
		  //memCount += 4;
		  
		 // char buf[10] = getRegister($1);
		  //strcat(instrString, 

		  setValue((yyvsp[-3].name), (yyvsp[-1].val));
		  //printf("<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>\n");
		}
#line 1628 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 265 "CminusParser.y" /* yacc.c:1646  */
    {
			//printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
		}
#line 1636 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 269 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<IfStatement> -> <IF> <TestAndThen>\n");
		}
#line 1644 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 276 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
		}
#line 1652 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 282 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Test> -> <LP> <Expr> <RP>\n");
		}
#line 1660 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 289 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
		}
#line 1668 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 295 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
		}
#line 1676 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 301 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<WhileToken> -> <WHILE>\n");
		}
#line 1684 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 307 "CminusParser.y" /* yacc.c:1646  */
    {

		  
		   //Creates the data for the string and names it
                  char *s = (char*)malloc(50*sizeof(char));
                  strcat(s, "\n.string_const");
                  char buf[10];
                  sprintf(buf, "%d", stringCount);
                  stringCount++;
                  strcat(s, buf);
                  strcat(s, ": .string ");
                  strcat(s, (yyvsp[-5].name));

                  strcat(stringString, s);

                  //Assembly instruction for scanf

                  char *instr = (char*)malloc(50*sizeof(char));
                  strcat(instr, "\nleaq ");
                  strcat(instr, substr(s, 1, 14)); //Gets the string name from s
                  strcat(instr, "(%rip), %rdi\nmovq ");
		  
		  
		  int n;
		  scanf((yyvsp[-5].name), &n);
		  setValue((yyvsp[-2].name), n);
		  setRegister((yyvsp[-2].name));

		  strcpy(buf, getRegister((yyvsp[-2].name)));
		  strcat(instr, buf);
		  strcat(instr,", %rsi\nmovl $0, %eax\ncall scanf@PLT"); 
		  strcat(instrString, instr);

		 // printf("The variable is %c\n", $6[0]);
		 // printf("The register associated with %s is %s\n", $6, getRegister($6));


		  
		 
		  /*	
		  int t;
		      
		  scanf($3, &t);
		  setValue($6, t); */
		  //printf("<IOStatement> -> <READ> <LP> <STRING> <COMMA> <ADDR> <Variable> <RP> <SC>\n");
		}
#line 1735 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 354 "CminusParser.y" /* yacc.c:1646  */
    {
		
		
		   //Creates the data for the string and names it
                  char *s = (char*)malloc(50*sizeof(char));
                  strcat(s, "\n.string_const");
                  char buf[10];
                  sprintf(buf, "%d", stringCount);
                  stringCount++;
                  strcat(s, buf);
                  strcat(s, ": .string ");
                  strcat(s, (yyvsp[-4].name));

                  strcat(stringString, s);

                  //Assembly instruction for printf
		  char *instr = (char*)malloc(50*sizeof(char));
                  strcat(instr, "\nleaq ");
                  strcat(instr, substr(s, 1, 14));
		  strcat(instr, "(%rip), %rdi\nmovl $");
		  sprintf(buf, "%d", (yyvsp[-2].val));
		  strcat(instr, buf);
		  strcat(instr, ", %esi\nmovl $0, %eax\ncall printf@PLT");
		  strcat(instrString, instr);
 

		
			
		
		  /* char *fmt = replaceNewline($3);
		  printf(fmt, $5);
		  free(fmt);
		  free($3);*/
		  //printf("<IOStatement> -> <WRITE> <LP> <STRING> <COMMA> <Expr> <RP> <SC>\n");
		
		}
#line 1776 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 391 "CminusParser.y" /* yacc.c:1646  */
    {

		  //Creates data for string
		  char *s = (char*)malloc(50*sizeof(char));
		  strcat(s, "\n.string_const");
		  char buf[10];
		  sprintf(buf, "%d", stringCount);
		  stringCount++;
		  strcat(s, buf);
		  strcat(s, ": .string ");
		  strcat(s, (yyvsp[-2].name));

		  strcat(stringString, s);


		  //Instruciton part of printf

		  char *instr = (char*)malloc(50*sizeof(char));
		  strcat(instr, "\nleaq ");
		  strcat(instr, substr(s, 1, 14));
		  strcat(instr, "(%rip), %rdi\nmovl $0, %eax\ncall printf@PLT");
		  strcat(instrString, instr);

		  /*
		  char * s = $3;
		  char *fmt = replaceNewline(s);
		  printf(fmt);
		  free(fmt);
		  free($3);*/
		  //printf("<IOStatement> -> <WRITE> <LP> <StringConstant> <RP> <SC>\n");

		}
#line 1813 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 426 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
		}
#line 1821 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 432 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ExitStatement> -> <EXIT> <SC>\n");
		}
#line 1829 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 438 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
		}
#line 1837 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 444 "CminusParser.y" /* yacc.c:1646  */
    {		
		  //printf("<StatementList> -> <Statement>\n");
		}
#line 1845 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 448 "CminusParser.y" /* yacc.c:1646  */
    {		
		  //printf("<StatementList> -> <StatementList> <Statement>\n");
		}
#line 1853 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 454 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval.val) = (yyvsp[0].val);
		  //printf("<Expr> -> <SimpleExpr>\n");
		}
#line 1862 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 459 "CminusParser.y" /* yacc.c:1646  */
    { 

		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for OR
                  strcat(instrString, "\norq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  (yyval.val) = ((yyvsp[-2].val) || (yyvsp[0].val));
		  //printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
		}
#line 1895 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 488 "CminusParser.y" /* yacc.c:1646  */
    {

		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for AND
                  strcat(instrString, "\nandq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  (yyval.val) = ((yyvsp[-2].val) && (yyvsp[0].val));
		  //printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
		}
#line 1928 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 517 "CminusParser.y" /* yacc.c:1646  */
    {

		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[0].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[0].val));
                  }

                  //Creates the instructions for NOT
                  strcat(instrString, "\nnotq ");
                  strcat(instrString, getRegister(buf1));

		  (yyval.val) = (!(yyvsp[0].val));
		  //printf("<Expr> -> <NOT> <SimpleExpr> \n");
		}
#line 1951 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 538 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval.val) = (yyvsp[0].val);
		  //printf("<SimpleExpr> -> <AddExpr>\n");
		}
#line 1960 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 543 "CminusParser.y" /* yacc.c:1646  */
    {
		
		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));
		
		  strcat(instrString, "\ncmove ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

  
		  (yyval.val) = ((yyvsp[-2].val) == (yyvsp[0].val));
		  //printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
		}
#line 1999 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 578 "CminusParser.y" /* yacc.c:1646  */
    {


		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

                  strcat(instrString, "\ncmovne ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  (yyval.val) = ((yyvsp[-2].val) != (yyvsp[0].val));
		  //printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
		}
#line 2038 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 613 "CminusParser.y" /* yacc.c:1646  */
    {

		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

                  strcat(instrString, "\ncmovne ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  (yyval.val) = ((yyvsp[-2].val) <= (yyvsp[0].val));
		  //printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
		}
#line 2076 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 647 "CminusParser.y" /* yacc.c:1646  */
    {

		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

          	  strcat(instrString, "\ncmove ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));


                  strcat(instrString, "\ncmovne ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  (yyval.val) = ((yyvsp[-2].val) < (yyvsp[0].val));
		  //printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
		}
#line 2120 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 687 "CminusParser.y" /* yacc.c:1646  */
    {

		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

                  strcat(instrString, "\ncmove ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  strcat(instrString, "\ncmovg ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));


		  (yyval.val) = ((yyvsp[-2].val) >= (yyvsp[0].val));
		  //printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
		}
#line 2164 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 727 "CminusParser.y" /* yacc.c:1646  */
    {

		  
		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

                  strcat(instrString, "\ncmovg ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  //printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
		  (yyval.val) = ((yyvsp[-2].val) > (yyvsp[0].val));
		}
#line 2203 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 764 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval.val) = (yyvsp[0].val);
		  //printf("<AddExpr> -> <MulExpr>\n");
		}
#line 2212 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 769 "CminusParser.y" /* yacc.c:1646  */
    {

		  //Checks that both values have an address assigned to them
		  char buf1[4];
		  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
			sprintf(buf1, "%d", (yyvsp[-2].val)); 
			setRegister(buf1);
		  }else {
			strcpy(buf1, (yyvsp[-2].val));
		  }

		  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
			setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

		  //Creates the instructions for adding
		  strcat(instrString, "\naddq ");
		  strcat(instrString, getRegister(buf1));
		  strcat(instrString, ", ");
		  strcat(instrString, getRegister(buf2));
		  (yyval.val) = (yyvsp[-2].val) + (yyvsp[0].val);
		  //printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
		}
#line 2244 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 797 "CminusParser.y" /* yacc.c:1646  */
    {

		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for subtracting
                  strcat(instrString, "\nsubq ");
                  strcat(instrString, getRegister(buf2));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf1));

		  (yyval.val) = (yyvsp[-2].val) - (yyvsp[0].val);
		  //printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
		}
#line 2277 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 828 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval.val) = (yyvsp[0].val);
		  //printf("<MulExpr> -> <Factor>\n");
		}
#line 2286 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 833 "CminusParser.y" /* yacc.c:1646  */
    {

		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for mul
                  strcat(instrString, "\nimulq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));
 
		  (yyval.val) = (yyvsp[-2].val) * (yyvsp[0].val);
		  //printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
		}
#line 2319 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 862 "CminusParser.y" /* yacc.c:1646  */
    {
		
		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof((yyvsp[-2].val)) == sizeof(int)){
                        sprintf(buf1, "%d", (yyvsp[-2].val));
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, (yyvsp[-2].val));
                  }

                  char buf2[4];
                  if (sizeof((yyvsp[0].val)) == sizeof(int)){
                        sprintf(buf2, "%d", (yyvsp[0].val));
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, (yyvsp[0].val));
                  }

                  //Creates the instructions for div
		  
		  /*
		  strcat(instrString, "\nmovl (");
		  strcat(instrString, getRegister(buf2));
		  strcat(instrString, "), %eax\nmovl (");
		  strcat(instrString, getRegister(buf1));
		  strcat(instrString, "), %edx");
                  strcat(instrString, "\nidivl ");
                  strcat(instrString, "%edx");*/

		  (yyval.val) = (yyvsp[-2].val) / (yyvsp[0].val);
		  //printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
		}
#line 2357 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 898 "CminusParser.y" /* yacc.c:1646  */
    { 
		  (yyval.val) = getValue((yyvsp[0].name));
		  //printf("<Factor> -> <Variable>\n");
		}
#line 2366 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 903 "CminusParser.y" /* yacc.c:1646  */
    { 
		  (yyval.val) = (yyvsp[0].val);
		  //printf("<Factor> -> <Constant>\n");
		}
#line 2375 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 908 "CminusParser.y" /* yacc.c:1646  */
    {	
		  //printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		}
#line 2383 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 912 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval.val) = (yyvsp[-1].val);
		  //printf("<Factor> -> <LP> <Expr> <RP>\n");
		}
#line 2392 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 919 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval.name) = (yyvsp[0].name);
		  //printf("<Variable> -> <IDENTIFIER>\n");
		}
#line 2401 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 924 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
               	}
#line 2409 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 930 "CminusParser.y" /* yacc.c:1646  */
    { 
		  (yyval.name) = (yyvsp[0].name);
		  //printf("<StringConstant> -> <STRING>\n");
		}
#line 2418 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 937 "CminusParser.y" /* yacc.c:1646  */
    { 
		  (yyval.val) = (yyvsp[0].val);
		  //printf("<Constant> -> <INTCON>\n");
		}
#line 2427 "CminusParser.c" /* yacc.c:1646  */
    break;


#line 2431 "CminusParser.c" /* yacc.c:1646  */
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
#line 943 "CminusParser.y" /* yacc.c:1906  */



/********************C ROUTINES *********************************/

void yyerror(const char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,yylineno,s);
}

int yywrap() {
	return 1;
}

void setRegister(char* c){

	for(int i = 0; i < 14; i++){
		
		if(strcmp(inUse[i], c) == 0){
			return;
		}


		if(strcmp(inUse[i], "0") == 0){
	
			strcpy(inUse[i], c);
		//	printf("Assigning %s to address %s\n", c, registers[i] );
			break;	

		}

	}

}


char* getRegister(char* c){

	char buf[5];
	strcpy(buf, c);

	for(int i = 0; i < 14; i++){

		if(strcmp(inUse[i], c) == 0){

		//	printf("Found! %s is assigned to %s\n", c, registers[i]);
			return registers[i];

		}/*else{

			setRegister(buf);
			return getRegister(buf);		

		}*/

	}

}


void freeRegister(char* c){

	for(int i = 0; i < 14; i++){

		if(strcmp(inUse[i], c) == 0){
		
			strcpy(inUse[i], "0");
			break;
		
		}

	}

}


static void initialize(char* inputFileName) {
	yyin = fopen(inputFileName,"r");
        if (yyin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }
	
        //  uncomment this section for Project 2
	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
	} 
        
	//printf(".section .rodata\n.text\n.global main\n.type main,@function\nmain: nop\npushq %rbp\nmovq %rsp, %rbp\n");	

	symtab = SymInit(SYMTABLE_SIZE);
	SymInitField(symtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);
}

static void finalize() {
    SymKillField(symtab,SYMTAB_VALUE_FIELD);
    SymKill(symtab);
    fclose(yyin);
    fclose(stdout);  //uncomment this line for Project 2
}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
	instrString = (char*)malloc(1000*sizeof(char));
	stringString = (char*)malloc(1000*sizeof(char));
	memString = (char*)malloc(1000*sizeof(char));

	for(int i = 0; i < 14; i++){

		strcpy(inUse[i], "0");		

	}


	
        yyparse();

	//Prints the data section
	printf(".section .rodata\n%s%s\n.text\n.global main\n.type main,@function\nmain: nop\npushq %rbp\nmovq %rsp, %rbp%s\nleave\nret\n", memString, stringString, instrString);
  
  	finalize();
  
	free(instrString);
	free(stringString);
	free(memString);

  	return 0;
}

/**
 *
 * retrieve the value of a key
 *
 :* @param name a C character string which is a key
 * @return the value of the key
 */
static int getValue(char *name)
{
  return (int)SymGetField(symtab, name, SYMTAB_VALUE_FIELD); 
}

/**
 *
 * retrieve the value of a key
 *
 * @param name a C character string which is a key
 * @param value the value of the key
 */
static void setValue(char *name, int value)
{
  SymPutField(symtab, name, SYMTAB_VALUE_FIELD, (Generic)value); 
}
/******************END OF C ROUTINES**********************/
