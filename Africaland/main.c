#include <stdio.h>
void main()
{
    int tour,arg,n,bef,i,j,a,s;
    scanf("%d",&tour);
    int res[tour];
    for(i=0; i<tour; i++)
    {
        bef=0;
        scanf("%d %d",&arg,&n);
        for(j=0; j<n; j++)
        {
            scanf("%d",&a);
            if(j%2!=0)
                arg=arg*a+bef;
            else
            {
                if(arg+bef<=a)
                    arg=1;
                else
                {
                    s=arg;
                    arg=(arg+bef)/a;
                    bef+=(s+bef)%a;
                }
            }
        }
        if((j-1)%2==0)
            res[i]=arg*a+bef;
        else
            res[i]=arg;
    }
    for(i=0; i<tour; i++)
        printf("\n%d",res[i]);
}
