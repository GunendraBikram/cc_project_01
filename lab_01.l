%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addtokens(char *, int);
int linenumber=1;
int tokencount=0;
int lcount=0;
int varcount=0;
int constcount=0;
int opcount=0;
struct token{
char tokenname[1000];
char linenumber[5000];
};
struct token tokenlist[5000];



%}
rational [-+]*[0-9]*[.][0-9]+
program obr eval expr cbr|obr eval term cbr| obr print expr cbr|obr print term cbr
type int|bool
var [a-zA-Z][-a-zA-Z0-9]*
const [0-9]+
obr "("|"{"|"["
cbr ")"|"{"|"]"
op "+"|"-"|"*"
rop "="|"<"|">"|"<="|">="
term var|const|obr op term term cbr| obr div term term cbr| obr mod term term cbr | obr if expr term term cbr | obr get-int cbr
expr true|false|obr rop term term cbr | obr not expr cbr | obr and expr expr cbr| obr or expr expr cbr 


%%
\n {linenumber++;}
\;(.*) {}; 
{const} {constcount++; if((constcount+varcount)==2) opcount=0;} 
{var} {varcount++; addtokens(yytext, linenumber); if((constcount+varcount)==2) opcount=0; }
{obr} {addtokens(yytext, linenumber);}
{cbr} {addtokens(yytext, linenumber);}
{op} {opcount++; if(opcount==1) addtokens(yytext, linenumber); else printf("\nInvalid Expression"); varcount=0; constcount=0;}
{rop} {addtokens(yytext, linenumber);}

{rational} {printf("No rational numbers are allowed");}
[_]* {printf("\nInvalid character");}
[~]* {printf("\nInvalid character");}
[\n\t"]




%%

int yywrap(void){}
void showtokens();
int main(int argc[], char *argv[] )

{
               FILE *fp1;
               fp1= fopen("test_case_03.txt", "r");
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



