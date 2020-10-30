#include"y.tab.h"
#include"containers.h"
int yyparse();

struct node_str* int_funs_r;
struct node_str* int_funs_t;
struct node_str* bool_funs_r;
struct node_str* bool_funs_t;
//struct node_istr* funs_r;
//struct node_istr* funs_t;
struct node_str* arities_r;
struct node_str* arities_t;


struct node_str* int_var_r;
struct node_str* int_var_t;
struct node_str* bool_var_r;
struct node_str* bool_var_t;
//struct node_istr* var_r;
//struct node_istr* var_t;


bool is_term(int t, char *str)
     {
      if (t==CONST || t == PLUS || t==MINUS || t== IF || t== MUL || t==MOD || t==DIV|| t==GETINT) return true;
      if (t== CALL && 0 == find_str(str, int_funs_r)) return true;
	//if (t== CALL && 0 == find_str(str, int_var_r)) return true;
        return false;
     }	 


bool is_expr(int t, char *str)
    {
     if (t==TRUE || t== FALSE || t==EQ || t==NOT || t==AND || t == LT || t==GT || t== LTEQ || t==GTEQ || t == OR) return true;
     if(t == CALL && 0 == find_str(str, bool_funs_r)) return true;
     //if(t == CALL && 0 == find_str(str, bool_var_r)) return true;
     return false;
    }

bool is_fun(int t, char *str)
{ 
  if(t== FUNID || t == ID) return true;
  return false;

}


int type_check(struct ast* ast_node)
{
	//int ntoken = ast_node->ntoken;    //added IF in token
	char* token = ast_node->token;   //added the token part and ntoken removed all from this  getting the warnings
	int needs_term = (token == "PLUS" || token == "IF" || token == "MINUS" || token == "MUL"  || token == "DIV" || token == "MOD"  || token == "LT" || token == "GT"  || token == "LTEQ" || token == "GTEQ");
	int needs_expr  = (token == "NOT" || token == "AND" || token == "OR");                      //problem added "" here
	//  || ntoken == LT || ntoken == GT  || ntoken == LTEQ || ntoken == GTEQ);
	struct ast_child* temp_child_root = ast_node-> child;
	while(temp_child_root!= NULL)
	{
		struct ast* child_node = temp_child_root->id;    

		if((needs_term && !is_expr(child_node->ntoken,child_node->token)) ||
		 (needs_expr && !is_expr(child_node->ntoken, child_node->token))) {
		printf("Does not type check\n");

		return 1;
	}
   temp_child_root = temp_child_root->next;
  }

 return 0;  

}

int get_var_types(struct ast* ast_node) {
if (ast_node->ntoken == CALL) {
  char* call_id = ast_node->token;
  if(0 == find_str(call_id, int_var_r) && 0== find_str(call_id,bool_var_r))
  {
  	printf("variable  %s has not been defined\n", call_id);
  	return 1;
  }
 }

if(ast_node->ntoken == ID)        //FUNID shoube be ID
 {
 	if(0 == find_str(ast_node->token, int_var_r)  ||
 	  (0 == find_str(ast_node->token, bool_var_r)))
 	{   
 		printf("variable %s has been defined twice\n", ast_node);
 		return 1;
 	}

 	struct ast* body = get_child(ast_node->parent, 2);


 	if(is_term(body->ntoken, ast_node->token))          //
 	{
 		push_str(ast_node->token, &int_var_r, &int_var_t);
 	}

 	else if (is_expr(body->ntoken, ast_node->token))
 	{
 		push_str(ast_node->token, &bool_var_r, &bool_var_t);
 	}
   }
   
   return 0;
  
}  

int get_fun_types(struct ast* ast_node) {
if (ast_node->ntoken == CALL) {
  char* call_id = ast_node->token;
  if(0 == find_str(call_id, int_funs_r) && 0== find_str(call_id,bool_funs_r))
  {
  	printf("function %s has not been defined\n", call_id);
  	return 1;
  }
 }

if(ast_node->ntoken == FUNID)                                                  //implememt the logic of arities here
 {
 	if(0 == find_str(ast_node->token, int_funs_r)  ||
 	  (0 == find_str(ast_node->token, bool_funs_r)))
 	{
 		printf("function %s has been defined twice\n", ast_node);
 		return 1;
 	}

 	struct ast* body = get_child(ast_node->parent, 2);


 	if(is_term(body->ntoken, ast_node->token))
 	{
 		push_str(ast_node->token, &int_funs_r, &int_funs_t);
 	}

 	else if (is_expr(body->ntoken, ast_node->token))
 	{
 		push_str(ast_node->token, &bool_funs_r, &bool_funs_t);
 	}
   }
   
   return 0;
  
} 

/*-----------------For checking the arities-------------------------------------*/

int get_arities_type(struct ast* ast_node)                             //checking for arities
{                                                    //check the type of variable and then store it in symbol tabel
  int ntoken = ast_node->ntoken;
  if(ntoken == FUNID)
    //ntoken->next;
   //int ntoken = ast_node->ntoken;
   //struct ast_child* temp_child_root = ast_node-> child;              //
   while(ntoken!=RPAR)                                   //while with ntoken!=NULL
   { 

    printf("Check_1\n");
    if(ntoken == RPAR);      //push arities in symbol tabel
    break;                   //v is CHAR  or 0 is CONST 
                             //check the type of variable and also where it's is occuring   
    
   }
   
  //printf("%c", ntoken);
  //printf("check_2\n");
   
  
  return 0;
  
  
  
  //return 1;  





}

int translate(struct ast *node)
{ //mytranslator from ast to cfg
//	printf("visited: %s\n", 	node->token);
	if(node->ntoken == FUNID) 
		{

	      printf("= = function %s\n",node->token );
	      printf("entry:\n");
       
        }
	if(node->ntoken ==LT || node->ntoken ==EQ || node->ntoken == PLUS  || node->ntoken == MINUS || node->ntoken ==AND || node->ntoken ==GT || node->ntoken ==LTEQ || node->ntoken == GTEQ  || node->ntoken == OR || node->ntoken ==MUL || node->ntoken ==DIV || node->ntoken ==MOD )
	{
		printf(" v%d := v%d %s v%d\n",node->id, get_child(node,1)-> id, node->token, get_child(node,2)->id );
	}

	if(node->ntoken ==NOT)//|| node->ntoken ==EQ || node->ntoken == PLUS  || node->ntoken == MINUS || node->ntoken ==AND )
	
		printf(" v%d := not  v%d\n",node->id,  get_child(node,1)->id );
	  
	if (node->ntoken == CONST)
	  	printf(" v%d := %s \n",node->id, node->token);   //%s to %d
	

	//need to support function call
	if(node->ntoken ==CALL){
	// for supporting the function call with arguments
	//load to input register
	printf(" call %s\n", node->token);
	printf(" v%d:= rv\n", node->id); //load from return register
	}

	if(node->ntoken ==IF){
	printf(" br v%d bb%d bb%d\n",get_child(node, 1)->id, get_child(node, 2)->id, get_child(node, 3)->id);
	
	printf("bb%d:\n", get_child(node, 2)->id);
	
	printf(" v%d := v%d\n", node->id, get_child(node,2)->id);	
	printf(" br bb%d\n",node->id);
		
	printf("bb%d\n", get_child(node, 3)->id);
	printf(" v%d := v%d\n", node->id, get_child(node,3)->id);
	printf(" br bb%d\n",node->id);
	printf("bb%d\n",node->id);	//translator for the join merge
	//printf(" v%d := if v%d then v%d else v%d\n", node->id, get_child(node, 1)->id, get_child(node, 2)->id, get_child(node, 3)->id);
	}

	//19.10 indicating the termination of computing the body of the function
        if((is_term(node->ntoken, node->token) || is_expr(node->ntoken, node->token))  && (node->parent->ntoken ==DEFFUN || node->parent->ntoken ==PRINT))
	{
	 if(node->parent->ntoken == PRINT){
	 printf(" a1 := v%d\n", node->id);
	 printf(" call := print\n");
	 }

	else {
	 printf(" rv := v%d\n", node->id);
	 }
	printf(" br exit\n");
 
	}

	return 0;



/*      if(node->ntoken == CALL)
      {
      	//load to input register
      	printf("call %s\n", node-> token);
      	printf(" v%d := rv\n", node->id);
      }
      if(node->ntoken == IF	)
      {
      	printf("br v%d  bb%d  bb%d\n", get_child(node,1)->id, get_child(node,2)->id,get_child(node,3)->id);
      	printf("bb%d\n",get_child(node,2)->id);         //changed %s to %d
        printf(" v%d : = v%d\n", node->id,get_child(node,2)->id); 
          
       printf("br bb%d", node->id);   //to 	the join changed %s to %d      
        printf("bb%d\n",get_child(node,3)->id);  //changed %s to %d
      	printf(" v%d : = v%d\n", node->id,get_child(node,3)->id);
      	printf("br bb%d\n", node->id);   //to 	the join
        printf("bb%d\n",node->id);
      	//translator for join(merge)
      	//printf(" v%d := if v%d then v%d else %d\n", node->id,get_child(node,1)->id, get_child(node,2)->id, get_child(node,3)->id);
      } 
	  if((is_term(node->ntoken,node->token) || is_expr(node->ntoken, node->token))  &&
	  	(node->parent->ntoken == DEFFUN || node-> parent->ntoken== PRINT))
	  {
	  	if(node-> parent->ntoken== PRINT)
         { 
         	printf(" a1 := v%d\n", node->id);
         	printf(" call := print\n");
            
        }
        else {
 	   	     printf(" rv :=v%d\n", node->id);
 	   	 }
	         printf("br exit\n");
       
       }
    //if(node->ntoken == VARID)
	 //printf(" vi%d := %s\n", node->id, get_register_from_symbol_table(node->token));
  */ 
  return 0;
}



int main(void)
  {
  	int retval = yyparse();
  	push_str("GET-INT", &int_funs_r, &int_funs_t);
  	if(retval == 0) retval = visit_ast(get_fun_types);              //not harming the output till now
	if(retval == 0) retval =visit_ast(get_var_types);               //passing now
  	if(retval== 0) retval = visit_ast(type_check);
	// if(retval== 0) retval = visit_ast(get_arities_type);
  	if(retval == 0)  print_ast();

    else return 1;

    visit_ast(translate);

  }

