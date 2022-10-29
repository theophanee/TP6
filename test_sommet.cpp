#include"Sommet.hpp"
#include "GC.hpp"
#include<iostream>


int main(){

    cout<<"Constructeurs : "<<endl;

    Sommet a{"A"}, b{"B"}, c{"C"}, d{a} ;
    char choix;

    cout<<"Test Getter"<<endl; 
    cout<<"Choisir le sommet test : (A,B,C)"<<endl;
    cin>>choix;

    switch (choix)
    {
    case 'A':
        cout<<"Etiquette de A : "<< a.getEtiquette() <<endl;
        break;
    case 'B':
        cout<<"Etiquette de B : "<< b.getEtiquette() <<endl;
        break;
    case 'C':
        cout<<"Etiquette de C : "<< c.getEtiquette() <<endl;
        break;
    
    default:
        cout<<"Pas compris"<<endl;
        break;
    }

    GC::libererMemoire();

    return EXIT_SUCCESS;
}