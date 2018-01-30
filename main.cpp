#include <iostream>
#include <string>
#include <fstream>
#include "Gra.h"
#include "Katalog.h"
#include "Komputerowa.h"
#include "Planszowa.h"
#include <stdexcept>
using namespace std;

class ZlyZnak
{
    char co_;
    public:
    string what_;
    ZlyZnak(const string& what):
        what_(what) {};
};
void drugaczesc(Katalog &kat)
{

        int k=0;
        cout<<"Szukaj Gry wybierz 1"<<endl;
        cout<<"Wyjscie, wybierz 3"<<endl;
        cin>>k;
        switch(k)
        {
        case 1:
        {
        cout<<"Podaj nazwe gry"<<endl;
        string nazwa;
        cin>>nazwa;
        kat.Szukaj(nazwa);
        cout<<"Czy znalazles gre ktorej szukasz?(t/n)"<<endl;
        char p;
        int id;
        try
{
         cin>>p;


        if(p=='t')
        {
            cout<<"Zeby dodac ocene wpisz numer id gry ktora chcesz ocenic oraz ocene"<<endl;
            cout<<"Zeby usunac gre wpisz -1"<<endl;
            cin>>id;
            if(id==-1)
            {
            cout<<"Zeby usunac wpisz numer id gry ktora chcesz usunac"<<endl;
            cin>>id;
            kat-id;
            drugaczesc(kat);
            }
            cin>>k;
            if(id>0&&k<=10)
            {
               kat.DodajOcene(id-1,k);
            }
            else
            {
                throw ZlyZnak("Podano nieprawidlowa wartosc");
            }
            drugaczesc(kat);

        }
        if(p=='n')
        {
            cout<<"Czy chcesz dodac nowa gre?(t/n)"<<endl;
            cin>>p;
            if(p=='n')
                drugaczesc(kat);
            if(p=='t')
            {
                cout<<"Komputerowa czy Planszowa?(K/P)"<<endl;
                cin>>p;
                if(p=='k')
                {
                    string smiec;
                    Komputerowa nowa;
                    getline(cin,smiec);
                    cin>>nowa;
                    kat+nowa;

                }
                if(p=='P')
                {
                    string smiec;
                    Planszowa nowa;
                    getline(cin,smiec);
                    cin>>nowa;
                    kat+nowa;
                }
            }
        }
}
    catch (const ZlyZnak())
    {

    }

        drugaczesc(kat);
        break;
        }
        case 3:
        {
        ofstream plikWyjscia("Katalog.txt");
        plikWyjscia<<kat;
        break;
        }
        default:
        {
        drugaczesc(kat);
        break;
        }
        }

}
void poczatek(Katalog &kat)
{   ifstream plik("Katalog.txt");
    plik>>kat;
    int id=0;
    cout<< "Witaj"<<endl;
        drugaczesc(kat);
    }


int main()
{
    Katalog kat;
    poczatek(kat);
    Komputerowa t("to","stusodsd",1994,"to jest super gra",6,20,"akcja",true);
    cout<<t<<endl<<endl;
    kat+t;
    cout<<kat;

    return 0;
}
