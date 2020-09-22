
[\t\n] {}%{
#include "y.tab.h"
int yylex();
%}

%%

int yywrap(void) {return 1;}[a-zA-Z]+ {yylval.str=strdup(yytext); return ID;}
, {return COMMA;}
; {return SEMICOLON;}
. {printf("lex error: %s\n", yytext); return ERR;}
%%
