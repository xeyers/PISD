#include "bib.h"

void Stos::print() const
{
    if(top == nullptr)
    {
        cout << "Stos pusty";
        return;
    }

    Node* runner = top;
    while(runner != nullptr)
    {
        cout << runner->dane;
        runner = runner->next;
    }
}

void Stos::push(const int& a)
{
    Node* nowy = new Node(a);

    if(top == nullptr)
    {
        top = nowy;
    }
    else
    {
        nowy->next = top;

        top = nowy;
    }

    ileJest++;
}



Stos::~Stos()
{
    Node* runner = top, *killer = nullptr;
    while(runner != nullptr)
    {
        killer = runner;
        runner = runner->next;
        delete killer;
    }
}

int Stos::pop()
{
    if(top == nullptr) throw underflow_error("brak elementow do zdjecia");
    Node* killer = top;
    int tmp = top->dane;
    top = top->next;
    delete killer;
    ileJest--;
    return tmp;
}

int Stos::getSize() const
{
    return ileJest;
}

int Stos::whatIsOnTop() const
{
    if(top == nullptr) throw underflow_error("brak elementow");
    return top->dane;
}

bool Stos::isEmpty() const
{
    if(ileJest == 0) return true;
    return false;
}

void Stos::clearAll()
{
    if(top == nullptr) throw underflow_error("brak elementow do wyczyszczenia");
    Node* runner = top, *killer = nullptr;
    while(runner != nullptr)
    {
        killer = runner;
        runner = runner->next;
        delete killer;
    }
    top = nullptr;
}

bool Stos::operator==(const Stos& k) const
{
    if(ileJest != k.ileJest) return false;
    Node* runner = top, *runnerK = k.top;
    while(runner != nullptr)
    {
        if(runner->dane != runnerK->dane) return false;
    }
    return true;
}

Stos::Stos(Stos& k)
{
    ileJest = 0;
    top = nullptr;
    Stos s1;

    Node* runner = k.top;

    while(runner != nullptr)
    {
        s1.push(runner->dane);
        runner = runner->next;
    }

    runner = s1.top;
    while(runner != nullptr)
    {
        this->push(runner->dane);
        runner = runner->next;
    }
}

Stos& Stos::operator=(const Stos& k)
{
    if(this == &k) return *this;

    if(top != nullptr)
    {
        this->clearAll();
    }

    ileJest = k.ileJest;

    Node* runner = k.top;

    while(runner != nullptr)
    {
        this->push(runner->dane);
        runner = runner->next;
    }

    return *this;
}


