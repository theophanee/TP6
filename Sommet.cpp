#include "Sommet.hpp"
#include<iostream>
#include<string>

using namespace std;

Sommet::Sommet(string e){
    etiquette = e;
    cout << "Construction de " << *this;
}

Sommet::Sommet(const Sommet &s){
    etiquette=*(s.getEtiquette());
    cout << "Copie de " << s;
}

ostream& operator<<( ostream& out ,const Sommet &s){
    out<<"Sommet:"<<s.getEtiquette()<<endl;
    return out ;
}

string Sommet::getEtiquette(){return etiquette;}