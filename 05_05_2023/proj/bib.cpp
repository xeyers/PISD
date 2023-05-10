#include "bib.h"
#include<iostream>
int Towar::getKod() const
{
    return kod;
}

int Towar::getIlosc() const
{
    return ilosc;
}

void Towar::setKod(int k)
{
    kod = k;
}

void Towar::setIlosc(int i)
{
    ilosc = i;
}

bool Towar::operator<(const Towar& t) const
{
    return kod < t.getKod();
}

bool Towar::operator==(const Towar& t) const
{
    return kod == t.getKod();
}

void Towar::wypiszTowar() const
{
    std::cout << "kod: " << kod << std::endl << "ilosc: " << ilosc << std::endl;
}
