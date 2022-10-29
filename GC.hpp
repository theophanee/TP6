#ifndef _GC
#define _GC
#include"Sommet.hpp"
#include"Arete.hpp"
#include<iostream>
#include<vector>

using namespace std;

class GC{
    public :
        static vector<Sommet*> gcSommets;
        static vector<Arete*> gcAretes;
        static void setGCS(Sommet *s);
        static void setGCA(Arete *a);
        static void affichage();
        static void libererMemoire();

};

ostream& operator <<(ostream& out, GC &g) ;

#endif
