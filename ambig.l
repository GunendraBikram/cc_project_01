%{
#include "y.tab.h"
int yylex();
%}
%%
[ \t\n] {}
[-]?[1-9][0-9]* { yylval.str = strdup(yytext); return CONST;}
"not" {return NOT;}
"=" {return EQ;}
"+" {return PLUS;}
"-" {return MINUS;}
"define-fun" return DEFFUN;
"get-int" return GETINT;
"true" return TRUE;
"false" return FALSE;
"print" return PRINT;
"eval" return EVAL;
[a-zA-Z][a-zA-Z0-9]* { yylval.str = strdup(yytext); return ID;}
[(] {return LPAR;}
[)] {return RPAR;}
. {printf("Lex error: %s\n", yytext); return ERR;}
%%
int yywrap(void) {return 1;}

