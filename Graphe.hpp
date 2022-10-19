#ifndef _GRAPHE
#define _GRAPHE
#include"Sommet.hpp"
#include"Arete.hpp"
#include<iostream>
#include<string>

using namespace std;

class Graphe{
    private:
        Sommet *sommets;
        Arete *aretes;
    public:
        Graphe(Sommet *s, Arete *a);
        Graphe(const Graphe &g);
        void ajoute_sommet(Sommet s);
        void ajoute_arete(Arete a);
        int poids();
        void symetrie();
        Sommet* getSommets();
        Arete* getAretes();
        //kruskal();
        
};

ostream& operator <<(ostream& out, Graphe &g) ;

#endif