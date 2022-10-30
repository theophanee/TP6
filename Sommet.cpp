#include "Sommet.hpp"
#include "GC.hpp"
#include<iostream>
#include<string>

using namespace std;

// constructeur
Sommet::Sommet(string e) : etiquette{e}{
    cout << "Construction de " << *this;
    GC::setGCS(this);
}

// copie
Sommet::Sommet(const Sommet &s) : etiquette{s.etiquette} {
    cout << "Copie de "<< *this;
    GC::setGCS(this);
    
}
/*
Sommet::~Sommet(){
    cout<<"Destruction du sommet "<< *this;
}*/


// setter et getter
void Sommet::setMarque(int val){ marque=val;}
int Sommet::getMarque(){ return marque; }
string Sommet::getEtiquette(){return etiquette;}

ostream& operator<<( ostream& out , Sommet &s){
    out<<"Sommet:"<<s.getEtiquette()<<endl;
    return out ;
}