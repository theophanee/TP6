#ifndef _ARETE
#define _ARETE
#include"Sommet.hpp"
#include<iostream>
#include<string>

using namespace std;

class Arete{
    private:
        // const pour ne plus pouvoir les changer
        Sommet *const gauche ;
        Sommet *const droite ;
        int poids;
    public:
        Arete(string etiquette1, string etiquette2, int p);
        Arete(const Arete &a);
        Arete(Sommet *g, Sommet *d, int p);
        //virtual ~Arete();
        Sommet* getGauche();
        Sommet* getDroite();
        int getPoids();
        void setPoids(int p);
        
};

ostream& operator <<(ostream& out, Arete &a) ;

#endif