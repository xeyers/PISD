#include "bib.h"

int main()
{
    Kolejka k;

    k.wstaw(2);
    k.wstaw(5);
    k.wstaw(7);
    k.wstaw(3);

    k.wypisz();

    endl(cout);
    endl(cout);

    cout << k.zdejmij();

    endl(cout);
    endl(cout);

    k.wypisz();

    endl(cout);
    endl(cout);

    Kolejka k2(k);
    k2.wypisz();

    Kolejka k3;
    k3.wstaw(4);
    k3.wstaw(5);
    k3.wstaw(6);

    k2 = k3;

    endl(cout);
    endl(cout);

    k2.wypisz();

    if(k2 == k3) cout << endl << endl << "sa takie same" << endl << endl;

    //Kolejka k4; k4.zdejmij();

    cout << k2.getFirst() << endl;
    cout << k2.getLast() << endl;
    k2.wyczysc();
    k2.wypisz();
    return 0;
}
