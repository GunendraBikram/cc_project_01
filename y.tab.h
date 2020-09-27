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
    CONST = 258,
    ADD = 259,
    SUB = 260,
    MUL = 261,
    DIV = 262,
    EQ = 263,
    LT = 264,
    LTE = 265,
    GT = 266,
    GTE = 267,
    NOT = 268,
    AND = 269,
    OR = 270,
    OBR = 271,
    CBR = 272,
    EVAL = 273,
    IF = 274,
    UMINUS = 275,
    TRUE = 276,
    FALSE = 277,
    DEFINEFUN = 278,
    PRINT = 279,
    VAR = 280,
    MOD = 281
  };
#endif
/* Tokens.  */
#define CONST 258
#define ADD 259
#define SUB 260
#define MUL 261
#define DIV 262
#define EQ 263
#define LT 264
#define LTE 265
#define GT 266
#define GTE 267
#define NOT 268
#define AND 269
#define OR 270
#define OBR 271
#define CBR 272
#define EVAL 273
#define IF 274
#define UMINUS 275
#define TRUE 276
#define FALSE 277
#define DEFINEFUN 278
#define PRINT 279
#define VAR 280
#define MOD 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "demo.y"
 int val; char *str;

#line 112 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
