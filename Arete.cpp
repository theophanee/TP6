#include "Arete.hpp"
#include "GC.hpp"
#include<iostream>
#include<string>

using namespace std;

Arete::Arete(string etiquette1, string etiquette2, int p) : gauche{new Sommet{etiquette1}}, droite{new Sommet{etiquette2}}, poids{p} {
    cout << "Construction de " << *this;
    GC::setGCA(this);
}

Arete::Arete(const Arete &a) : poids{a.poids} {
    gauche = a.gauche;
    droite = a.droite;
    cout << "Copie de "<< *this<<endl;
    GC::setGCA(this);
}

Arete::Arete(Sommet *g, Sommet *d, int p) : poids{p} {
    gauche = g;
    droite = d;
    cout << "Construction de " << *this ;
    GC::setGCA(this);

}
/*
Arete::~Arete(){
    cout<<"Destruction de l'arete "<< *this;
}*/

Sommet* Arete::getDroite(){ return droite ;}
Sommet* Arete::getGauche() { return  gauche; }
int Arete::getPoids(){ return poids; }  
void Arete::setPoids(int p){ poids = p ;}

ostream& operator<<( ostream& out , Arete &a){
    out<<"Arete("<< a.getPoids() <<"):\nGauche-> "<< *(a.getGauche())<< "Droite-> " << *(a.getDroite()) <<endl ;
    return out ;
}

