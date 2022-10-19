#include"Sommet.hpp"
#include"Arete.hpp"
#include"Graphe.hpp"
#include<iostream>


int main(){

    Sommet s{"test"};

    Sommet s2 = s;

    Arete a{s,s2,4};

    Arete a2{a};
    Arete a3{"1","2",5};

    Graphe g{&s,&a3};
    return EXIT_SUCCESS;
}