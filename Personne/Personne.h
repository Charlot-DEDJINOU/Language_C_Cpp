#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <string>


using namespace std ;

class Personne
{
public :

    Personne(string name="Charlot",string date="17 Juillet 2003",bool etat=false,char sex='M',double tail=1.70) ;
    Personne(Personne const& originale) ;
    //accesseurs
    string get_nom() const ;
    string get_dateNaissance() const ;
    bool get_estMalade() const ;
    char get_sexe() const ;
    double get_taille() const ;
    //mutateurs
    bool set_nom(string nouveauNom) ;
    bool set_dateNaissance(string nouveauDateNaissance) ;
    bool set_estMalade(bool nouveauetat) ;
    bool set_sexe(char nouveauSexe) ;
    bool set_taille(double nouveauTaille) ;
    ~Personne() ;

private :
    string nom ;
    string dateNaissance ;
    bool estMalade ;
    char sexe ;
    double taille ;
};

#endif // PERSONNE_H_INCLUDED
