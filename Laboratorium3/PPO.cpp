#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
int n=10;
int k=2;
// dodaj osobne listy obecności które dzielą wskaźniki na tę same osoby dwie tablice każda



class Osoba
{
private:
//data urodzenia                
    int Wzrost;
    int Indeks;
    string Imie;
    string Nazwisko;
public:
    void setWzrost(int Wzrost);
    void setIndeks(int Indeks);
    void setImie(string Imie);
    void setNazwisko(string Nazwisko);
    int getWzrost();
    int getIndeks();
    string getImie();
    string getNazwisko();
};
void Osoba::setWzrost(int wartosc)
{
    Wzrost=wartosc;
}
void Osoba::setIndeks(int wartosc)
{
    if(wartosc>99999&&wartosc<1000000)
    {
        Indeks=wartosc;
    }
}
void Osoba::setImie(string wartosc)
{
    if(wartosc.length()>0)
    {
        Imie=wartosc;
    }
}
void Osoba::setNazwisko(string wartosc)
{
    if(wartosc.length()>0)
    {
        Nazwisko=wartosc;
    }
}
int Osoba::getWzrost()
{
    return Wzrost;
}
int Osoba::getIndeks()
{
    return Indeks;
}
string Osoba::getImie()
{
    return Imie;
}
string Osoba::getNazwisko()
{
    return Nazwisko;
}

class Lista_obecnosci
{
private:
    Osoba *tabOsob;
    bool *tabObecnosc;
public:
    void settabOsob(Osoba *tabOsoba);
    void settabObecnosc(bool *tabObecnosc);
    Osoba* gettabOsoba();
    bool* gettabObecnosc();
};
void Lista_obecnosci::settabOsob(Osoba *temp)
{
    tabOsob=temp;
}
void Lista_obecnosci::settabObecnosc(bool *temp)
{
    tabObecnosc=temp;
}
Osoba* Lista_obecnosci::gettabOsoba()
{
    return tabOsob;
}
bool* Lista_obecnosci::gettabObecnosc()
{
    return tabObecnosc;
}


class Interfejs
{
private:
    Osoba *tabOsob;
    Lista_obecnosci *tabList;
    int ileOsob, ileList;

    void dodajOsobe(Osoba *tabOsoba, Osoba Osoba);
    void ustawObecnosc(Osoba *tabOsob, bool *tabObecnosc, string Nazwisko, bool Obecnosc);
    void drukujListe(Osoba *tabOsob, bool *tabObecnosc);
    void Edytuj(Osoba *tabOsob, bool *tabObecnosc, string Nazwisko, Osoba Osoba, bool Obecnosc);
    void Usun(Osoba *tabOsob, bool *tabObecnosc, string Nazwisko);

public:
    void petla();
    void settabOsob(Osoba *tabOsoba);
    void settabList(Lista_obecnosci *tabLista);
    void settabileOsob(int ileosob);
    void settabileList(int ilelist);

};
void Interfejs::settabOsob(Osoba *temp)
{
    tabOsob=temp;
}
void Interfejs::settabList(Lista_obecnosci *temp)
{
    tabList=temp;
}
void Interfejs::settabileOsob(int temp)
{
    ileOsob=temp;
}
void Interfejs::settabileList(int temp)
{
    ileList=temp;
}
void Interfejs::dodajOsobe(Osoba *tabOsob, Osoba Osoba)
{
    for(int i=0;i<n;i++)
    {
        if(tabOsob[i].getNazwisko()=="")
        {
            tabOsob[i]=Osoba;
            return;
        }
    }
    return;
}
void Interfejs::ustawObecnosc(Osoba *tabOsob, bool *tabObecnosc, string Nazwisko, bool Obecnosc)
{
    for(int i=0;i<n;i++)
    {
        if(tabOsob[i].getNazwisko()==Nazwisko)
        {
            tabObecnosc[i]=Obecnosc;
            return;
        }
    }
    return;
}
void Interfejs::drukujListe(Osoba *tabOsob, bool *tabObecnosc)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<tabOsob[i].getIndeks()<<" ,"<<tabOsob[i].getImie()<<" ,"<<tabOsob[i].getNazwisko()<<" ,"<<tabOsob[i].getWzrost()<<" ,"<<tabObecnosc[i];
    }
    return;
}
void Interfejs::Edytuj(Osoba *tabOsob, bool *tabObecnosc, string Nazwisko, Osoba Osoba, bool Obecnosc)
{
    for(int i=0;i<n;i++)
    {
        if(tabOsob[i].getNazwisko()==Nazwisko)
        {
            tabOsob[i]=Osoba;
            tabObecnosc[i]=Obecnosc;
            
            return;
        }
    }
    return;
}
void Interfejs::Usun(Osoba *tabOsob, bool *tabObecnosc, string Nazwisko)
{
    Osoba temp;
    for(int i=0;i<n;i++)
    {
        if(tabOsob[i].getNazwisko()==Nazwisko)
        {
            for(int j=i;j<n-1;j++)
            {
                tabOsob[j]=tabOsob[j+1];
                tabObecnosc[j]=tabObecnosc[j+1];
                
            }
            tabOsob[n-1]=temp;
            tabObecnosc[n-1]=NULL;

            return;
        }
    }
    return;
}

void Interfejs::petla()
{
    int tempint, nr_listy;
    string tempstring;
    bool Obecnosc;
    bool *tabObecnosc; 
    for(int i=ileList-1;i>=0;i--)
    {
        tabObecnosc=new bool[n];
        
        tabList[i].settabObecnosc(tabObecnosc);
        tabList[i].settabOsob(tabOsob);
    }
    

    Osoba temp_Osoba;
    int m=1;
    
    while(m!=0)
    {
        cout<<"\nMenu:"<<"\n"<<"0-Wyjdz"<<"\n"<<"1-dodaj Osobe"<<"\n"<<"2-ustaw Obecnosc"<<"\n"<<"3-wyswietl liste"<<"\n"<<"4-edytuj liste"<<"\n"<<"5-usun z listy"<<"\n"<<"6-zmien liste obecnosci(1-"<<k<<")";
        cin>>m;
        switch(m)
        {
        case 1:
            cout<<"Podaj numer indeksu: ";
            cin>>tempint;
            temp_Osoba.setIndeks(tempint);
            cout<<"Podaj Imie: ";
            cin>>tempstring;
            temp_Osoba.setImie(tempstring);
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            temp_Osoba.setNazwisko(tempstring);
            cout<<"Podaj Wzrost: ";
            cin>>tempint;
            temp_Osoba.setWzrost(tempint);
            dodajOsobe(tabOsob, temp_Osoba);
            break;
        case 2:
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            cout<<"Obecosc(0-nieobecny, 1-obecny): ";
            cin>>Obecnosc;
            ustawObecnosc(tabOsob, tabObecnosc, tempstring, Obecnosc);
            break;
        case 3:
            drukujListe(tabOsob, tabObecnosc);
            break;
        case 4:
            cout<<"Podaj numer indeksu: ";
            cin>>tempint;
            temp_Osoba.setIndeks(tempint);
            cout<<"Podaj Imie: ";
            cin>>tempstring;
            temp_Osoba.setImie(tempstring);
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            temp_Osoba.setNazwisko(tempstring);
            cout<<"Podaj Wzrost: ";
            cin>>tempint;
            temp_Osoba.setWzrost(tempint);
            cout<<"Obecosc(0-nieobecny, 1-obecny): ";
            cin>>Obecnosc;
            cout<<"Podaj nazwisko osoby do edycji: ";
            cin>>tempstring;
            Edytuj(tabOsob, tabObecnosc, tempstring, temp_Osoba, Obecnosc);
            break;
        case 5:
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            Usun(tabOsob, tabObecnosc, tempstring);
            break;
        case 6:
            cout<<"Podaj numer listy: ";
            cin>>nr_listy;
            tabOsob=tabList[nr_listy-1].gettabOsoba();
            tabObecnosc=tabList[nr_listy-1].gettabObecnosc();
            break;
        default:
            break;
        }
    }
    delete []tabObecnosc;
    tabObecnosc=nullptr; 
}

int main()
{
    Osoba *tabOsob=new Osoba[n];
    Lista_obecnosci *tabList=new Lista_obecnosci[k];  
    
    Interfejs ui;
    ui.settabOsob(tabOsob);
    ui.settabileOsob(n);
    ui.settabList(tabList);
    ui.settabileList(k);

    ui.petla();

    delete []tabOsob;
    tabOsob=nullptr;   
    delete []tabList;
    tabList=nullptr;    
    return 0;
}
