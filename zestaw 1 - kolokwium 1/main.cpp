#include "bib.h"

int main()
{
    Sznur s;
    s.wstaw(1);
    s.wstaw(3);
    s.wstaw(6);
    s.wstaw(1);
    s.wstaw(3);
    s.wstaw(7);
    s.wstaw(2);
    s.wstaw(6);
    s.wstaw(3);
    s.wstaw(1);
    s.wstaw(1);
    s.usun(7);
    s.wypisz();
    return 0;
}
