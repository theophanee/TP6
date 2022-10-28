#include "Sommet.hpp"
#include<iostream>
#include<string>

using namespace std;

Sommet::Sommet(string e) : etiquette{e}{
    cout << "Construction de " << *this;
}

Sommet::Sommet(const Sommet &s) : etiquette{s.etiquette} {
    cout << "Copie de "<< *this;
}

Sommet::~Sommet(){
    cout<<"Destruction du sommet "<< *this;
}

void Sommet::setMK(int val){
    marque=val;
}

int Sommet::getMK(){
    return marque;
}

ostream& operator<<( ostream& out , Sommet &s){
    out<<"Sommet:"<<s.getEtiquette()<<endl;
    return out ;
}

void Sommet::setMarque(int val){
    marque = val;
}
int Sommet::getMarque(){return marque;}

string Sommet::getEtiquette(){return etiquette;}