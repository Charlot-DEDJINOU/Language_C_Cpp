#include "IFraction.h"
#include <iostream>
#include <cmath>

IFraction::IFraction(int s,int a,int b)
{
    add=s ;
    num=a ;
    if(b==0)
        dem=1 ;
    else
        dem=b ;
}
void IFraction::impure()
{
    int ajout=0 ,tmp;
    if(abs(num)>abs(dem))
    {
        ajout=num/dem ;
        num=num%dem ;
    }
    if(num!=0)
    {
        tmp=dem ;
        dem=dem/PGCD(dem,num) ;
        num=num/PGCD(tmp,num) ;
    }
    add+=ajout ;
    sign() ;
}
int IFraction::PGCD(int a,int b){
    if(b==0)
        return a;
    else
        return PGCD(b,a%b) ;
}
void IFraction::sign()
{
        if(num*dem<0)
            num=-1*abs(num) ;
        else
            num=abs(num) ;
    dem=abs(dem) ;
}
string IFraction::afficher() const
{
    string res="" ;
        if(num==0)
            res+=to_string(add) ;
        else
        {
            add!=0 ? res+=to_string(add) : res+="" ;
            if(add==0)
                num<0 ? res+="-" : res+="" ;
            else
                num<0 ? res+=" - " : res+=" + " ;
            res+=to_string(abs(num))+"/"+to_string(dem) ;
        }
        return res ;
}
IFraction::~IFraction(){}

