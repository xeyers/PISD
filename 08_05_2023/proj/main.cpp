#include "bib.h"

int main()
{
    Sznur s;
    s.add(6);
    s.add(3);
    s.add(1);
    s.add(7);
    s.add(8);
    s.print();
    cout << endl;
    s.odwroc(5);
    s.print();
    return 0;
}
