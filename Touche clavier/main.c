#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,j,s=0;
    char mot[100];
    scanf("%d",&n);
    int tab[n];
    for(j=0; j<=n; j++)
    {
        tab[j]=0;
        gets(mot);
        for(i=0; i<strlen(mot); i++)
        {
            if(mot[i]=='a' || mot[i]=='d' || mot[i]=='g' || mot[i]=='j' || mot[i]=='m' || mot[i]=='p' || mot[i]=='t' || mot[i]=='w' || mot[i]==' ')
                tab[j]+=1;
            else if(mot[i]=='b' || mot[i]=='e' || mot[i]=='h' || mot[i]=='k' || mot[i]=='n' || mot[i]=='q' || mot[i]=='u' || mot[i]=='x')
                tab[j]+=2;
            else if(mot[i]=='c' || mot[i]=='f' || mot[i]=='i' || mot[i]=='l' || mot[i]=='o' || mot[i]=='r' || mot[i]=='v' || mot[i]=='i')
                tab[j]+=3;
            else
                tab[j]+=4;
        }
    }
    for(i=1; i<=n; i++)
        printf("case#%d :%d\n",i,tab[i]);
}

