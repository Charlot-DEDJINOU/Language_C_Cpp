#include<stdio.h>
void  main()
{
    int mult;
    int i,k,j,n,p,m;
    scanf("%d %d",&n,&p);
    int matrice[n][p];
    scanf("%d",&m);
    int Matrice[p][m];
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=p-1; j++)
            scanf("%d",&matrice[i][j]);
    }
    for(i=0; i<=p-1; i++)
    {
        for(j=0; j<=m-1; j++)
            scanf("%d",&Matrice[i][j]);
    }
    printf("\n\n");
    for(i=0; i<=n-1; i++)
    {
        for(k=0; k<=m-1; k++)
        {
            mult=0;
            for(j=0; j<=p-1; j++)
            {
                mult=mult+matrice[i][j]*Matrice[j][k];
                if(j==p-1)
                    printf("   %d",mult);
            }
        }
        printf("\n");
    }
}
