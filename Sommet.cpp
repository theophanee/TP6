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
    cout<<"Destruction du sommet "<< *this<<endl;
}

ostream& operator<<( ostream& out , Sommet &s){
    out<<"Sommet:"<<s.getEtiquette()<<endl;
    return out ;
}

string Sommet::getEtiquette(){return etiquette;}