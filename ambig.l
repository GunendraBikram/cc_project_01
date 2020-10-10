%{
#include "y.tab.h"
int yylex();
#include<string.h>
%}
%%
[ \t\n] {}


"=" {return EQ;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
">" {return GT;}
"<" {return LT;}
">=" {return LTEQ;}
"<=" {return GTEQ;}
"not" {return NOT;}
"div" {return DIV;}
"mod" {return MOD;}
"or"  {return OR;}
"and" return AND;
"define-fun" return DEFFUN;
"get-int" return GETINT;
"true" return TRUE;
"false" return FALSE;
"print" return PRINT;
"eval"  return EVAL;
"if"  return IF;
[(] {return LPAR;}
[)] {return RPAR;}
[-]?[1-9][0-9]* { yylval.str = strdup(yytext); return CONST;}
[a-zA-Z][a-zA-Z0-9]* { yylval.str = strdup(yytext); return ID;}        //changed id to ID

. {printf("Lex error: %s\n", yytext); return ERR;}
%%
int yywrap(void) {return 1;}
