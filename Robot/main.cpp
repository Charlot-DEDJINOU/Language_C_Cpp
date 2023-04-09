#include <iostream>
#include "robot.h"
#include <ctime>
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int i=0;
    Robot robot("Espoir",'M') ;
    int choix;
    do
    {
       cout<<"Entrez le nombre a deviner unh compris entre 0 et 10000: " ;
       cin>>choix ;
    }
    while(choix<0 || choix>10000) ;

    if(choix>0 && choix<=100)
       robot.initialisation_max("facile") ;
    else if(choix>101 && choix<=1000)
       robot.initialisation_max("moyen") ;
    else
       robot.initialisation_max("dificile") ;

    cout<<"Charlot:A toi de jouer"<<endl ;
    do
    {
        robot.jouer() ;
        cout<<robot.get_name()<<" :"<<robot.get_choix()<<endl ;
         usleep(1000000);
        if(choix < robot.get_choix()){
            cout<<"Charlot : C'est moins"<<endl ;
            robot.set_min_max(false) ;
        }else if(choix > robot.get_choix()){
            cout<<"Charlot : C'est plus"<<endl ;
            robot.set_min_max(true) ;
        }else{
            cout<<"Charlot : Youpi"<<endl ;
        }
    }while(choix!=robot.get_choix()) ;
    return 0;
}
