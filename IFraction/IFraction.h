#ifndef IFRACTION_H_INCLUDED
#define IFRACTION_H_INCLUDED
#include <string>

using namespace std ;

class IFraction{
    public :
     IFraction(int s,int a,int b) ;
     void impure() ;
     string afficher() const ;
     ~IFraction() ;
    private :
     int num ;
     int dem ;
     int add ;
     void sign() ;
     int PGCD(int a,int b) ;
} ;

#endif // IFRACTION_H_INCLUDED
