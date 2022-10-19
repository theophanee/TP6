#include "Graphe.hpp"
#include<iostream>
#include<string>

using namespace std;

Graphe::Graphe(Sommet *s, Arete *a){

    cout<< "Construction de " << *this ;
}

Graphe::Graphe(const Graphe &g) {
    sommets = g.sommets;
    aretes = g.aretes;
    cout << "Copie de "<< *this;
} 

ostream& operator<<( ostream& out , Graphe &g){
    out<<"Graphe : "<< *(g.getSommets()) <<endl <<*(g.getAretes());
    return out ;
}

Sommet* Graphe::getSommets(){ return sommets;}
Arete* Graphe::getAretes(){ return aretes;}

