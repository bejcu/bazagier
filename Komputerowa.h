#ifndef KOMPUTEROWA_H_INCLUDED
#define KOMPUTEROWA_H_INCLUDED
#include <iostream>
#include <fstream>
#include "Gra.h"
using namespace std;
class Komputerowa : public Gra
{
    string kategoria_;
    bool trybWieluGraczy_;

    public:
        Komputerowa();
        Komputerowa(string nazwa,string studio,short rok,string recenzja,int liczbaOcen,int sumaOcen,string kategoria,bool tryb);
        Komputerowa(const Komputerowa& gra):Gra(gra),kategoria_(gra.kategoria_),trybWieluGraczy_(gra.trybWieluGraczy_){cout<<"konstruktor kopiujacy KOMP"<<endl;} ;
        Komputerowa &operator=(const Komputerowa &gra);// operator przypisania
        friend bool operator==(const Komputerowa& pierwszy,const Komputerowa& drugi); // operator porownania dwoch gier

        virtual void Wypisz(ostream&os) const;
        virtual void Dodaj(istream& is) ;
        virtual void Zpliku(ofstream& os) const;
        virtual void Dopliku(ifstream& is) ;
        virtual Komputerowa &operator+( int ocena); // operator dodawania oceny
        virtual Komputerowa &operator-( int ocena); // operator usuwania oceny
        friend bool operator==(const Komputerowa& pierwszy,const string nazwa); // operator porownania gry oraz ciagu znakow

        virtual double WypiszOcene();

};


#endif // KOMPUTEROWA_H_INCLUDED
