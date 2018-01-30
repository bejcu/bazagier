#include "Planszowa.h"

Planszowa::Planszowa()
{
    nazwa_="puste";
    rok_=0;
    studio_="pute";
    recenzja_="brak";
    liczbaOcen_=0;
    sumaOcen_=0;
    ocena_=0;
    liczbaGraczy_=0;
    zalezanyWiek_=0;
    if(_DEBUG)
    cout<<"konstruktor bezargumentowy"<<endl;
}
Planszowa::Planszowa(string nazwa,string studio, short rok,string recenzja,  int liczbaOcen,  int sumaOcen,int liczbagraczy,int wiek)
{
    nazwa_=nazwa;
    rok_=rok;
    studio_=studio;
    recenzja_=recenzja;
    liczbaOcen_=liczbaOcen;
    sumaOcen_=sumaOcen;
    ocena_=(double)sumaOcen/liczbaOcen;
    liczbaGraczy_=liczbagraczy;
    zalezanyWiek_=wiek;
    if(_DEBUG)
    cout<<"konstruktor wieloargumentowy"<<endl;
}


Planszowa::Planszowa(const Planszowa& gra)
{
    nazwa_=gra.nazwa_;
    rok_=gra.rok_;
    studio_=gra.studio_;
    recenzja_=gra.recenzja_;
    liczbaOcen_=gra.liczbaOcen_;
    sumaOcen_=gra.sumaOcen_;
    ocena_=gra.ocena_;
    liczbaGraczy_=gra.liczbaGraczy_;
    zalezanyWiek_=gra.zalezanyWiek_;
    if(_DEBUG)
    cout<<"konstruktor kopiujacy"<<endl;
}
bool operator==(const Planszowa& pierwszy,const Planszowa& drugi)
{
    return(pierwszy.nazwa_==drugi.nazwa_);
}
Planszowa &Planszowa::operator=(Planszowa &gra)
{
    nazwa_=gra.nazwa_;
    rok_=gra.rok_;
    studio_=gra.studio_;
    recenzja_=gra.recenzja_;
    liczbaOcen_=gra.liczbaOcen_;
    sumaOcen_=gra.sumaOcen_;
    ocena_=gra.ocena_;
    liczbaGraczy_=gra.liczbaGraczy_;
    zalezanyWiek_=gra.zalezanyWiek_;

    return *this;
}
Planszowa &Planszowa::operator+(int ocena)
{
    ++liczbaOcen_;
    sumaOcen_=sumaOcen_+ocena;
    ocena_=(double)sumaOcen_/liczbaOcen_;
    return *this;

}
Planszowa &Planszowa::operator-(int ocena)
{
    --liczbaOcen_;
    sumaOcen_=sumaOcen_-ocena;
    ocena_=(double)sumaOcen_/liczbaOcen_;
    return *this;

}
void Planszowa::Wypisz(ostream& os) const
{
    os<<"Gra o nazwie ";
    os<<nazwa_;
    os<<" wydana przez ";
    os<<studio_;
    os<<" w roku ";
    os<<rok_<<"."<<endl;
    os<<recenzja_<<endl;
    os<<liczbaGraczy_<<" "<<endl;
    os<<"Zalecany wiek "<<zalezanyWiek_<<endl;
    os<<"Ocena gry ";
    os<<ocena_<<endl;

}
void Planszowa::Dodaj(istream& is)
{
    cout<<"Nazwa gry?"<<endl;
    getline(is,nazwa_);
    cout<<"Wydana przez?"<<endl;
    getline(is,studio_);
    cout<<"W roku?"<<endl;
    is>>rok_;
    cout<<"Krotka recenzja"<<endl;
    getline(is,recenzja_);
    getline(is,recenzja_);
    cout<<"Zalecany wiek?"<<endl;
    is>>zalezanyWiek_;
    cout<<"Dla ilu osob?"<<endl;
    is>>liczbaGraczy_;
    cout<<"Ocena gry ";
    is>>ocena_;
    liczbaOcen_=1;
    sumaOcen_=ocena_;
}

void Planszowa::Zpliku(ofstream& os) const
{
    os<<nazwa_<<endl;;
    os<<studio_<<endl;;
    os<<rok_<<endl;
    os<<recenzja_<<endl;
    os<<liczbaOcen_<<endl;
    os<<sumaOcen_<<endl;
    os<<zalezanyWiek_<<endl;
    os<<liczbaGraczy_<<endl;
}
void Planszowa::Dopliku(ifstream& is)
{
    getline(is,nazwa_);
    getline(is,studio_);
    is>>rok_;
    getline(is,recenzja_);
    getline(is,recenzja_);
    is>>liczbaOcen_;
    is>>sumaOcen_;
    ocena_=(double)sumaOcen_/liczbaOcen_;
    is>>zalezanyWiek_;
    is>>liczbaGraczy_;
}
bool operator==(const Planszowa& pierwszy,const string nazwa)
{
    int ile=0;
    int i=0;
    int k=pierwszy.nazwa_.length();
    while(pierwszy.nazwa_[i]!=nazwa[0]&&i<pierwszy.nazwa_.length())
    {
        i++;

    }
    for(int j=0;j<nazwa.length();j++)
    {   if(i+j<k)
            if(nazwa[j]==pierwszy.nazwa_[i+j])
                ile++;
    }
    if(ile>2)
    {
        return true;
    }
    else
        return false;

}
double Planszowa::WypiszOcene()
{
    return ocena_;
}
