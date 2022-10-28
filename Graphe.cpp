#include "Graphe.hpp"
#include <algorithm>
#include<iostream>
#include<string>

using namespace std;

Graphe::Graphe(vector<Sommet*> s, vector<Arete*> a) : sommets{s}, aretes{a}{
    
    cout<< "Construction de " << *this ;
}

Graphe::Graphe(const Graphe &g) {
    sommets = g.sommets;
    aretes = g.aretes;
    cout << "Copie de "<< *this;
} 

Graphe::~Graphe(){
    cout<<"Destruction du sommet "<< *this<<endl;
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
    cout<<"Ajout "<<*s<<endl;
    sommets.push_back(s);
}

void Graphe::ajoute_arete(Arete *a){
    cout<<"Ajout arete "<<*a<<endl;
    aretes.push_back(a);
}

void Graphe::ajoute_arete(Sommet *s1, Sommet *s2, int p){
    Arete *a = new Arete(s1 , s2 , p);
    cout<<"Ajout arete "<<*a<<endl;
    aretes.push_back(a);
}

void Graphe::ajoute_arete(string e1, string e2, int p){
    Arete *a = new Arete( (new Sommet{e1}) , (new Sommet{e2}) , p);
    cout<<"Ajout arete "<<*a<<endl;
    aretes.push_back(a);
}

int Graphe::poids(){
    int p=0 ;
    for(unsigned int i = 0; i < aretes.size() ; i++)
        p += aretes[i]->getPoids();
    return p;
}

int Graphe::find(Arete* a){
    cout<<"_______ FAINDE _______"<<endl;

    Sommet* d=a->getDroite();
    Sommet* g=a->getGauche();
    int p=a->getPoids();
    cout<<g<<endl;
    cout<<d<<endl;
    
    cout<<p<<endl;

    
    for (unsigned int i = 0; i < aretes.size(); i++){
        // cout<<"_______ find "<<i+1<<"_______"<<endl;
        
        cout<<getAretes()[i]->getGauche()<<endl;
        cout<<getAretes()[i]->getDroite()<<endl;
        cout<<getAretes()[i]->getPoids()<<endl;

        if ( getAretes()[i]->getDroite()==d && getAretes()[i]->getGauche()==g && getAretes()[i]->getPoids()==p){
            // cout<<"_______ find 000 _______"<<endl;
            return 0;
        }
        
    }
    // cout<<"_______ find ---111 _______"<<endl;
    return -1;
}

void Graphe::symetrise(){
    for (unsigned int i = 0; i < aretes.size(); i++){
        
        Arete *sym = new Arete( getAretes()[i]->getDroite() , getAretes()[i]->getGauche() , getAretes()[i]->getPoids());

        // cout<<"sujet "<<i<<endl;
        
        
        if ( find(sym) == -1 ) {
            cout<<"bizarre, on ajoute sym dans aretes : "<<sym<<endl;
            ajoute_arete(sym);
        }
        else cout<<"ok: "<<aretes[i]<<endl;
    }
   
}


// vector<Arete*> Graphe::kruskaltheophile(){
//     cout<<"Kruskal"<<endl;
//     int cptD, cptG; // compteur pour verifier la presence dans tmpS
//     vector<Arete*> res = {}; // liste des aretes choisies
//     vector<Sommet*> tmpS = {}; // stocker les sommets de res
    
//     // trie les aretes par ordre de poids croissant
//     sort(aretes.begin(), aretes.end(), [] (Arete* x, Arete* y) { return x->getPoids() < y->getPoids(); });
    
//     // parcours les aretes du graphes dans l'ordre croissant des poids
//     for(unsigned int i = 0 ; i < aretes.size() ; i++){
//         cout<<"1  "<<*aretes[i]<<endl;
//         cptD = 0;
//         cptG = 0;
        
//         // pour savoir si les sommets de l'arete sont deja present
//         for(unsigned int j=0; j < tmpS.size() ; j++){
//             cout<<"2  "<<*tmpS[j]<<endl;
//             // verifie pour les deux sommets
//             if(aretes[i]->getDroite()==tmpS[j]){
//                 cout<< *(tmpS[j]) << " existe deja"<<endl;
//                 cptD = 1;
//             }if(aretes[i]->getGauche()==tmpS[j]){
//                 cout<< *(tmpS[j]) << " existe deja"<<endl;
//                 cptG = 1;
//             }
//         }
//         if((cptD + cptG) <2){
//             // ajoute si necessaire les sommets dans tmpS et les aretes dans res
//                 cout<<" ajoute les sommets "<<*aretes[i]->getDroite()<<" et "<<*aretes[i]->getGauche()<<endl;
//                 if(cptD==0)
//                     tmpS.push_back(aretes[i]->getDroite());
//                 if(cptG==0)
//                     tmpS.push_back(aretes[i]->getGauche());
//                 res.push_back(aretes[i]);
//         }else
//             cout<<*aretes[i]<<"Non ajouter"<<endl;

//     }
//     // affiche les aretes choisies
//     for(unsigned int i = 0; i<res.size() ; i++)
//         cout<< "    " << *(res[i]) ;
//     cout<< "Fin Kruskal"<<endl;

//     return res;

// }




// etiquette sommet avec entier unique
void Graphe::creerEnsemble(Sommet &v, int val)
{
    v.setMK(val);
    cout << v << "numero : " << val << endl;
}

// retourne l'entier du sommet
int Graphe::findkruskal(Sommet &v)
{
    return v.getMK();
}

void Graphe::unir(Sommet &u, Sommet &v)
{
    // donner le même numéro à tous les sommets qui ont le même numéro que u ou que v
    for (Sommet *s : this->getSommets())
    {
        cout << "on regarde le sommet " << s->getEtiquette() << ", entier : " << s->getMK() << endl;
        // si sommet s a le meme numero que sommet u ou v (sans prendre les sommet u et v)
        if (((s->getMK() == v.getMK()) || (s->getMK() == u.getMK())) && (s != &u) && (s != &v))
        {
            cout << "on affecte num " << u.getMK() << " au sommet " << s->getEtiquette() << endl;
            // on donne meme numero que sommet u
            s->setMK(u.getMK());
        }
    }
    // on affecte aussi a v num de u
    v.setMK(u.getMK());
}

bool sortkruskal(Arete *u, Arete *v)
{
    return ((*u).getPoids() < (*v).getPoids());
}

vector<Arete *> Graphe::kruskal()
{
    // on creer un nouveau graphe
    cout<<"Kruskal"<<endl;
    sort(aretes.begin(), aretes.end(), [] (Arete* x, Arete* y) { return x->getPoids() < y->getPoids(); });
    Graphe gk{*this};
    vector<Arete *> A;
    size_t sizeListeS = getSommets().size();
    for (size_t i = 0; i < sizeListeS; i++)
    {
        // on donne aux sommets des valeurs distinctes
        gk.creerEnsemble(*(gk.getSommets()[i]), i);
    }
    vector<Arete *> areteL = gk.getAretes();
    
    // trier les arêtes de G par poids croissant
    
    // on affecte a la liste d'arete du graphe la liste triee
    gk.setAretes(areteL);
    // pour chaque arete triee
    for (Arete *a : gk.getAretes())
    {
        cout << *a;
        // on regarde numero sommets
        if (gk.findkruskal(*(a->getGauche())) != gk.findkruskal(*(a->getDroite())))
        {
            // on ajoute a la liste resultat
            A.push_back(a);
            gk.unir(*(a->getGauche()), *(a->getDroite()));
            cout << "on ajoute "<<*a<<" au graphe" << endl;
        }else{
            cout << "on ajoute pas" << endl;
        }
    }
    return A;
}

void Graphe::setAretes(vector<Arete *> a){
    aretes=a;
}
vector<Sommet*> Graphe::getSommets(){ return sommets;}
vector<Arete*> Graphe::getAretes(){ return aretes;}



