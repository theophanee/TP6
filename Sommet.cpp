#include "Sommet.hpp"
#include "GC.hpp"
#include<iostream>
#include<string>

using namespace std;

Sommet::Sommet(string e) : etiquette{e}{
    cout << "Construction de " << *this;
    GC::setGCS(this);
}

Sommet::Sommet(const Sommet &s) : etiquette{s.etiquette} {
    cout << "Copie de "<< *this;
    GC::setGCS(this);
    
}

Sommet::~Sommet(){
    cout<<"Destruction du sommet "<< *this;
}

void Sommet::setMarque(int val){
    marque=val;
}

int Sommet::getMarque(){
    return marque;
}

ostream& operator<<( ostream& out , Sommet &s){
    out<<"Sommet:"<<s.getEtiquette()<<endl;
    return out ;
}

string Sommet::getEtiquette(){return etiquette;}