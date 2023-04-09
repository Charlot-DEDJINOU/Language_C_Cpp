#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "aleatoire.h"

int main()
{
    char c;
    int s,d,i,j,l;
    do
    {
        srand(time(NULL));
        d=(rand() % (6))+3;
        if(d==3)
        {
            char mot[]="aaa";
            char vra[]="aaa";
            char pre[]="aaa";
            aleatoire(&mot,&vra,d);
            d=0;
            s=0;
            j=12;
            l=-1;
            printf("Le mot mystere a ete deja choisi.A vous de le determiner.\nIl comporte %d lettres\n\n",strlen(mot));
            do
            {
                printf("Entrez une lettre que vous pensez etre dans le mot mystere ");
                scanf(" %c",&c);
                s=0;
                for(i=0; i<3; i++)
                {
                    if(mot[i]==c)
                    {
                        pre[d]=c;
                        mot[i]='*';
                        d=d+1;
                        i=3;
                        if(d==3)
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c",c);
                            printf("\nYoupi !!! Enfin la derniere lettre a ete trouve\n");
                        }
                        else
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c\n",c);
                        }
                    }
                    else
                    {
                        s=s+1;
                    }
                    if(s==3)
                    {
                        j=j-1;
                        printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                        if(j==0)
                        {
                            printf("\nDesole !!! vous avez atteint le nombre d'essai maximale\nOr le mot mystere n'etait que %s",vra);
                            d=3;
                        }
                    }
                }
            }
            while(d<3);
            printf("\n\n");
            if(j!=0)
            {
                s=0;
                for(i=0; i<3; i++)
                {
                    if(pre[i]==vra[i])
                    {
                        s=s+1;
                    }
                    else
                    {
                        i=3;
                    }
                }
                if(s==3)
                {
                    printf("\nIncroyable mais vrai !!! Vous venez de trouver le mot mystere qui etait bien sur %s \n",vra);
                }
                else
                {
                    printf("\nLes lettres du mot mystere sont trouvees mais pas en ordre.Veuillez donc les ordonnees pour obtenir un bon sens.Et surtout n'oubliez pas qu'il vous reste %d essaies.\nOn vous attend !!! ",j);
                    scanf("%s",pre);
                    do
                    {
                        s=0;
                        for(i=0; i<3; i++)
                        {
                            if(pre[i]==vra[i])
                            {
                                s=s+1;
                            }
                            else
                            {
                                i=3;
                            }
                        }
                        if(s!=3)
                        {
                            j=j-1;
                            if(j==0)
                            {
                                printf("\nDesole beaucoup !!! VOUS n'avez pas pu trouver %s",vra);
                            }
                            else
                            {
                                printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                                printf("Vous etes toujours en jeu.Donc on vous attend toujours ");
                                scanf("%s",pre);
                            }
                        }
                        else
                        {
                            j=0;
                            s=10000;
                        }
                    }
                    while(j!=0);
                    if(s==10000)
                    {
                        printf("\nFinalement le mot mystere %s a ete trouve",vra);
                    }
                }
            }
        }
        else if(d==4)
        {
            char mot[]="aaaa";
            char vra[]="aaaa";
            char pre[]="aaaa";
            aleatoire(&mot,&vra,d);
            d=0;
            s=0;
            j=12;
            l=-1;
            printf("Le mot mystere a ete deja choisi.A vous de le determiner\nIl comporte %d lettres\n\n",strlen(mot));
            do
            {
                printf("Entrez une lettre que vous pensez etre dans le mot mystere ");
                scanf(" %c",&c);
                s=0;
                for(i=0; i<4; i++)
                {
                    if(mot[i]==c)
                    {
                        pre[d]=c;
                        mot[i]='*';
                        d=d+1;
                        i=4;
                        if(d==4)
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c",c);
                            printf("\nYoupi !!! Enfin la derniere lettre a ete trouve\n");
                        }
                        else
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c\n",c);
                        }
                    }
                    else
                    {
                        s=s+1;
                    }
                    if(s==4)
                    {
                        j=j-1;
                        printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                        if(j==0)
                        {
                            printf("\nDesole !!! vous avez atteint le nombre d'essai maximale\nOr le mot mystere n'etait que %s",vra);
                            d=4;
                        }
                    }
                }
            }
            while(d<4);
            printf("\n\n");
            if(j!=0)
            {
                s=0;
                for(i=0; i<4; i++)
                {
                    if(pre[i]==vra[i])
                    {
                        s=s+1;
                    }
                    else
                    {
                        i=4;
                    }
                }
                if(s==4)
                {
                    printf("\nIncroyable mais vrai !!! Vous venez de trouver le mot mystere qui etait bien sur %s \n",vra);
                }
                else
                {
                    printf("\nLes lettres du mot mystere sont trouvees mais pas en ordre.Veuillez donc les ordonnees pour obtenir un bon sens.Et surtout n'oubliez pas qu'il vous reste %d essaies.\nOn vous attend !!! ",j);
                    scanf("%s",pre);
                    do
                    {
                        s=0;
                        for(i=0; i<4; i++)
                        {
                            if(pre[i]==vra[i])
                            {
                                s=s+1;
                            }
                            else
                            {
                                i=4;
                            }
                        }
                        if(s!=4)
                        {
                            j=j-1;
                            if(j==0)
                            {
                                printf("\nDesole beaucoup !!! VOUS n'avez pas pu trouver %s",vra);
                            }
                            else
                            {
                                printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                                printf("Vous etes toujours en jeu.Donc on vous attend toujours ");
                                scanf("%s",pre);
                            }
                        }
                        else
                        {
                            j=0;
                            s=10000;
                        }
                    }
                    while(j!=0);
                    if(s==10000)
                    {
                        printf("\nFinalement le mot mystere %s a ete trouve",vra);
                    }
                }
            }
        }
        else if(d==5)
        {
            char mot[]="aaaaa";
            char vra[]="aaaaa";
            char pre[]="aaaaa";
            aleatoire(&mot,&vra,d);
            d=0;
            s=0;
            j=12;
            l=-1;
            printf("Le mot mystere a ete deja choisi.A vous de le determiner\nIl comporte %d lettres\n\n",strlen(mot));
            do
            {
                printf("Entrez une lettre que vous pensez etre dans le mot mystere ");
                scanf(" %c",&c);
                s=0;
                for(i=0; i<5; i++)
                {
                    if(mot[i]==c)
                    {
                        pre[d]=c;
                        mot[i]='*';
                        d=d+1;
                        i=5;
                        if(d==5)
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c",c);
                            printf("\nYoupi !!! Enfin la derniere lettre a ete trouve\n");
                        }
                        else
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c\n",c);
                        }
                    }
                    else
                    {
                        s=s+1;
                    }
                    if(s==5)
                    {
                        j=j-1;
                        printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                        if(j==0)
                        {
                            printf("\nDesole !!! vous avez atteint le nombre d'essai maximale\nOr le mot mystere n'etait que %s",vra);
                            d=5;
                        }
                    }
                }
            }
            while(d<5);
            printf("\n\n");
            if(j!=0)
            {
                s=0;
                for(i=0; i<5; i++)
                {
                    if(pre[i]==vra[i])
                    {
                        s=s+1;
                    }
                    else
                    {
                        i=5;
                    }
                }
                if(s==5)
                {
                    printf("\nIncroyable mais vrai !!! Vous venez de trouver le mot mystere qui etait bien sur %s \n",vra);
                }
                else
                {
                    printf("\nLes lettres du mot mystere sont trouvees mais pas en ordre.Veuillez donc les ordonnees pour obtenir un bon sens.Et surtout n'oubliez pas qu'il vous reste %d essaies.\nOn vous attend !!! ",j);
                    scanf("%s",pre);
                    do
                    {
                        s=0;
                        for(i=0; i<5; i++)
                        {
                            if(pre[i]==vra[i])
                            {
                                s=s+1;
                            }
                            else
                            {
                                i=5;
                            }
                        }
                        if(s!=5)
                        {
                            j=j-1;
                            if(j==0)
                            {
                                printf("\nDesole beaucoup !!! VOUS n'avez pas pu trouver %s",vra);
                            }
                            else
                            {
                                printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                                printf("Vous etes toujours en jeu.Donc on vous attend toujours ");
                                scanf("%s",pre);
                            }
                        }
                        else
                        {
                            j=0;
                            s=10000;
                        }
                    }
                    while(j!=0);
                    if(s==10000)
                    {
                        printf("\nFinalement le mot mystere %s a ete trouve",vra);
                    }
                }
            }
        }
        else if(d==6)
        {
            char mot[]="aaaaaa";
            char vra[]="aaaaaa";
            char pre[]="aaaaaa";
            aleatoire(&mot,&vra,d);
            d=0;
            s=0;
            j=12;
            l=-1;
            printf("Le mot mystere a ete deja choisi.A vous de le determiner.\nIl comporte %d lettres\n\n",strlen(mot));
            do
            {
                printf("Entrez une lettre que vous pensez etre dans le mot mystere ");
                scanf(" %c",&c);
                s=0;
                for(i=0; i<6; i++)
                {
                    if(mot[i]==c)
                    {
                        pre[d]=c;
                        mot[i]='*';
                        d=d+1;
                        i=6;
                        if(d==6)
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c",c);
                            printf("\nYoupi !!! Enfin la derniere lettre a ete trouve\n");
                        }
                        else
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c\n",c);
                        }
                    }
                    else
                    {
                        s=s+1;
                    }
                    if(s==6)
                    {
                        j=j-1;
                        printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                        if(j==0)
                        {
                            printf("\nDesole !!! vous avez atteint le nombre d'essai maximale\nOr le mot mystere n'etait que %s",vra);
                            d=6;
                        }
                    }
                }
            }
            while(d<6);
            printf("\n\n");
            if(j!=0)
            {
                s=0;
                for(i=0; i<6; i++)
                {
                    if(pre[i]==vra[i])
                    {
                        s=s+1;
                    }
                    else
                    {
                        i=6;
                    }
                }
                if(s==6)
                {
                    printf("\nIncroyable mais vrai !!! Vous venez de trouver le mot mystere qui etait bien sur %s \n",vra);
                }
                else
                {
                    printf("\nLes lettres du mot mystere sont trouvees mais pas en ordre.Veuillez donc les ordonnees pour obtenir un bon sens.Et surtout n'oubliez pas qu'il vous reste %d essaies.\nOn vous attend !!! ",j);
                    scanf("%s",pre);
                    do
                    {
                        s=0;
                        for(i=0; i<6; i++)
                        {
                            if(pre[i]==vra[i])
                            {
                                s=s+1;
                            }
                            else
                            {
                                i=6;
                            }
                        }
                        if(s!=6)
                        {
                            j=j-1;
                            if(j==0)
                            {
                                printf("\nDesole beaucoup !!! VOUS n'avez pas pu trouver %s",vra);
                            }
                            else
                            {
                                printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                                printf("Vous etes toujours en jeu.Donc on vous attend toujours ");
                                scanf("%s",pre);
                            }
                        }
                        else
                        {
                            j=0;
                            s=10000;
                        }
                    }
                    while(j!=0);
                    if(s==10000)
                    {
                        printf("\nFinalement le mot mystere %s a ete trouve",vra);
                    }
                }
            }
        }
        else  if(d==7)
        {
            char mot[]="aaaaaaa";
            char vra[]="aaaaaaa";
            char pre[]="aaaaaaa";
            aleatoire(&mot,&vra,d);
            d=0;
            s=0;
            j=12;
            l=-1;
            printf("Le mot mystere a ete deja choisi.A vous de le determiner.\nIl comporte %d lettres\n\n",strlen(mot));
            do
            {
                printf("Entrez une lettre que vous pensez etre dans le mot mystere ");
                scanf(" %c",&c);
                s=0;
                for(i=0; i<7; i++)
                {
                    if(mot[i]==c)
                    {
                        pre[d]=c;
                        mot[i]='*';
                        d=d+1;
                        i=7;
                        if(d==7)
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c",c);
                            printf("\nYoupi !!! Enfin la derniere lettre a ete trouve\n");
                        }
                        else
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c\n",c);
                        }
                    }
                    else
                    {
                        s=s+1;
                    }
                    if(s==7)
                    {
                        j=j-1;
                        printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                        if(j==0)
                        {
                            printf("\nDesole !!! vous avez atteint le nombre d'essai maximale\nOr le mot mystere n'etait que %s",vra);
                            d=7;
                        }
                    }
                }
            }
            while(d<7);
            printf("\n\n");
            if(j!=0)
            {
                s=0;
                for(i=0; i<7; i++)
                {
                    if(pre[i]==vra[i])
                    {
                        s=s+1;
                    }
                    else
                    {
                        i=7;
                    }
                }
                if(s==7)
                {
                    printf("\nIncroyable mais vrai !!! Vous venez de trouver le mot mystere qui etait bien sur %s \n",vra);
                }
                else
                {
                    printf("\nLes lettres du mot mystere sont trouvees mais pas en ordre.Veuillez donc les ordonnees pour obtenir un bon sens.Et surtout n'oubliez pas qu'il vous reste %d essaies.\nOn vous attend !!! ",j);
                    scanf("%s",pre);
                    do
                    {
                        s=0;
                        for(i=0; i<7; i++)
                        {
                            if(pre[i]==vra[i])
                            {
                                s=s+1;
                            }
                            else
                            {
                                i=7;
                            }
                        }
                        if(s!=5)
                        {
                            j=j-1;
                            if(j==0)
                            {
                                printf("\nDesole beaucoup !!! VOUS n'avez pas pu trouver %s",vra);
                            }
                            else
                            {
                                printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                                printf("Vous etes toujours en jeu.Donc on vous attend toujours ");
                                scanf("%s",pre);
                            }
                        }
                        else
                        {
                            j=0;
                            s=10000;
                        }
                    }
                    while(j!=0);
                    if(s==10000)
                    {
                        printf("\nFinalement le mot mystere %s a ete trouve",vra);
                    }
                }
            }
        }
        else if(d==8)
        {
            char mot[]="aaaaaaaa";
            char vra[]="aaaaaaaa";
            char pre[]="aaaaaaaa";
            aleatoire(&mot,&vra,d);
            d=0;
            s=0;
            j=12;
            l=-1;
            printf("Le mot mystere a ete deja choisi.A vous de le determiner\nIl comporte %d lettres\n\n",strlen(mot));
            do
            {
                printf("Entrez une lettre que vous pensez etre dans le mot mystere ");
                scanf(" %c",&c);
                s=0;
                for(i=0; i<8; i++)
                {
                    if(mot[i]==c)
                    {
                        pre[d]=c;
                        mot[i]='*';
                        d=d+1;
                        i=8;
                        if(d==8)
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c",c);
                            printf("\nYoupi !!! Enfin la derniere lettre a ete trouve\n");
                        }
                        else
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c\n",c);
                        }
                    }
                    else
                    {
                        s=s+1;
                    }
                    if(s==8)
                    {
                        j=j-1;
                        printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                        if(j==0)
                        {
                            printf("\nDesole !!! vous avez atteint le nombre d'essai maximale\nOr le mot mystere n'etait que %s",vra);
                            d=8;
                        }
                    }
                }
            }
            while(d<8);
            printf("\n\n");
            if(j!=0)
            {
                s=0;
                for(i=0; i<8; i++)
                {
                    if(pre[i]==vra[i])
                    {
                        s=s+1;
                    }
                    else
                    {
                        i=8;
                    }
                }
                if(s==8)
                {
                    printf("\nIncroyable mais vrai !!! Vous venez de trouver le mot mystere qui etait bien sur %s \n",vra);
                }
                else
                {
                    printf("\nLes lettres du mot mystere sont trouvees mais pas en ordre.Veuillez donc les ordonnees pour obtenir un bon sens.Et surtout n'oubliez pas qu'il vous reste %d essaies.\nOn vous attend !!! ",j);
                    scanf("%s",pre);
                    do
                    {
                        s=0;
                        for(i=0; i<8; i++)
                        {
                            if(pre[i]==vra[i])
                            {
                                s=s+1;
                            }
                            else
                            {
                                i=8;
                            }
                        }
                        if(s!=8)
                        {
                            j=j-1;
                            if(j==0)
                            {
                                printf("\nDesole beaucoup !!! VOUS n'avez pas pu trouver %s",vra);
                            }
                            else
                            {
                                printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                                printf("Vous etes toujours en jeu.Donc on vous attend toujours ");
                                scanf("%s",pre);
                            }
                        }
                        else
                        {
                            j=0;
                            s=10000;
                        }
                    }
                    while(j!=0);
                    if(s==10000)
                    {
                        printf("\nFinalement le mot mystere %s a ete trouve",vra);
                    }
                }
            }
        }
        else if(d==9)
        {
            char mot[]="aaaaaaaaa";
            char vra[]="aaaaaaaaa";
            char pre[]="aaaaaaaaa";
            aleatoire(&mot,&vra,d);
            d=0;
            s=0;
            j=12;
            l=-1;
            printf("Le mot mystere a ete deja choisi.A vous de le determiner\nIl comporte %d lettres\n\n",strlen(mot));
            do
            {
                printf("Entrez une lettre que vous pensez etre dans le mot mystere ");
                scanf(" %c",&c);
                s=0;
                for(i=0; i<9; i++)
                {
                    if(mot[i]==c)
                    {
                        pre[d]=c;
                        mot[i]='*';
                        d=d+1;
                        i=9;
                        if(d==9)
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c",c);
                            printf("\nYoupi !!! Enfin la derniere lettre a ete trouve\n");
                        }
                        else
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c\n",c);
                        }
                    }
                    else
                    {
                        s=s+1;
                    }
                    if(s==9)
                    {
                        j=j-1;
                        printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                        if(j==0)
                        {
                            printf("\nDesole !!! vous avez atteint le nombre d'essai maximale\nOr le mot mystere n'etait que %s",vra);
                            d=9;
                        }
                    }
                }
            }
            while(d<9);
            printf("\n\n");
            if(j!=0)
            {
                s=0;
                for(i=0; i<5; i++)
                {
                    if(pre[i]==vra[i])
                    {
                        s=s+1;
                    }
                    else
                    {
                        i=9;
                    }
                }
                if(s==9)
                {
                    printf("\nIncroyable mais vrai !!! Vous venez de trouver le mot mystere qui etait bien sur %s \n",vra);
                }
                else
                {
                    printf("\nLes lettres du mot mystere sont trouvees mais pas en ordre.Veuillez donc les ordonnees pour obtenir un bon sens.Et surtout n'oubliez pas qu'il vous reste %d essaies.\nOn vous attend !!! ",j);
                    scanf("%s",pre);
                    do
                    {
                        s=0;
                        for(i=0; i<9; i++)
                        {
                            if(pre[i]==vra[i])
                            {
                                s=s+1;
                            }
                            else
                            {
                                i=9;
                            }
                        }
                        if(s!=9)
                        {
                            j=j-1;
                            if(j==0)
                            {
                                printf("\nDesole beaucoup !!! VOUS n'avez pas pu trouver %s",vra);
                            }
                            else
                            {
                                printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                                printf("Vous etes toujours en jeu.Donc on vous attend toujours ");
                                scanf("%s",pre);
                            }
                        }
                        else
                        {
                            j=0;
                            s=10000;
                        }
                    }
                    while(j!=0);
                    if(s==10000)
                    {
                        printf("\nFinalement le mot mystere %s a ete trouve",vra);
                    }
                }
            }
        }
        else
        {
            char mot[]="aaaaaaaaaa";
            char vra[]="aaaaaaaaaa";
            char pre[]="aaaaaaaaaa";
            aleatoire(&mot,&vra,d);
            d=0;
            s=0;
            j=12;
            l=-1;
            printf("Le mot mystere a ete deja choisi.A vous de le determiner\nIl comporte %d lettres\n\n",strlen(mot));
            do
            {
                printf("Entrez une lettre que vous pensez etre dans le mot mystere ");
                scanf(" %c",&c);
                s=0;
                for(i=0; i<10; i++)
                {
                    if(mot[i]==c)
                    {
                        pre[d]=c;
                        mot[i]='*';
                        d=d+1;
                        i=10;
                        if(d==5)
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c",c);
                            printf("\nYoupi !!! Enfin la derniere lettre a ete trouve\n");
                        }
                        else
                        {
                            printf("\t  \t  \t  \t  \t  \t  \t  \t  \t %c\n",c);
                        }
                    }
                    else
                    {
                        s=s+1;
                    }
                    if(s==10)
                    {
                        j=j-1;
                        printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                        if(j==0)
                        {
                            printf("\nDesole !!! vous avez atteint le nombre d'essai maximale\nOr le mot mystere n'etait que %s",vra);
                            d=10;
                        }
                    }
                }
            }
            while(d<10);
            printf("\n\n");
            if(j!=0)
            {
                s=0;
                for(i=0; i<10; i++)
                {
                    if(pre[i]==vra[i])
                    {
                        s=s+1;
                    }
                    else
                    {
                        i=10;
                    }
                }
                if(s==10)
                {
                    printf("\nIncroyable mais vrai !!! Vous venez de trouver le mot mystere qui etait bien sur %s \n",vra);
                }
                else
                {
                    printf("\nLes lettres du mot mystere sont trouvees mais pas en ordre.Veuillez donc les ordonnees pour obtenir un bon sens.Et surtout n'oubliez pas qu'il vous reste %d essaies.\nOn vous attend !!! ",j);
                    scanf("%s",pre);
                    do
                    {
                        s=0;
                        for(i=0; i<10; i++)
                        {
                            if(pre[i]==vra[i])
                            {
                                s=s+1;
                            }
                            else
                            {
                                i=10;
                            }
                        }
                        if(s!=10)
                        {
                            j=j-1;
                            if(j==0)
                            {
                                printf("\nDesole beaucoup !!! VOUS n'avez pas pu trouver %s",vra);
                            }
                            else
                            {
                                printf("\t \t  \t  \t  \t  \t  \t  \t  \t \t%d\n",j);
                                printf("Vous etes toujours en jeu.Donc on vous attend toujours ");
                                scanf("%s",pre);
                            }
                        }
                        else
                        {
                            j=0;
                            s=10000;
                        }
                    }
                    while(j!=0);
                    if(s==10000)
                    {
                        printf("\nFinalement le mot mystere %s a ete trouve",vra);
                    }
                }
            }
        }
        printf("\nVoulez vous rejouez ? 1-OUI 2-NON ");
        scanf("%d",&d);
         system("cls");
    }
    while(d==1);
    return 0;
}


