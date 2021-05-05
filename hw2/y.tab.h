/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    STRING = 261,
    SEMICOLON = 262,
    IfStmt = 263,
    LoopStmt = 264,
    PRINT = 265,
    INC = 266,
    DEC = 267,
    BIG_EQU = 268,
    SMALL_EQU = 269,
    EQUAL = 270,
    NOT_EQUAL = 271,
    AND = 272,
    OR = 273,
    TRUE = 274,
    FALSE = 275,
    IF = 276,
    ELSE = 277,
    WHILE = 278,
    FOR = 279,
    INT_LIT = 280,
    FLOAT_LIT = 281,
    STRING_LIT = 282,
    IDENT = 283
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define STRING 261
#define SEMICOLON 262
#define IfStmt 263
#define LoopStmt 264
#define PRINT 265
#define INC 266
#define DEC 267
#define BIG_EQU 268
#define SMALL_EQU 269
#define EQUAL 270
#define NOT_EQUAL 271
#define AND 272
#define OR 273
#define TRUE 274
#define FALSE 275
#define IF 276
#define ELSE 277
#define WHILE 278
#define FOR 279
#define INT_LIT 280
#define FLOAT_LIT 281
#define STRING_LIT 282
#define IDENT 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "compiler_hw2.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 120 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
