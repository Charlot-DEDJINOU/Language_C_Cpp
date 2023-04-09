#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int max,min;
    int mys,nom;
    do
    {
        do
        {
            printf("1-Mode 1 joueur\n2-Mode 2 joueur\n");
            scanf("%d",&max);
        }
        while((max!=1) && (max!=2));
        if(max==1)
        {
            do
            {
                printf("Niveau du jeu:\n1-Facile\n2-Normal\n3-Difficile\n");
                scanf("%d",&min);
            }
            while((min!=1) && (min!=2) && (min!=3));
            switch(min)
            {
            case 1:
                min=1;
                max=100;
                srand(time(NULL));
                mys=(rand() % (max-min+1))+min;
                do
                {
                    min=min+1;
                    printf("Quel est le nombre mystere? ");
                    scanf("%d",&nom);
                    if(mys>nom)
                    {
                        printf("c'est plus!\n");
                    }
                    else if(mys<nom)
                    {
                        printf("C'est moins!\n");
                    }
                    else
                    {
                        printf("Bravo vous avez trouve le nombre mystere en %d coups\n",min-1);
                    }
                }
                while(mys!=nom);
                break;
            case 2:
                min=1;
                max=1000;
                srand(time(NULL));
                mys=(rand() % (max-min+1))+min;
                do
                {
                    min=min+1;
                    printf("Quel est le nombre mystere? ");
                    scanf("%d",&nom);
                    if(mys>nom)
                    {
                        printf("c'est plus!\n");
                    }
                    else if(mys<nom)
                    {
                        printf("C'est moins!\n");
                    }
                    else
                    {
                        printf("Bravo vous avez trouve le nombre mystere en %d coups\n",min-1);
                    }
                }
                while(mys!=nom);
                break;
            case 3:
                min=1;
                max=100;
                srand(time(NULL));
                mys=(rand() % (max-min+1))+min;
                do
                {
                    min=min+1;
                    printf("Quel est le nombre mystere? ");
                    scanf("%d",&nom);
                    if(mys>nom)
                    {
                        printf("c'est plus!\n");
                    }
                    else if(mys<nom)
                    {
                        printf("C'est moins!\n");
                    }
                    else
                    {
                        printf("Bravo vous avez trouve le nombre mystere en %d coups\n",min-1);
                    }
                }
                while(mys!=nom);
                break;
            default :
                printf("Error");
                break;
            }
        }
        else
        {
            printf("Veuillez entrer votre nombre mystere :");
            scanf("%d",&mys);

            min=0;
            do
            {
                min=min+1;
                printf("Quel est le nombre mystère? ");
                scanf("%d",&nom);
                if(mys>nom)
                {
                    printf("c'est plus!\n");
                }
                else if(mys<nom)
                {
                    printf("C'est moins!\n");
                }
                else
                {
                    printf("Bravo vous avez trouve le nombre mystere en %d coups\n",min);
                }
            }
            while(mys!=nom);
        }
        printf("Voulez vous rejouer?\n1-oui 2-non\n");
        scanf("%d",&max);
        if(max==1)
        {
            printf("\n\n");
        }
    }
    while(max==1);
    return 0;
}
