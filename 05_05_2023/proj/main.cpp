#include "bib2.h"
#include "bib.h"
#include<iostream>
int main()
{
    Towar t(124,10);
    Towar t2(123,10);
    Towar t1(122,10);

    SpisTowaru S;
    SpisTowaru S1;


    S.wstaw(t);
    S.wstaw(t1);
    S.wstaw(t2);

    Towar t11(124,11);
    S1.wstaw(t11);

    S.odejmijZeSpisu(S1);
    S.wypisz();
    return 0;
}
