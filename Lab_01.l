%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addtokens(char *, int);
int linenumber=1;
int tokencount=0;
int lcount=0;
struct token{
char tokenname[1000];
char linenumber[5000];
};
struct token tokenlist[5000];

char n_x;
char str1[1000] ;

%}


%%
\n {linenumber++;}
\;(.*) {}; 
[a-zA-Z][-a-zA-Z0-9]* {addtokens(yytext, linenumber);}
"["|"]"|"{"|"}"|"("|")" {addtokens(yytext, linenumber);}
"<"|">"|"="|"+"|"*"|"-" {addtokens(yytext, linenumber);}
[+-][0-9]*[.][0-9]+ {printf("No rational numbers are allowed");}
[\n\t"]






%%

int yywrap(void){}
void showtokens();
int main(int argc[], char *argv[] )

{
               FILE *fp1;
               fp1= fopen("test_case_04.txt", "r");
               yyin=fp1;
               yylex();
               
               showtokens();
               return 0;
}

void addtokens(char *str, int linenumber)
{ 
  char lno[1000];
  tokencount++;
  strcpy(tokenlist[tokencount].tokenname,str);
  sprintf(lno,"%d",linenumber);
  strcpy(tokenlist[tokencount].linenumber,lno);
 // printf("\n%s\t%s", tokenlist[tokencount].tokenname, tokenlist[tokencount].linenumber);
 }


void showtokens(){
	int i,j,count;
	int freq[1000];
	char lineno[1000];
	for(i=1;i<=tokencount;i++) freq[i]=-1;
	for(i=1;i<=tokencount;i++){
		count = 1;
		strcpy(lineno,"");
		for(j=i+1;j<=tokencount;j++){
			if(strcmp(tokenlist[i].tokenname, tokenlist[j].tokenname)==0){
				count++; freq[j]=0; strcat(lineno," "); strcat(lineno,tokenlist[j].linenumber);
			}
		}
		
		if(freq[i]!=0){
			freq[i]=count; strcat(tokenlist[i].linenumber, lineno);
		}
	}
	for(i=1;i<=tokencount;i++)
	if(freq[i]!=0)
	printf("\n%s:\t %s", tokenlist[i].tokenname, tokenlist[i].linenumber);
}
