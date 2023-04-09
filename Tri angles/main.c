#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
    float a,b,c;
        scanf("%f %f %f",&a,&b,&c);
    if((a>=b && b>=c) || (a>=c && c>=b))
    {
        if(a>b+c)
            printf("NONE");
        else
        {
            if(a>=b && b>=c)
                printf("\n %.3f %.3f %.3f",acos(-1*((c*c-(a*a+b*b))/(2*a*b))),acos(-1*((b*b-(a*a+c*c))/(2*a*c))),acos(-1*((a*a-(b*b+c*c))/(2*b*c))));
            else
                printf("\n %.3f %.3f %.3f",acos(-1*((b*b-(a*a+c*c))/(2*a*c))),acos(-1*((c*c-(a*a+b*b))/(2*a*b))),acos(-1*((a*a-(b*b+c*c))/(2*b*c))));
        }
    }
    else if((b>=a && a>=c) || (b>=c && c>=a))
    {
        if(b>a+c)
            printf("NONE");
        else
        {
            if(b>=a && a>=c)
                printf("\n %.3f %.3f %.3f",acos(-1*((c*c-(a*a+b*b))/(2*a*b))),acos(-1*((a*a-(b*b+c*c))/(2*b*c))),acos(-1*((b*b-(a*a+c*c))/(2*a*c))));
            else
                printf("\n %.3f %.3f %.3f",acos(-1*((a*a-(b*b+c*c))/(2*b*c))),acos(-1*((c*c-(a*a+b*b))/(2*a*b))),acos(-1*((b*b-(a*a+c*c))/(2*a*c))));
        }
    }
    else
    {
        if(c>a+b)
            printf("NONE");
        else
        {
            if(c>=a && a>=b)
                printf("\n %.3f %.3f %.3f",acos(-1*((b*b-(a*a+c*c))/(2*a*c))),acos(-1*((a*a-(b*b+c*c))/(2*b*c))),acos(-1*((c*c-(a*a+b*b))/(2*a*b))));
            else
                printf("\n %.3f %.3f %.3f",acos(-1*((a*a-(b*b+c*c))/(2*b*c))),acos(-1*((b*b-(a*a+c*c))/(2*a*c))),acos(-1*((c*c-(a*a+b*b))/(2*a*b))));
        }
    }
}
