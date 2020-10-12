%{
#include "y.tab.h"
int yylex();
%}
%%
[ \t\n] {}
[-]?[1-9][0-9]* { yylval.str = strdup(yytext); return CONST;}
"not" {return NOT;}
"=" {return EQ;}
"<" {return LT;}
">" {return GT;}
"<=" {return LTEQ;}
">=" {return GTEQ;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"div" return DIV;
"mod" return MOD;

"define-fun" return DEFFUN;
"get-int" return GETINT;
"if" return IF;
"true"  {yylval.val=1; return BOOL;}
"false" {yylval.val=0;  return BOOL;}
"and" return AND;
"or" return OR;
"print" return PRINT;
"eval" return EVAL;
[a-zA-Z][a-zA-Z0-9]* { yylval.str = strdup(yytext); return ID;}
[(] {return LPAR;}
[)] {return RPAR;}
. {printf("Lex error: %s\n", yytext); return ERR;}
%%
int yywrap(void) {return 1;}
