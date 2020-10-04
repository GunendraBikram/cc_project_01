%{
void yyerror(char *s);
int yylex();
#include<stdio.h>
#include<string.h>
#include "containers.h"


%}

%union {int val; char* str;}
%start program

%token<val> PLUS MINUS EQ NOT LPAR RPAR CONST GETINT DEFFUN TRUE FALSE  ERR 
%token PRINT CALL
%token<str> ID 
%type<val> term fla 


%%

program: term;

program: 
LPAR PRINT term RPAR 
|LPAR PRINT fla RPAR 
|LPAR DEFFUN ID term RPAR program
|LPAR DEFFUN ID fla RPAR program
;

term: CONST
|LPAR PLUS term term RPAR
|LPAR MINUS term term RPAR
|LPAR GETINT RPAR
;

fla: TRUE
|FALSE
|LPAR  EQ term term RPAR
|LPAR NOT fla RPAR
;
%%

int main(void) {return yyparse();}
void yyerror (char *s) {printf("%s\n", s);}
