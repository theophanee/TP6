#include"Sommet.hpp"
#include"Arete.hpp"
#include"Graphe.hpp"
#include<iostream>
#include<vector>


int main(){
    Sommet s{"A"};

    Sommet s2{"B"};

    cout<<"blelblel   "<<&s2<<endl;

    vector<Sommet*> const tabs { &s, &s2 };

    Arete a{&s,&s2,4};
    Arete asym{&s2,&s,4};


    Arete a2{a};
    
    Arete a3{"1","2",5};

    vector<Arete*> const taba {&a,&asym,&a3};
    
    Graphe g{tabs,taba};

    g.ajoute_arete(new Arete{"7","2",2});


    cout<<"Poids : " << g.poids()<< endl;

    cout<< g << endl;
    cout<< "----------------------- symetrise -----------------------" << endl;
    g.symetrise();
    cout<< "----------------------- fin de symetrise -----------------------" << endl;

    cout<< g << endl;

    return EXIT_SUCCESS;
}