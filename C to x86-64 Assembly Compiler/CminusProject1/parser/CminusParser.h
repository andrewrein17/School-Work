/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 90 "CminusParser.y" /* yacc.c:1909  */
int value;
	char* name;
#line 92 "CminusParser.y" /* yacc.c:1909  */
int exprVal;
#line 93 "CminusParser.y" /* yacc.c:1909  */
char* theValue;
#line 95 "CminusParser.y" /* yacc.c:1909  */
char* stringName;

#line 107 "CminusParser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMINUSPARSER_H_INCLUDED  */
