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
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    DIV = 260,                     /* DIV  */
    MOD = 261,                     /* MOD  */
    MULT = 262,                    /* MULT  */
    EQ = 263,                      /* EQ  */
    LT = 264,                      /* LT  */
    GT = 265,                      /* GT  */
    GE = 266,                      /* GE  */
    LE = 267,                      /* LE  */
    NOT = 268,                     /* NOT  */
    OR = 269,                      /* OR  */
    AND = 270,                     /* AND  */
    IF = 271,                      /* IF  */
    LET = 272,                     /* LET  */
    LPAR = 273,                    /* LPAR  */
    RPAR = 274,                    /* RPAR  */
    CONST = 275,                   /* CONST  */
    GETINT = 276,                  /* GETINT  */
    GETBOOL = 277,                 /* GETBOOL  */
    DEFFUN = 278,                  /* DEFFUN  */
    TRUE = 279,                    /* TRUE  */
    FALSE = 280,                   /* FALSE  */
    ID = 281,                      /* ID  */
    INT = 282,                     /* INT  */
    BOOL = 283,                    /* BOOL  */
    ERR = 284,                     /* ERR  */
    PRINT = 285,                   /* PRINT  */
    EVAL = 286,                    /* EVAL  */
    CALL = 287,                    /* CALL  */
    FUNID = 288,                   /* FUNID  */
    REGID = 289,                   /* REGID  */
    LETID = 290,                   /* LETID  */
    VARID = 291,                   /* VARID  */
    INP = 292,                     /* INP  */
    COST = 293,                    /* COST  */
    BOOLID = 294,                  /* BOOLID  */
    INTID = 295,                   /* INTID  */
    DECLID = 296                   /* DECLID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PLUS 258
#define MINUS 259
#define DIV 260
#define MOD 261
#define MULT 262
#define EQ 263
#define LT 264
#define GT 265
#define GE 266
#define LE 267
#define NOT 268
#define OR 269
#define AND 270
#define IF 271
#define LET 272
#define LPAR 273
#define RPAR 274
#define CONST 275
#define GETINT 276
#define GETBOOL 277
#define DEFFUN 278
#define TRUE 279
#define FALSE 280
#define ID 281
#define INT 282
#define BOOL 283
#define ERR 284
#define PRINT 285
#define EVAL 286
#define CALL 287
#define FUNID 288
#define REGID 289
#define LETID 290
#define VARID 291
#define INP 292
#define COST 293
#define BOOLID 294
#define INTID 295
#define DECLID 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "lab_yacc.y"
int val; char* str;

#line 151 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
