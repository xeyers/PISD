#ifndef KONTENER
#define KONTENER
#include<iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node* next;
    Node(T _data) : data(_data), next(nullptr){}
};

template<typename T>
struct List
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    List() : head(nullptr), tail(nullptr){}
    ~List()=default;
    void add(const T& thing);
    void print() const; //do usuniecia potem
    friend void listToFile(List<T> ls, const string& fileName);
    Node<T>* getHead();
};

template<typename T>
Node<T>* List<T>::getHead() {return head;}

template<typename T>
void listToFile(List<T> ls, const string& fileName);

template<typename T>
void List<T>::add(const T& thing)
{
    Node<T>* newNode = new Node<T>(thing);
    if(!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

template<typename T>
void List<T>::print() const
{
    Node<T>* n = head;
    while(n)
    {
        cout << n->data << endl << endl;
        n = n->next;
    }
}
#endif // KONTENER
