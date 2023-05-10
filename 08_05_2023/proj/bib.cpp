#include "bib.h"

void Sznur::add(const int& a)
{
    Node* nowy = new Node(a);
    iloscElementow++;
    if(head == nullptr)
    {
        head = nowy;
        tail = nowy;
    }
    else
    {
        tail->next = nowy;
        tail = nowy;
    }
}

void Sznur::print() const
{
    if(head == nullptr)
    {
        cout << "Pusty sznur";
        return;
    }
    Node* runner = head;
    while(runner != nullptr)
    {
        cout << runner->data << " ";
        runner = runner->next;
    }
}

void Sznur::usunZpozycji(int x, int y)
{
    if(x == y) throw runtime_error("Nie mozna usunac tego samego elementu 2 razy");
    int counter = 1;
    Node* runner = head, *preRunner = nullptr;

    while(runner != nullptr && counter < x)
    {
        counter++;
        preRunner = runner;
        runner = runner->next;
    }

    if(runner == nullptr) throw runtime_error("Nie mozna usunac elementu (nie istnieje)");
    else if(runner == head)
    {
        head = runner->next;
        delete runner;
        iloscElementow--;
    }
    else
    {
        preRunner->next = runner->next;
        delete runner;
        iloscElementow--;
    }

    ///usuwanie z pozycji y

    counter = 1;
    runner = head, preRunner = nullptr;
    x = y - 1;

    while(runner != nullptr && counter < x)
    {
        counter++;
        preRunner = runner;
        runner = runner->next;
    }

    if(runner == nullptr) throw runtime_error("Nie mozna usunac elementu (nie istnieje)");
    else if(runner == head)
    {
        head = runner->next;
        delete runner;
        iloscElementow--;
    }
    else
    {
        preRunner->next = runner->next;
        delete runner;
        iloscElementow--;
    }
}

Sznur::~Sznur()
{
    Node* runner = head, *killer = nullptr;
    while(runner != nullptr)
    {
        killer = runner;
        runner = runner->next;
        delete killer;
    }
}
/*
void Sznur::odwroc(const int& n)
{
    if(head == nullptr) throw runtime_error("Nie mozna odwrocic pustego sznura");
 //to dziala ale w zly sposob
    Node* runner = head;
    Node* stop = tail;
    if(n >= iloscElementow) //odwracamy caly sznur
    {
        while(head != stop)
        {
            head = runner->next; //head na kolejny do przestawienia
            runner->next = nullptr; //odlaczamy runnera
            tail->next = runner; //przestawiamy na koniec
            tail = runner; // przesuwamy taila (miejsce podpiecia)
            runner = head; //przeusawamy runnera
        }
    }
    else //odwracamy tylko kawalek
    {

    }
    /////////////

    ///to nie dziala
    Node* runner, *preRunner, *stop = tail;
    if(n >= iloscElementow) //odwracamy caly sznur
    {
        int counter = 1;
        ///wywala sie na pierwszej petli
        while(counter <= iloscElementow)
        {
            counter++;
            runner = head, preRunner = nullptr;
            while(runner->next != stop)
            {
                preRunner = runner;
                runner = runner->next;
            }

            if(runner != head)
            {
                preRunner->next = stop;
                runner->next = nullptr;
                runner = tail->next;
                tail = runner;
            }
            else
            {
                runner->next = nullptr;
                runner = tail->next;
                head = stop;
                tail = runner;
            }

        }
        //swap(head,stop);
        //tail = stop;
    }
    else
    {

    }
}
*/
void Sznur::odwroc(const int& n)
{
    if (head == nullptr) throw runtime_error("Nie mozna odwrocic pustego sznura");

    if (n >= iloscElementow) // caly sznur jest odwracany
    {
        Node* current = head;
        Node* previous = nullptr;
        Node* nextNode = nullptr;

        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        tail = head;
        head = previous;
    }
    else // tylko czesc jest odwrocona
    {
        Node* previousGroupTail = nullptr;
        Node* currentGroupHead = head;
        Node* previous = nullptr;
        Node* nextNode = nullptr;
        int groupCount = 0;

        while (groupCount < n && currentGroupHead != nullptr)
        {
            nextNode = currentGroupHead->next;
            currentGroupHead->next = previous;
            previous = currentGroupHead;
            currentGroupHead = nextNode;
            groupCount++;
        }

        if (previousGroupTail != nullptr)
        {
            previousGroupTail->next = previous;
        }
        else
        {
            head = previous;
        }

        Node* groupTail = previous;
        while (groupTail->next != nullptr)
        {
            groupTail = groupTail->next;
        }

        groupTail->next = currentGroupHead;
        tail = currentGroupHead;
    }
}


