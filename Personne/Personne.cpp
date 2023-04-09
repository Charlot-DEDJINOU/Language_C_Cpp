#include "Personne.h"

Personne::Personne(string name,string date,bool etat,char sex,double tail)
{
    nom=name ;
    dateNaissance=date ;
    estMalade=etat ;
    sexe=sex ;
    taille=tail ;
}
Personne::Personne(Personne const& originale)
{
    nom=originale.nom ;
    dateNaissance=originale.dateNaissance ;
    estMalade=originale.estMalade ;
    sexe=originale.sexe;
    taille=originale.taille ;
}
string Personne::get_nom() const
{
    return nom ;
}
string Personne::get_dateNaissance() const
{
    return dateNaissance ;
}
bool Personne::get_estMalade() const
{
    return estMalade ;
}
char Personne::get_sexe() const
{
    return sexe ;
}
double Personne::get_taille() const
{
    return taille ;
}
bool Personne::set_nom(string nouveauNom)
{
    nom=nouveauNom ;
}
bool Personne::set_dateNaissance(string nouveauDateNaissance)
{
    dateNaissance=nouveauDateNaissance ;
}
bool Personne::set_estMalade(bool nouveauetat)
{
    estMalade=nouveauetat ;
}
bool Personne::set_sexe(char nouveauSexe)
{
    sexe=nouveauSexe ;
}
bool Personne::set_taille(double nouveauTaille)
{
    taille=nouveauTaille ;
}
Personne::~Personne(){}
