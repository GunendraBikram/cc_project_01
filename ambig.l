%{
#include "y.tab.h"
#include<string.h>
int yylex();
%}
%%
[ \t\n] {}
[-]?[1-9][0-9]* { yylval.str = strdup(yytext); return CONST;}
"not" {return NOT;}
"=" {return EQ;}
"+" {return PLUS;}
"-" {return MINUS;}
"*"  return MUL;
"<" return GT;
">"  return LT;
"<="  return GTEQ;
">="  return LTEQ;
"define-fun" return DEFFUN;
"get-int" return GETINT;
"true" return TRUE;
"false" return FALSE;
"print" return PRINT;
"eval"  return EVAL;
"print" return print;
"if"    return IF;
"get-int" return GETINT;
"not"    return NOT;
"and"    return AND;
"or"     return OR;
"div"    return DIV;
"mod"     return MOD;
[a-zA-Z][a-zA-Z0-9]* { yylval.str = strdup(yytext); return id;}
[(] {return LPAR;}
[)] {return RPAR;}
. {printf("Lex error: %s\n", yytext); return ERR;}
%%
int yywrap(void) {return 1;}
