#ifndef GRA_H_INCLUDED
#define GRA_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;
class Gra
{   protected:
    bool _DEBUG=true;
    string nazwa_;
    string studio_;
    short rok_;
    string recenzja_;
    int liczbaOcen_;
    int sumaOcen_;
    double ocena_;
    public:
        Gra();
        Gra(string nazwa,string studio,short rok,string recenzja,int liczbaOcen,int sumaOcen);
        Gra(const Gra& gra);
        Gra &operator=(const Gra &gra);
        friend bool operator==(const Gra& pierwszy,const Gra& drugi); // operator porownania dwoch gier
        inline friend ostream& operator<< (ostream& os,const Gra& gra) {    gra.Wypisz(os); return os; }; // operator strumieniowy

        virtual void Wypisz(ostream& os) const;
        virtual void Dodaj(istream& is) ;
        virtual void Zpliku(ofstream& os) const ;
        virtual void Dopliku(ifstream& is) ;
        friend ofstream& operator<< (ofstream& os,const Gra& gra); // operator strumieniowy
        virtual Gra &operator+( int ocena); // operator dodawania oceny
        virtual Gra &operator-( int ocena); // operator usuwania oceny
        friend istream& operator>> (istream& is,Gra& gra); // operator strumieniowy
        friend ifstream& operator>> (ifstream& is,Gra& gra); // operator strumieniowy
        friend bool operator==(const Gra& pierwszy,const string nazwa); // operator porownania gry oraz ciagu znakow

        double WypiszOcene();

};


#endif // GRA_H_INCLUDED
