#ifndef _GRAPHE
#define _GRAPHE
#include"Sommet.hpp"
#include"Arete.hpp"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Graphe{
    private:
        vector<Sommet> sommets;
        vector<Arete> aretes;
    public:
        Graphe(vector<Sommet> s,vector<Arete> a);
        Graphe(const Graphe &g);
        void ajoute_sommet(Sommet *s);
        void ajoute_arete(Arete *a);
        int poids();
        void symetrie();
        vector<Sommet> getSommets();
        vector<Arete> getAretes();
        //kruskal();
        
};

ostream& operator <<(ostream& out, Graphe &g) ;

#endif