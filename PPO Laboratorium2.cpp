#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
int n=10;
int k=2;
// dodaj osobne listy obecności które dzielą wskaźniki na tę same osoby
class Osoba
{
private:
//data urodzenia
//wzrost
    int Indeks;
    string Imie;
    string Nazwisko;
public:
    void setIndeks(int Indeks);
    void setImie(string Imie);
    void setNazwisko(string Nazwisko);
    int getIndeks();
    string getImie();
    string getNazwisko();
};
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
void dodajOsobe(Osoba *tabOsoba, Osoba Osoba)
{
    for(int i=0;i<n;i++)
    {
        if(tabOsoba[i].getNazwisko()=="")
        {
            tabOsoba[i]=Osoba;
            return;
        }
    }
    return;
}
void ustawObecnosc(Osoba *tabOsoba, bool **tabObecnosc, string Nazwisko, bool Obecnosc, int nr_listy)
{
    for(int i=0;i<n;i++)
    {
        if(tabOsoba[i].getNazwisko()==Nazwisko)
        {
            tabObecnosc[i][nr_listy-1]=Obecnosc;
            return;
        }
    }
    return;
}
void drukujListe(Osoba *tabOsoba, bool **tabObecnosc)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<tabOsoba[i].getIndeks()<<" ,"<<tabOsoba[i].getImie()<<" ,"<<tabOsoba[i].getNazwisko();
        for(int j=0;j<k;j++)
        {
            cout<<" ,"<<tabObecnosc[i][j];
        }
    }
    return;
}
void Edytuj(Osoba *tabOsoba, bool **tabObecnosc, string Nazwisko, Osoba Osoba, bool *Obecnosc)
{
    for(int i=0;i<n;i++)
    {
        if(tabOsoba[i].getNazwisko()==Nazwisko)
        {
            tabOsoba[i]=Osoba;
        for(int j=0;j<k;j++)
        {
            tabObecnosc[i][j]=Obecnosc[j];
        }
            
            return;
        }
    }
    return;
}
void Usun(Osoba *tabOsoba, bool **tabObecnosc, string Nazwisko)
{
    Osoba temp;
    for(int i=0;i<n;i++)
    {
        if(tabOsoba[i].getNazwisko()==Nazwisko)
        {
            for(int j=i;j<n-1;j++)
            {
                tabOsoba[j]=tabOsoba[j+1];
                for(int l=0;l<k;l++)
                {
                    tabObecnosc[j][l]=tabObecnosc[j+1][l];
                }
                
            }

            tabOsoba[n-1]=temp;
            for(int l=0;l<k;l++)
            {
                tabObecnosc[n-1][l]=NULL;
            }
            return;
        }
    }
    return;
}
int main()
{
    bool **tabObecnosc=new bool*[n];
    for(int i=0;i<n;i++)
    {
		tabObecnosc[i] = new bool[k];
    }
    bool *tempObecnosc=new bool[k];    
    
    int nr_indeksu, nr_listy;
    string tempstring;
    bool Obecnosc;
    

    Osoba *tabOsoba=new Osoba[n];
    Osoba temp_Osoba;
    
    int m=1;
    while(m!=0)
    {
        cout<<"\nMenu:"<<"\n"<<"0-Wyjdz"<<"\n"<<"1-dodaj Osobe"<<"\n"<<"2-ustaw Obecnosc"<<"\n"<<"3-wyswietl liste"<<"\n"<<"4-edytuj liste"<<"\n"<<"5-usun z listy";
        cin>>m;
        switch(m)
        {
        case 1:
            cout<<"Podaj numer indeksu: ";
            cin>>nr_indeksu;
            temp_Osoba.setIndeks(nr_indeksu);
            cout<<"Podaj Imie: ";
            cin>>tempstring;
            temp_Osoba.setImie(tempstring);
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            temp_Osoba.setNazwisko(tempstring);
            dodajOsobe(tabOsoba, temp_Osoba);
            break;
        case 2:
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            cout<<"Podaj Numer listy obecnosci ";
            cin>>nr_listy;
            cout<<"Obecosc(0-nieobecny, 1-obecny): ";
            cin>>Obecnosc;
            ustawObecnosc(tabOsoba, tabObecnosc, tempstring, Obecnosc, nr_listy);
            break;
        case 3:
            drukujListe(tabOsoba, tabObecnosc);
            break;
        case 4:
            cout<<"Podaj numer indeksu: ";
            cin>>nr_indeksu;
            temp_Osoba.setIndeks(nr_indeksu);
            cout<<"Podaj Imie: ";
            cin>>tempstring;
            temp_Osoba.setImie(tempstring);
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            temp_Osoba.setNazwisko(tempstring);
            for(int i=0;i<k;i++)
            {
            cout<<"Obecosc["<<i+1<<"](0-nieobecny, 1-obecny): ";
            cin>>tempObecnosc[i];
            }
            cout<<"Podaj nazwisko osoby do edycji: ";
            cin>>tempstring;
            Edytuj(tabOsoba, tabObecnosc, tempstring, temp_Osoba, tempObecnosc);
            break;
        case 5:
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            Usun(tabOsoba, tabObecnosc, tempstring);
            break;
        default:
            break;
        }
    }
    delete []tabOsoba;
    tabOsoba=nullptr;
    delete []tabObecnosc;
    tabObecnosc=nullptr;    
    delete []tempObecnosc;
    tempObecnosc=nullptr;
    return 0;
}