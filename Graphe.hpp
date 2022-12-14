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
        virtual ~Graphe();
        void ajoute_sommet(Sommet *s);
        void ajoute_sommet(string e);
        void ajoute_arete(Arete *a);
        void ajoute_arete(Sommet *s1, Sommet *s2, int poids);
        void ajoute_arete(string e1, string e2, int p);
        int poids();
        int findArete(Arete *a);
        void symetrise();
        void creerEnsemble(Sommet &v, int val);
        int find(Sommet &v);
        void uni(Sommet &u, Sommet &v);
        void setAretes(vector<Arete*> a);
        vector<Sommet*> getSommets();
        vector<Arete*> getAretes();
        vector<Arete*> kruskal();

        
};

ostream& operator <<(ostream& out, Graphe &g) ;

#endif