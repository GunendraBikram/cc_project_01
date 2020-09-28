%{
void yyerror(char *s);
int yylex();
#include<stdio.h>
#include<string.h>
int flag=0;
%}

%union { int val; char *str;}
%token<val> CONST 
%token ADD SUB MUL DIV 
%token EQ LT LTE GT GTE
%token NOT AND OR
%token OBR CBR
%token EVAL IF
%token UMINUS
%token<val> TRUE FALSE
%token DEFINEFUN
%token<str> VAR

%type<val> program  fun expr term

%start program
%left NOT AND OR
%left EQ LT LTE GT GTE
%left ADD  SUB
%left MUL  DIV MOD
%left UMINUS
%left OBR CBR 

%%

program:fun {printf("\n%d\n", $$); return 0;};
fun:	OBR EVAL expr CBR {$$=$3;}| 
	OBR EVAL term CBR {$$=$3;}
	;
term:   CONST {$$=$1;}  | 
	ADD term term  {$$=$2+$3;}|
	SUB term term  {$$=$2-$3;}|
	MUL term term  {$$=$2*$3;}|
	DIV  term term  {$$=$2/$3;}|
	MOD  term term  {$$=$2%$3;}|
	IF expr expr expr  {$$=$2;}|
	OBR term CBR {$$=$2;}
	;
expr:	TRUE {$$=$1;} | FALSE {$$=$1;}| 
	EQ term term   {$$=$2==$3;}|
	LT  term term   {$$=$2<$3;}|
	LTE  term term   {$$=$2<=$3;}|
	GT  term term    {$$=$2>$3;}|
	GTE  term term   {$$=$2>=$3;}|
	NOT  expr   {$$= !$2;}|
	AND  expr expr     {$$=($2 && $3);}|
	OR  expr expr   {$$=$2 || $3;}|
	UMINUS expr {$$=-$2;}|
	OBR expr CBR {$$=$2;}	
	;
		
%%

void  main(){ 
yyparse();
if(flag==0)printf("\n"); }
void yyerror(char *s){ printf("%s\n", s); flag=1;}
