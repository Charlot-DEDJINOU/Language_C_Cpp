#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void brek(char tab[],int L,int W,int B,int C,int* m)
{
    char c=tab[B];
    if(c==tab[B+1] && (B+1)%L!=0 && *m==0)
    {
        tab[B]='A';
        if(B+1==C)
            *m=1;
        else
            brek(tab,L,W,B+1,C,m);
    }
    if(c==tab[B-1] && B%L!=0 && *m==0)
    {
        tab[B]='C';
        if(B-1==C)
            *m=1;
        else
            brek(tab,L,W,B-1,C,m);
    }
    if(tab[B+L]==c && (B+L)<L*W && *m==0)
    {
        tab[B]='D';
        if(B+L==C)
            *m=1;
        else
            brek(tab,L,W,B+L,C,m);
    }
    if(tab[B-L]==c && (B-L)>=0 && *m==0)
    {
        tab[B]='B';
        if(B-L==C)
            *m=1;
        else
            brek(tab,L,W,B-L,C,m);
    }
}

void main()
{
    int L,W,A,B,C,D,i,j,m=0,n;
    scanf("%d %d",&W,&L);
    char mot[W][L],tab[W][L];
    for(i=0; i<W; i++)
        scanf("%s",mot[i]);
    scanf("%d",&n);
    int res[n];
    for(i=0; i<n; i++)
    {
        m=0;
        for(j=0; j<W; j++)
            strcpy(tab[j],mot[j]);
        scanf("%d %d %d %d",&B,&A,&D,&C);
        if(A==C && B==D && mot[B-1][A-1]=='1')
            res[i]=10;
        else if(A==C && B==D && mot[B-1][A-1]=='0')
            res[i]=2;
        else
        {
            brek(tab,L,W,A-1+(B-1)*L,C-1+(D-1)*L,&m);
            if(m==1 && mot[B-1][A-1]=='0')
                res[i]=2;
            else if(m==1 && mot[B-1][A-1]=='1')
                res[i]=10;
            else
                res[i]=8;
        }
    }
    for(i=0; i<n; i++)
    {
        if(res[i]==2)
            printf("\nbinary");
        else if(res[i]==10)
            printf("\ndecimal");
        else
            printf("\nneither");
    }
}


