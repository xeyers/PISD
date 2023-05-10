#include "bib2.h"
#include<iostream>
SpisTowaru::~SpisTowaru()
{
    Node* runner = head, *killer = nullptr;
    while(runner != nullptr)
    {
        killer = runner;
        runner = runner->next;
        delete killer;
    }
}

void SpisTowaru::wypisz() const
{
    if(head == nullptr)
    {
        std::cout << "Brak towarow we spisie";
        return;
    }
    Node* runner = head;
    while(runner != nullptr)
    {
        runner->dane.wypiszTowar();
        runner = runner->next;
    }
}

void SpisTowaru::wstaw(Towar A)
{
    Node* nowy = new Node(A);
    if(head == nullptr)
    {
        head = nowy;
    }
    else
    {
        if(A < head->dane) //wstawiamy jako nowy head
        {
            nowy->next = head;
            head = nowy;
        }
        else
        {
            Node* preRunner = head, *runner = head->next;
            while(runner !=nullptr && runner->dane < A)
            {
                preRunner = runner;
                runner = runner->next;
            }
            preRunner->next = nowy;
            nowy->next = runner;
        }
    }
}

void SpisTowaru::wstawRoznowartosciowo(Towar A)
{
    Node* runner = head;

    while(runner != nullptr)
    {
        if(runner->dane == A)
        {
            runner->dane.setIlosc(runner->dane.getIlosc()+1);
            return;
        }
    }

    wstaw(A);
}

void SpisTowaru::usun(Towar A)
{
    if(head == nullptr) throw std::runtime_error("Nie mozna usunac z pustego spisu");

    Node* runner = head, *preRunner = nullptr;

    while(runner != nullptr && !(runner->dane == A))
    {
        preRunner = runner;
        runner = runner->next;
    }

    if(runner == nullptr) throw std::runtime_error("Brak elementu w liscie");

    if(runner == head)
    {
        head = runner->next;
        delete runner;
    }
    else
    {
       preRunner->next = runner->next;
       delete runner;
    }

}


void SpisTowaru::odejmijZeSpisu(const SpisTowaru& S)
{
    Node* runner = head, *runner2 = S.head;

    while(runner != nullptr)
    {

        while(runner2 != nullptr)
        {
            if(runner->dane == runner2->dane)
            {
                runner->dane.setIlosc(runner->dane.getIlosc() - runner2->dane.getIlosc());

                if(runner->dane.getIlosc() < 0)
                {
                    usun(runner->dane);
                    break;
                }

                break;
            }


            runner2 = runner2->next;
        }
        runner2 = S.head;
        runner = runner->next;
    }
}

void SpisTowaru::skompresuj() //TO DO
{
    Node* preRunner = head, *runner = head->next;

    if(head == nullptr || head->next == nullptr) return;

    while(runner != nullptr) //we see through entire list, check if next is the same and then if yes, run runner to the last same element and re connect stuff and delete disconnected
}
