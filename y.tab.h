/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PRINT = 258,                   /* PRINT  */
    IF = 259,                      /* IF  */
    FUNID = 260,                   /* FUNID  */
    OR = 261,                      /* OR  */
    EVAL = 262,                    /* EVAL  */
    LT = 263,                      /* LT  */
    GT = 264,                      /* GT  */
    LTEQ = 265,                    /* LTEQ  */
    GTEQ = 266,                    /* GTEQ  */
    MUL = 267,                     /* MUL  */
    DIV = 268,                     /* DIV  */
    MOD = 269,                     /* MOD  */
    PLUS = 270,                    /* PLUS  */
    MINUS = 271,                   /* MINUS  */
    AND = 272,                     /* AND  */
    EQ = 273,                      /* EQ  */
    NOT = 274,                     /* NOT  */
    LPAR = 275,                    /* LPAR  */
    RPAR = 276,                    /* RPAR  */
    CALL = 277,                    /* CALL  */
    GETINT = 278,                  /* GETINT  */
    DEFFUN = 279,                  /* DEFFUN  */
    TRUE = 280,                    /* TRUE  */
    FALSE = 281,                   /* FALSE  */
    ERR = 282,                     /* ERR  */
    ID = 283,                      /* ID  */
    CONST = 284                    /* CONST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PRINT 258
#define IF 259
#define FUNID 260
#define OR 261
#define EVAL 262
#define LT 263
#define GT 264
#define LTEQ 265
#define GTEQ 266
#define MUL 267
#define DIV 268
#define MOD 269
#define PLUS 270
#define MINUS 271
#define AND 272
#define EQ 273
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
#line 8 "ambig.y"
int val; char* str;

#line 127 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
