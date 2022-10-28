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
<<<<<<< HEAD
        int getMK();
        void setMK(int val);
=======
        void setMarque(int m);
        int getMarque();
>>>>>>> 9ec26faebb8d14ee3aa6c48deb7c97ea7d86187e
        
};

ostream& operator <<(ostream& out, Sommet &) ;

#endif