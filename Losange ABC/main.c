#include <stdio.h>
void main()
{
    int i,k,j,n;
    scanf("%d",&n);
    n=n-1;
    for(i=0; i<=n*2+1; i++)
    {
        for(j=0; j<=n*2+1; j++)
        {
            if(i<=n && j>=n-i && j<=n+i)
            {
                k=n;
                for(j=n-i; j<=(n+i); j++)
                {
                    if(j<=n)
                    {
                        printf(" %c",k%26+97);
                        k-=1;
                    }
                    else
                    { k+=1;
                        if(k<25)
                            printf(" %c",k%25+98);
                        else
                            printf(" %c",k%25+97);
                    }
                }
                j-=1;
            }
            else if(i>n && j>=i-n && j<=3*n-i)
            {
                k=n;
                for(j=i-n; j<=3*n-i; j++)
                {
                    if(j<=n)
                    {
                        printf(" %c",k%26+97);
                        k-=1;
                    }
                    else
                    {
                        k+=1;
                        if(k<25)
                            printf(" %c",k%25+98);
                        else
                            printf(" %c",k%25+97);
                    }
                }
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}

