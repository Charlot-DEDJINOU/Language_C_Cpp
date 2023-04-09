#include<stdio.h>
#include<stdlib.h>
void main()
{
    char mot[1000],tab[52]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i,s=0,j;
        scanf("%s",mot);
    if(strlen(mot)<26)
        printf("Pas mixte");
    else
    {
        for(i=25; i>=0; i--)
        {
            for(j=0; j<strlen(mot); j++)
            {
                if(tab[i]!=mot[j] && tab[i+26]!=mot[j])
                    s=s+1;
            }
            if(s==strlen(mot))
            {
                printf("Pas mixte");
                j=strlen(mot);
                i=-2;
            }
            else
                s=0;
        }
        if(s==0)
            printf("Mixte");
    }
}
