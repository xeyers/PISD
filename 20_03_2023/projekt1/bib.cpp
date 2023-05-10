#include "bib.h"

void Kolejka::wstaw(const int& a)
{
    int* pom = new int [ileJest+1];

    for(int i = 0; i < ileJest; i++)
    {
        pom[i] = dane[i];
    }

    pom[ileJest] = a;

    delete [] dane;

    dane = pom;

    ileJest++;
}

Kolejka::~Kolejka()
{
    delete [] dane;
}

void Kolejka::wypisz() const
{
    for(int i = 0; i < ileJest; i++) cout << dane[i] << ' ';
}

int Kolejka::zdejmij()
{
    if(ileJest == 0) throw underflow_error("brak elementow do zdjecia");

    int do_zwrotu = dane[0];

    int *pom = new int [ileJest - 1];

    for(int i = 0; i < ileJest - 1; i++)
    {
        pom[i] = dane[i+1];
    }

    delete [] dane;

    dane = pom;

    ileJest--;

    return do_zwrotu;
}


Kolejka::Kolejka(Kolejka& k)
{

    ileJest = k.ileJest;

    dane = new int [ileJest];

    for(int i = 0; i < ileJest; i++)
    {
        dane[i] = k.dane[i];
    }
}


Kolejka& Kolejka::operator=(const Kolejka& k)
{
    if(this == &k) return *this;

    delete [] dane;

    ileJest = k.ileJest;
    if(k.dane != nullptr)
    {
       dane = new int [ileJest];

        for(int i = 0; i < ileJest; i++)
        {
            dane[i] = k.dane[i];
        }
    }
    else dane = nullptr;


    return *this;
}

bool Kolejka::operator==(const Kolejka& k)
{
    if(ileJest != k.ileJest) return false;

    for(int i = 0; i < ileJest; i++)
    {
        if(dane[i] != k.dane[i]) return false;
    }

    return true;
}

void Kolejka::wyczysc()
{
    if(dane != nullptr)
    {
        delete [] dane;
        ileJest = 0;
        dane = nullptr;
    }
    else return;
}

int Kolejka::getRozmiar() const
{
    return ileJest;
}

int Kolejka::getFirst() const
{
    if(dane == nullptr) throw runtime_error("Kolejka jest pusta");
    return dane[0];
}

int:: Kolejka::getLast() const
{
    if(dane == nullptr) throw runtime_error("Kolejka jest pusta");
    return dane[ileJest - 1];
}
