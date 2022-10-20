#include "Graphe.hpp"
#include<iostream>
#include<string>

using namespace std;

Graphe::Graphe(vector<Sommet> s, vector<Arete> a) : sommets{s}, aretes{a}{
    
    cout<< "Construction de " << *this ;
}

Graphe::Graphe(const Graphe &g) {
    sommets = g.sommets;
    aretes = g.aretes;
    cout << "Copie de "<< *this;
} 

ostream& operator<<( ostream& out , Graphe &g){
    out << "Graphe : " <<endl;
    out << "Sommets : "<< endl;
    for(unsigned int i = 0; i < g.getSommets().size(); i++)
        out<< "    " << g.getSommets()[i] ;
    out << "Aretes : " <<endl;
    for(unsigned int i = 0; i < g.getAretes().size(); i++)
        out<< "    " << g.getAretes()[i] ;
    return out ;
}

void Graphe::ajoute_sommet(Sommet *s){
    sommets.push_back(*s);
}

void Graphe::ajoute_sommet(string e){
    sommets.push_back(*(new Sommet{e}));
}

void Graphe::ajoute_arete(Arete *a){
    aretes.push_back(*a);
}

void Graphe::ajoute_arete(Sommet *s1, Sommet *s2, int p){
    Arete *a = new Arete(*s1 , *s2 , p);
    aretes.push_back(*a);
}

void Graphe::ajoute_arete(string e1, string e2, int p){
    Arete *a = new Arete( *(new Sommet{e1}) , *(new Sommet{e2}) , p);
    aretes.push_back(*a);
}

int Graphe::poids(){
    int p=0 ;
    for(unsigned int i = 0; i < aretes.size() ; i++)
        p += aretes[i].getPoids();
    return p;
}


vector<Sommet> Graphe::getSommets(){ return sommets;}
vector<Arete> Graphe::getAretes(){ return aretes;}

