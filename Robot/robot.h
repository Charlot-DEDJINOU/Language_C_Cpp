#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED
#include <string>

using namespace std ;

class Robot
{
    public:
        //Construtor
    Robot(string nom="Charlot",char sex='M') ;
    Robot(Robot const& original) ;
       //accesseurs
    string get_name() const ;
    int get_choix() const ;
    int get_maximum() const ;
    int get_minimum() const ;
        //mutateur
    void initialisation_max(string niveau) ;
    void jouer() ;
    void set_min_max(bool etat);
   ~Robot() ;

    private:
    string name ;
    int tour=0 ;
    char sexe ;
    int minimum=0 ;
    int maximum ;
    int Size ;
    int choix ;
    int Choice() const ;
};

#endif // ROBOT_H_INCLUDED
