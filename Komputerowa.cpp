#include "Komputerowa.h"

Komputerowa::Komputerowa()
{
    nazwa_="puste";
    rok_=0;
    studio_="pute";
    recenzja_="brak";
    liczbaOcen_=0;
    sumaOcen_=0;
    ocena_=0;
    kategoria_="puste";
    trybWieluGraczy_=false;
    if(_DEBUG)
    cout<<"konstruktor bezargumentowy"<<endl;
}
Komputerowa::Komputerowa(string nazwa,string studio, short rok,string recenzja,  int liczbaOcen,  int sumaOcen,string kategoria,bool tryb)
{
    nazwa_=nazwa;
    rok_=rok;
    studio_=studio;
    recenzja_=recenzja;
    liczbaOcen_=liczbaOcen;
    sumaOcen_=sumaOcen;
    ocena_=(double)sumaOcen/liczbaOcen;
    kategoria_=kategoria;
    trybWieluGraczy_=tryb;
    if(_DEBUG)
    cout<<"konstruktor wieloargumentowy"<<endl;
}

bool operator==(const Komputerowa& pierwszy,const Komputerowa& drugi)
{
    return(pierwszy.nazwa_==drugi.nazwa_);
}
Komputerowa &Komputerowa::operator=(const Komputerowa &gra)
{
    nazwa_=gra.nazwa_;
    rok_=gra.rok_;
    studio_=gra.studio_;
    recenzja_=gra.recenzja_;
    liczbaOcen_=gra.liczbaOcen_;
    sumaOcen_=gra.sumaOcen_;
    ocena_=gra.ocena_;
    trybWieluGraczy_=gra.trybWieluGraczy_;
    kategoria_=gra.kategoria_;
    cout<<"kons = KOMP"<<endl;
    return *this;
}
Komputerowa &Komputerowa::operator+(int ocena)
{
    ++liczbaOcen_;
    sumaOcen_=sumaOcen_+ocena;
    ocena_=(double)sumaOcen_/liczbaOcen_;
    return *this;

}
Komputerowa &Komputerowa::operator-(int ocena)
{
    --liczbaOcen_;
    sumaOcen_=sumaOcen_-ocena;
    ocena_=(double)sumaOcen_/liczbaOcen_;
    return *this;

}

void Komputerowa::Wypisz(ostream&os) const
{
    os<<"Gra o nazwie ";
    os<<nazwa_;
    os<<" wydana przez ";
    os<<studio_;
    os<<" w roku ";
    os<<rok_<<"."<<endl;
    os<<recenzja_<<endl;
    os<<trybWieluGraczy_<<" "<<endl;
    os<<"Kategoria "<<kategoria_<<endl;
    os<<"Ocena gry ";
    os<<ocena_<<endl;

}
void Komputerowa::Dodaj(istream& is)
{
    cout<<"Nazwa gry?"<<endl;
    getline(is,nazwa_);
    cout<<"Wydana przez?"<<endl;
    getline(is,studio_);
    cout<<"Kategoria?"<<endl;
    getline(is,kategoria_);
    cout<<"W roku?"<<endl;
    is>>rok_;
    cout<<"Czy dostêpny jest tryb wielu graczy(T/N)"<<endl;
    char t;
    is>>t;
    if(t=='t')
        trybWieluGraczy_=true;
    else
        trybWieluGraczy_=false;
    cout<<"Krotka recenzja"<<endl;
    getline(is,recenzja_);
    getline(is,recenzja_);
    liczbaOcen_=0;
    sumaOcen_=0;

}

void Komputerowa::Zpliku(ofstream& os)const
{
    os<<nazwa_<<endl;;
    os<<studio_<<endl;;
    os<<rok_<<endl;
    os<<recenzja_<<endl;
    os<<liczbaOcen_<<endl;
    os<<sumaOcen_<<endl;
    os<<kategoria_<<endl;
    os<<trybWieluGraczy_<<endl;
}
void Komputerowa::Dopliku(ifstream& is)
{
    getline(is,nazwa_);
    getline(is,studio_);
    is>>rok_;
    getline(is,recenzja_);
    getline(is,recenzja_);
    is>>liczbaOcen_;
    is>>sumaOcen_;
    ocena_=(double)sumaOcen_/liczbaOcen_;
    getline(is,kategoria_);
    is>>trybWieluGraczy_;
}
bool operator==(const Komputerowa& pierwszy,const string nazwa)
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
double Komputerowa::WypiszOcene()
{
    return ocena_;
}
