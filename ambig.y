%{
void yyerror(char *s);
int yylex();
#include<stdio.h>
#include<string.h>
#include "containers.h"


%}

%union {int val; char* str;}
%start program

%token<val> PLUS MINUS EQ NOT LPAR RPAR  GETINT DEFFUN TRUE FALSE  ERR CALL
%token PRINT 
%token<str> ID CONST  
%type<val> expr id 


%%



program: 
LPAR PRINT expr RPAR { 
current_node_id ++;
insert_child ($3);
insert_node_tmp(current_node_id, "PRINT", false,PRINT); 
//$$=current_node_id;
printf("My expression\n");
} 


|LPAR DEFFUN id expr RPAR program { 

current_node_id ++;
insert_child ($3);
insert_child ($4);
insert_node_tmp (current_node_id, "DEFINE", false, DEFFUN);
//$$=current_node_id; 
}
;

id: ID{
current_node_id ++;
//insert_child($1);
insert_node_tmp (current_node_id,"ID", false, ID) ;
$$=current_node_id;
}
;

expr: CONST{
current_node_id ++;
//insert_child($1);
insert_node_tmp (current_node_id, $1, false, CONST);
$$=current_node_id;
}

|LPAR PLUS expr expr  RPAR {
current_node_id ++;
insert_child($3);
insert_child($4);
insert_node_tmp (current_node_id, "PLUS", false, PLUS);
$$=current_node_id;
}

|LPAR MINUS expr expr  RPAR{
current_node_id ++;
insert_child($3);
insert_child($4);
insert_node_tmp (current_node_id, "MINUS", false, MINUS);
$$=current_node_id;
}

|LPAR GETINT RPAR{
current_node_id ++;

//insert_child($3);
//insert_child($4);
insert_node_tmp (current_node_id, "GET_INT", true, GETINT);
$$=current_node_id;
}

|LPAR id RPAR{
current_node_id ++;
insert_child($2);
//insert_child($4);
insert_node_tmp (current_node_id, "CALL" , false, CALL);
$$=current_node_id;
}

|TRUE{
current_node_id ++;

//insert_child($3);
//insert_child($4);
insert_node_tmp (current_node_id, "true", true, TRUE);

$$=current_node_id;
}

|FALSE{
current_node_id ++;

//insert_child($3);
//insert_child($4);
insert_node_tmp (current_node_id, "false", true, FALSE);
$$=current_node_id;
}

|LPAR  EQ expr expr  RPAR{
current_node_id ++;
insert_child($3);
insert_child($4);
insert_node_tmp (current_node_id, "EQ", false, EQ);
$$=current_node_id;
}

|LPAR NOT expr  RPAR{
current_node_id ++;
insert_child($3);
//insert_child($4);
insert_node_tmp (current_node_id, "NOT", false, NOT);
$$=current_node_id;
}
;
%%

int main(void) {
int ret= yyparse();
if (ret == 0) print_ast();
free_ast();
return ret;
}

void yyerror (char *s) {printf("%s\n", s);}
