%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
int yylex();
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUMBER;}
[ \t] {;}
[\n] return 0;
"+" return ADD;
"-" return SUB;
"*" return MUL;
div return DIV;
mod  return MOD;
"(" return OBR;
")" return CBR;
"~" return UMINUS;
"=" return EQ;
"<" return LT;
"<=" return LTE;
">" return GT;
">=" return GTE;
not return NOT;
and return AND;
or return OR;

. {printf("lex error%s\n", yytext);}

%%

int yywrap(void) {return 1;}
