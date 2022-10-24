#include "Graphe.hpp"
#include <algorithm>
#include<iostream>
#include<string>

using namespace std;

Graphe::Graphe(vector<Sommet*> s, vector<Arete*> a) : sommets{s}, aretes{a}{
    
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
        out<< "    " << *(g.getSommets()[i]) ;
    out << "Aretes : " <<endl;

    for(unsigned int i = 0; i < g.getAretes().size(); i++)
        out<< "    " << *(g.getAretes()[i]) ;
    return out ;
}

void Graphe::ajoute_sommet(Sommet *s){
    cout<<"Ajout sommet "<<*s<<endl;
    sommets.push_back(s);
}

void Graphe::ajoute_sommet(string e){
    Sommet *s = new Sommet{e};
    cout<<"Ajout sommet "<<*s<<endl;
    sommets.push_back(s);
}

void Graphe::ajoute_arete(Arete *a){
    cout<<"Ajout arete "<<a<<endl;
    aretes.push_back(a);
}

void Graphe::ajoute_arete(Sommet *s1, Sommet *s2, int p){
    Arete *a = new Arete(s1 , s2 , p);
    cout<<"Ajout arete "<<*a<<endl;
    aretes.push_back(a);
}

void Graphe::ajoute_arete(string e1, string e2, int p){
    Arete *a = new Arete( (new Sommet{e1}) , (new Sommet{e2}) , p);
    cout<<"Ajout arete "<<*a<<endl;
    aretes.push_back(a);
}

int Graphe::poids(){
    int p=0 ;
    for(unsigned int i = 0; i < aretes.size() ; i++)
        p += aretes[i]->getPoids();
    return p;
}

int Graphe::find(Arete* a){
    cout<<"_______ FAINDE _______"<<endl;

    Sommet* d=a->getDroite();
    Sommet* g=a->getGauche();
    int p=a->getPoids();
    cout<<g<<endl;
    cout<<d<<endl;
    
    cout<<p<<endl;

    
    for (unsigned int i = 0; i < aretes.size(); i++){
        // cout<<"_______ find "<<i+1<<"_______"<<endl;
        
        cout<<getAretes()[i]->getGauche()<<endl;
        cout<<getAretes()[i]->getDroite()<<endl;
        cout<<getAretes()[i]->getPoids()<<endl;

        if ( getAretes()[i]->getDroite()==d && getAretes()[i]->getGauche()==g && getAretes()[i]->getPoids()==p){
            // cout<<"_______ find 000 _______"<<endl;
            return 0;
        }
        
    }
    // cout<<"_______ find ---111 _______"<<endl;
    return -1;
}

void Graphe::symetrise(){
    for (unsigned int i = 0; i < aretes.size(); i++){
        
        Arete *sym = new Arete( getAretes()[i]->getDroite() , getAretes()[i]->getGauche() , getAretes()[i]->getPoids());

        // cout<<"sujet "<<i<<endl;
        
        
        if ( find(sym) == -1 ) {
            cout<<"bizarre, on ajoute sym dans aretes : "<<sym<<endl;
            ajoute_arete(sym);
        }
        else cout<<"ok: "<<aretes[i]<<endl;
    }
   
}

// Graphe* Graphe::kruskal(){
//     Graphe *res = new Graphe({},{});
//    


//     return res;

// }

vector<Sommet*> Graphe::getSommets(){ return sommets;}
vector<Arete*> Graphe::getAretes(){ return aretes;}



