#ifndef _SOMMET
#define _SOMMET
#include<iostream>
#include<string>

using namespace std;

class Sommet{
    private:
        string etiquette;
        int marque;
    public:
        Sommet(string etiquette);
        Sommet(const Sommet &s);
        virtual ~Sommet();
        string getEtiquette();
        void setMarque(int m);
        int getMarque();
        
};

ostream& operator <<(ostream& out, Sommet &) ;

#endif