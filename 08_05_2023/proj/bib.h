#ifndef bib
#define bib

#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

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
    Node* tail;
    int iloscElementow;
public:
    Sznur() : head(nullptr), tail(nullptr), iloscElementow(0){}
    ~Sznur();
    void add(const int& a);
    void print() const;
    void usunZpozycji(int x, int y);
    void odwroc(const int& n);
};
#endif // bib
