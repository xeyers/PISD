#ifndef bib
#define bib

//zestaw 23

#include<iostream>
using namespace std;

    struct Node
    {
        int data;
        Node* next;
        Node(int _data) : data(_data), next(nullptr){}
    };
class Sznur
{
    Node* head;

public:
    Sznur() : head(nullptr){}

    ~Sznur()
    {
        Node* killer, *runner;
        while(runner != nullptr)
        {
            killer = runner;
            runner = runner->next;
            delete killer;
        }
    }

    void wypisz() const;
    void wstaw (const int& a);
    void usun();
    void rozrzucPary()
};

void Sznur::wypisz() const
{
    Node* runner = head;
    while(runner != nullptr)
    {
        cout << runner->data << " ";
        runner = runner->next;
    }
}

void Sznur::wstaw(const int& a)
{
    Node* nowy = new Node(a);
    Node* runner, *preRunner;
    if(head == nullptr) //new head
    {
        head = nowy;
    }
    else if(a > head->data) //before head
    {
        nowy->next = head;
        head = nowy;
    }
    else //after head
    {
        runner = head; preRunner = nullptr;

        while(runner != nullptr && runner->data > a)
        {

            preRunner = runner;
            runner = runner->next;
        }

        if(runner == nullptr)
        {
            preRunner -> next = nowy;
        }
        else
        {
            preRunner -> next = nowy;
            nowy ->next = runner;
        }
    }
}

void Sznur::usun()
{

    Node* one = head;
    Node* preThird = head;

    Node* two, *three;

    if(head != nullptr && head->next != nullptr) two = one->next;
    else two = nullptr;

    if(two != nullptr && two->next != nullptr) three = one->next->next;
    else three = nullptr;


    while(one != nullptr && two!=nullptr && three != nullptr)
    {
        if(two->data == one->data - 1)
        {
            if(one == head)
            {
                head = two;
                delete one;

                preThird = two;

                one = three->next;
                if(one != nullptr && one->next != nullptr) two = one->next;
                else {two = nullptr; three = nullptr;}

                if(two != nullptr && two->next != nullptr) three = one->next->next;
                else three = nullptr;
            }
            else
            {
                preThird->next = two;
                delete one;

                preThird = three;
                one = three->next;

                if(one != nullptr && one->next != nullptr) two = one->next;
                else {two = nullptr; three = nullptr;}

                if(two != nullptr && two->next != nullptr) three = one->next->next;
                else three = nullptr;
            }
        }
        else
        {
            if(one == head)
            {
                head = two;
                delete one;

                preThird = two;
                one = three->next; //may be null
                delete three;
                preThird->next = one;

                if(one != nullptr && one->next != nullptr)
                {
                    //two->next = one;
                    two = one->next;
                }
                else {two = nullptr; three = nullptr;}


                if(two != nullptr && two->next != nullptr) three = one->next->next;
                else three = nullptr;
            }
            else
            {
                preThird->next = two;
                delete one;

                preThird = two;
                one = three->next; //may be null
                delete three;
                preThird->next = one;

                if(one != nullptr && one->next != nullptr)
                {
                    //two->next = one;
                    two = one->next;
                }
                else {two = nullptr; three = nullptr;}

                if(two != nullptr && two->next != nullptr) three = one->next->next;
                else three = nullptr;
            }
        }
    }
}
#endif // bib
