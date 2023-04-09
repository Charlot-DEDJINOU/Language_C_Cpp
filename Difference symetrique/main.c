#include <stdio.h>
#include <string.h>
void main()
{
    int i,j,l=0,k;
    char mot[200],tab[200],intr[30];
    scanf("%s%s",mot,tab);
    for(i=0; i<strlen(mot); i++)
    {
        for(j=0; j<strlen(tab); j++)
        {
            if(mot[i]==tab[j])
                j=strlen(tab)+1;
        }
        if(j==strlen(tab)+2)
        {
            intr[l]=mot[i];
            l+=1;
        }
    }
    strcat(mot,tab);
    l=-1;
    for(i=0; i<strlen(mot); i++)
    {
        for(j=0; j<strlen(intr); j++)
        {
            if(mot[i]==intr[j])
            {
                j=strlen(intr)+2;
            }
        }
        if(j==strlen(intr))
        {
            l+=1;
            tab[l]=mot[i];
            if(l==0)
                printf("\n%c",mot[i]);
            else
            {
                for(k=0; k<l; k++)
                {
                    if(mot[i]==tab[k])
                        k=l+1;
                }
                if(k==l)
                    printf("%c",mot[i]);
            }
        }
    }
}
