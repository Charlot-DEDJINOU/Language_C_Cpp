#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,b,c,p;
    char x,mot[15];
    do
    {
        scanf("%d",&p);
    }
        while(p<1 || p>1000);
    float tab[p];
    for(i=0; i<p; i++)
    {
        scanf("%s %c %d %c %d",mot,&x,&b,&x,&c);
        if(atoi(mot)==0 && c!=b)
        {
          tab[i]=1234567890;
        }
        else if(atoi(mot)==0 && c==b)
        {
            tab[i]=9876543210;
        }
        else
        {
        tab[i]=(c-b)/(1.0*atoi(mot));
        }
    }
     for(i=0; i<p; i++)
    {
        if(tab[i]==1234567890)
        {
          printf("\nEquation %d\nPas de solution\n",i+1);
        }
        else if(tab[i]==9876543210)
        {
             printf("\nEquation %d\nMore than one solution\n",i+1);
        }
        else
        {
        printf("\nEquation %d\n%f\n",i+1,tab[i]);
        }
    }
    return 0;
}
