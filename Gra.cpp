#include "Gra.h"

#include "Gra.h"

Gra::Gra()
{
    nazwa_="puste";
    rok_=0;
    studio_="pute";
    recenzja_="brak";
    liczbaOcen_=0;
    sumaOcen_=0;
    ocena_=0;
}
Gra::Gra(string nazwa,string studio, short rok,string recenzja,  int liczbaOcen,  int sumaOcen)
{
    nazwa_=nazwa;
    rok_=rok;
    studio_=studio;
    recenzja_=recenzja;
    liczbaOcen_=liczbaOcen;
    sumaOcen_=sumaOcen;
    ocena_=(double)sumaOcen/liczbaOcen;
}
Gra &Gra::operator=(const Gra &gra)
{
    nazwa_=gra.nazwa_;
    rok_=gra.rok_;
    studio_=gra.studio_;
    recenzja_=gra.recenzja_;
    liczbaOcen_=gra.liczbaOcen_;
    sumaOcen_=gra.sumaOcen_;
    ocena_=gra.ocena_;
    cout<<"konstruktor = Gra";
}
Gra::Gra(const Gra& gra)
{
    nazwa_=gra.nazwa_;
    rok_=gra.rok_;
    studio_=gra.studio_;
    recenzja_=gra.recenzja_;
    liczbaOcen_=gra.liczbaOcen_;
    sumaOcen_=gra.sumaOcen_;
    ocena_=gra.ocena_;
    cout<<"konstruktor kop Gra";
}

bool operator==(const Gra& pierwszy,const Gra& drugi)
{
    return(pierwszy.nazwa_==drugi.nazwa_);
}
Gra &Gra::operator+(int ocena)
{
    ++liczbaOcen_;
    sumaOcen_=sumaOcen_+ocena;
    ocena_=(double)sumaOcen_/liczbaOcen_;
    return *this;

}
Gra &Gra::operator-(int ocena)
{
    --liczbaOcen_;
    sumaOcen_=sumaOcen_-ocena;
    ocena_=(double)sumaOcen_/liczbaOcen_;
    return *this;

}

void Gra::Wypisz(ostream& os) const
{
    os<<nazwa_;

}
void Gra::Dodaj(istream& is)
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
    cout<<"Ocena gry ";
    is>>ocena_;
    liczbaOcen_=1;
    sumaOcen_=ocena_;
}

void Gra::Zpliku(ofstream& os) const
{
    os<<nazwa_<<endl;;
    os<<studio_<<endl;;
    os<<rok_<<endl;
    os<<recenzja_<<endl;
    os<<liczbaOcen_<<endl;
    os<<sumaOcen_<<endl;
}
void Gra::Dopliku(ifstream& is)
{
    getline(is,nazwa_);
    getline(is,studio_);
    is>>rok_;
    getline(is,recenzja_);
    getline(is,recenzja_);
    is>>liczbaOcen_;
    is>>sumaOcen_;
    ocena_=(double)sumaOcen_/liczbaOcen_;
}
ofstream& operator<< (ofstream& os,const Gra& gra)
{
    gra.Zpliku(os);
    return os;
}
istream& operator>> (istream& is,Gra& gra)
{
    gra.Dodaj(is);
    return is;
}
ifstream& operator>> (ifstream& is,Gra& gra)
{
    gra.Dopliku(is);
    return is;
}
bool operator==(const Gra& pierwszy,const string nazwa)
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
double Gra::WypiszOcene()
{
    return ocena_;
}

