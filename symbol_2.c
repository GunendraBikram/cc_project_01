#include<stdio.h>
#include<string.h>
int err_no=0,fl=0,i=0,j=0,type[100];
char symbol[100][100],temp[100];


int main()
{
if(err_no==0)
{
for(j=0;j<i;j++)
{
if(type[j]==0) printf("INT-");
if(type[j]==1) printf("FLOAT-");
if(type[j]==2) printf("CHAR-");
if(type[j]==3) printf("DOUBLE-");
printf("%sn",symbol[j]);
}
}
}
void insert(int type1)
{
fl=0;
 for(j=0;j<i;j++)
if(strcmp(temp,symbol[j])==0)
{
if(type[i]==type1) printf("Redeclaration of variable");
else {printf("Multiple Declaration of Variable");err_no=1;}
fl=1;
}
if(fl==0)
{
type[i]=type1;
strcpy(symbol[i],temp);
i++;
}
}
