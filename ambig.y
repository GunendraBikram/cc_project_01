%{
  void yyerror (char *s);
  int yylex();
  #include "containers.h"
%}


%union {int val; char* str;}
%start program

%token  PRINT EVAL 
%token<val> FUNID1 FUNID2 FUNID3  PLUS MINUS AND EQ NOT LPAR RPAR CALL GETINT DEFFUN TRUE FALSE ERR
%token<str> ID CONST
%type<val> expr id funid1 funid2 //funid3 


%%
program :
  LPAR PRINT expr RPAR {
    insert_child ($3);
    insert_node("PRINT", PRINT);}

  | LPAR EVAL expr RPAR{
    insert_child ($3);
    insert_node("EVAL", EVAL);}

  | LPAR DEFFUN  funid1  expr RPAR program {
    insert_children (2, $3, $4);
    insert_node("DEF-FUN", DEFFUN);}

 | LPAR DEFFUN funid2 id expr RPAR program {
    insert_children (3, $3, $4, $5);
    insert_node("DEF-FUN", DEFFUN);}

// | LPAR DEFFUN funid3 id id expr RPAR program {
//    insert_children (4, $4, $5, $6, $8);
//    insert_node("DEF-FUN", DEFFUN);}
;

funid1 : ID { $$ = insert_node($1, FUNID1);};
funid2 : ID { $$ = insert_node($1, FUNID2);};
//funid3 : ID { $$ = insert_node($1, FUNID3);};


id: ID { $$ = insert_node($1, ID);}

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

void yyerror (char *s) {printf ("%s\n", s
