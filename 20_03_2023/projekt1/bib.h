#ifndef bib
#define bib


#include<iostream>
#include<stdexcept>
using namespace std;

struct Kolejka
{
private:
    int *dane; //adres poczatku tablicy
    int ileJest; //dlugosc tablicy (cala tablica zawsze pelna)
public:
    Kolejka() : dane(nullptr),ileJest(0){};
    Kolejka(Kolejka& k);
    ~Kolejka();
    void wstaw(const int& a); //zastepuje tablice z danymi dluzsza tablica dokladajac liczbe A na koncu
    void wypisz() const;
    int zdejmij();
    Kolejka& operator= (const Kolejka& k);
    bool operator==(const Kolejka& k);
    void wyczysc();
    int getRozmiar() const;
    int getFirst() const;
    int getLast() const;
};

#endif // bib
