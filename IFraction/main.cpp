#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "IFraction.h"

using namespace std ;

int main()
{
    int numerateur,denominateur,addition(0) ;
    std::istringstream isstream ;
    vector<string> words ;
    string word, entrez ;
    getline(cin,entrez)  ;
    isstream.str(entrez) ;
    while(getline(isstream,word,' '))
        words.push_back(word) ;
    if(words.size()>0 && words.size()<=3)
    {
        if(words.size()==1)
        {
            numerateur=std::stof(words[0])*10000 ;
            denominateur=10000 ;
        }
        else if(words.size()==2)
        {
            numerateur=std::stoi(words[0]) ;
            denominateur=std::stoi(words[1]) ;
        }
        else if(words.size()==3)
        {
            addition=std::stoi(words[0]) ;
            numerateur=std::stoi(words[1]) ;
            denominateur=std::stoi(words[2]) ;
        }
        IFraction fraction(addition,numerateur,denominateur) ;
        fraction.impure() ;
        cout<<fraction.afficher() ;
    }
    else
        cout<<"Plan ?????" ;
    return 0;
}
