#include"Sommet.hpp"
#include"Arete.hpp"
#include"Graphe.hpp"
#include "GC.hpp"
#include<iostream>
#include<vector>


int main(){

    Sommet a{"A"}, b{"B"}, c{"C"}, d{a};

    Arete a1{&a,&b,7}, a2{&a,&d,8}, a3{"D","E",6}, a4{a1};

    vector<Sommet*> const tabs { &a, &b, &c, &d };

    vector<Arete*> const taba {&a1,&a2, &a3, &a4 };
    
    Graphe graphe{tabs,taba}, g2{graphe};

    int choix;

    cout<<"Test des méthodes de graphe"<<endl; 
    cout<<"Choisir le test pour "<< graphe<<"1) Ajouts de sommet\n2) Ajouts d'arete\n3) Getter du Poids, des Sommet et des Arete\n4) Symetrise le graphe\n5) Kruskal"<<endl;
    cin>>choix;

    switch (choix)
    {
    case 1:
        cout<<"Ajouts de sommet : "<<endl;
        graphe.ajoute_sommet("Z");
        graphe.ajoute_sommet(new Sommet{"X"});
        graphe.ajoute_sommet(&a);

        cout<<"\nGraphe après ajouts : "<<graphe;
        break;
    case 2:
        cout<<"Ajouts d'arete : "<<endl;
        graphe.ajoute_arete(&a1);
        graphe.ajoute_arete(new Arete{new Sommet{"I"},new Sommet{"J"},11});
        graphe.ajoute_arete("M","N",2);
        graphe.ajoute_arete(&a,&c,13);

        cout<<"\nGraphe après ajouts :\n"<<graphe;
        break;
    case 3:
        cout<<"Getter du Poids, des Sommet et des Arete : \n"<<endl;
        cout<<"Poids du Graphe : "<<graphe.poids()<<endl;
        cout<<"Sommets du graphe :"<<endl;
        for(unsigned int i=0; i<graphe.getSommets().size(); i++)
            cout<<*graphe.getSommets()[i];
        cout<<"\nAretes du graphe :"<<endl;
        for(unsigned int i=0; i<graphe.getAretes().size(); i++)
            cout<<*graphe.getAretes()[i];
        break;
    case 4:
        cout<<"Symetrise le graphe"<<endl;
        graphe.symetrise();
        cout<<graphe<<endl;
        break;
    case 5:
        {
        graphe.symetrise();
        vector<Arete*> res = graphe.kruskal();
        cout<<"Parcours de poids minimal : "<<endl;
        for(unsigned int i=0; i<res.size() ; i++)
            cout<<*res[i];
        }
        break;
    
    default:
        cout<<"Pas compris"<<endl;

        break;
    }

    GC::libereGC();

    return EXIT_SUCCESS;
}