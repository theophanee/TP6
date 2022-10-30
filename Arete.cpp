#include "Arete.hpp"
#include "GC.hpp"
#include<iostream>
#include<string>

using namespace std;

// construit Arete
Arete::Arete(string etiquette1, string etiquette2, int p) : gauche{new Sommet{etiquette1}}, droite{new Sommet{etiquette2}}, poids{p} {
    cout << "Construction de " << *this;
    // ajoute au GC puisque 2 new
    GC::setGCS(gauche);
    GC::setGCS(droite);

}

// constructeur par copie
Arete::Arete(const Arete &a) : gauche{a.gauche}, droite{a.droite}, poids{a.poids} {
    cout << "Copie de "<< *this<<endl;
    GC::setGCA(this);
}

Arete::Arete(Sommet *g, Sommet *d, int p) : gauche{g}, droite{d}, poids{p} {
    cout << "Construction de " << *this ;
    GC::setGCA(this);

}
/*
Arete::~Arete(){
    delete gauche;
    delete droite;
    cout<<"Destruction de l'arete "<< *this;
}
*/

// getters
Sommet* Arete::getDroite(){ return droite ;}
Sommet* Arete::getGauche() { return  gauche; }
int Arete::getPoids(){ return poids; }  

// setter du poids
void Arete::setPoids(int p){ poids = p ;}


ostream& operator<<( ostream& out , Arete &a){
    out<<"Arete("<< a.getPoids() <<"):\nGauche-> "<< *(a.getGauche())<< "Droite-> " << *(a.getDroite()) <<endl ;
    return out ;
}

