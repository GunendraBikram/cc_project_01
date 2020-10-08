#include "containers.h"
#include "y.tab.h"

int yyparse();

struct node_str *int_fun_r;
struct node_str *int_fun_t;
struct node_str *bool_fun_r;
struct node_str *bool_fun_t;

int is_fla(int t, char *fname)
{
  if (t == TRUE || t == FALSE || t == EQ || t == NOT | t == AND)
    return true;
  if (t == CALL && 0 == find_str(fname, bool_fun_r))       
    return true;
  return false;
}

int is_term(int t, char *fname)
{
  if (t == CONST || t == PLUS || t == MINUS)
    return true;     
  if(t == CALL && 0==find_str(fname, int_fun_r)) 
     return true; 
  return false;
}

int type_check(struct ast *tmp)
{
  int cur_token = tmp->ntoken;                            //check for = or -
  int needs_term = cur_token == EQ || cur_token == MINUS || cur_token == PLUS; //additon of terms
  int needs_fla = cur_token == AND || cur_token == NOT;

  struct ast_child *t = tmp->child; //added *
  while (t != NULL)
  {
    struct ast *ch = t->id; //type check ast*
    if (needs_term && !is_term(ch->ntoken,ch-> token)) || (needs_fla && !is_fla(ch->ntoken, ch->token)) //needs_fla
      {
        printf("there is no type check");
        return 1;
      }

    t = t->next;
  }

  return 0;
}

int get_fun(struct ast *tmp)
{
  if (tmp->ntoken == FUNID)
  {
    struct ast *body = get_child(tmp->parent, 2);
    if (is_term(body->ntoken, body->token))
      push_str(tmp->token, &int_fun_r, &int_fun_t);

    if (is_fla(body->ntoken, body->token))                           //changed is_fla to is_term
      push_str(tmp->token, &bool_fun_r, &bool_fun_t);
  }

  return 0;
}

//int fun3() struct ast *tmp
//{

  //return 0;
//}

int main(void)
{

  int retval = yyparse();
  if (retval == 0)
    visit_ast(get_fun); //sematic chekc 1
  if (retval == 0)
    visit_ast(type_check); //sematic chekc 1
  //if (retval == 0)
    //visit_ast(fun3); //sematic chekc 1
  if (retval == 0)
    print_ast(); //sematic chekc 1

  free_ast();
  return retval;
}
