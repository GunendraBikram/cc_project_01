%{
  void yyerror (char *s);
  int yylex();
  #include "containers.h"
  #include<string.h>
%}


%union {int val; char* str;}
%start program

%token  PRINT EVAL 
%token<val> PLUS MINUS MUL DIV MOD  AND EQ LT GT LTEQ GTEQ NOT LPAR RPAR CALL GETINT DEFFUN  TRUE FALSE ERR OR IF FUNID
%token<str> ID CONST                                     
%type<val> expr id  expr2 expr3 fun1  fun2  fun3          


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

  
    | LPAR DEFFUN fun1 expr RPAR                
                                   
                                               
 ;


 
fun1          :  LPAR id RPAR 
                  
               
                                                        
              | fun2  
               | fun3          
               ;


fun2          :  LPAR id id RPAR  
                
               ;


fun3          : LPAR id id id RPAR 
               

;     


expr :
  CONST {
  $$ =insert_node ($1 ,CONST);
  
  }
  | ID {
   $$ = insert_node($1,ID);
  
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
  
  | LPAR IF expr expr expr RPAR{         
    insert_children(3,$3,$4,$5);
    $$ =insert_node("IF", IF);
  
  
  }   
  | LPAR GETINT RPAR {
   
    $$ = insert_node("GET-INT", CALL);
      }
   | LPAR expr2 RPAR 
   {
        insert_child ($2);
        $$ =insert_node("AND", AND);        
   
   }  |  LPAR expr3 RPAR 
      {
      insert_child ($2);
        $$ =insert_node("AND", AND);       
      }
      | LPAR ID RPAR  {                             
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
