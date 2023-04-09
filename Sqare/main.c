#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float nbrcarre(int n)
{
    if(n==1)
     return 1;
    return pow(n,2)+nbrcarre(n-1);
}
int main()
{
    int nbrdonnee,i;
    do
        {
    scanf("%d",&nbrdonnee);
        }
    while(nbrdonnee<=0||nbrdonnee>=1000000);
    int longueur[nbrdonnee];
    for(i=0;i<nbrdonnee;i++)
    {
        scanf("%d",&longueur[i]);
    }
    printf("\n\n");
    for(i=0;i<nbrdonnee;i++)
    {
        printf("%0.f \n",nbrcarre(longueur[i]));
    }

    return 0;
}
