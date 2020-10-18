%{
  void yyerror (char *s);
  int yylex();
  #include "containers.h"
%}


%union {int val; char* str;}
%start program
%token  PRINT 
%token<val> IF  FUNID OR  EVAL LT GT LTEQ GTEQ  MUL DIV MOD  PLUS MINUS AND EQ NOT LPAR RPAR CALL GETINT DEFFUN TRUE FALSE ERR
%token<str> ID CONST
%type<val> expr id   funid funbody 
%%

program :
  LPAR PRINT expr RPAR {
    insert_child ($3);
    insert_node("PRINT", PRINT);}
  
  |LPAR EVAL expr RPAR {
    insert_child ($3);
    insert_node("EVAL", EVAL);}



  | LPAR DEFFUN LPAR  funid RPAR   funbody RPAR program {
    insert_children (2, $4, $6);
    insert_node("DEF-FUN", DEFFUN);}


  | LPAR DEFFUN LPAR  funid id RPAR   funbody RPAR program {
    insert_children (3, $4, $5, $7);
    insert_node("DEF-FUN", DEFFUN);}
    
  | LPAR DEFFUN LPAR  funid  id id RPAR   funbody RPAR program  {
    insert_children(4,$4,$5,$6,$8);
    insert_node("DEF-FUN",DEFFUN);
  
  }
;
funid : ID { $$ = insert_node($1, FUNID);}

//id : ID {$$ = insert_node($1, FUNID);};

;

funbody: expr; 

expr :
    ID {$$=insert_node ($1, CALL);}
  | CONST {$$ = insert_node ($1, CONST);}
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

  | LPAR MOD  expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("MOD", MOD);}
  | LPAR EQ expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("EQ", EQ);}
  
  | LPAR LT  expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("LT", LT);}
  | LPAR GT  expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("GT", GT);}
  | LPAR LTEQ expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("LTEQ", LTEQ);}
  | LPAR GTEQ expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("GTEQ", GTEQ);}



| LPAR AND expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("AND", AND);}
  | LPAR NOT expr RPAR {
    insert_child ($3);
    $$ = insert_node("NOT", NOT);}

  | LPAR OR  expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("OR", OR);}
  | LPAR ID RPAR {
    $$ = insert_node($2, CALL);}
  | LPAR GETINT RPAR {
    $$ = insert_node("GET-INT", CALL);}
  | LPAR IF  expr expr expr  RPAR {
  insert_children (3, $3, $4, $5);
  $$ = insert_node("IF", IF);
	}
   //| LPAR expr RPAR {;}
   //| LPAR expr expr RPAR {;}
   	
;
id : ID {$$ = insert_node($1, FUNID);};


;

%%


void yyerror (char *s) {printf ("%s\n", s);}

