%{
#include<stdio.h>
char n_x;
char str1[1000] ;
int line =0;
int line2 = 0;
int line3 =0;

%}


%%
\;(.*); 
[a-zA-Z][-a-zA-Z0-9]* {printf("%s:\n",yytext);}
"<"|">"|"="|"+"|"<"|"++"|"*"|"-" {printf("%s:\n",yytext);}
"("|")" {printf("%s:\n",yytext);}




%%


int main(int argc[], char *argv[] )

{
               yyin = fopen("file3.txt", "r");
               
               yylex();
               //printf("Total number of tokens = %c\n",n_x);
               //printf("Total number of tokens = %d\n",n_y);
               //printf("Total number of tokens = %d\n",n_z);
               printf("Total number of tokens = %d\n",line);
               printf("Total number of tokens = %d\n",line2);
               printf("Total number of tokens = %d\n",line3);
               
               return 0;






}









