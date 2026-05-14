#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
int n=10;
int k=2;
// dodaj osobne listy obecności które dzielą wskaźniki na tę same osoby dwie tablice każda



class Osoba
{
protected:
//data urodzenia                
    int Wzrost;
    string Imie;
    string Nazwisko;
public:
    void setWzrost(int Wzrost);
    void setImie(string Imie);
    void setNazwisko(string Nazwisko);
    int getWzrost();

    string getImie();
    string getNazwisko();
    void drukuj();
};
void Osoba::setWzrost(int wartosc)
{
    Wzrost=wartosc;
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
string Osoba::getImie()
{
    return Imie;
}
string Osoba::getNazwisko()
{
    return Nazwisko;
}
void Osoba::drukuj()
{
    cout<<Imie<<" "<<Nazwisko;
}

class Student:public Osoba
{
private:              
    int Indeks;
public:
    void setIndeks(int Indeks);
    int getIndeks();
    void drukuj();
};

void Student::setIndeks(int wartosc)
{
    if(wartosc>99999&&wartosc<1000000)
    {
        Indeks=wartosc;
    }
}
int Student::getIndeks()
{
    return Indeks;
}
void Student::drukuj()
{   
    cout<<Indeks<<" "<<Imie<<" "<<Nazwisko;
}
class Pracownik:public Osoba
{
private:              
    int Id;
public:
    void setId(int Indeks);
    int getId();
    void drukuj();
};

void Pracownik::setId(int wartosc)
{
    if(wartosc>99&&wartosc<1000)
    {
        Id=wartosc;
    }
}
int Pracownik::getId()
{
    return Id;
}
void Pracownik::drukuj()
{   
    cout<<Id<<" "<<Nazwisko<<" "<<Imie;
}
class Lista_obecnosci
{
private:
    Osoba **tabOsob;
    bool *tabObecnosc;
public:
    void settabOsob(Osoba **tabOsoba);
    void settabObecnosc(bool *tabObecnosc);
    Osoba** gettabOsoba();
    bool* gettabObecnosc();
};
void Lista_obecnosci::settabOsob(Osoba **temp)
{
    tabOsob=temp;
}
void Lista_obecnosci::settabObecnosc(bool *temp)
{
    tabObecnosc=temp;
}
Osoba** Lista_obecnosci::gettabOsoba()
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
    Lista_obecnosci *tabList;
    int ileOsob, ileList;

    void dodajStudent(Osoba **tabOsoba, Student *Osoba);
    void dodajPracownik(Osoba **tabOsoba, Pracownik *Osoba);
    void ustawObecnosc(Osoba **tabOsob, bool *tabObecnosc, string Nazwisko, bool Obecnosc);
    void drukujListe(Osoba **tabOsob, bool *tabObecnosc);
    void Edytuj(Osoba **tabOsob, bool *tabObecnosc, string Nazwisko, Osoba Osoba, bool Obecnosc);
    void Usun(Osoba **tabOsob, bool *tabObecnosc, string Nazwisko);

public:
    void petla();
    void settabList(Lista_obecnosci *tabLista);
    void settabileOsob(int ileosob);
    void settabileList(int ilelist);

};
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
void Interfejs::dodajStudent(Osoba **tabOsob, Student *osoba)
{
    for(int i=0;i<ileOsob;i++)
    {
        if(tabOsob[i]->getNazwisko()=="")
        {
            tabOsob[i]=osoba;
            return;
        }
    }
    return;
}
void Interfejs::dodajPracownik(Osoba **tabOsob, Pracownik *osoba)
{
    for(int i=0;i<ileOsob;i++)
    {
        if(tabOsob[i]->getNazwisko()=="")
        {
            tabOsob[i]=osoba;
            return;
        }
    }
    return;
}
void Interfejs::ustawObecnosc(Osoba **tabOsob, bool *tabObecnosc, string Nazwisko, bool Obecnosc)
{
    for(int i=0;i<n;i++)
    {
        if(tabOsob[i]->getNazwisko()==Nazwisko)
        {
            tabObecnosc[i]=Obecnosc;
            return;
        }
    }
    return;
}
void Interfejs::drukujListe(Osoba **tabOsob, bool *tabObecnosc)
{
    for(int i=0;i<n;i++)
    {
        
        ((Student*)tabOsob[i])->drukuj();
        //((Pracownik*)tabOsob[i])->drukuj();
        cout<<" "<<tabObecnosc[i]<<"\n";
    }
    return;
}
void Interfejs::Edytuj(Osoba **tabOsob, bool *tabObecnosc, string Nazwisko, Osoba Osoba, bool Obecnosc)
{
    for(int i=0;i<n;i++)
    {
        if(tabOsob[i]->getNazwisko()==Nazwisko)
        {
            tabOsob[i]=&Osoba;
            tabObecnosc[i]=Obecnosc;
            
            return;
        }
    }
    return;
}
void Interfejs::Usun(Osoba **tabOsob, bool *tabObecnosc, string Nazwisko)
{
    Osoba temp;
    for(int i=0;i<n;i++)
    {
        if(tabOsob[i]->getNazwisko()==Nazwisko)
        {
            for(int j=i;j<n-1;j++)
            {
                tabOsob[j]=tabOsob[j+1];
                tabObecnosc[j]=tabObecnosc[j+1];
                
            }
            tabOsob[n-1]=&temp;
            tabObecnosc[n-1]=NULL;

            return;
        }
    }
    return;
}

void Interfejs::petla()
{
    
    int l=0;
    int tempint, nr_listy;
    string tempstring;
    bool Obecnosc;
    bool *tabObecnosc; 
    Osoba **tabOsob;
    Osoba os;
    os.setImie("");
    os.setNazwisko("");
    os.setWzrost(1);
    
    for(int i=0;i<ileList;i++)
    {
        tabObecnosc=new bool[n];
        tabOsob=new Osoba*[ileOsob];
        for(int j=0;j<ileOsob;j++)
        {
            tabOsob[j]=&os;     
        }
        tabList[i].settabObecnosc(tabObecnosc);
        tabList[i].settabOsob(tabOsob);
    }
    
    //Osoba **tabOsob=tabList[l].gettabOsoba();
    Student temp_Student;
    Pracownik temp_Pracownik;
    int m=1;
    
    while(m!=0)
    {
        cout<<"\nMenu:"<<"\n"<<"0-Wyjdz"<<"\n"<<"1-dodaj Studenta"<<"\n"<<"2-dodaj Pracownika"<<"\n"<<"3-ustaw Obecnosc"<<"\n"<<"4-wyswietl liste"<<"\n"<<"5-edytuj liste"<<"\n"<<"6-usun z listy"<<"\n"<<"7-zmien liste obecnosci(1-"<<k<<")";
        cin>>m;
        switch(m)
        {
        case 1:
            cout<<"Podaj numer indeksu: ";
            cin>>tempint;
            temp_Student.setIndeks(tempint);
            cout<<"Podaj Imie: ";
            cin>>tempstring;
            temp_Student.setImie(tempstring);
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            temp_Student.setNazwisko(tempstring);
            cout<<"Podaj Wzrost: ";
            cin>>tempint;
            temp_Student.setWzrost(tempint);
            dodajStudent(tabList[l].gettabOsoba(), &temp_Student);
            break;
        case 2:
            cout<<"Podaj numer id: ";
            cin>>tempint;
            temp_Pracownik.setId(tempint);
            cout<<"Podaj Imie: ";
            cin>>tempstring;
            temp_Pracownik.setImie(tempstring);
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            temp_Pracownik.setNazwisko(tempstring);
            cout<<"Podaj Wzrost: ";
            cin>>tempint;
            temp_Pracownik.setWzrost(tempint);
            dodajPracownik(tabList[l].gettabOsoba(), &temp_Pracownik);
            break;
        case 3:
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            cout<<"Obecosc(0-nieobecny, 1-obecny): ";
            cin>>Obecnosc;
            ustawObecnosc(tabList[l].gettabOsoba(), tabObecnosc, tempstring, Obecnosc);
            break;
        case 4:
            drukujListe(tabList[l].gettabOsoba(), tabList[l].gettabObecnosc());
            break;
        case 5:
            cout<<"Podaj numer indeksu: ";
            cin>>tempint;
            temp_Student.setIndeks(tempint);
            cout<<"Podaj Imie: ";
            cin>>tempstring;
            temp_Student.setImie(tempstring);
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            temp_Student.setNazwisko(tempstring);
            cout<<"Podaj Wzrost: ";
            cin>>tempint;
            temp_Student.setWzrost(tempint);
            cout<<"Obecosc(0-nieobecny, 1-obecny): ";
            cin>>Obecnosc;
            cout<<"Podaj nazwisko osoby do edycji: ";
            cin>>tempstring;
            Edytuj(tabList[l].gettabOsoba(), tabList[l].gettabObecnosc(), tempstring, temp_Student, Obecnosc);
            break;
        case 6:
            cout<<"Podaj Nazwisko: ";
            cin>>tempstring;
            Usun(tabList[l].gettabOsoba(), tabList[l].gettabObecnosc(), tempstring);
            break;
        case 7:
            cout<<"Podaj numer listy: ";
            cin>>nr_listy;
            l=nr_listy-1;
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
    
    Lista_obecnosci *tabList=new Lista_obecnosci[k];  
    Interfejs ui;
    
    ui.settabileOsob(n);
    ui.settabList(tabList);
    ui.settabileList(k);

    ui.petla();

    delete []tabList;
    tabList=nullptr;    
    return 0;
}
