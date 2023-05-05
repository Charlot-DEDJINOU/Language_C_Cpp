#include "Gestion.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

Gestion::Gestion(string chemin_fichier)
{

    cheminFichier=chemin_fichier ;
}

bool Gestion::charger_fichier()
{

    ifstream fichier(cheminFichier) ;
    string line ;

    data.clear() ;

    if(!fichier.is_open())
        return false ;

    while(getline(fichier,line))
        data.push_back(line) ;

    fichier.close() ;

    return true ;
}

vector <string> Gestion::get_profils() const
{
    vector <string> profils ;

    int i=0 ;
    while(i < data.size())
    {
        if(data[i] == "PFL:")
        {
            profils.push_back(data[i+1]) ;
            i+=3+std::stoi(data[i+2]) ;
        }
        else if(data[i] == "PRO:")
            i+=4+std::stoi(data[i+3]) ;
        else if(data[i] == "CPT:")
            i+=2+std::stoi(data[i+1]) ;
        else
            i++ ;
    }

    return profils ;
}

vector <string> Gestion::get_professionnels() const
{
    vector <string> profesionnels ;
    string tmp ;

    int i=0 ;
    while(i < data.size())
    {
        if(data[i] == "PRO:")
        {
            tmp=data[i+2] ;
            tmp[0]=' '  ;
            profesionnels.push_back(data[i+1]+tmp) ;
            i+=4+std::stoi(data[i+3]) ;
        }
        else if(data[i] == "PFL:")
            i+=3+std::stoi(data[i+2]) ;
        else if(data[i] == "CPT:")
            i+=2+std::stoi(data[i+1]) ;
        else
            i++ ;
    }

    return profesionnels ;

}

vector <string> Gestion::get_toutes_competences() const
{
    vector <string> all_competences ;
    int i = 0 ;
    while(i < data.size())
    {
        if(data[i] == "PFL:")
        {
            for(int j=3 ; j < stoi(data[i+2])+3 ; j++)
                all_competences.push_back(data[i+j]) ;

            i+=3+std::stoi(data[i+2]) ;
        }
        else if(data[i] == "PRO:")
        {
            for(int j=4 ; j< stoi(data[i+3])+4 ; j++)
                all_competences.push_back(data[i+j]) ;

            i+=4+std::stoi(data[i+3]) ;
        }
        else if(data[i] == "CPT:")
        {
            for(int j=2 ; j < stoi(data[i+1])+2 ; j++)
                all_competences.push_back(data[i+j]) ;

            i+=2+std::stoi(data[i+1]) ;
        }
        else
            i++ ;
    }

    return all_competences;

}

vector <string> Gestion::get_competences_profil(string nom_profil) const
{
    vector <string> competences_profil ;

    int i = 0 ;
    while(i < data.size())
    {
        if(data[i] == "PFL:")
        {
            if(data[i+1] == nom_profil)
            {
                for(int j=3 ; j < stoi(data[i+2])+3 ; j++)
                    competences_profil.push_back(data[i+j]) ;
                i=data.size() ;
            }
            else
                i+=3+std::stoi(data[i+2]) ;
        }
        else if(data[i] == "PRO:")
            i+=4+std::stoi(data[i+3]) ;
        else if(data[i] == "CPT:")
            i+=2+std::stoi(data[i+1]) ;
        else
            i++ ;
    }

    return competences_profil ;
}

vector <string> Gestion::get_competences_professionnel(string nom_professionnel) const
{
    vector <string> competences_professionnel ;
    string tmp;
    int i = 0 ;
    while(i < data.size())
    {
        if(data[i] == "PFL:")
            i+=3+std::stoi(data[i+2]) ;
        else if(data[i] == "PRO:")
        {
            tmp=data[i+2] ;
            tmp[0]=' ' ;
            tmp=data[i+1]+tmp ;
            if(nom_professionnel == tmp)
            {
                for(int j=4 ; j< stoi(data[i+3])+4 ; j++)
                    competences_professionnel.push_back(data[i+j]) ;
                i=data.size() ;
            }
            else
                i+=4+std::stoi(data[i+3]) ;
        }
        else if(data[i] == "CPT:")
            i+=2+std::stoi(data[i+1]) ;
        else
            i++ ;
    }
    return competences_professionnel ;
}

bool Gestion::set_profil(string nom_profil,string type_modifier,string competence)
{
    int i=0 ;
    string tmp ;
    while(i < data.size())
    {
        if(data[i] == "PFL:")
        {
            if(data[i+1] == nom_profil)
            {
                if(type_modifier == "ajouter")
                {
                    tmp=to_string(stoi(data[i+2])+1);
                    data[i+2]='\t'+tmp ;
                    data.insert((data.begin()+i+3),'\t'+competence) ;
                    return true ;
                }
                else
                {
                    for(int j=3 ; j < stoi(data[i+2])+3 ; j++)
                    {
                        if(data[i+j] == competence)
                        {
                            tmp=to_string(stoi(data[i+2])-1);
                            data[i+2]='\t'+tmp ;
                            data.erase(data.begin()+i+j) ;
                            return true ;
                        }
                    }
                }
                return false ;
            }
            else
                i+=3+std::stoi(data[i+2]) ;
        }
        else if(data[i] == "PRO:")
            i+=4+std::stoi(data[i+3]) ;
        else if(data[i] == "CPT:")
            i+=2+std::stoi(data[i+1]) ;
        else
            i++ ;
    }

}

bool Gestion::set_professionnel(string nom_professionnel,string type_modifier,string competence)
{
    int i=0 ;
    string tmp ;
    bool cond = false ;
    while(i < data.size())
    {
        if(data[i] == "PFL:")
            i+=3+std::stoi(data[i+2]) ;
        else if(data[i] == "PRO:")
        {
            tmp=data[i+2] ;
            tmp[0]=' ' ;
            tmp=data[i+1]+tmp ;

            if(tmp == nom_professionnel)
            {
                if(type_modifier == "ajouter")
                {
                    tmp=to_string(stoi(data[i+3])+1);
                    data[i+3]='\t'+tmp ;
                    data.insert((data.begin()+i+4),'\t'+competence) ;
                    return true ;
                }
                else
                {
                    for(int j=4 ; j < stoi(data[i+3])+4 ; j++)
                    {
                        if(data[i+j] == competence)
                        {
                            tmp=to_string(stoi(data[i+3])-1);
                            data[i+3]='\t'+tmp ;
                            data.erase(data.begin()+i+j) ;
                            cond = true ;
                            j-- ;
                        }
                    }
                }
                return cond ;
            }
            else
                i+=4+std::stoi(data[i+3]) ;
        }
        else if(data[i] == "CPT:")
            i+=2+std::stoi(data[i+1]) ;
        else
            i++ ;
    }

}

vector <string> Gestion::get_professionnel_et_profil(string nom_profil) const
{
    vector <string> professionnels = get_professionnels() ;
    vector <string> competences_profil = get_competences_profil(nom_profil) ;
    vector <string> professionnels_can_do ;
    for(string professionnel : professionnels)
    {
        if(competences_profil.size() == intersection(get_competences_professionnel(professionnel),competences_profil).size())
            professionnels_can_do.push_back(professionnel) ;
    }
    return professionnels_can_do ;
}

vector<string> Gestion::intersection(vector<string> v1,vector<string> v2) const
{
    vector<string> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
}

bool Gestion::sauvegarder_data(string chemin_fichier)
{
    ofstream fichier(chemin_fichier) ;
    if(!fichier.is_open())
        return false ;
    else
    {
        for(int i=0 ; i<data.size() ; i++)
            fichier<<data.at(i)<<endl ;

        fichier.close() ;
        return true ;
    }
}

int Gestion::get_size_data() const
{
    return data.size() ;
}

bool Gestion::set_chemin_fichier(string name)
{
    cheminFichier = name ;
    return true ;
}

Gestion::~Gestion() {}

void trier_et_afficher(vector <string> tableau)
{
    sort(tableau.begin(),tableau.end()) ;
    tableau.erase(std::unique(tableau.begin(),tableau.end()),tableau.end()) ;

    for(string element : tableau)
        cout<<element<<endl ;
}

void menu()
{
    Gestion fichier ;
    vector <string> menu_option ;
    ifstream menu("data/menu.txt") ;
    string line ;
    int choix;
    bool continuer = false ;

    cout<<"Bienvenue  sur CAT"<<endl ;

    if(!menu.is_open())
        cout<<"Impossible d'afficher le menu" ;
    else
    {
        while(getline(menu,line))
            menu_option.push_back(line) ;
        menu.close() ;
    }

    do
    {
        cout<<endl ;
        for(string & option : menu_option)
            cout<<option<<endl;

        cin>>choix ;
        while(choix < 1 || choix > 14)
        {
            cout<<"Chef plan !!!"<<endl ;
            cin>>choix ;
        }
        continuer=gestion_menu(choix,fichier) ;
    }
    while(continuer == true) ;
}

bool gestion_menu(int choix,Gestion & f)
{
    int param ;
    bool condition ;
    vector <string> names ;
    string name,competence;

    if(choix == 1 && f.get_size_data() == 0)
    {
        dont_repeat_me(f) ;
        return true ;
    }
    else if(choix == 1 && f.get_size_data() != 0)
    {
        cout<<"Un autre fichier est charge en memoire.Voulez vous l'ecrasez ???"<<endl<<"\t1-Oui"<<endl<<"\t2-Non"<<endl ;
        cin>>param ;
        while(param != 1 && param != 2)
        {
            cout<<"Chef plan !!!"<<endl ;
            cin>>param ;
        }
        if(param == 1)
            dont_repeat_me(f) ;
        else
            cout<<endl<<"Voila tu avais pris de l'eau en poudre"<<endl ;
        return true ;
    }
    if(f.get_size_data() == 0 && choix != 1 && choix != 13)
    {
        cout<<"Aucun fichier n'est charge en memoire"<<endl ;
        dont_repeat_me(f) ;
        return true ;
    }
    switch(choix)
    {
    case 2 :
        names=f.get_profils() ;
        cout<<"A quel profil vous voulez ajouter de competence ??? " <<endl ;
        name=help_me(names) ;
        name[0]=' ' ;
        cout<<"Quelle competence voulez vous ajouter au profil "<<name<<" : " ;
        cin>>competence ;
        name[0]='\t' ;
        condition = f.set_profil(name,"ajouter",competence);
        if(condition == true)
            cout<<endl<<"Competence ajouter avec succes !!!"<<endl ;
        else
            cout<<endl<<"Une eureur s'est produite lors de l'ajout !!!"<<endl ;
        return true ;
        break ;
    case 3 :
        names=f.get_profils() ;
        cout<<"A quel profil vous voulez retirer de competence ??? " <<endl ;
        name=help_me(names) ;
        name[0]=' ' ;
        cout<<"Quelle competence voulez vous retirer au profil (Veuillez le donner en un mot svp) "<<name<<" : " <<endl;
        name[0]='\t' ;
        names=f.get_competences_profil(name) ;
        competence=help_me(names) ;
        competence[0]='\t' ;
        condition = f.set_profil(name,"retirer",competence);
        if(condition == true)
            cout<<endl<<"Competence retirer avec succes !!!"<<endl<<endl ;
        else
            cout<<endl<<"Une eureur s'est produite lors de la suppression!!!"<<endl<<endl ;
        return true ;
        break ;
    case 4 :
        names=f.get_professionnels() ;
        cout<<"A quel profesionnel vous voulez ajouter de competence ??? " <<endl ;
        name=help_me(names) ;
        name[0]=' ' ;
        cout<<"Quelle competence voulez vous ajouter a (Veuillez le donner en un mot svp)"<<name<<" : " ;
        cin>>competence ;
        name[0]='\t' ;
        condition = f.set_professionnel(name,"ajouter",competence);
        if(condition == true)
            cout<<endl<<"Competence ajouter avec succes !!!"<<endl ;
        else
            cout<<endl<<"Une eureur s'est produite lors de l'ajout !!!"<<endl ;
        return true ;
        break ;
    case 5 :
        names=f.get_professionnels() ;
        cout<<"A quel profesionnel vous voulez retirer de competence ??? " <<endl ;
        name=help_me(names) ;
        name[0]=' ' ;
        cout<<"Quelle competence voulez vous retirer a "<<name<<" : " <<endl;
        name[0]='\t' ;
        names=f.get_competences_professionnel(name) ;
        competence=help_me(names) ;
        competence[0]='\t' ;
        cout<<competence ;
        condition = f.set_professionnel(name,"retirer",competence);
        if(condition == true)
            cout<<endl<<"Competence retirer avec succes !!!"<<endl<<endl ;
        else
            cout<<endl<<"Une eureur s'est produite lors de la suppression!!!"<<endl<<endl ;
        return true ;
        break ;
    case 6 :
        cout<<endl<<"Les competences du fichier sont :"<<endl ;
        trier_et_afficher(f.get_toutes_competences()) ;
        cout<<endl ;
        return true ;
        break ;
    case 7 :
        cout<<endl<<"Les profils du fichier sont :"<<endl ;
        trier_et_afficher(f.get_profils()) ;
        cout<<endl ;
        return true ;
        break ;
    case 8 :
        cout<<endl<<"Les professionnels du fichier sont :"<<endl ;
        trier_et_afficher(f.get_professionnels()) ;
        cout<<endl ;
        return true ;
        break ;
    case 9 :
        names=f.get_profils() ;
        cout<<"Quel profil vous voulez les competence ??? " <<endl ;
        name=help_me(names) ;
        name[0]=' ' ;
        cout<<"Les competences du profil "<<name<<" : "<<endl ;
        name[0]='\t' ;
        trier_et_afficher(f.get_competences_profil(name)) ;
        cout<<endl ;
        return true ;
        break ;
    case 10 :
        names=f.get_professionnels() ;
        cout<<"Quel professionnel vous voulez les competence ??? " <<endl ;
        name=help_me(names) ;
        name[0]=' ' ;
        cout<<"Les competences du professionnel "<<name<<" : "<<endl ;
        name[0]='\t' ;
        trier_et_afficher(f.get_competences_professionnel(name)) ;
        cout<<endl ;
        return true ;
        break ;
    case 11 :
        names=f.get_profils() ;
        cout<<"Quel profil dont vous voulez conaitre les profesionnel qui correspond  ??? " <<endl ;
        name=help_me(names) ;
        name[0]='\t' ;
        if(f.get_professionnel_et_profil(name).size() == 0)
            cout<<"Pas de professionnel ayant cet profil" <<endl ;
        else
        {
            name[0]=' ' ;
            cout<<"Les professionnels ayant le profil  "<<name<<" : "<<endl ;
            name[0]='\t' ;
            trier_et_afficher(f.get_professionnel_et_profil(name)) ;
            cout<<endl ;
        }
        return true ;
        break ;
    case 12 :
        cout<<"Sauvegarde en cours ..."<<endl ;
        cout<<"Sauvegarde termine"<<endl ;
        f.sauvegarder_data() ;
        return true ;
        break ;
    case 13 :
        cout<<"Merci d'avoir utiliser CAT pour la gestion"<<endl ;
        return false ;
        break ;
    }
    return false ;
}

void dont_repeat_me(Gestion & f)
{
    int param ;
    bool condition ;
    string name ;

    cout<<"Donner le chemin vers le fichier ou prenons celui par defaut data/sample.cpt ? "<<endl<<"\t1-Oui"<<endl<<"\t2-Non"<<endl ;
    cin>>param ;
    while(param != 1 && param != 2)
    {
        cout<<"Chef plan !!!"<<endl ;
        cin>>param ;
    }
    if(param == 1)
    {
        f.set_chemin_fichier("data/sample.cpt") ;
        condition = f.charger_fichier() ;
    }
    else
    {
        cout<<"Donner le chemin de votre fichier donc : " ;
        cin>>name ;
        f.set_chemin_fichier(name) ;
        condition = f.charger_fichier() ;
        cout<<endl ;
    }
    if(condition == false)
        cout<<"Impossible de charger le fichier.veillez ressayer !!!"<<endl ;
    else
        cout<<"Fichier charger avec succes"<<endl ;
}

string help_me(vector <string> v1)
{
    int number ;

    do
    {
        for(int i=0 ; i< v1.size() ; i++)
        {
            v1[i][0]=' ' ;
            cout<<"\t"<<i+1<<"-"<<v1[i]<<endl ;
        }
        cin>>number ;
    }
    while(number < 1 || number > v1.size()) ;

    return v1[number-1] ;
}

