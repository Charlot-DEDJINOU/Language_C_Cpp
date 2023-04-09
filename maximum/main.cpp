#include <iostream>
#include <string>

using namespace std;

int solitaire(int n)
{
    int i,s=0;;
        for(i=1; n/i!=0; i*=10)
            s++ ;
    return s;
}

int main()
{
   int n,trouver=0;
   cin>>n ;
   int i=n ;
   while(trouver==0 && i!=0)
   {
   	if(i*solitaire(i)<=n){
   		cout<<i ;
   		trouver=1 ;
   	}
   	i-- ;
   }
   if(i==0){
   	cout<<"Pas trouver" ;
   }
}
