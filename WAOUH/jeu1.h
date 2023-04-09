#ifndef JEU1_H_INCLUDED
#define JEU1_H_INCLUDED
void dessin(char tab[]);
void joueur(char tab[],char* o,int* tour);
void ordi(char tab[],int* tour,char* o);
void gagne(char tab[],char o,int* tour);
void verifie(char tab[],char o,int* b,int* v);
#endif // JEU1_H_INCLUDED
