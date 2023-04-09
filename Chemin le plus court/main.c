#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tronc
{
    char depart[50];
    char desti[50];
    int distance;
} tronc;
int main()
{
    int i,j,n,l=-1;
    int min[10];
    char dep[50],dest[50],tem[50];
    scanf("%d %s %s",&n,dep,dest);
    tronc tr[n+1];
    {
        char depart[50];
        char desti[50];
        int distance;
    }
    for(i=0; i<n; i++)
    {
        scanf("%s %s %d",tr[i].depart,tr[i].desti,&tr[i].distance);
        tr[n].distance=0;
    }
     for(i=0; i<n; i++)
     {
         for(j=i+1;j<n;j++)
         {
             if(tr[i].distance>tr[j].distance)
             {
                 l=tr[i].distance;
                 tr[i].distance=tr[j].distance;
                 tr[j].distance=l;
                 strcpy(tem,tr[i].depart);
                 strcpy(tr[i].depart,tr[j].depart);
                 strcpy(tr[j].depart,tem);
                 strcpy(tem,tr[i].desti);
                 strcpy(tr[i].desti,tr[j].desti);
                 strcpy(tr[j].desti,tem);
                 l=-1;
             }
         }
     }
    for(i=0; i<n; i++)
    {
        strcpy(tr[n].depart,dep);
        strcpy(tr[n].desti,dest);
        tr[n].distance=0;
        if(strcmp(tr[n].depart,tr[i].depart)==0 || strcmp(tr[n].depart,tr[i].desti)==0)
        {
            l+=1;
            if(strcmp(tr[n].depart,tr[i].depart)==0)
            {
                strcpy(tr[n].depart,tr[i].desti);
            }
            else
            {
                strcpy(tr[n].depart,tr[i].depart);
            }
            tr[n].distance+=tr[i].distance;
            min[l]=tr[n].distance;
            for(j=0; strcmp(tr[n].depart,tr[n].desti)!=0; j++)
            {
                if( i!=j && (strcmp(tr[n].depart,tr[j].depart)==0 || strcmp(tr[n].depart,tr[j].desti)==0))
                {
                    if(strcmp(tr[n].depart,tr[j].depart)==0)
                    {
                        strcpy(tr[n].depart,tr[j].desti);
                    }
                    else
                    {
                        strcpy(tr[n].depart,tr[j].depart);
                    }
                    tr[n].distance+=tr[j].distance;
                    min[l]+=tr[j].distance;
                }
            }
        }
    }
    for(i=1; i<l+1; i++)
    {
      if(min[0]>min[i])
          min[0]=min[i];
    }
    printf("\n%s %s %d",dep,dest,min[0]);
    return 0;
}
