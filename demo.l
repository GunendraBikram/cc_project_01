%{
#include "y.tab.h"
int yylex();
%}

%%
[\t\n] {}
[a-zA-Z]+ {yylval.str=strdup(yytext); return ID;}
, {return COMMA;}
; {return SEMICOLON;}
. {printf("lex error: %s\n", yytext); return ERR;}
%%
int yywrap(void) {return 1;}
