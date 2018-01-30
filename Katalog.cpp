#include "Katalog.h"
Katalog::Katalog()
{
    gry_.reserve(CHUNK_SIZE);
    if(_DEBUG)
    cout<<"konstruktor bezargumentowy "<<endl;

}
Katalog::Katalog(const Katalog& kat)
{
    size_=kat.size_;
    for(int i=0;i<kat.size_;++i)
    {
        gry_.push_back(kat.gry_[i]);
    }
    if(_DEBUG)
    cout<<"konstruktor kopiujacy"<<endl;
}
Katalog &Katalog::operator=(Katalog& kat)
{
    size_=kat.size_;
    for(int i=0;i<size_;++i)
    {
        gry_.push_back(kat.gry_[i]);
    }
}

Katalog &Katalog::operator-( int id)
{
    gry_.erase(gry_.begin() + id-1);
    cout<<"gra zostala usunieta";
}
Katalog &Katalog::operator+( Komputerowa& gra)
{
    gry_.push_back(gra);
}
Katalog &Katalog::operator+( Planszowa& gra)
{
    gry_.insert(gry_.begin(),gra);
}
void Katalog::DodajOcene(int id,int ocena)
{
    gry_[id]+ocena;
}

void Katalog::Szukaj(string nazwa)
{
    for(int i=0;i<gry_.size();i++)
    {
        if(gry_[i]==nazwa)
        {
            cout<<"id gry to :";
            cout<<i+1;
            cout<<" ";
            cout<<gry_[i];

        }

    }
}
ofstream& operator<< (ofstream& plik,const Katalog &kat)
{
    plik<<kat.gry_.size()<<endl;
    for(int i=0;i<kat.gry_.size();i++)
    {
        plik<<kat.gry_[i];


    }
}
ifstream& operator>> (ifstream& plik,Katalog& kat)
{   string smiec;
    size_t wartosc;
    plik>>wartosc;
    Gra nowa;
    for(int i=0;i<wartosc;i++)
    {

        getline(plik,smiec);
        plik>>nowa;
        kat.gry_.push_back(nowa);

    }
}
ostream& operator<< (ostream& os,const Katalog& kat)
{
    os<<"Liczba gier w katalogu: "<<kat.gry_.size()<<endl;
    for(int i=0;i<kat.gry_.size();i++)
    {
        os<<"id :"<<i<<endl;
        os<<kat.gry_[i];

    }
}
