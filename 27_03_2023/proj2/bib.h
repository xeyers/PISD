#ifndef bib
#define bib

#include<iostream>
#include<stdexcept>
using namespace std;

struct Stos
{
private:
    struct Node
    {
        int dane;
        Node* next;

        Node(int w, Node* n = nullptr) : dane(w), next(n){}
    };
    Node* top;
    int ileJest;
public:
    Stos() : top(nullptr), ileJest(0){}
    Stos(Stos& k);
    ~Stos();
    void print() const;
    void push(const int& a);
    int pop();
    int getSize() const;
    int whatIsOnTop() const;
    bool isEmpty() const;
    void clearAll();
    bool operator==(const Stos& k) const;
    Stos& operator=(const Stos& k);
    friend void reverseOrder(Stos& s);
};
    void reverseOrder(Stos& s);


#endif // bib
