#include <stdio.h>
void main()
{
    int a,b,i=-1,res[14];
    do
    { i+=1;
        scanf("%d %d",&a,&b);
        res[i]=a*30+b*40;
        if(res[i]>a*35+b*30)
            res[i]=a*35+b*30;
        if(res[i]>a*40+b*20)
            res[i]=a*40+b*20;
    }
    while(a!=0 || b!=0);
    for(a=0;a<i;a++)
        printf("\n%d",res[a]);
}
