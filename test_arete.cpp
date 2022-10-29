#include"Sommet.hpp"
#include"Arete.hpp"
#include "GC.hpp"
#include<iostream>
#include<vector>


int main(){

    cout<<"Constructeurs : "<<endl;

    Sommet a{"A"}, b{"B"}, c{"C"}, d{a};

    Arete a1{&a,&b,7}, a2{&a,&d,8}, a3{"D","E",6}, a4{a1};

    int choix;

    cout<<"Test des méthodes d'arete"<<endl; 
    cout<<"Choisir le test pour "<< a1<<"1) Getter Sommet de Gauche\n2) Getter Sommet de Droite\n3) Getter du Poids\n4) Setter du Poids"<<endl;
    cin>>choix;

    switch (choix)
    {
    case 1:
        cout<<"Getter Sommet de Gauche : "<< *a1.getGauche() <<endl<<endl;
        break;
    case 2:
        cout<<"Getter Sommet de Droite : "<< *a1.getDroite() <<endl<<endl;
        break;
    case 3:
        cout<<"Getter du Poids : "<< a1.getPoids() <<endl<<endl;
        break;
    case 4:
        cout<<"Setter du Poids à 10 : "<<endl;
        a1.setPoids(10) ;
        cout<<a1<<endl;
        break;
    
    default:
        cout<<"Pas compris"<<endl;
        break;
    }

    GC::libererMemoire();

    return EXIT_SUCCESS;
}