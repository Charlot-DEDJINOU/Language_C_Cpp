#include <stdio.h>
#include<string.h>
int cmp(char tab[],char mot[])
{
    if(strcmp(tab,mot)<0)
        return strlen(mot);
    else
        return strlen(tab);
}
void main()
{
    int i;
    char tab[10],mot[10],s;
    scanf("%s %c %s",tab,&s,mot);
    printf("%20.d\n",atoi(tab));
    for(i=0; i<=20-cmp(tab,mot); i++)
    {
        if(i==16-cmp(tab,mot))
            printf("%c",s);
        else
            printf(" ");
    }
    printf("\n%20.d\n",atoi(mot));
    for(i=0; i<20; i++)
    {
        if(i>=17-cmp(tab,mot))
            printf("_");
        else
            printf(" ");
    }
    if(s=='+')
        printf("\n%20.d\n",atoi(mot)+atoi(tab));
    if(s=='-')
        printf("\n%20.d\n",atoi(tab)-atoi(mot));
    if(s=='*')
        printf("\n%20.d\n",atoi(mot)*atoi(tab));
}

