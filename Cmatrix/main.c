#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

int main()
{
    int i=1,j,k,l,m,s=0;
    char tab[45][105];
    srand(time(NULL));
    system("COLOR 02");
    for(i=0; i<45; i++)
    {
        for(j=0; j<105; j++)
        {
            if((j%5==0 && i!=39) || j==49 || (i<30 && j%7==0) || (i>29 && j%3==0 && i!=39) || (i>15 && i<40 && (j%3==0 || j%7==0)))
                tab[i][j]=33+(rand()%93);
            else
                tab[i][j]=' ';
        }
    }
    for(k=44; k>=0; k--)
    {
        printf("\e[1;1H\e[2J");
        for(i=0; i<=44-k; i++)
        {
            for(j=0; j<105; j++)
                printf("%-2.c",tab[k+i][j]);
            printf("\n");

        }
        for(l=0; l<105; l++)
            tab[44][l]=33+(rand()%93);
    }
    system("cls");
    do
    {
        for(l=0; l<45; l++)
        {
            for(k=0; k<105; k++)
                printf("%-2.c",tab[l][k]);
            printf("\n");
        }
        printf("\e[1;1H\e[2J");
        for(j=0; j<105; j++)
        {
            if(tab[44][j]!=' ')
            {
                for(i=0; i<45; i++)
                {
                    if(tab[i][j]!=' ')
                    {
                        tab[i][j]=' ';
                        i=45;
                    }
                }
            }
            else
            {
                for(l=43; l>=0; l--)
                {
                    tab[l+1][j]=tab[l][j];
                    tab[l][j]=' ';
                }
            }
        }
        for(l=0; l<105; l++)
        {
            m=0;
            for(k=0; k<45; k++)
            {
                if(tab[k][l]!=' ')
                    m+=1;
            }
            if(m<10+(rand()%20) && tab[44][l]==' ' && tab[25][l]==' ')
                tab[0][l]=33+(rand()%93);
        }
        for(l=0; l<105; l++)
        {
            if(tab[44][l]==' ')
            {
                for(k=44; k>=0; k--)
                {
                    if(tab[k][l]!=' ')
                    {
                        tab[k][l]=33+(rand()%93);
                        k=-1;
                    }
                }
            }
        }
    }
    while(1==1);
    return 0;
}
