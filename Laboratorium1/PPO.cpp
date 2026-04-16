#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
int n=10;
void dodajOsobe(int *tabIndeks, string *tabImie, string *tabNazwiska, int nr_indeksu, string Imie, string Nazwisko)
{
    for(int i=0;i<n;i++)
    {
        if(tabNazwiska[i]=="")
        {
            tabIndeks[i]=nr_indeksu;
            tabImie[i]=Imie;
            tabNazwiska[i]=Nazwisko;
            return;
        }
    }
    return;
}
void ustawObecnosc(string *tabNazwiska, bool *tabObecnosc, string Nazwisko, bool Obecnosc)
{
    for(int i=0;i<n;i++)
    {
        if(tabNazwiska[i]==Nazwisko)
        {
            tabObecnosc[i]=Obecnosc;
            return;
        }
    }
    return;
}
void drukujListe(int *tabIndeks, string *tabImie, string *tabNazwiska, bool *tabObecnosc)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<tabIndeks[i]<<" ,"<<tabImie[i]<<" ,"<<tabNazwiska[i]<<" ,"<<tabObecnosc[i];
    }
    return;
}
void Edytuj(int *tabIndeks, string *tabImie, string *tabNazwiska, bool *tabObecnosc, string stareNazwisko, int nr_indeksu, string Imie, string Nazwisko, bool Obecnosc)
{
    for(int i=0;i<n;i++)
    {
        if(tabNazwiska[i]==stareNazwisko)
        {
            tabIndeks[i]=nr_indeksu;
            tabImie[i]=Imie;
            tabNazwiska[i]=Nazwisko;
            tabObecnosc[i]=Obecnosc;
            return;
        }
    }
    return;
}
void Usun(int *tabIndeks, string *tabImie, string *tabNazwiska, bool *tabObecnosc, string Nazwisko)
{
    for(int i=0;i<n;i++)
    {
        if(tabNazwiska[i]==Nazwisko)
        {
            for(int j=i;j<n-1;j++)
            {
                tabIndeks[j]=tabIndeks[j+1];
                tabImie[j]=tabImie[j+1];
                tabNazwiska[j]=tabNazwiska[j+1];
                tabObecnosc[j]=tabObecnosc[j+1];
            }
            tabIndeks[n-1]=0;
            tabImie[n-1]="";
            tabNazwiska[n-1]="";
            tabObecnosc[n-1]=NULL;
            return;
        }
    }
    return;
}
int main()
{
    int *tabIndeks=new int[n];
    string *tabImie=new string[n];
    string *tabNazwiska=new string[n];
    bool *tabObecnosc=new bool[n];
    for(int i=0;i<n;i++)
    {
        tabIndeks[i]=0;
        tabObecnosc[i]=0;
    }
        
    int nr_indeksu;
    string Imie, Nazwisko, stareNazwisko;
    bool Obecnosc;
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
            cout<<"Podaj Imie: ";
            cin>>Imie;
            cout<<"Podaj Nazwisko: ";
            cin>>Nazwisko;
            dodajOsobe(tabIndeks, tabImie, tabNazwiska, nr_indeksu, Imie, Nazwisko);
            break;
        case 2:
            cout<<"Podaj Nazwisko: ";
            cin>>Nazwisko;
            cout<<"Obecosc(0-nieobecny, 1-obecny): ";
            cin>>Obecnosc;
            ustawObecnosc(tabNazwiska, tabObecnosc, Nazwisko, Obecnosc);
            break;
        case 3:
            drukujListe(tabIndeks, tabImie, tabNazwiska, tabObecnosc);
            break;
        case 4:
            cout<<"Podaj nazwisko do edycji: ";
            cin>>stareNazwisko;
            cout<<"Podaj numer indeksu: ";
            cin>>nr_indeksu;
            cout<<"Podaj Imie: ";
            cin>>Imie;
            cout<<"Podaj Nazwisko: ";
            cin>>Nazwisko;
            cout<<"Obecosc(0-nieobecny, 1-obecny): ";
            cin>>Obecnosc;
            Edytuj(tabIndeks, tabImie, tabNazwiska, tabObecnosc,stareNazwisko, nr_indeksu, Imie, Nazwisko, Obecnosc);
            break;
        case 5:
            cout<<"Podaj Nazwisko: ";
            cin>>Nazwisko;
            Usun(tabIndeks, tabImie, tabNazwiska, tabObecnosc, Nazwisko);
            break;
        default:
            break;
        }
    }
    delete []tabIndeks;
    tabIndeks=nullptr;
    delete []tabImie;
    tabImie=nullptr;
    delete []tabNazwiska;
    tabNazwiska=nullptr;
    delete []tabObecnosc;
    tabObecnosc=nullptr;    
    return 0;
}
