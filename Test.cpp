#include"Sommet.hpp"
#include"Arete.hpp"
#include"Graphe.hpp"
#include<iostream>
#include<vector>


int main(){

    Sommet a{"A"}, b{"B"}, c{"C"}, d{"D"}, e{"E"}, f{"F"}, g{"G"};

    vector<Sommet*> const tabs { &a, &b, &c, &d, &e, &f, &g };

    Arete a1{&a,&b,7}, a2{&a,&d,5}, a3{&d,&b,9}, a4{&b,&c,8}, a5{&b,&e,7}, a6{&d,&e,15}, a7{&c,&e,5}, a8{&d,&f,6}, a9{&f,&e,8}, a10{&e,&g,9}, a11{&f,&g,11} ;

    vector<Arete*> const taba {&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10,&a11};
    
    Graphe graphe{tabs,taba};


    cout<<"Poids : " << graphe.poids()<< endl;

    cout<< graphe << endl;
    cout<< "----------------------- symetrise -----------------------" << endl;
    //graphe.symetrise();
    cout<< "----------------------- fin de symetrise -----------------------" << endl;

    vector<Arete*>res = graphe.kruskal();
    for(unsigned int i = 0; i<res.size() ; i++)
        cout<< "    " << *(res[i]) ;
    cout<< "Fin Kruskal"<<endl;

    //cout<< graphe << endl;

    return EXIT_SUCCESS;
}