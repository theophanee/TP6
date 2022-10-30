#include"Sommet.hpp"
#include"Arete.hpp"
#include"Graphe.hpp"
#include "GC.hpp"
#include<iostream>
#include<vector>


int main(){


    // Test qui représente le test wikipédia
    // https://fr.wikipedia.org/wiki/Algorithme_de_Kruskal

    Sommet a{"A"}, b{"B"}, c{"C"}, d{"D"}, e{"E"}, f{"F"}, g{"G"};

    Arete a1{&a,&b,7}, a2{&a,&d,5}, a3{&d,&b,9}, a4{&b,&c,8}, a5{&b,&e,7}, a6{&d,&e,15}, a7{&c,&e,5}, a8{&d,&f,6}, a9{&f,&e,8}, a10{&e,&g,9}, a11{&f,&g,11} ;

    vector<Sommet*> tabs { &a, &b, &c, &d, &e, &f, &g };
    vector<Arete*> taba {&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10,&a11};
    
    Graphe graphe{tabs,taba}; // graphe test

    cout<<"Poids : " << graphe.poids()<< endl; // test poids

    vector<Arete*>res = graphe.kruskal(); // prend le parcourt resultant
    cout<<"Aretes de sortie : "<<endl;
    for(unsigned int i = 0; i<res.size() ; i++) // affiche le parcours
        cout<< "    " << *(res[i]) ;
    cout<< "Fin Kruskal"<<endl;

    GC::libereGC(); // libere GC

    return EXIT_SUCCESS;
}