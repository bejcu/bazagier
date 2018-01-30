#ifndef PLANSZOWA_H_INCLUDED
#define PLANSZOWA_H_INCLUDED
#include <iostream>
#include <fstream>
#include "Gra.h"
using namespace std;
class Planszowa : public Gra
{
    int liczbaGraczy_;
    int zalezanyWiek_;

    public:
        Planszowa();
        Planszowa(string nazwa,string studio,short rok,string recenzja,int liczbaOcen,int sumaOcen,int liczbagraczy,int wiek);
        Planszowa(const Planszowa& gra);
        Planszowa &operator=(Planszowa &gra); // operator przypisania
        friend bool operator==(const Planszowa& pierwszy,const Planszowa& drugi); // operator porownania dwoch gier
        virtual void Wypisz(ostream& os)const ; // operator strumieniowy
        virtual void Dodaj(istream& is) ;
        virtual void Zpliku(ofstream& os) const;
        virtual void Dopliku(ifstream& is) ;
        virtual Planszowa &operator+( int ocena); // operator dodawania oceny
        virtual Planszowa &operator-( int ocena); // operator usuwania oceny
        friend bool operator==(const Planszowa& pierwszy,const string nazwa); // operator porownania gry oraz ciagu znakow

        virtual double WypiszOcene();

};


#endif // PLANSZOWA_H_INCLUDED
