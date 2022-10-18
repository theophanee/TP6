#include"Sommet.hpp"
#include"Arete.hpp"
#include<iostream>


int main(){

    Sommet s{"test"};
    cout<<s;

    Sommet s2 = s;
    cout<<s2;

    Arete a{s,s2,4};
    cout<<a;
    return EXIT_SUCCESS;
}