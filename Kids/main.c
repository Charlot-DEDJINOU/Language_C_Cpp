#include <stdio.h>
void main()
{
    int tour,n,min,i,j,a;
    scanf("%d",&tour);
    int res[tour];
    for(i=0;i<tour;i++)
    { res[i]=0;
        scanf("%d %d",&n,&min);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a);
            res[i]+=a/min;
        }
    }
    for(i=0;i<tour;i++)
        printf("\n%d",res[i]);

}
