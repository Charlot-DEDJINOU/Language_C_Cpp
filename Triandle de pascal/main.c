#include<stdio.h>
void main()
{
    int n=20,i,j;
    scanf("%d",&n);
    int tab[n+1][n+1];
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j==0 || j==i)
                tab[i][j]=1;
            else
                tab[i][j]=tab[i-1][j]+tab[i-1][j-1];
        }
    }
    system("cls");
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(tab[n][j]/10==0)
                printf(" %-1.d",tab[i][j]);
            else if(tab[n][j]/100==0)
                printf(" %-2.d",tab[i][j]);
            else if(tab[n][j]/1000==0)
                printf(" %-3.d",tab[i][j]);
            else if(tab[n][j]/10000==0)
                printf(" %-4.d",tab[i][j]);
            else if(tab[n][j]/100000==0)
                printf(" %-5.d",tab[i][j]);
            else if(tab[n][j]/1000000==0)
                printf(" %-6.d",tab[i][j]);
            else if(tab[n][j]/10000000==0)
                printf(" %-7.d",tab[i][j]);
            else if(tab[n][j]/100000000==0)
                printf(" %-8.d",tab[i][j]);
            else
                printf(" %-9.d",tab[i][j]);
        }
        printf("\n");
    }
}








