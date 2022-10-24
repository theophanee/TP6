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
        vector<Sommet*> sommets;
        vector<Arete*> aretes;
    public:
        Graphe(vector<Sommet*> s,vector<Arete*> a);
        Graphe(const Graphe &g);
        void ajoute_sommet(Sommet *s);
        void ajoute_sommet(string e);
        void ajoute_arete(Arete *a);
        void ajoute_arete(Sommet *s1, Sommet *s2, int poids);
        void ajoute_arete(string e1, string e2, int p);
        int poids();
        int find(Arete *a);
        void symetrise();
        vector<Sommet*> getSommets();
        vector<Arete*> getAretes();
        Graphe* kruskal();
        
};

ostream& operator <<(ostream& out, Graphe &g) ;

#endif