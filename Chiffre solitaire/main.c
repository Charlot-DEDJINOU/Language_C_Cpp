#include<stdio.h>
void main()
{
    int n,i,s=0;
        scanf("%d",&n);
    do
    {
        for(i=1; n/i!=0; i*=10)
            s=s+n%(i*10)/i;
    n=s;
    s=0;
    }
    while(n/10!=0);
    printf("%d",n);
}
