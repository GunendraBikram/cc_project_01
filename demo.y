%{
void yyerror(char *s);
int yylex();
#include<stdio.h>
int flag=0;
%}


%start program
%token NUMBER
%token ADD SUB MUL DIV
%token EQ LT LTE GT GTE
%token NOT AND OR
%token OBR CBR
%token EVAL
%token MOD
%token UMINUS



%%
program: expr {printf("\n%d\n", $$); return 0;}
expr: 
  ADD expr expr {$$=$2+$3;}|
  SUB expr expr {$$=$2-$3;}|
  MUL expr expr {$$=$2*$3;}|
  DIV expr expr {$$=$2/$3;}|
  MOD expr expr {$$=$2 % $3;}|
  EQ expr expr {$$=($2==$3);}|
  LT expr expr {$$=$2<$3;}|
  LTE expr expr {$$=($2<=$3);}|
  GT expr expr {$$=$2>$3;}|
  GTE expr expr {$$=($2>=$3);}|
  NOT expr {$$=!$2;}|
  AND expr expr {$$=$2 && $3;}|
  OR expr expr {$$=$2||$3;}|
  UMINUS expr {$$=-$2;}|
  OBR expr CBR {$$=$2;} |
  NUMBER {$$=$1;}
%%

void  main() {  yyparse (); if(flag ==0) printf("\nValid expression\n"); }
void yyerror (char *s) {printf("Invalid Expression: %s\n", s); flag=1;}
