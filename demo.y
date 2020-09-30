%{
void yyerror(char *s);
int yylex();
#include<stdio.h>
#include<string.h>
int flag=0;
%}

%union { int val; char *str;}
%token<val> CONST 
%token ADD SUB MUL DIV MOD
%token EQ LT LTE GT GTE
%token NOT AND OR
%token OBR CBR
%token EVAL IF
%token<val> TRUE FALSE
%token DEFINEFUN
%token<str> VAR
%token GETINT
%token PRINT

%type<val> program  fun expr term

%start program

%%

program:
        OBR DEFINEFUN OBR VAR CBR  CBR {;} |
        OBR DEFINEFUN OBR VAR VAR CBR CBR {;} |
        OBR DEFINEFUN OBR VAR VAR VAR CBR  CBR {;} |
        fun {printf("\n%d\n", $$); return 0;}                           
       ;
       
       
       
fun:	OBR EVAL expr CBR {$$=$3;}| 
	OBR EVAL term CBR {$$=$3;} |
	OBR PRINT expr CBR {;} |                              
        OBR PRINT term CBR {;}        
	;
term:   
	OBR ADD term term  CBR {$$=$3+$4;}|
	OBR SUB term term CBR {$$=$3-$4;}|
	OBR MUL term term CBR {$$=$3*$4;}|
	OBR DIV  term term CBR {$$=$3/$4;}|
	OBR MOD  term term CBR  {$$=$3%$4;}|
	OBR IF expr expr expr  CBR  {if ($3 == 1) $$ =$4; else $$=$5;} |
	VAR { yyerror("Error!");return 0;}  |
        CONST  {$$=$1;}   
	
	;
expr:	OBR TRUE CBR {$$=$2;} | OBR  FALSE CBR {$$=$2;}| 
	OBR EQ term term CBR   {$$=$3==$4;}|
	OBR LT  term term  CBR  {$$=$3<$4;}|
	OBR LTE  term term  CBR  {$$=$3<=$4;}|
	OBR GT  term term   CBR  {$$=$3>$4;}|
	OBR GTE  term term  CBR  {$$=$3>=$4;}|
	OBR NOT  expr       CBR  {$$= !$3;}|
	OBR AND  expr expr  CBR   {$$=($3 && $4);}|
	OBR OR  expr expr  CBR  {$$=$3 || $4;}
	;
		
%%

void  main(){ 
yyparse();
if(flag==0)printf("\n"); }
void yyerror(char *s){ printf("%s\n", s); flag=1;}
