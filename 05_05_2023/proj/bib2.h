#ifndef spis
#define spis
#include "bib.h"
#include <stdexcept>
struct SpisTowaru
{
private:
    struct Node
    {
        Towar dane;
        Node* next;
        Node(Towar& t) : dane(t), next(nullptr){}
    };

    Node* head;
public:
    SpisTowaru() : head(nullptr){}
    ~SpisTowaru();
    void wypisz() const;
    void wstaw(Towar A);
    void wstawRoznowartosciowo(Towar A);
    void odejmijZeSpisu(const SpisTowaru& S);
    void usun(Towar A);
    void skompresuj();
};
#endif // spis

