#include <stdio.h>
void main()
{
    int i=-1,a,b,c;
    int res[10][2];
    do
    { i+=1;
        scanf("%d%d%d",&a,&b,&c);
        if(c==2*b-a)
        {
            res[i][0]=1;
            res[i][1]=(c+b-a);
        }
        else
        {
            res[i][0]=0;
            res[i][1]=c*(b/a);
        }
    }
    while(a!=0 || b!=0 || c!=0);
    for(a=0; a<i; a++)
    {
        if(res[a][0]==1)
            printf("\nAP %d",res[a][1]);
        else
            printf("\nGP %d",res[a][1]);
    }
}
