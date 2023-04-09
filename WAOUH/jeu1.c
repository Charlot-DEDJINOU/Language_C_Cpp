void dessin(char tab[])
{
    int i,j;
    for(i=0; i<25; i++)
    {
        for(j=0; j<25; j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                    printf("\t\t%c ",tab[0]);
                }
                else if(j==12)
                {
                    printf("%c ",tab[1]);
                }
                else if(j==24)
                {
                    printf("%c",tab[2]);
                }
                else
                {
                    printf("* ");
                }
            }
            else if(i==12)
            {
                if(j==0)
                {
                    printf("\t\t%c ",tab[3]);
                }
                else if(j==12)
                {
                    printf("%c ",tab[4]);
                }
                else if(j==24)
                {
                    printf("%c",tab[5]);
                }
                else
                {
                    printf("* ");
                }
            }
            else if(i==24)
            {
                if(j==0)
                {
                    printf("\t\t%c ",tab[6]);
                }
                else if(j==12)
                {
                    printf("%c ",tab[7]);
                }
                else if(j==24)
                {
                    printf("%c",tab[8]);
                }
                else
                {
                    printf("* ");
                }
            }
            else
            {
                if(j==0)
                {
                    printf("\t\t* ");
                }
                else if(j==24-i || i==j|| j==24 || j==12)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
}

void joueur(char tab[],char* o,int* tour)
{
    int a,b;
    char c;
    do
    {
        printf("\nEntrez les coordonnees presentes du point et celles de destinations ");
        scanf("%d%d",&a,&b);
        a=a-1;
        b=b-1;
    }
    while(a==b || (abs(a-b)==2 && (b!=4 && a!=4)) || (abs(b-a)==4 && (b!=4 && a!=4)) || (a<=2 && b>=6) || (b<=2 && a>=6) || abs(a-b)==5 || (a%3==0 && (b==2 || b==5 || b==8)) ||  (b%3==0 && (a==2 || a==5 || a==8)) || tab[b]!=' ' || tab[a]!=*o);
    c=tab[a];
    tab[a]=tab[b];
    tab[b]=c;
    a=gagne(tab,*o,tour);
}

void ordi(char tab[],int* tour,char* o)
{
    int a,b,choix,v;
    char c;

    verifie(tab,'O',&b,&v);
    if(v==1)
    {
        v=0;
        for(a=0; a<9; a++)
        {
            if(tab[a]=='O')
            {
                if(!(a==b || a==4 || (abs(a-b)==2 && (b!=4 && a!=4)) || (abs(b-a)==4 &&(b!=4 && a!=4)) || (a<=2 && b>=6) || (b<=2 && a>=6) || abs(a-b)==5 || (a%3==0 && (b==2 || b==5 || b==8)) ||  (b%3==0 && (a==2 || a==5 || a==8)) || tab[b]!=' ' || tab[a]!='O'))
                {
                    c=tab[a];
                    tab[a]=tab[b];
                    tab[b]=c;
                    a=9;
                    v=2;
                }
            }
        }
    }
    if(v==0)
    {
        do
        {
            a=(rand() % 9)+0;
            b=(rand() % 9)+0;
        }
        while(a==b || (abs(a-b)==2 && (b!=4 && a!=4)) || (abs(b-a)==4 &&(b!=4 && a!=4)) || (a<=2 && b>=6) || (b<=2 && a>=6) || abs(a-b)==5 || (a%3==0 && (b==2 || b==5 || b==8)) ||  (b%3==0 && (a==2 || a==5 || a==8)) || tab[b]!=' ' || tab[a]!='O');
        c=tab[a];
        tab[a]=tab[b];
        tab[b]=c;
    }
    sleep(2);
    a=gagne(tab,'O',tour);
}

void gagne(char tab[],char o,int* tour)
{
    if(o=='O')
    {
        if((tab[0]==o && tab[4]==o && tab[8]==o) || (tab[2]==o && tab[4]==o && tab[6]==o) || (tab[0]==o && tab[3]==o && tab[7]==o) || (tab[2]==o && tab[5]==o && tab[8]==o )|| (tab[3]==o && tab[4]==o && tab[5]==o) || (tab[0]==o && tab[1]==o && tab[2]==o) || (tab[1]==o && tab[4]==o && tab[7]==o))
        {
            *tour=-1;
        }
        else
        {
            *tour=1;
        }
    }
    else
    {
        if((tab[0]==o && tab[4]==o && tab[8]==o) || (tab[2]==o && tab[4]==o && tab[6]==o) || (tab[0]==o && tab[3]==o && tab[7]==o) || (tab[2]==o && tab[5]==o && tab[8]==o )|| (tab[3]==o && tab[4]==o && tab[5]==o) || (tab[6]==o && tab[7]==o && tab[8]==o) || (tab[1]==o && tab[4]==o && tab[7]==o))
        {
            *tour=-2;
        }
        else
        {
            *tour=0;
        }
    }
}

void verifie(char tab[],char o,int* b,int* v)
{
    int h;
    if(o=='O')
    {
        if((tab[0]==o && tab[4]==o) || (tab[4]==o && tab[8]==o) || (tab[8]==o && tab[0]==o))
        {
            for(h=0; h<9; h++)
            {
                if(h%4==0 && tab[h]==' ')
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[2]==o && tab[4]==o) || (tab[6]==o && tab[4]==o) || (tab[2]==o && tab[6]==o))
        {
            for(h=2; h<7; h++)
            {
                if(h%2==0 && tab[h]==' ')
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[0]==o && tab[3]==o) || (tab[3]==o && tab[6]==o) || (tab[0]==o && tab[6]==o))
        {
            for(h=0,(h%3==0 || h==0),tab[h]==' '; h<7; h++)
            {
                *b=h;
            }
            *v=1;
        }
        else if((tab[2]==o && tab[5]==o) || (tab[8]==o && tab[5]==o) || (tab[2]==o && tab[8]==o))
        {
            for(h=2; h<9; h+=3)
            {
                if(tab[h]==' ')
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[3]==o && tab[4]==o) || (tab[3]==o && tab[5]==o) || (tab[5]==o && tab[4]==o))
        {
            for(h=3; h<6; h++)
            {
                if(tab[h]==' ')
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[0]==o && tab[1]==o) || (tab[2]==o && tab[0]==o) || (tab[1]==o && tab[2]==o))
        {
            for(h=0; h<3; h++)
            {
                if(tab[h]==' ')
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[1]==o && tab[4]==o) || (tab[1]==o && tab[7]==o) || (tab[7]==o && tab[4]==o))
        {
            for(h=1; h<8; h+=3)
            {
                if(tab[h]==' ')
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else
        {
            *v=0;
        }
    }
    else
    {
        if((tab[0]==o && tab[4]==o) || (tab[4]==o && tab[8]==o) || (tab[8]==o && tab[0]==o))
        {
            for(h=0,h%4==0,tab[h]!=o; h<9; h++)
            {
                if(h%4==0 && tab[h]!=o)
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[2]==o && tab[4]==o) || (tab[6]==o && tab[4]==o) || (tab[2]==o && tab[6]==o))
        {
            for(h=2,h%2==0,tab[h]!=o; h<7; h++)
            {
                if(h%2==0 && tab[h]!=o)
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[0]==o && tab[3]==o) || (tab[3]==o && tab[6]==o) || (tab[0]==o && tab[6]==o))
        {
            for(h=0; h<7; h++)
            {
                if(h%3==0 && tab[h]!=o)
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[2]==o && tab[5]==o) || (tab[8]==o && tab[5]==o) || (tab[2]==o && tab[8]==o))
        {
            for(h=2; h<9; h+=3)
            {
                if(tab[h]!=o)
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[3]==o && tab[4]==o) || (tab[3]==o && tab[5]==o) || (tab[5]==o && tab[4]==o))
        {
            for(h=3; h<6; h++)
            {
                if(tab[h]!=o)
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[6]==o && tab[7]==o) || (tab[8]==o && tab[6]==o) || (tab[7]==o && tab[8]==o))
        {
            for(h=6; h<9; h++)
            {
                if(tab[h]!=o)
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else if((tab[1]==o && tab[4]==o) || (tab[7]==o && tab[1]==o) || (tab[7]==o && tab[4]==o))
        {
            for(h=1; h<8; h+=3)
            {
                if(tab[h]!=o)
                {
                    *b=h;
                }
            }
            *v=1;
        }
        else
        {
            *v=0;
        }
    }
}



