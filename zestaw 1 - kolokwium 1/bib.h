#ifndef BIB
#define BIB

#include<iostream>

struct Sznur
{
private:
    struct Node
    {
        int data;
        Node* next;
        Node(int a) : data(a), next(nullptr){}
    };
    Node* head;
    int counter;
public:
    Sznur() : head(nullptr), counter(0){};
    ~Sznur();
    void wypisz() const;
    void wstaw(const int& number);
    void usun(const int& K);
    void przenies();
};

#endif // BIB
