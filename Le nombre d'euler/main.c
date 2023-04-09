#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}
float som(int n)
{
    if(n==0)
        return 1.0;
    else
        return 1.0/fact(n)+som(n-1);
}

void main()
{
    int n;
    printf("n e\n- ---------\n");
    for(n=0; n<10; n++)
    {
        if(n<=1)
            printf("%d %.0f\n",n,som(n));
        else if(n==2)
            printf("%d %.1f\n",n,som(n));
        else
            printf("%d %f\n",n,som(n));
    }
}
