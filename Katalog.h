#ifndef KATALOG_H_INCLUDED
#define KATALOG_H_INCLUDED
#include "Gra.h"
#include "Komputerowa.h"
#include "Planszowa.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class Katalog
{   bool _DEBUG=false;
    const unsigned int MAX_ROZMIAR=100;
    size_t size_;
    size_t capacity_;
     const size_t CHUNK_SIZE = 128;
    vector<Gra> gry_;
    public:
        Katalog();
        Katalog(const Katalog& kat);
        Katalog &operator=(Katalog& kat); // operator przypisania
        Katalog &operator+( Komputerowa& gra);
        Katalog &operator+( Planszowa& gra); // operator dodawania gry do katalogu
        Katalog &operator-( int id); // operator usuwania gry z id
        friend ofstream& operator<< (ofstream& plik,const Katalog& kat); // operator strumieniowy
        friend ostream& operator<< (ostream& os,const Katalog& kat);   //operator strumieniowy
        friend ifstream& operator>> (ifstream& plik,Katalog& kat);  // operator strumieniowy
        void DodajOcene(int id,int ocena); // d
        void Szukaj(string nazwa);  // wyszukaj gry

};


#endif // KATALOG_H_INCLUDED
