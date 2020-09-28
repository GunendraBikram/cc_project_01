%{
#include<stdio.h>
#include "y.tab.h"
#include<stdlib.h>
#include<string.h>
extern YYSTYPE yylval;
int yylex();
%}
%%
[0-9]+ {
	yylval.val=atoi(yytext);
	return CONST;
	}
true {yylval.val=1; return TRUE;}
false {yylval.val=0; return FALSE;}
[ \t] {;}
[\n] return 0;
"+" return ADD;
"-" return SUB;
"*" return MUL;
div return DIV;
mod return MOD;
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
define-fun return DEFINEFUN;
get-int  return GETINT;
print return PRINT;


[a-zA-Z][a-zA-Z0-9]* {yylval.str=strdup(yytext); return VAR;}
. {;} 

%%

int yywrap(void) { return 1;}

