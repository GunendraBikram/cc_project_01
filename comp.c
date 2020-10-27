#include"y.tab.h"
#include"containers.h"
int yyparse();

struct node_str* int_funs_r;
struct node_str* int_funs_t;
struct node_str* bool_funs_r;
struct node_str* bool_funs_t;
struct node_istr* funs_r;
struct node_istr* funs_t;
struct node_str* int_var_r;
struct node_str* int_var_t;
struct node_str* bool_var_r;
struct node_str* bool_var_t;
struct node_isstr* var_r;
struct node_isstr* var_t;

bool is_term(int t, char *str)
     {
     	if (t==CONST || t == PLUS || t==MINUS || t== IF) return true;
        if (t== CALL && 0 == find_str(str, int_funs_r)) return true;

        return false;
     }	 


bool is_fla(int t, char *str)
    {
     if (t==TRUE || t== FALSE || t==EQ || t==NOT || t==AND || t == LT ) return true;
     if(t == CALL && 0 == find_str(str, bool_funs_r)) return true;
     return false;
    }

int type_check(struct ast* ast_node)
{
	int ntoken = ast_node->ntoken;
	int needs_term = (ntoken == EQ || ntoken == PLUS || ntoken == MINUS );
	int needs_fla  = (ntoken == NOT || ntoken == AND);
	struct ast_child* temp_child_root = ast_node-> child;
	while(temp_child_root!= NULL)
	{
		struct ast* child_node = temp_child_root->id;

		if((needs_term && !is_fla(child_node->ntoken,child_node->token)) ||
		 (needs_fla && !is_fla(child_node->ntoken, child_node->token))) {
		printf("Does not type check");

		return 1;
	}
   temp_child_root = temp_child_root->next;
  }

 return 0;  

}

int get_fun_types(struct ast* ast_node) {
if (ast_node->ntoken == CALL) {
  char* call_id = ast_node->token;
  if(0 == find_str(call_id, int_funs_r) && 0 == find_str(call_id,bool_funs_r))
  {
  	printf("function %s has not been defined\n", call_id);
  	return 1;
  }
 }

if(ast_node->ntoken == FUNID)
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

 	else if (is_fla(body->ntoken, ast_node->token))
 	{
 		push_str(ast_node->token, &bool_funs_r, &bool_funs_t);
 	}
   }
   
   return 0;
  
} 


int get_var_types(struct ast* ast_node) {
if (ast_node->ntoken == CALL) {
  char* call_id = ast_node->token;
  if(0 == find_str(call_id, int_var_r) && 0 == find_str(call_id, bool_var_r))
  {
  	printf("variable  %s has not been defined\n", call_id);
  	return 1;
  }
 }

if(ast_node->ntoken == FUNID)
 {
 	if(0 == find_str(ast_node->token, int_var_r)  ||
 	  (0 == find_str(ast_node->token, bool_var_r)))
 	{
 		printf("varible  %s has been defined twice\n", ast_node);
 		return 1;
 	}

 	struct ast* body = get_child(ast_node->parent, 2);


 	if(is_term(body->ntoken, ast_node->token))
 	{
 		push_str(ast_node->token, &int_var_r, &int_var_t);
 	}

 	else if (is_fla(body->ntoken, ast_node->token))
 	{
 		push_str(ast_node->token, &bool_var_r, &bool_var_t);
 	}
   }
   
   return 0;
  
} 



int translate(struct ast *node)
{ //mytranslator from ast to cfg
	printf("visited:%s\n", 	node->token);
	if(node->ntoken == FUNID) 
		{

	      printf("= = function %s\n",node->token );
	      printf("entry:\n");
       
        }
	if(node->ntoken ==LT || node->ntoken ==EQ || node->ntoken == PLUS  || node->ntoken == MINUS || node->ntoken ==AND )
	{
		printf(" v%d := v%d %s v%d\n",node->id, get_child(node,1)-> id, node->token, get_child(node,2)->id );
	}

	if(node->ntoken ==NOT)//|| node->ntoken ==EQ || node->ntoken == PLUS  || node->ntoken == MINUS || node->ntoken ==AND )
	
		printf("v%d := not v%d\n",node->id, get_child(node,1)->id );
	  
	  if (node->ntoken == CONST)
	  	printf("v%d := %s v%d\n",node->id,node->id );
      

      if(node->ntoken == CALL)
      {
      	//load to input register
      	printf("call %s\n", node-> token);
      	printf(" v%d := rv\n", node->id);


      }

      if(node->ntoken == IF	)

      {

      	printf("br v%d  bb%d  bb%d\n", get_child(node,1)->id, get_child(node,2)->id,get_child(node,3)->id);

      	printf("bb%s\n",get_child(node,2)->id);


        printf(" v%d : = v%d\n", node->id,get_child(node,2)->id);
          
       printf("br bb%s", node->id);   //to 	the join

        printf("bb%s\n",get_child(node,3)->id);
      	printf(" v%d : = v%d\n", node->id,get_child(node,3)->id);


      	printf("br bb%d\n", node->id);   //to 	the join

        printf("bb%d\n",node->id);

      	//translator for join(merge)

      	//printf(" v%d := if v%d then v%d else %d\n", node->id,get_child(node,1)->id, get_child(node,2)->id, get_child(node,3)->id);
      } 

	  if((is_term(node->ntoken,node->token) || is_fla(node->ntoken, node->token))  &&
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


   
  return 0;
}



int main(void)
  {
  	int retval = yyparse();
  	push_str("GET-INT", &int_funs_r, &int_funs_t);
  	if(retval == 0) retval = visit_ast(get_fun_types);
  	if(retval== 0) retval = visit_ast(type_check);
	if(retval== 0) retval = visit_ast(get_var_types);
	//if(retval== 0) retval = visit_ast(arity_check);
  	if(retval == 0)  print_ast();

    else return 1;

   visit_ast(translate);

  }





