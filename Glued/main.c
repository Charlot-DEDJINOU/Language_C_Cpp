
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char pr[2],suf[2];
    char m='b';
    int rad,a,b,c,d,l=0,tab[15][4];
    do
    {
        scanf("%s",pr);
        if(pr[0]!='#')
        {
            scanf("%d %s",&rad,suf);
            a=rad/1000;
            b=(rad%1000)/100;
            c=((rad%1000)%100)/10;
            d=((rad%1000)%100)%10;
            if(a==b)
            {
                if (c==d)
                {
                    if(b!=c)
                    {
                        tab[l][0]=a;
                        tab[l][1]=b;
                        tab[l][2]=c;
                        tab[l][3]=d;
                    }
                    else
                    {
                        tab[l][0]=a;
                        tab[l][1]=b;
                        tab[l][2]=-1;
                    }
                }
                else
                {
                    tab[l][0]=a;
                    tab[l][1]=b;
                    tab[l][2]=-1;
                }
            }
            else if (b==c)
            {
                tab[l][0]=c;
                tab[l][1]=b;
                tab[l][2]=-1;
            }
            else if(c==d)
            {
                tab[l][0]=c;
                tab[l][1]=d;
                tab[l][2]=-1;
            }
            else
            {

                tab[l][0]=-1;
                tab[l][1]=-1;
                tab[l][2]=-1;
            }
            l+=1;
        }
        else
        {
            m='a';
        }
    }
    while(m!='a');
    for(a=0; a<l; a++)
    {
        if(tab[a][2]==-1 && tab[a][1]==-1)
        {
            printf("Nothing\n");
        }
        else if(tab[a][2]==-1)
        {
            printf("%d %d is glued\n",tab[a][0],tab[a][1]);
        }
        else
        {
            printf("%d %d is glued %d %d is glued\n",tab[a][0],tab[a][1],tab[a][2],tab[a][3]);
        }
    }
    return 0;
}
