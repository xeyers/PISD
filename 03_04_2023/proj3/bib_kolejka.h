#ifndef kolejka_bib
#define kolejka_bib

#include "bib.h"

struct Node
{
    Process p;
    Node* next;
    Node(Process _p, Node* n = nullptr) : p(_p), next(n){}
};

struct ProcessQ
{
private:

    Node* head;
    int ileJest;
public:
    ProcessQ() : head(nullptr), ileJest(0){}
    ~ProcessQ();
    void push(Process p);
    void printQ() const;
    void Przestaw_na_poczatek(unsigned int _PID);
};

#endif // kolejka_bib

