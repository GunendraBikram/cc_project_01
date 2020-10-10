%{
  void yyerror (char *s);
  int yylex();
  #include "containers.h"
  #include<string.h>
%}


%union {int val; char* str;}
%start program

%token  PRINT EVAL 
%token<val> PLUS MINUS MUL DIV MOD  AND EQ LT GT LTEQ GTEQ NOT LPAR RPAR CALL GETINT DEFFUN  TRUE FALSE ERR OR IF 
%token<str> ID CONST                                    //ID instead of id
%type<val> expr id  funid1 funid2 funid3  expr2 expr3            //comeents added


%%
program :
     LPAR PRINT expr RPAR {
  
    insert_child ($3);
    insert_node("PRINT", PRINT);
    }

  | LPAR EVAL expr RPAR{
    insert_child ($3);
    insert_node("EVAL", EVAL);
    }

  | LPAR DEFFUN  funid1 expr RPAR program {
 
    insert_children (2, $2, $3);
    insert_node("DEF-FUN" ,DEFFUN );
  
     }

 ;

funid1    : LPAR funid2 RPAR 
           | LPAR funid2 funid3 RPAR;

funid2    : id ;      
             
funid3    : id funid3 |
            id;
             




//funid1 : ID { $$ = insert_node($1, FUNID1);};         //comments added
//funid2 : ID { $$ = insert_node($1, FUNID2);};
//funid3 : ID { $$ = insert_node($1, FUNID3);}; 




expr :
  CONST {
  $$ =insert_node ($1 ,CONST);
  
  }
  | TRUE{
    
    $$ =insert_node("TRUE", TRUE);
    }
  | FALSE { 

   $$=insert_node("FALSE", FALSE);
   }

  | LPAR PLUS expr expr RPAR {
  
    insert_children (2, $3, $4);
     $$ = insert_node("PLUS", PLUS);
    }
  | LPAR MINUS expr expr RPAR {
 
    insert_children (2, $3, $4);
    $$=("MINUS", MINUS);
    }
  | LPAR DIV expr expr RPAR {

    insert_children (2, $3, $4);
    $$ =insert_node("DIV", DIV);
    }
  | LPAR MUL expr expr RPAR {

    insert_children (2, $3, $4);
    $$ =insert_node("MUL", MUL);
   }
  | LPAR MOD expr expr RPAR {
   
    insert_children (2, $3, $4);
    $$=insert_node("MOD", MOD);
    }


  | LPAR EQ expr expr RPAR {
    insert_children (2, $3, $4);
    $$=insert_node("EQ", EQ);
    }

   | LPAR LT expr expr RPAR {
    insert_children (2, $3, $4);
     $$ = insert_node("LT", LT);
      
    }
   | LPAR GT expr expr RPAR {
   
    insert_children (2, $3, $4);
      $$ =insert_node("GT", GT);
    
    }
   | LPAR LTEQ expr expr RPAR {
   
    insert_children (2, $3, $4);
    $$ = insert_node("LTEQ", LTEQ);
      
    }
  | LPAR GTEQ expr expr RPAR {
 
    insert_children (2, $3, $4);
    $$ =insert_node("GTEQ", GTEQ);
      }
  | LPAR AND expr expr RPAR {
    
    insert_children (2, $3, $4);
    $$ =insert_node("AND", AND);
       
    }
  | LPAR NOT expr RPAR {

    insert_child ($3); 
    $$ = insert_node("NOT", NOT);
      }
  
  | LPAR IF expr expr expr RPAR{           //check
    insert_children(4,$2,$3,$4,$5);
    $$ =insert_node("IF", IF);
  
  
  }   
  | LPAR GETINT RPAR {
   
    $$ = insert_node("GET-INT", CALL);
      }
   | LPAR expr2 RPAR 
   {
        insert_child ($2);
        $$ =insert_node("AND", AND);         //need to add
   
   }  |  LPAR expr3 RPAR 
      {
      insert_child ($2);
        $$ =insert_node("AND", AND);       //need to add
      }
      | LPAR ID RPAR {
    
    $$ = insert_node($2, CALL);
      }
      
;      
      
expr2 : expr ID 
       {insert_children (2, $1,$2);
        $$ =insert_node("AND", AND);  
       }
;

expr3 : expr2 ID   
        {insert_children (2, $1,$2);
        $$ =insert_node("AND", AND);  
       } 
      
; 

id: ID { 
     current_node_id++;
     $$ = current_node_id;}

%%

int main (void) {
  int retval = yyparse();
  if (retval == 0) print_ast();      // run "dot -Tpdf ast.dot -oast.pdf" to create a PDF
  free_ast();
  return retval;
}

void yyerror (char *s) {printf ("%s\n", s);}
