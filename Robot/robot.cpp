#include "robot.h"
#include <string>
#include <unistd.h>
#include <array>

using namespace std ;

Robot::Robot(string nom,char sex)
{
    name=nom ;
    sexe=sex ;
}
Robot::Robot(Robot const& original) :
    name(original.name),
    sexe(original.sexe)
{
}
string Robot::get_name() const
{
    return name ;
}
int Robot::get_choix() const
{
    return choix;
}
int Robot::get_maximum() const
{
    return maximum ;
}
int Robot::get_minimum() const
{
    return minimum ;
}

void Robot::initialisation_max(string niveau)
{
    if(niveau=="facile")
        maximum=Size=100 ;
    if(niveau=="moyen")
        maximum=Size=1000 ;
    if(niveau=="dificile")
        maximum=Size=10000 ;
}
int Robot::Choice() const
{
    int nombre_precedent(0),nombre_actuel(0),choice,somme=0 ;
    int tab[Size];
    for(int i(0); i<Size; i++)
        tab[i]=(rand() % (maximum-minimum+1))+minimum ;
    choice=tab[0] ;
    for(int i(0); i<Size; i++)
    {
        for(int j=i; j<Size; j++)
        {
            if(tab[i]==tab[j])
                nombre_actuel++ ;
        }
        if(nombre_actuel>nombre_precedent)
        {
            choice=tab[i] ;
            nombre_precedent=nombre_actuel ;
        }
        somme+=tab[i] ;
    }
    return maximum-minimum<=10 ? choice : somme/Size ;
}
void Robot::jouer()
{
    if(tour%5==0)
        choix=(rand() % (maximum-minimum+1))+minimum ;
    else
        choix=Choice();
    usleep(20000);
    tour ++ ;
}
void Robot::set_min_max(bool etat)
{
    if(etat==true)
        minimum=choix+1 ;
    else
        maximum=choix-1 ;
}
Robot::~Robot() {}
