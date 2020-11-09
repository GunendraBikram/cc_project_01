#include"y.tab.h"
#include"containers.h"
#include<string.h>
int yyparse();

struct node_str* int_funs_r;
struct node_str* int_funs_t;
struct node_str* bool_funs_r;
struct node_str* bool_funs_t;
//struct node_str* arities_r;
//struct node_str* arities_t;


struct node_str* int_var_r;
struct node_str* int_var_t;
struct node_str* bool_var_r;
struct node_str* bool_var_t;
//struct node_istr* var_r;
//struct node_istr* var_t;

struct sequence{
   
  char lhs[10];          //for LHS value

  char rhs[10];            //for RHS value, can be const, register, and operation
  

  struct sequence* next; 
} ;

                                            //initiliazation of head
 //head= (struct sequence*)malloc(sizeof(struct sequence));           //memory allocation


void traverse_CGF(struct sequence* ptr)
{
  
while(ptr!=NULL)

  {
  printf("the value is %s\n" ,ptr->lhs);
  printf("the value is %s\n", ptr->rhs );
  ptr = ptr->next;
  }
}      

void insert_seq(struct sequence *head, char x[10], char y[10])
{
  
  //printf("Heloo 1\n");

  struct sequence *ptr = (struct sequence*)malloc(sizeof(struct sequence));
  struct sequence  *p= head;
  //ptr-> lhs = *x;
  //printf("Heloo 2\n");
  strncpy(ptr->lhs,x,10);
  //ptr-> rhs= *y;
  strncpy(ptr->rhs,y,10);
 
  //printf("Heloo 3\n");
  while(p->next!= NULL)           
  {
    p = p->next;       
     //printf("check\n");
   }

  //printf("Heloo 4\n");
  //p=p->next;               //main problem for segmentation fault
  p->next = ptr;
  ptr->next = NULL;
  //return head;
}



   void push_new(struct sequence* head, char x[10], char y[10]) {
    struct sequence * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (struct sequence *) malloc(sizeof(struct sequence));
    //current->next->val = val;
     strncpy(current->lhs,x,10);


     strncpy(current->rhs,y,10);
   
    current->next = NULL;
      //current->next = NULL;
   }






 void insert_new(struct sequence *head, char x[10], char y[10])
    {
            /* Iterate through the list till we encounter the last node.*/
    	    struct sequence *ptr = (struct sequence*)malloc(sizeof(struct sequence));
            ptr->next = (struct sequence *)malloc(sizeof(struct sequence));
            while(ptr->next!=NULL)
            {
                    ptr = ptr -> next;
            }
     
            /* Allocate memory for the new node and put data in it.*/
     
            //ptr->next = (struct sequence *)malloc(sizeof(struct sequence));
            ptr = ptr->next;
            

            strncpy(ptr->lhs,x,10);


            strncpy(ptr->rhs,y,10);

            //ptr->data = data;
            

            ptr->next = NULL;
    }

 

struct sequence *head; 
//struct sequence *second;



//head= (struct sequence*)malloc(sizeof(struct sequence));   //memory alloctaed



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

int type_check(struct ast* ast_node)
{
	//int ntoken = ast_node->ntoken;    //added IF in token
	//int needs_term = (ntoken == PLUS || ntoken == MINUS || ntoken == MUL  || ntoken == DIV || ntoken == MOD  || ntoken == LT || ntoken == GT  || ntoken == LTEQ || ntoken == GTEQ || ntoken == OR);
	//int needs_expr  = (ntoken == NOT || ntoken == AND);                      //problem
	//  || ntoken == LT || ntoken == GT  || ntoken == LTEQ || ntoken == GTEQ);
    char* token = ast_node->token; 

	int needs_term = (token == "PLUS" || token == "IF" || token == "MINUS" || token == "MUL"  || token == "DIV" || token == "MOD"  || token == "LT" || token == "GT"  || token == "LTEQ" || token == "GTEQ");
	int needs_expr  = (token == "NOT" || token == "AND" || token == "OR");                      //problem
	//  || ntoken == LT || ntoken == GT  || ntoken == LTEQ || ntoken == GTEQ);
    

	struct ast_child* temp_child_root = ast_node-> child;
	while(temp_child_root!= NULL)
	{
		struct ast* child_node = temp_child_root->id;    

		if((needs_term && !is_term(child_node->ntoken,child_node->token)) ||
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
 		//printf("variable %s has been defined twice\n", ast_node);
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
 		//printf("function %c has been defined twice\n", ast_node);
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



int bb_num =0;
void rec_descend(struct ast* node){
	if(node->ntoken ==IF) {
	 int bb_then_num = bb_num +1;
	 int bb_else_num = bb_num +2;
	 int bb_join_num = bb_num +3;
	 bb_num +=3;
 	 printf("    <<<< NODE ID %d >>>> \n", get_child(node, 1)->id);
 	 printf(" br v<cond> bb%d, bb%d\n", bb_then_num, bb_else_num);
	 printf("bb:%d\n", bb_then_num);
	 rec_descend(get_child(node,2));	
	 printf("    <<<< NODE ID %d >>>>   \n", get_child(node, 2)->id);
	 printf(" br bb%d\n", bb_join_num);
	 printf("bb:%d\n", bb_else_num);
	 rec_descend(get_child(node,3));
	 printf("    <<<< NODE ID %d >>>>  \n", get_child(node, 3)->id);
	 printf(" br bb%d\n", bb_join_num);
	 printf("bb%d\n", bb_join_num);
	}
	else {
		struct ast_child* tmp = node->child;
		while(tmp!=NULL){
		rec_descend(tmp->id);
		tmp = tmp->next;
		}
	}
}


int br_struct(struct ast *node){
 if(node->ntoken ==FUNID){
 printf("= = function %s\n", node->token);
 rec_descend(node->parent);
 }  
 return 0;
}


//insert_seq(head, "data", "make");  
//struct sequence *head;                                        //head node initialized
//head= (struct sequence*)malloc(sizeof(struct sequence));

struct sequence *second;
int translate(struct ast *node)
{ //mytranslator from ast to cfg
//	printf("visited: %s\n", 	node->token);
	if(node->ntoken == FUNID ) 
		{
          
          //struct sequence *head;                                            //initiliazation of head
	      head= (struct sequence*)malloc(sizeof(struct sequence));           //memory allocation
          
          //second = (struct sequence*)malloc(sizeof(struct sequence)); 
	      
	     
	      printf("\n= = function %s\n",node->token );

          //push_new(head, "first", "first");
          
	      //insert_seq(head,"new", "new_node");
	      //insert_seq(head, node->token, "NULL");     //insertion in the sequnece
          //insert_new(head, "first", "first");
          //insert_seq(head, "kon", "mak"); 
	      
	      //traverse_CGF(head);                      //segmentaion core fault dumped error

	      printf("entry:\n");

        }
	if(node->ntoken ==LT || node->ntoken ==EQ || node->ntoken == PLUS  || node->ntoken == MINUS || node->ntoken ==AND || node->ntoken ==GT || node->ntoken ==LTEQ || node->ntoken == GTEQ  || node->ntoken == OR || node->ntoken ==MUL || node->ntoken ==DIV || node->ntoken ==MOD )
	{ 
	     if (node->parent->ntoken == IF &&
 		 (get_child(node->parent,2) ==node ||
		 get_child(node->parent,3) ==node))
		 printf(" v%d := v%d %s v%d\n",node->parent->id, get_child(node,1)-> id, node->token, get_child(node,2)->id );
		else
		 printf(" v%d := v%d %s v%d\n",node->id, get_child(node,1)-> id, node->token, get_child(node,2)->id );
	}

	if(node->ntoken ==NOT)//|| node->ntoken ==EQ || node->ntoken == PLUS  || node->ntoken == MINUS || node->ntoken ==AND )

		printf(" v%d := not  v%d\n",node->id,  get_child(node,1)->id );

	if (node->ntoken == CONST) //58.20 
	{
        	 if (node->parent->ntoken == IF &&
		(get_child(node->parent,2) ==node ||
		get_child(node->parent,3) ==node))
	  	printf(" v%d := %s \n",node->parent->id, node->token);
	 	else
	  	printf(" v%d := %s \n",node->id, node->token);
	}
	//need to support function call
	if(node->ntoken ==CALL){
	// for supporting the function call with arguments
	//load to input register
		printf(" call %s\n", node->token);
	         if (node->parent->ntoken == IF &&
	         (get_child(node->parent,2) ==node ||
			get_child(node->parent,3) ==node))
			printf(" v%d:= rv\n", node->parent->id);
	 	else
			printf(" v%d:= rv\n", node->id);  //load from return register

	}


	if ( node->parent != NULL &&
	 node->parent->ntoken ==IF &&
	 get_child(node->parent, 1)==node )
	{
	printf(" br v%d bb%d bb%d\n", node->id,  get_child(node->parent, 2)->id, get_child(node->parent, 3)->id);
	printf("bb%d:\n", get_child(node->parent, 2)->id); 

	}


	if ( node->parent != NULL &&
         node->parent->ntoken ==IF &&
         get_child(node->parent, 2)==node)
        {
	printf(" br bb%d:\n", node->parent->id);
	printf("bb%d:\n", get_child(node->parent, 3)->id);
	;

//	printf("bb%d:\n", get_child(node->parent,2)->id);

	}


	if (node->ntoken == IF){
	//printf(" br v%d bb%d bb%d\n", get_child(node, 1)->id,  get_child(node, 2)->id,  get_child(node, 3)->id);

//	printf("bb%d:\n", get_child(node, 2)->id); 
//	printf(" v%d := v%d\n", node->id, get_child(node,2)->id);
//	printf(" br v%d\n",node->id);

//	printf("bb%d:\n", get_child(node, 3)->id);
//	printf(" v%d := v%d\n", node->id, get_child(node,3)->id);
	printf(" br bb%d\n", node->id);

	printf("bb%d:\n", node->id);
	// printf(" v%d := if v%d then v%d else v%d\n", node->id, get_child(node, 1)->id, get_child(node, 2)->id, get_child(node, 3)->id);
        //      (get_child(node->parent,2) ==node ||
        //      get_child(node->parent,3) ==node))

        //  printf(" v%d := %s \n",node->parent->id, node->token);   //%s to %d
        // else
//          printf(" v%d := %s \n",node->id, node->token);
        }

	//19.10 indicating the termination of computing the body of the function

 	 //printf("    <<<< NODE ID %d >>>> \n", node->id);


        if((is_term(node->ntoken, node->token) || is_expr(node->ntoken, node->token))  && 
	(node->parent->ntoken ==DEFFUN || node->parent->ntoken == PRINT))
	{
	 if(node->parent->ntoken == PRINT){
	 //printf("\n\n PRINT");
	 //printf("\n\nentry:\n");
	 // printf(" v%d:= a1\n", node->id);
	 printf(" a1 := v%d\n", node->id);
	 //printf(" call %s\n", node->token);
         printf(" call := print\n"); 
	 }

	 else {
	  printf(" rv := v%d\n", node->id);
	  }
	 printf(" br exit\n\n\n");

	}

	//return 0;



    //if(node->ntoken == VARID)
	 //printf(" vi%d := %s\n", node->id, get_register_from_symbol_table(node->token));



  return 0;
}




int main(void)
  {
  	int retval = yyparse();
  	push_str("GET-INT", &int_funs_r, &int_funs_t);
  	if(retval == 0) retval = visit_ast(get_fun_types);
	push_str("GET-INT", &int_funs_r, &int_funs_t);
	 if(retval == 0) retval =visit_ast(get_var_types);               //commented out
     if(retval== 0) retval = visit_ast(type_check);


     //struct sequence *head;                                            //initiliazation of head
	 //head= (struct sequence*)malloc(sizeof(struct sequence));           //memory allocation

	   

	      
	 //insert_seq(head, "data", "make");     //insertion in the sequnece
	 //insert_seq(head, node->token, "NULL");  // not working
      //traverse_CGF(head);
   
  	if(retval == 0)	 print_ast();
	else return 1;
	//visit_ast(br_struct);


	visit_ast(translate);

  }



