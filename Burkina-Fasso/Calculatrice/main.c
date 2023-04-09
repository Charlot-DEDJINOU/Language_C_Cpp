#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float virgule1(char tab[],int* i,int a)
{
    char mot[10];
    int j=1,s=1;
    *i=*i+1;
    if(tab[*i+1]=='.')
    {
        mot[0]=tab[*i];
        do
        {
            mot[j]=tab[*i+j+1];
            s*=10;
            j+=1;
        }
        while(tab[*i+j]!='*' && tab[*i+j]!='+' && tab[*i+j]!='-' && tab[*i+j]!='%' && tab[*i+j]!='/');
        return 1.0*atoi(mot)/s;
    }
    else
        return 1.0*atoi(tab[*i]);
}

float virgule2(char tab[],int* i)
{
    char mot[10];
    int j=1,s=1;
    *i=*i-1;
    if(tab[*i-1]=='.')
    {
        mot[0]=tab[*i];
        do
        {
            mot[j]=tab[*i-j];
            s*=10;
            j+=1;
        }
        while(tab[*i-j]!='*' && tab[*i-j]!='+' && tab[*i-j]!='-' && tab[*i-j]!='%' && tab[*i-j]!='/' && tab[*i-j]!='.');
        return 1.0*atoi(mot)/s;
    }
    else
        return 1.0*atoi(tab[*i]);

}

int main()

{
    char tab[50];
    int i,j=1;
    scanf("%s",tab);
    int res[strlen(tab)/2];
    do
    {
        for(i=j; i<strlen(tab); i+=2)
        {
            if(tab[i]=='/' && virgule1(tab,&i)==0.000000)
            {
                printf("ERROR");
                i=strlen(tab);
            }
            else
            {
                if(tab[i]=='*')
                }
        }
    }
    return 0;
}
