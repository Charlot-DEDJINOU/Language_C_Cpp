#include<stdio.h>
void main()
{
    int n,s,i;
        scanf("%d",&n);
    for(i=100; i>=1; i/=10)
    {
        s=n%(i*10)/i;
        if(i==100)
        {
            switch(s)
            {
            case 1:
                printf("Cent-");
                break;
            case 2:
                printf("Deux cent-");
                break;
            case 3:
                printf("Trois cent-");
                break;
            case 4:
                printf("Quatres cent-");
                break;
            case 5:
                printf("Cinq cent-");
                break;
            case 6:
                printf("Six cent-");
                break;
            case 7:
                printf("Sept cent-");
                break;
            case 8:
                printf("Huit cent-");
                break;
            case 9:
                printf("Neuf cent-");
                break;
            }
        }
        if(i==10)
        {
            switch(s)
            {
            case 1:
                if(n%10<=6 && n%10!=0)
                {
                    if(n%10==1)
                        printf("Onze");
                    else if(n%10==2)
                        printf("Douze");
                    else if(n%10==3)
                        printf("Treize");
                    else if(n%10==4)
                        printf("Quatorze");
                    else if(n%10==5)
                        printf("Quinze");
                    else
                        printf("Seize");
                }
                else
                    printf("Dix-");
            break;
            case 2:
                printf("Vingt-");
                break;
            case 3:
                printf("Trente-");
                break;
            case 4:
                printf("Quarante-");
                break;
            case 5:
                printf("Cinqante-");
                break;
            case 6:
                printf("Soixante-");
                break;
            case 7:
                if(n%10<=6 && n%10!=0)
                {
                    if(n%10==1)
                        printf("Soixante Onze ");
                    else if(n%10==2)
                        printf("Soixante Douze ");
                    else if(n%10==3)
                        printf("Soixante Treize ");
                    else if(n%10==4)
                        printf("Soixante Quatorze ");
                    else if(n%10==5)
                        printf("Soixante Quinze ");
                    else
                        printf("Soixante Seize ");
                }
                else
                    printf("Soixante dix ");
            break;
            case 8:
                printf("Quatre vingts-");
                break;
            case 9:
                if(n%10<=6 && n%10!=0)
                {
                    if(n%10==1)
                        printf("Quatre vingts Onze ");
                    else if(n%10==2)
                        printf("Quatre vingts Douze ");
                    else if(n%10==3)
                        printf("Quatre vingts Treize ");
                    else if(n%10==4)
                        printf("Quatre vingts Quatorze ");
                    else if(n%10==5)
                        printf("Quatre vingts Quinze ");
                    else
                        printf("Quatre vingts Seize ");
                }
                else
                printf("Quatre vingts dix-");
            break;
            }
        }
        if(i==1)
        {
            if((n%100/10==1) ||(n%100/10==7) ||(n%100/10==9))
            {
                if(s>6)
                {
                    switch(s)
                    {
                    case 7:
                        printf("Sept");
                        break;
                    case 8:
                        printf("Huit");
                        break;
                    case 9:
                        printf("Neuf");
                        break;
                    }
                }
            }
            else
            {
                switch(s)
                {
                case 1:
                    printf("Un");
                    break;
                case 2:
                    printf("Deux");
                    break;
                case 3:
                    printf("Trois");
                    break;
                case 4:
                    printf("Quatre");
                    break;
                case 5:
                    printf("Cinq");
                    break;
                case 6:
                    printf("Six");
                    break;
                case 7:
                    printf("Sept");
                    break;
                case 8:
                    printf("Huit");
                    break;
                case 9:
                    printf("Neuf");
                    break;
                }
            }
        }
        s=0;
    }
}
