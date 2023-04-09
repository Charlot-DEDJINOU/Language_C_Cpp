#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void moi(int tab[],int a,int i,int* o)
{
    int j,l;
    for(j=1,l=0; a/j!=0; j*=10,l++)
    {
        *o+=1;
        tab[i+l]=a%(j*10)/j;
    }
    if(a/j==0 && j==1000 && a%(j*10)/j==0)
    {
        *o+=1;
        tab[i+l]=0;
    }
}
void main()
{
    int i,a,l=0,s=0,m=-1,tab[16],res[10];
    do
    { l=0;
    s=0;
        for(i=0; i<=12; i+=4)
        {
            scanf("%d",&a);
            if(a==0000)
            {
                s+=1;
            }
        moi(tab,a,i,&l);
        }
        if(s!=4)
        {
            m+=1;
            if(l!=16)
                res[m]=0;
            else
            {
                a=0;
                for(i=0; i<16; i++)
                {
                    if(i%2==0)
                        a+=tab[i];
                    else if(tab[i]*2>9)
                        a+=tab[i]*2-9;
                    else
                        a+=tab[i]*2;
                }
                if(a%10==0)
                    res[m]=1;
                else
                    res[m]=0;
            }
        }
    }
    while(s!=4);
            for(i=0; i<=m; i++)
            {
                if(res[i]==0)
                    printf("\nNO");
                else
                    printf("\nYES");
            }
}
