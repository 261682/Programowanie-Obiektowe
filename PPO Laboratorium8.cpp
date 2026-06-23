// ============================================================
//  Lab: Interfejsy i wzorzec Strategy
//  Paradygmaty Programowania Obiektowego
//
// ============================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ============================================================
//  KLASY PODSTAWOWE
//  Mozesz skopiować tutaj swoje klasy Student i ListaObecnosci,
//  z poprzednich zajec, lub użyć zaproponowanych (uproszczone)
// ============================================================


// ============================================================
// STUDENT
// Bazowa implementacja - tylko podstawowe informacje o studencie
// ustawianie danych przez konstruktor, bez setterów
// ============================================================

class Student {
  private:
    string imie;
    string nazwisko;
    string nrIndeksu;

  public:
    Student(string imie, string nazwisko, string nrIndeksu)
        : imie(imie), nazwisko(nazwisko), nrIndeksu(nrIndeksu) {}

    string getImie()       { return imie; }
    string getNazwisko()   { return nazwisko; }
    string getNrIndeksu() { return nrIndeksu; }
};


// ============================================================
//  ListaObecnosci
//
//  Prosta implementacja oparta o dwie oddzielne tablice polaczone indeksem:
//    studenci[i]  — wskaznik do obiektu Student
//    obecnosc[i]  — licznik obecnosci studenta i
//
//  Indeksy obu tablic sa zsynchronizowane:
//  obecnosc[2] to liczba obecnosci studenta studenci[2].
// ============================================================
class ListaObecnosci {
  private:
    Student** studenci;
    int*      obecnosc;
    int       liczba_zajec;
    int       rozmiar;
    int       pojemnosc;
    string nazwa_przedmiotu;

  public:
    ListaObecnosci(string nazwa, int pojemnosc)
        : liczba_zajec(0), rozmiar(0), pojemnosc(pojemnosc),
          nazwa_przedmiotu(nazwa) {
        studenci = new Student*[pojemnosc];
        obecnosc = new int[pojemnosc];
        for (int i = 0; i < pojemnosc; i++)
            obecnosc[i] = 0;
    }

    ~ListaObecnosci() {
        for (int i = 0; i < rozmiar; i++)
            delete studenci[i];
        delete[] studenci;
        delete[] obecnosc;
    }

    void dodajStudenta(Student* s) {
        if (rozmiar < pojemnosc)
            studenci[rozmiar++] = s;
    }

    // Zaznacza obecnosc dla jednych zajec.
    // obecni[i] == 1 oznacza ze student studenci[i] byl obecny.
    // obecni[i] == 0 oznacza nieobecnosc.
    void zaznaczObecnosc(int* obecni, int rozmiar_tablicy) {
        liczba_zajec++;
        for (int i = 0; i < rozmiar_tablicy && i < rozmiar; i++)
            if (obecni[i])
                obecnosc[i]++;
    }

    int getLiczbaObecnosci(int i) { return obecnosc[i]; }
    int getLiczbaZajec()          { return liczba_zajec; }
    
    int getProcentObecnosci(int i) {
        if (liczba_zajec == 0) return 0;
        return (obecnosc[i] * 100) / liczba_zajec;
    }

    Student**   getStudenci() { return studenci; }
    int*        getObecnosc() { return obecnosc; }
    int         getRozmiar()  { return rozmiar; }
    string getNazwa()    { return nazwa_przedmiotu; }
};


// ============================================================
//  INTERFEJSY
//  Nie modyfikuj tych klas.
// ============================================================

class IFiltr {
  public:
    // Zwraca nowa tablice wskaznikow do studentow spelniajacych
    // kryterium. Rozmiar wynikowej tablicy zapisywany jest
    // do *wynik_rozmiar. Wywolujacy jest odpowiedzialny za
    // zwolnienie pamieci tablicy wynikowej (nie obiektow Student).
    virtual Student** filtruj(Student** studenci,
                              int*      obecnosc,
                              int       liczba_zajec,
                              int       rozmiar,
                              int*      wynik_rozmiar) = 0;
};



// ============================================================
//  CZESC 1 — IMPLEMENTACJE IFiltr
//
//  Zaimplementuj jedna z ponizszych klas.
//  UWAGA - każda klasa w swoim konstruktorze powinna przyjmować
//  odpowiewni parametr (prog, litere lub cyfre)
//
//  FiltrProguObecnosci — zwraca studentow ktorych procent
//    obecnosci jest nizszy niz prog podany w konstruktorze
//.   np. FiltrProguObecniosci(50) zwroci studentow ktorzy byli obecni na mniej niz 50% zajec
//
//  FiltrNazwiska — zwraca studentow ktorych nazwisko
//    zaczyna sie na litere podana w konstruktorze
//    np. FiltrNazwiska('K') zwroci studentow ktorzy mają nazwisko zaczynające się na literę 'K'
//
//  FiltrIndeksu — zwraca studentow ktorych numer indeksu
//    zaczyna sie od ciagu znakow podanego w konstruktorze
//.   np. FiltrIndeksu("12") zwroci studentow ktorzy mają numer indeksu zaczynający się od "12"
// ============================================================


//  PRZYKLAD IMPLEMENTACJI TYPU "STUB"
//  FiltrStub zwraca cala tablice, ktora otrzymal na wejsciu
//

class FiltrStub : public IFiltr {
  public:
    Student** filtruj(Student** studenci, int* obecnosc,
                      int liczba_zajec, int rozmiar,
                      int* wynik_rozmiar) {
        Student** wynik = new Student*[rozmiar];
        for (int i = 0; i < rozmiar; i++)
            wynik[i] = studenci[i];
        *wynik_rozmiar = rozmiar;
        return wynik;
    }

};


// TUTAJ ZAIMPLEMENTUJ FILTRY
class FiltrNazwiska : public IFiltr {
  public:
    string prug;
    Student** filtruj(Student** studenci, int* obecnosc,
                      int liczba_zajec, int rozmiar,
                      int* wynik_rozmiar) 
    {
        //string temp;

        Student** wynik = new Student*[rozmiar];
        int j=0;
        for (int i = 0; i < rozmiar; i++)
        {
            //temp=studenci[i]->getNazwisko().substr(0,prug.length());
            
            if(studenci[i]->getNazwisko().substr(0,prug.length())==prug)
            {
            wynik[j] = studenci[i];
            j++;
            }

        }
        *wynik_rozmiar = j;
        return wynik;
    }

    FiltrNazwiska(string temp);
};
FiltrNazwiska::FiltrNazwiska(string temp)
    {
        prug=temp;
    }

class FiltrProguObecnosci : public IFiltr {
  public:
    int prug;
    Student** filtruj(Student** studenci, int* obecnosc,
                      int liczba_zajec, int rozmiar,
                      int* wynik_rozmiar) 
    {
        Student** wynik = new Student*[rozmiar];
        int j=0;
        for (int i = 0; i < rozmiar; i++)
        {
            if((obecnosc[i]*100)/liczba_zajec<prug)
            {
            wynik[j] = studenci[i];
            j++;
            }

        }
        *wynik_rozmiar = j;
        return wynik;
    }

    FiltrProguObecnosci(int temp);
};
FiltrProguObecnosci::FiltrProguObecnosci(int temp)
    {
        prug=temp;
    }

class FiltrIndeksu : public IFiltr {
private:
    string prefiks;
public:
    FiltrIndeksu(string prefiks) : prefiks(prefiks) {}

    Student** filtruj(Student** studenci, int* obecnosc, 
                      int liczba_zajec, int rozmiar, 
                      int* wynik_rozmiar) {

        int dopasowania = 0;
        for (int i = 0; i < rozmiar; i++) {
            if (studenci[i]->getNrIndeksu().find(prefiks) == 0) {
                dopasowania++;
            }
        }

        Student** wynik = new Student*[dopasowania];
        int indeks_wyniku = 0;
        for (int i = 0; i < rozmiar; i++) {
            if (studenci[i]->getNrIndeksu().find(prefiks) == 0) {
                wynik[indeks_wyniku++] = studenci[i];
            }
        }

        *wynik_rozmiar = dopasowania;
        return wynik;
    }
};

// ============================================================
//  MAIN i przyklad filtra
// ============================================================


void testFiltrowania(IFiltr *filtr, ListaObecnosci *lista){
    int wynik_rozmiar_stub = 0;
    Student **wynikStub = filtr->filtruj(lista->getStudenci(),
                                            lista->getObecnosc(),
                                            lista->getLiczbaZajec(),
                                            lista->getRozmiar(),
                                            &wynik_rozmiar_stub);

    for(int i=0; i<wynik_rozmiar_stub; i++){
      cout << wynikStub[i]->getImie() << endl;
    }

    delete[] wynikStub;


}



int main() {
    ListaObecnosci lista("Paradygmaty Programowania Obiektowego", 10);

    lista.dodajStudenta(new Student("Anna",    "Kowalska",   "123456"));
    lista.dodajStudenta(new Student("Bartosz", "Nowak",      "654321"));
    lista.dodajStudenta(new Student("Celina",  "Kwiatkowska","111111"));
    lista.dodajStudenta(new Student("Damian",  "Krawczyk",   "222222"));

    // symulacja trzech zajec
    // zajecia 1: Anna, Celina i Damian obecni
    int zajecia1[] = {1, 0, 1, 1};
    lista.zaznaczObecnosc(zajecia1, lista.getRozmiar());

    // zajecia 2: tylko Damian obecny
    int zajecia2[] = {0, 0, 0, 1};
    lista.zaznaczObecnosc(zajecia2, lista.getRozmiar());

    // zajecia 3: Anna i Celina obecne
    int zajecia3[] = {1, 0, 1, 0};
    lista.zaznaczObecnosc(zajecia3, lista.getRozmiar());

    // PRZYKLADY UZYCIA FILTRA, RAPORTU i NOTYFIKATORA na podstawie interfejsów
    cout<<"FiltrStub: \n";
    FiltrStub filtrStub;
    testFiltrowania(&filtrStub, &lista);
    cout<<"FiltrProguObecnosci(50): \n";
    FiltrProguObecnosci filtrProguObecnosci(50);
    testFiltrowania(&filtrProguObecnosci, &lista);
    cout<<"FiltrNazwiska(K): \n";
    FiltrNazwiska filtrNazwiska("K");
    testFiltrowania(&filtrNazwiska, &lista);
    cout<<"FiltrIndeksu(11): \n";
    FiltrIndeksu filtrIndeksu("11");
    testFiltrowania(&filtrIndeksu, &lista);


    return 0;
}