%{
void yyerror(char *s);
int yylex();
#include<stdio.h>
#include<string.h>

int flag=0;
struct ret{int t1; char *t2;}

%}



%union { int val; char *str; struct ret *rec;}
%start program

%token<rec> CONST TRUE FALSE 
%token<rec> VAR
%token ADD SUB MUL DIV 
%token EQ LT LTE GT GTE
%token NOT AND OR
%token<rec>DEFINEFUN  OBR CBR
%token EVAL IF
%token UMINUS
%token<rec>  GETINT
%token<rec>PRINT

%type<rec>program   
%type<rec>fun  
%type<rec>expr 
%type<rec>term

%left IF
%left NOT AND OR
%left EQ LT LTE GT GTE
%left ADD  SUB
%left MUL  DIV MOD
%left UMINUS
%left OBR CBR 

%%

program:OBR DEFINEFUN OBR fun CBR term  CBR program |
	OBR DEFINEFUN OBR fun VAR  CBR term  CBR program |
	OBR DEFINEFUN OBR fun VAR VAR CBR term  CBR program| 
	fun {printf("\nhello\n" ); return 0;}
	;

fun:	OBR EVAL expr CBR {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$3->t1;
	}

	|OBR EVAL term CBR {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$3->t1;
	}

	|OBR PRINT expr CBR {printf("Error\n");}	|
	OBR PRINT term CBR {printf("Error\n");}
	;
term:   VAR {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t2= strdup($1->t2);
	}
	
	| CONST {
	$$=(struct ret*) malloc (sizeof(struct ret));	
	$$->t1=$1->t1;
	}

	| ADD term term  {
	$$=(struct ret*) malloc (sizeof(struct ret));	
	$$->t1=$2->t1+$3->t1;
	}

	|SUB term term  {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1-$3->t1;
	}

	|MUL term term  {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1*$3->t1;
	}
	
	|DIV  term term  {
	$$=(struct ret*) malloc (sizeof(struct ret));	
	$$->t1=$2->t1/$3->t1;
	}

	|MOD  term term  {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1%$3->t1;
	}

	|IF expr expr expr  {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1;
	}

	//|GETINT| fun | fun term| fun term term
	
	|OBR term CBR {
	$$=(struct ret*) malloc (sizeof(struct ret));	
	$$->t1=$2->t1;
	}
	;

expr:	TRUE {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$1->t1;
	}

	| FALSE {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$1->t1;
	}
 
	|EQ term term   {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1==$3->t1;
	}

	|LT  term term   {
	$$=(struct ret*) malloc (sizeof(struct ret));	
	$$->t1=$2->t1<$3->t1;}

	|LTE  term term   {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1<=$3->t1;
	}
	
	|GT  term term    {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1>$3->t1;
	}
	
	|GTE  term term   {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1>=$3->t1;
	}
	
	|NOT  expr   {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1= !$2->t1;
	}
	
	|AND  expr expr     {
	$$=(struct ret*) malloc (sizeof(struct ret));	
	$$->t1=($2->t1 && $3->t1);
	}
	
	|OR  expr expr {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1 || $3->t1;
	}
	
	|UMINUS expr {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=-$2->t1;
	}
	
	|OBR expr CBR {
	$$=(struct ret*) malloc (sizeof(struct ret));
	$$->t1=$2->t1;
	};

		
%%

void  main(){ 
yyparse();
if(flag==0)printf("\nvalid expression\n"); }
void yyerror(char *s){ printf("%s\n", s); flag=1;}

