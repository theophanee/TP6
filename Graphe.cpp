#include "Graphe.hpp"
#include "GC.hpp"
#include <algorithm>
#include<iostream>
#include<string>

using namespace std;

Graphe::Graphe(vector<Sommet*> s, vector<Arete*> a) : sommets{s}{
    for (unsigned int i = 0; i < a.size(); i++){
        ajoute_arete(a[i]);
    }
    
    cout<< "Construction de " << *this ;

}

Graphe::Graphe(const Graphe &g) {
    sommets = g.sommets;
    aretes = g.aretes;
    cout << "Copie de "<< *this;
} 

Graphe::~Graphe(){
    cout<<"Destruction du "<< *this<<endl;
}

ostream& operator<<( ostream& out , Graphe &g){
    out << "Graphe : " <<endl;
    out << "Sommets : "<< endl;
    for(unsigned int i = 0; i < g.getSommets().size(); i++)
        out<< "    " << *(g.getSommets()[i]) ;
    out << "Aretes : " <<endl;

    for(unsigned int i = 0; i < g.getAretes().size(); i++)
        out<< "    " << *(g.getAretes()[i]) ;
    return out ;
}


void Graphe::ajoute_sommet(Sommet *s){
    cout<<"Ajout "<<*s<<endl;
    sommets.push_back(s);
}

void Graphe::ajoute_sommet(string e){
    Sommet *s = new Sommet{e};
    GC::setGCS(s);
    cout<<"Ajout "<<*s<<endl;
    sommets.push_back(s);
}

void Graphe::ajoute_arete(Arete *a){
    cout<<"Ajout arete "<<*a<<endl;
    aretes.push_back(a);
}

void Graphe::ajoute_arete(Sommet *s1, Sommet *s2, int p){
    Arete *a = new Arete(s1 , s2 , p);
    GC::setGCA(a);
    cout<<"Ajout arete "<<*a<<endl;
    aretes.push_back(a);
}

void Graphe::ajoute_arete(string e1, string e2, int p){
    Sommet* s1 = new Sommet{e1};
    Sommet* s2 = new Sommet{e2};
    Arete *a = new Arete( s1 ,s2 , p);
    GC::setGCS(s1);
    GC::setGCS(s2);
    GC::setGCA(a);
    cout<<"Ajout arete "<<*a<<endl;
    aretes.push_back(a);
}

int Graphe::poids(){
    int p=0 ;
    for(unsigned int i = 0; i < aretes.size() ; i++)
        p += aretes[i]->getPoids();
    return p;
}

int Graphe::findArete(Arete* a){
    Sommet* d=a->getDroite();
    Sommet* g=a->getGauche();
    int p=a->getPoids();
    
    for (unsigned int i = 0; i < aretes.size(); i++){


        if ( getAretes()[i]->getDroite()==d && getAretes()[i]->getGauche()==g && getAretes()[i]->getPoids()==p){
            return 0;
        }
    }
    return -1;
}

void Graphe::symetrise(){
    cout<<"Debut de symetrise"<<endl;
    for (unsigned int i = 0; i < aretes.size(); i++){
        
        Arete *sym = new Arete( getAretes()[i]->getDroite() , getAretes()[i]->getGauche() , getAretes()[i]->getPoids());

        if ( findArete(sym) == -1 ) {
            cout<<"On ajoute l'aretes : "<<sym<<endl;
            ajoute_arete(sym);
        }
        else cout<<"l'arete: "<<aretes[i]<<" est presente"<<endl;
    }
   cout<<"Fin de symetrise"<<endl;
}

// etiquette sommet avec entier unique
void Graphe::creerEnsemble(Sommet &v, int val)
{
    v.setMarque(val);
    cout << v << "numero : " << val << endl;
}

// retourne l'entier du sommet
int Graphe::find(Sommet &v)
{
    return v.getMarque();
}

void Graphe::uni(Sommet &u, Sommet &v)
{
    // On donne le même numéro à tous les sommets qui ont le même numéro que u ou que v
    for (Sommet *s : this->getSommets()){
        cout << "Sommet " << s->getEtiquette() << ", entier : " << s->getMarque() << endl;
        // si sommet s a le meme numero que sommet u ou v (sans prendre les sommet u et v)
        if (((s->getMarque() == v.getMarque()) || (s->getMarque() == u.getMarque())) && (s != &u) && (s != &v))
        {
            cout << "on affecte la marque " << u.getMarque() << " au sommet " << s->getEtiquette() << endl;
            // on donne meme numero que sommet u
            s->setMarque(u.getMarque());
        }
    }
    // on affecte aussi a v num de u
    v.setMarque(u.getMarque());
}

bool sortkruskal(Arete *u, Arete *v)
{
    return ((*u).getPoids() < (*v).getPoids());
}

vector<Arete *> Graphe::kruskal(){
    cout<<"Debut de l'algorithme de Kruskal"<<endl;
    // On trie nos arete dans l'ordre croissant en fonction de leur poids
    sort(aretes.begin(), aretes.end(), [] (Arete* x, Arete* y) { return x->getPoids() < y->getPoids(); });


    // on creer un nouveau graphe
    Graphe gk{*this};
    vector<Arete *> A;
    size_t sizeListeS = getSommets().size();
    for (size_t i = 0; i < sizeListeS; i++)
    {
        // On donne aux sommets des valeurs distinctes
        gk.creerEnsemble(*(gk.getSommets()[i]), i);
    }
    vector<Arete *> areteL = gk.getAretes();
    
    
    // on affecte a la liste d'arete du graphe la liste triee
    gk.setAretes(areteL);
    // On parcourt les arete triee
    for (Arete *a : gk.getAretes())
    {
        cout << "-----------------------"<<endl<<"nous traitons l'arete "<<*a<<endl;
        // on regarde numero sommets
        if (gk.find(*(a->getGauche())) != gk.find(*(a->getDroite())))
        {
            // on ajoute a la liste resultat
            A.push_back(a);
            gk.uni(*(a->getGauche()), *(a->getDroite()));
            cout << "L'arete est ajoutee "<< endl;
        }else{
            cout << "L'arete n'est pas ajoutee"<< endl;
        }
    }
    cout<<"Fin de l'algorithme de Kruskal"<<endl;
    return A;
}

void Graphe::setAretes(vector<Arete *> a){
    aretes=a;
}
vector<Sommet*> Graphe::getSommets(){ return sommets;}
vector<Arete*> Graphe::getAretes(){ return aretes;}



