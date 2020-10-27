#include"y.tab.h"
#include"containers.h"
int yyparse();


struct node_str *int_fun_r;  //creation of node for the implementaion of symbol table ,the head node  
struct node_str *int_fun_t;   //creation of the tail part of the node  
struct node_str *bool_fun_r;  //creation of node for the implementaion of symbol table ,the head node
struct node_str *bool_fun_t;   //creation of the tail part of the node  
                               /* The initializatio of the link list is done here for symbol table*/
                               //create more linked list because we more types 

int is_fla(int t, char* fname){
if(t==TRUE || t== FALSE || t==EQ || t==NOT || t==AND || t== OR || t== GT || t == LT || t== GTEQ || t== LTEQ) return true;
if(t==CALL || ID &&  0==find_str(fname, bool_fun_r)) return true;  //ID added
return false;
}


int is_expr(int t, char* fname)  //defining is_term() 
{                                                            //ID added
  if(t== CONST ||  t == ID || t == PLUS || t == MOD || t== MINUS || t== DIV || t == MUL || t == OR || t == IF) return true; // add other
  if(t== CALL || ID && 0== find_str(fname, int_fun_r)) return true;  //helper method used that use the root of the node
  //if(t== CALL && 0== find_str(fname, bool_fun_r)) return true;  //addition for boolean function
  return false;
}



int type_check(struct ast* tmp){
int cur_token=tmp->ntoken;                                                          //2nd argunemt of insert node in YACC file
int needs_expr =  cur_token == MOD ||cur_token ==PLUS || cur_token == MINUS || cur_token == DIV || cur_token == MUL  || cur_token == GT || cur_token == IF;             //needs_term hekper function used   expect all child nodes to be term
int needs_fla = cur_token == AND || cur_token == NOT || cur_token == EQ ||cur_token == GTEQ || cur_token == LTEQ || cur_token == LT || cur_token == OR;
struct ast_child* t = tmp->child ;         //visiting child to check the type

while(t!=NULL)
{
	struct ast* ch = t->id;
    if((needs_expr && is_expr(ch->ntoken, ch->token))  ||  (needs_fla && !is_fla (ch->ntoken, ch->token)))
    {
    	printf("Does not type check\n");
    	return 1;
    }  
                                                            //checking the type of ch
	t=t->next;
}

 return 0;
}










int get_fun(struct ast* tmp){                       //for functions  checking and types

 if(tmp->ntoken== FUNID)
 {
 	struct ast* body = get_child(tmp->parent,2) ;              //using 2 for the child             //using mixed traversal and first goes up and then down
    if(is_expr(body->ntoken,body-> token)) push_str(tmp->token,&int_fun_r,&int_fun_t) ;          //checking and pushing to the symbol table
    if (is_fla(body->ntoken, body->token)) push_str(tmp->token,&bool_fun_r,&bool_fun_t) ;    
    {

    }                      

 }

return 0;
}






int fun4(struct ast* tmp){
return 0;
}
int fun5(struct ast* tmp){
return 0;
}

int main(void){
int retval = yyparse();                                     //0 means eveything is good and working for return part
//if(retval == 0) visit_ast(get_fun);                         // if retval = 0 do some checking  visit_ast() method for traversal and can take the function
//push_str("GET-INT", &int_fun_r, &int_fun_t);  
if(retval == 0) visit_ast(get_fun);                             //function checking 
push_str("GET-INT", &int_fun_r, &int_fun_t);                  //pushing in the symbol table
if(retval == 0) visit_ast(type_check);                          //functions are the input to the visit_ast() method
if(retval == 0) visit_ast(fun4);                //checking for variables defining
if(retval == 0) visit_ast(fun5);               //checking for the varibale per DEFFUN
if (retval == 0) print_ast();                     //printing of the ast
free_ast();                                                                //free the memory
return retval;
}
