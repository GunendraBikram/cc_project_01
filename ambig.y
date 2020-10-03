%{
  void yyerror (char *s);
  int yylex();
  #include "containers.h"
  #include<string.h>
%}


%union {int val; char* str;}
%start program
%token PLUS MINUS EQ NOT AND LPAR RPAR CONST GETINT DEFFUN TRUE FALSE ID ERR PRINT CALL FUNID
%type<val> expr funid FUNID PLUS MINUS AND EQ NOT LPAR RPAR CALL GETINT DEFFUN TRUE FALSE ERR
%type<str> ID CONST

%%

program :
  LPAR PRINT expr RPAR {
    insert_child ($3);
    insert_node("PRINT", PRINT);}
  | LPAR DEFFUN funid expr RPAR program {
    insert_children (2, $3, $4);
    insert_node("DEF-FUN", DEFFUN);
}

funid : ID { $$ = insert_node($1, FUNID);};

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
  | LPAR EQ expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("EQ", EQ);}
  | LPAR AND expr expr RPAR {
    insert_children (2, $3, $4);
    $$ = insert_node("AND", AND);}
  | LPAR NOT expr RPAR {
    insert_child ($3);
    $$ = insert_node("NOT", NOT);}
  | LPAR ID RPAR {
    $$ = insert_node($2, CALL);}
  | LPAR GETINT RPAR {
    $$ = insert_node("GET-INT", CALL);}
;

%%

int main (void) {
  int retval = yyparse();
  if (retval == 0) print_ast();      // run "dot -Tpdf ast.dot -o ast.pdf" to create a PDF
  free_ast();
  return retval;
}

void yyerror (char *s) {printf ("%s\n", s);}

