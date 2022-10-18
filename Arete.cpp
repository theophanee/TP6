#include "Arete.hpp"
#include<iostream>
#include<string>

using namespace std;

/*Arete::Arete(string etiquette1, string etiquette2, int p){
    poids = p;
    gauche = Sommet(etiquette1);
    droite = Sommet(etiquette2);
    cout << "Construction de " << *this;
}*/

Arete::Arete(const Arete &a) : poids{a.poids} {
    gauche = a.gauche;
    droite = a.droite;
    cout << "Copie d'Arete"<<endl;
}

Arete::Arete(Sommet g, Sommet d, int p) : poids{p} {
    gauche = &g;
    droite = &d;
    cout << "Construction Arete" << endl;
}

Sommet* Arete::getDroite(){ return droite ;}
Sommet* Arete::getGauche() { return  gauche; }
int Arete::getPoids(){ return poids; }  

ostream& operator<<( ostream& out , Arete &a){
    out<<"Arete("<< a.getPoids() <<"):\nGauche->"<< *(a.getGauche()) << "Droite->" << *(a.getDroite()) <<endl;
    return out ;
}

