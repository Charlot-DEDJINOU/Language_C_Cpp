#include<stdio.h>
int solitaire(int n)
{
    int i,s=0;;
    do
    {
        for(i=1; n/i!=0; i*=10)
        {
            s=s+n%(i*10)/i;
        }
        n=s;
        s=0;
    }
    while(n/10!=0);
    return n;
}

int main()
{
    int n,tab[25],l=-1;
    do
    {
        l+=1;
        scanf("%d",&n);
        tab[l]=solitaire(n);
    }
    while(n!=0);

    for(n=0;n<l;n++)
    {
        printf("\n%d\n",tab[n]);
    }
}
