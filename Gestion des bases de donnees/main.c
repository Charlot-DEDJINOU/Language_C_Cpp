#include<stdio.h>
void main()
{
    char nombase[60];
    char choix='a';
    int n=0,i;
    do
    {
        gets(nombase);
        for(n=0; n<strlen(nombase); n++)
        {
            if(nombase[n]==' ')
                n=strlen(nombase);
        }
    }
    while(n==strlen(nombase)+1 || strlen(nombase)>60);
    scanf("%d",&n);
    char prenom[n][25];
    for(i=0; i<n; i++)
        scanf("%s",&prenom[i][25]);
    do
    {
        scanf(" %c",&choix);
    }
    while(choix!='o' && choix!='n');
    if(choix=='n')
        printf("Annuler");
    else
        printf("Creer");
}
