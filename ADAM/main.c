#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    int i,j,n;
    char tab[100];
    scanf("%d",&n);
    int res[n];
    for(i=0; i<n; i++)
    {
        j=-1;
        scanf("%s",tab);
        res[i]=-1;
        do
        {
            res[i]+=1;
            j+=1;
        }
        while(tab[j]!='D' && j<strlen(tab));
    }
    for(i=0; i<n; i++)
        printf("\n%d\n",res[i]);
}
