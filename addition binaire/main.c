#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char bin1[80], bin2[80];
    int bin[81];
    int i,n,j,k,dec=0,p;
    scanf("%i",&n);
    for (i=0; i<n; i++)
    {
        for(p=0; p<80; p++)
        {


            do
            {
                scanf("%c %c",&bin1[p], &bin2[p]);


            }
            while(bin2!='\n');
        }
    }
    dec=strlen(bin1)-strlen(bin2);
    if(dec>0)
    {
        for(j=0; j<strlen(bin1); j++)
        {
            bin2[j+dec]= bin2[j];

        }
        for(j=0; j<dec; j++)
        {
            bin2[j]='0';
        }
    }


    if(dec<0)
    {
        for(j=0; j<strlen(bin2); j++)
        {
            bin1[j+dec]= bin1[j];

        }
        for(j=0; j<dec; j++)
        {
            bin1[j]='0';
        }
    }


    for(k=strlen(bin1)-1; k>=0; k--)
    {
        bin[k+1]=atoi(bin1[k])+atoi(bin2[k]);
        if(bin[k+1]=2)
        {
            bin[k+1]=0;
            bin[k]=bin[k]+1;
        }
        if (bin[k+1]=3)
        {
            bin[k+1]=1;
            bin[k]=bin[k]+1;
        }

    }
    for(i=0; i<=strlen(bin1); i++)
    {
        printf("%d",bin[i]);
    }

    return 0;
}
