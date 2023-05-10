#include "bib.h"

int main()
{
    Stos s;
    s.push(2);
    s.push(3);
    s.push(6);
    s.print();

    cout << endl << endl;
    Stos s2= s;
    //reverseOrder(s2);
    s2.print();

    //cout << "zdjety element: " << s.pop() << endl << endl;
    //s.print();
    return 0;
}
