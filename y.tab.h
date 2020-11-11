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
    IF = 258,                      /* IF  */
    LET = 259,                     /* LET  */
    PRINT = 260,                   /* PRINT  */
    EVAL = 261,                    /* EVAL  */
    REGID = 262,                   /* REGID  */
    INP = 263,                     /* INP  */
    COST = 264,                    /* COST  */
    BOOLID = 265,                  /* BOOLID  */
    INTID = 266,                   /* INTID  */
    FUNID = 267,                   /* FUNID  */
    PLUS = 268,                    /* PLUS  */
    MINUS = 269,                   /* MINUS  */
    DIV = 270,                     /* DIV  */
    MOD = 271,                     /* MOD  */
    MULT = 272,                    /* MULT  */
    EQ = 273,                      /* EQ  */
    LT = 274,                      /* LT  */
    GT = 275,                      /* GT  */
    GE = 276,                      /* GE  */
    LE = 277,                      /* LE  */
    NOT = 278,                     /* NOT  */
    OR = 279,                      /* OR  */
    AND = 280,                     /* AND  */
    LPAR = 281,                    /* LPAR  */
    RPAR = 282,                    /* RPAR  */
    CALL = 283,                    /* CALL  */
    GETINT = 284,                  /* GETINT  */
    GETBOOL = 285,                 /* GETBOOL  */
    INT = 286,                     /* INT  */
    BOOL = 287,                    /* BOOL  */
    DEFFUN = 288,                  /* DEFFUN  */
    TRUE = 289,                    /* TRUE  */
    FALSE = 290,                   /* FALSE  */
    ERR = 291,                     /* ERR  */
    ID = 292,                      /* ID  */
    CONST = 293,                   /* CONST  */
    LETID = 294,                   /* LETID  */
    VARID = 295,                   /* VARID  */
    DECLID = 296                   /* DECLID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define LET 259
#define PRINT 260
#define EVAL 261
#define REGID 262
#define INP 263
#define COST 264
#define BOOLID 265
#define INTID 266
#define FUNID 267
#define PLUS 268
#define MINUS 269
#define DIV 270
#define MOD 271
#define MULT 272
#define EQ 273
#define LT 274
#define GT 275
#define GE 276
#define LE 277
#define NOT 278
#define OR 279
#define AND 280
#define LPAR 281
#define RPAR 282
#define CALL 283
#define GETINT 284
#define GETBOOL 285
#define INT 286
#define BOOL 287
#define DEFFUN 288
#define TRUE 289
#define FALSE 290
#define ERR 291
#define ID 292
#define CONST 293
#define LETID 294
#define VARID 295
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
