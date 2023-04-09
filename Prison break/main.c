#include <stdio.h>
#include <stdlib.h>
void brek(char tab[],int L,int W,int B,int C,int* m)
{ char c=tab[B];
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
        { tab[B]='D';
            if(B+L==C)
                *m=1;
            else
                brek(tab,L,W,B+L,C,m);
        }
        if(tab[B-L]==c && (B-L)>=0 && *m==0)
        { tab[B]='B';
            if(B-L==C)
                *m=1;
            else
                brek(tab,L,W,B-L,C,m);
        }
}

void main()
{
    int L,W,A,B,C,D,i,j,m=0;
    scanf("%d %d %d %d %d %d",&L,&W,&A,&B,&C,&D);
    char tab[W][L];
    for(i=W-1; i>=0; i--)
    {
        for(j=0; j<L; j++)
            scanf(" %c",&tab[i][j]);
    }
    brek(tab,L,W,A-1+(B-1)*L,C-1+(D-1)*L,&m);
    if(m==1)
        printf("Yes\n");
    else
        printf("No\n");
     for(i=W-1; i>=0; i--)
    {
        for(j=0; j<L; j++)
            printf(" %c",tab[i][j]);
        printf("\n");
    }
}
