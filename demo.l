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
if return IF;
eval return EVAL;
define-fun return DEFINE-FUN;
[a-zA-Z0-9]* return VAR;
[a-z][-]?[a-z]?+ return FUN;
get-int return GET-INT;
true return TRUE;
false return FALSE;
fun return FUN;





. {printf("lex error%s\n", yytext);}

%%

int yywrap(void) {return 1;}
