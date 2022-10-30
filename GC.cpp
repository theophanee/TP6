#include "GC.hpp"
#include"Sommet.hpp"
#include"Arete.hpp"
#include <iostream>
using namespace std;

// initialise les listes
vector<Sommet*> GC::gcSommets{};
vector<Arete*> GC::gcAretes{};

// setters
void GC::setGCS(Sommet *s){
    gcSommets.push_back(s);
}
void GC::setGCA(Arete *a){
    gcAretes.push_back(a);
}

// liberer la memoire
void GC::libereGC(){
    cout<<"Liberation de la memoire"<<endl<<endl;

    // affiche les sommets et aretes à supprimer
    cout<<"Sommets a detruire : "<<endl;
    for(Sommet* s : gcSommets)
        cout<<*s;
    cout<<"Aretes a detruire : "<<endl;
    for(Arete* a : gcAretes)
        cout<<*a;

    // supprime les sommets et aretes
    for (unsigned int i = 0 ; i<gcSommets.size() ; i++){
        cout<<"Destruction de "<< *gcSommets[i] << "a l'adresse : " << gcSommets[i]<<endl;
        delete gcSommets[i];
    }
    for (unsigned int i = 0 ; i<gcAretes.size() ; i++){
        cout<<"Destruction de "<< *gcAretes[i] << "a l'adresse : " << gcAretes[i]<<endl;
        delete gcAretes[i];
    }    

    gcSommets.clear();
    gcAretes.clear();
}



ostream & operator << (ostream& out, const GC &gc){
    out<< gc.gcAretes.size() << "aretes et "<< gc.gcSommets.size() << "sommets "<< endl;
    return out;
}