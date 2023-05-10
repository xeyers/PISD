#include "bib_kolejka.h"

void ProcessQ::push(Process _p)
{
    if(head == nullptr)
    {
        head = new Node(_p);
        ileJest++;
    }
    else
    {
        Node* runner = head, *preRunner = nullptr;

        while(runner != nullptr)
        {
            if(runner->p.getPID() == _p.getPID())
            {
                runner->p.changeLW(_p.getLW());
                return;
            }

            preRunner = runner;
            runner = runner->next;
        }

        preRunner->next = new Node(_p);
    }
}

void ProcessQ::printQ() const
{
    Node* runner = head;
    while(runner != nullptr)
    {
        runner->p.printProcess(); endl(cout);
        runner = runner->next;
    }
}

ProcessQ::~ProcessQ()
{
    Node* runner = head, *killer = nullptr;
    while(runner != nullptr)
    {
        killer = runner;
        runner = runner->next;
        delete killer;
    }
}

void ProcessQ::Przestaw_na_poczatek(unsigned int _PID)
{
    Node* runner = head, *preRunner = nullptr;

        while(runner != nullptr)
        {
            if(runner->p.getPID() == _PID)
            {
                if(runner == head) return;
                else
                {
                    preRunner->next = runner->next; //wypinamy
                    runner->next = head; //wpinamy poczatek listy jako element nr 2
                    head = runner; //ustawiamy head na nasz element
                    return;
                }
            }

            preRunner = runner;
            runner = runner->next;
        }

        throw runtime_error("brak takiego procesu");
}
