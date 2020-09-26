%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
int yylex();
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUMBER;}
true {yylval=1; return TRUE;}
false {yylval=0; return FALSE;}
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
if return IF;
eval return EVAL;


. {;}

%%

int yywrap(void) {return 1;}