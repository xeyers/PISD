#include "bib.h"
#include "bib_kolejka.h"

int main()
{
    ProcessQ k;
    Process p1(10,1);
    Process p2(11,2);
    Process p3(12,3);

    k.push(p1);
    k.push(p2);
    k.push(p3);

    k.printQ();

    cout << endl << "nowa lista" << endl;
    k.Przestaw_na_poczatek(10);
    endl(cout);
    k.printQ();
    return 0;
}
