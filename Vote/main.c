#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elec
{
    char candidat[1000];
    int s;
} elec;

typedef struct gagnant
{
    char candidat[1000];
    int s;
} gagne;

int main()
{
    int tour,p,com,i,k,l;
    char toto[15];
    do
    {
        scanf("%d",&tour);
    }
    while(tour<0||tour>1000);
    gagne win[tour];
    {
        char candidat[1000];
        int s;
    };
    for(i=0; i<tour; i++)
    {
        do
        {
            scanf("%d %d",&p,&com);
        }
        while(p<1||p>100||com<1||com>1000);
        elec elect[p+1];
        {
            char candidat[1000];
            int s;
        };
        for(k=0; k<p; k++)
        {
            scanf("%s",elect[k].candidat);
            elect[k].s=0;
        }
        for(k=0; k<com; k++)
        {
            scanf("%s %d %s",elect[p].candidat,&elect[p].s,toto);
            for(l=0; l<p; l++)
            {
                if(strcmp(elect[p].candidat,elect[l].candidat)==0)
                {
                    elect[l].s+=elect[p].s;
                    l=p;
                }
            }
        }
        elect[p].s=elect[0].s;

        for(k=0; k<p; k++)
        {
            if(elect[p].s<elect[k].s)
            {
                elect[p].s=elect[k].s;
                strcpy(elect[p].candidat,elect[k].candidat);
            }
        }
        l=0;
        for(k=0; k<p; k++)
        {
            if(elect[p].s==elect[k].s)
            {
                l+=1;
            }
        }
        if(l!=1)
        {
            win[i].s=-2;
        }
        else
        {
            win[i].s=elect[p].s;
            strcpy(win[i].candidat,elect[p].candidat);
        }
    }
    for(l=0; l<tour; l++)
    {
        if(win[l].s==-2)
        {
            printf("\nVOTE %d:THERE IS ARE DILEMMA",l+1);
        }
        else
        {
            printf("\nVOTE %d:THE WINNER IS %s %d",l+1,win[l].candidat,win[l].s);
        }
    }
    return 0;
}

