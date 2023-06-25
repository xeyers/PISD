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
    List() : head(nullptr), tail(nullptr){} //constructor, head and tail are initialized as nullptr
    ~List(); //destructor
    void add(const T& thing); //adds data to the list
    Node<T>* getHead(); //returns head of the list

    template<typename U>
    friend void listToFile(List<U>& ls, const string& fileName); //sends list to file
};

template<typename T>
List<T>::~List()
{
    Node<T>* runner = head, *killer = nullptr;
    while(runner)
    {
        killer = runner;
        runner = runner->next;
        delete killer;
    }
}

template<typename T>
Node<T>* List<T>::getHead() {return head;} //getter to get the head of the list

template<typename T>
void List<T>::add(const T& thing)
{
    ///Starting condition
    //Data to add to the list

    ///End condition
    //Data is added to the list

    ///Exceptions:
    //None

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

#endif // KONTENER
