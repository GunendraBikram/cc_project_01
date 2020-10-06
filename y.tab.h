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
    PRINT = 258,
    EVAL = 259,
    FUNID1 = 260,
    FUNID2 = 261,
    FUNID3 = 262,
    PLUS = 263,
    MINUS = 264,
    MUL = 265,
    DIV = 266,
    MOD = 267,
    AND = 268,
    EQ = 269,
    LT = 270,
    GT = 271,
    LTEQ = 272,
    GTEQ = 273,
    NOT = 274,
    LPAR = 275,
    RPAR = 276,
    CALL = 277,
    GETINT = 278,
    DEFFUN = 279,
    TRUE = 280,
    FALSE = 281,
    ERR = 282,
    ID = 283,
    CONST = 284
  };
#endif
/* Tokens.  */
#define PRINT 258
#define EVAL 259
#define FUNID1 260
#define FUNID2 261
#define FUNID3 262
#define PLUS 263
#define MINUS 264
#define MUL 265
#define DIV 266
#define MOD 267
#define AND 268
#define EQ 269
#define LT 270
#define GT 271
#define LTEQ 272
#define GTEQ 273
#define NOT 274
#define LPAR 275
#define RPAR 276
#define CALL 277
#define GETINT 278
#define DEFFUN 279
#define TRUE 280
#define FALSE 281
#define ERR 282
#define ID 283
#define CONST 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "ambig.y"
int val; char* str;

#line 118 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
