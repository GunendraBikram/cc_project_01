%{
void yyerror(char *s);
int yylex();
#include<stdio.h>
%}

%union {int val; char* str;}
%start program
%token ID
%token COMMA
%token SEMICOLON
%token ERR
%type<str> id id_list_prefix

%%
program: id_list_prefix SEMICOLON{printf("root\n");}|
id_list_prefix ERR {yyerror("missing semicolon\n");};
id_list_prefix: id_list_prefix COMMA id| id;
id: ID{printf("received (*): %s\n", $$);}
%%

int main(void) { return yyparse (); }
void yyerror (char *s) {printf("%s\n", s);}
