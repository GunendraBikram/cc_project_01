%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
int yylex();
%}

%%
[ \t] {;}       //[a-zA-Z0-9]+ {yylval.str=strdup(yytext); return FUN}
            
[a-zA-Z]+ {yylval.str=strdup(yytext); return VAR}     //added
[0-9]+ {yylval=atoi(yytext); return CONST;}           //added
true {yylval=1; return TRUE;}
false {yylval=0; return FALSE;}
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
define-fun return DEFINE_FUN;               //added
print return PRINT;                         //added
get-int return GET_INT;                     //added
. {;}

%%

int yywrap(void) {return 1;}
