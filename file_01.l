%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addtokens(char *, int);
int linenumber=1;
int tokencount=0;
int lcount=0;
struct token{
char tokenname[100];
char linenumber[50];
};
struct token tokenlist[50];

char n_x;
char str1[1000] ;
int line =0;
int line2 = 0;
int line3 =0;

%}


%%
\n {linenumber++;}
\;(.*) {}; 
[a-zA-Z][-a-zA-Z0-9]* {addtokens(yytext, linenumber);}
"<"|">"|"="|"+"|"<"|"++"|"*"|"-" {addtokens(yytext, linenumber);}
"("|")" {printf("%s:\n",yytext);}
[+-][0-9]*[.][0-9]+ {printf("No rational numbers are allowed");}
[\n\t"]





%%

int yywrap(void){}
void showtokenss();
int main(int argc[], char *argv[] )

{
               FILE *fp1;
               fp1= fopen("test_case_01.txt", "r");
               yyin=fp1;
               yylex();
               //printf("Total number of tokens = %c\n",n_x);
               //printf("Total number of tokens = %d\n",n_y);
               //printf("Total number of tokens = %d\n",n_z);
               //printf("Total number of tokens = %d\n",line);
               //printf("Total number of tokens = %d\n",line2);
               //printf("Total number of tokens = %d\n",line3);
               
               return 0;
}

void addtokens(char *str, int linenumber)
{ 
  char lno[100];
  tokencount++;
  strcpy(tokenlist[tokencount].tokenname,str);
  sprintf(lno,"%d",linenumber);
  strcpy(tokenlist[tokencount].linenumber,lno);
  printf("\n%s\t%s", tokenlist[tokencount].tokenname, tokenlist[tokencount].linenumber);
 }







