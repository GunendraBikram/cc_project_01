%{
#include<stdio.h>
char n_x;
char str1[1000] ;
int line =0;
int line2 = 0;
int line3 =0;

%}


%%

[a-zA-Z][-a-zA-Z0-9]* {str1,yytext;}
"<"|">"|"="|"+"|"<"|"*"|"-" {line2,printf("Special Character\n");}
"("|")" {line3,printf("Braces\n");}

%%


int main(int argc[], char *argv[] )

{
               yyin = fopen("file3.txt", "r");
               
               yylex();
               printf("%s",str1);
               return 0;






}









