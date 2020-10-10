%{
  void yyerror (char *s);
  int yylex();
  #include "containers.h"
%}


%union {int val; char* str;}
%start program
%token  PRINT EVAL
%token<val> BOOLVAR INTVAR BOOL INT  FUNID PLUS MINUS MUL DIV MOD  AND OR  EQ LT LTEQ GT GTEQ  NOT LPAR RPAR CALL GETINT IF  DEFFUN TRUE FALSE ERR
%token<str> ID CONST
%type<val> expr funid funrtype funbody funparam boolvar intvar
%%

program :
  LPAR PRINT expr RPAR {
    insert_child ($3);
    insert_node("PRINT", PRINT);}

  | LPAR EVAL expr RPAR {
    insert_child ($3);
    insert_node("EVAL", EVAL);}

  | LPAR DEFFUN LPAR funid funparam RPAR funrtype funbody RPAR  program {
    insert_children (2, $4, $5);
    insert_node("DEF-FUN", DEFFUN);
}

funid : 
  ID { $$ = insert_node($1, FUNID);}
  //| LPAR funid RPAR {
  //$$=insert_node($2, FUNID);};
  ;
funbody: expr;

funparam: 
  LPAR BOOL boolvar LPAR funparam {;}
  | LPAR INT intvar LPAR funparam {;}
  | {;}
boolvar:  ID {$$ = insert_node($1, BOOLVAR);};
intvar: ID {$$ = insert_node($1, INTVAR);};

funrtype: 
  INT {$$ =$1; }
  | BOOL {if($1==1) $$=1;  else $$= 0;}
  ;

expr :
  CONST {$$ = insert_node ($1, CONST);}
  | TRUE{ $$ = insert_node("TRUE", TRUE);}
  | FALSE { $$ = insert_node("FALSE", FALSE);}
  | LPAR PLUS expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("PLUS", PLUS);}
  | LPAR MINUS expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("MINUS", MINUS);}
  | LPAR MUL expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("MUL", MUL);}
  | LPAR DIV expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("DIV", DIV);}
  | LPAR MOD expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("MOD", MOD);}


  | LPAR EQ expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("EQ", EQ);}
  | LPAR LT  expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("LT", LT);}
  | LPAR LTEQ expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("LTEQ", LTEQ);}
  | LPAR GT expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("GT", GT);}
  | LPAR GTEQ expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("GTEQ", GTEQ);}
  | LPAR AND expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("AND", AND);}
  | LPAR OR  expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("OR", OR);}
  | LPAR NOT expr RPAR {
    insert_child ($3);
    $$ = insert_node("NOT", NOT);}
  | LPAR ID RPAR {
    $$ = insert_node($2, CALL);}

  | LPAR ID expr RPAR {
    insert_child($3);
    $$ = insert_node($2, CALL);}

  | LPAR ID expr expr  RPAR {
    insert_children(2, $3, $4);
    $$ = insert_node($2, CALL);}


  | LPAR GETINT RPAR {
    $$ = insert_node("GET-INT", CALL);}
  | LPAR IF expr expr expr RPAR{
    if($3==1) $$=$4; else $$=$5;}
;

%%


void yyerror (char *s) {printf ("%s\n", s);}

