#include "GC.hpp"
#include <iostream>
using namespace std;

vector<Sommet*> GC::gcSommets{};
vector<Arete*> GC::gcAretes{};

//setter
void GC::setGCS(Sommet *s){
    GC::gcSommets.push_back(s);
}

void GC::setGCA(Arete *a){
    GC::gcAretes.push_back(a);
}

void GC::affichage(){
    cout << "Il y a " << gcAretes.size() << " pointeurs sur aretes et "<< gcSommets.size() << " pointeurs sur sommets "<< endl;
}

void GC::libererMemoire(){
    for (Sommet *s : gcSommets){
        delete s;
    }
    for (Arete *a : gcAretes){
        delete a;
    }
    gcSommets.clear();
    gcAretes.clear();
}

ostream & operator << (ostream& out, const GC &gc){
    out << "Il y a " << gc.gcAretes.size() << "aretes et "<< gc.gcSommets.size() << "sommets "<< endl;
    return out;
}