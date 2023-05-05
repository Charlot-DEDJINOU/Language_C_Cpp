#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED
#include <string>
#include <vector>

using namespace std ;

class Gestion {

    public :
        Gestion(string chemin_fichier="data/sample.cpt") ; // accomplir
        bool charger_fichier() ; // accomplir
        bool set_profil(string nom_profil,string type_modifier,string competence) ; //accomplir
        bool set_professionnel(string nom_professionnel,string type_modifier,string competence) ; // accomplir
        bool set_chemin_fichier(string name) ;//accomplir
        vector <string> get_toutes_competences() const ; //accomplir
        vector <string> get_competences_profil(string nom_profil) const ; //accomplir
        vector <string> get_competences_professionnel(string nom_professionnel) const ; //accomplir
        vector <string> get_profils() const ; // accomplir
        vector <string> get_professionnels() const; //accomplir
        vector <string> get_professionnel_et_profil(string nom_profil) const ; //accomplir
        int get_size_data() const ;//accomplir
        bool sauvegarder_data(string chemin_fichier="data/sample.cpt") ;//accomplir
       ~Gestion() ; //accomplir
    private :
        string cheminFichier ;
        vector <string> data ;
        vector<string> intersection(vector<string> v1,vector<string> v2) const ;
};

void trier_et_afficher(vector <string> tableau) ; //accomplir
void menu() ; //accomplir
bool gestion_menu(int choix,Gestion & f) ; //accomplir
void dont_repeat_me(Gestion & f) ; //accomplir
string help_me(vector <string> v1) ; //accomplir
#endif // GESTION_H_INCLUDED
