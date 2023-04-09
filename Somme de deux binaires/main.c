#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void binaire(char mot[],char tab[],char res[],int max,int min,char* s)
{
    int i,l;
    for(i=max-1,l=min-1; i>=0; i--,l--)
    {
        if(l<0)
        {
            tab[l]='0';
        }

        if(mot[i]=='0' && tab[l]=='0' && *s=='0')
        {
            res[i+1]='0';
        }
        else if((tab[l]=='1' && mot[i]=='0' && *s=='0') || (tab[l]=='0' && mot[i]=='1' && *s=='0') || (tab[l]=='0' && mot[i]=='0' && *s=='1'))
        {
            res[i+1]='1';
             *s='0';
        }
        else if((mot[i]=='1' && tab[l]=='1' && *s=='0') || (mot[i]=='1' && tab[l]=='0' && *s=='1') || (mot[i]=='0' && tab[l]=='1' && *s=='1'))
        {
            res[i+1]='0';
            *s='1';
        }
        else
        {
            res[i+1]='1';
            *s='1';
        }
    }
    if(*s=='1' && i==-1)
    {
        res[0]='1';
    }

}

int main()
{
    int l,k;
    char tab[15],mot[15],res[20],s;
    scanf("%d",&l);
    int joe[l];
    for(k=0; k<l; k++)
    {
        scanf("%s %s",mot,tab);
        s='0';
        if(strlen(mot)>=strlen(tab))
        {
            binaire(mot,tab,res,strlen(mot),strlen(tab),&s);
        }
        else
        {
            binaire(tab,mot,res,strlen(tab),strlen(mot),&s);
        }
        joe[k]=atoi(res);
    }
     for(k=0; k<l; k++)
    {
        printf("\n%d\n",joe[k]);
    }
    return 0;
}
