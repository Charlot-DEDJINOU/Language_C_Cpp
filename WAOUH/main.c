#include<stdio.h>
#include<time.h>
#include<math.h>
#include<unistd.h>
#include"jeu1.h"
int main()
{
    char tab[3][3],o;
    int tour=2;
    printf("\nEntrez la lettre representante\n");
    scanf("%c",&o);
    system("cls");
    tab[0][1]=tab[0][0]=tab[0][2]=o;
    tab[2][0]=tab[2][2]=tab[2][1]='O';
    tab[1][0]= tab[1][1]=tab[1][2]=' ';
    dessin(tab);
    do
    {
        if(tour==2)
        {
            joueur(tab,&o,&tour);
            tour=tour+1;
            system("cls");
            dessin(tab);
        }
        if(tour==1)
        {
            srand(time(NULL));
            ordi(tab,&tour,&o);
            tour=tour+1;
            system("cls");
            dessin(tab);
        }
    }
    while(tour>0);
    return 0;
}
