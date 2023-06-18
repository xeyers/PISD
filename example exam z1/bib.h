#ifndef BIB
#define BIB

#include<iostream>
#include<fstream>
#include<stdexcept>
using namespace std;

bool checkNIP(string&& NIP, int& flag); //checks if NIP number meets requirements
void listToFile(const List& ls); //takes list and distributes taxpayers to the right files
void trunc(string& text, const char& what); //removes specified character from a string

struct List
{
private:
    struct Node
    {
        string data;
        Node* next;
        Node(const string& _data) : data(_data), next(nullptr){}
    };
    Node* head;
    Node* tail;
public:
    List() : head(nullptr), tail(nullptr){}
    ~List();
    void add(const string& fileName);
    friend void listToFile(const List& ls);
};

List::~List()
{
    Node* runner = head, *killer = nullptr;
    while(runner)
    {
        killer = runner;
        runner = runner->next;
        delete killer;
    }
}

void List::add(const string& fileName)
{
    ///Starting conditions:
    //Name of the file

    ///End conditions:
    //Only correct lines from file are on the list
    //All incorrect lines are printed on the console with short description of what is wrong

    ///Exceptions
    //File might not exist, in that case program terminates itself with error "File does not exist"

    fstream file(fileName, ios::in);

    if(file.good())
    {
        string line;
        int flag; //used to print right error message
        while(getline(file,line))
        {
            if(line.empty()) continue; //ignores empty lines
            else
            {
                flag = 0;
                if(checkNIP(line.substr(0,10),flag))
                {
                    Node* newNode = new Node(line);
                    if(head == nullptr)
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
                else
                {
                    switch(flag)
                    {
                    case 1:
                        cout << "Wrong length " << line << endl;
                        break;
                    case 2:
                        cout << "Wrong bank " << line << endl;
                        break;
                    case 3:
                        cout << "Wrong control number " << line << endl;
                        break;
                    default:
                        throw runtime_error("Unexpected flag");
                    }
                }
            }
        }
    }
    else throw runtime_error("File does not exist");
}

void listToFile(const List& ls)
{
    ///Starting conditions:
    //List with taxpayers

    ///End conditions:
    //Taxpayers are divided to their respective files

    ///Exceptions
    //None

    fstream piotrkow("piotrkow.txt", ios::out);
    fstream radomsko("radomsko.txt", ios::out);
    fstream tomaszow("tomaszow.txt", ios::out);

    List::Node* n = ls.head;
    while(n) //compares only the third character of the strings as it is enough to identify where the line should go
    {
        if(n->data[2] == '1') piotrkow << n->data << endl;
        else if(n->data[2] == '2') radomsko << n->data << endl;
        else tomaszow  << n->data << endl;
        n = n->next;
    }
    piotrkow.close();
    radomsko.close();
    tomaszow.close();
}

void trunc(string& text, const char& what)
{
    ///Starting condition
    //String of text and what character to remove

    ///End condition
    //Text passed as argument without specified character

    ///Exceptions:
    //Due to how C++ works this function will only take variable, strings passed like this "string" will not work
    //and since this function use is limited to only this excercise there is not much sense to make another one that would take "string"
    //but if for some reason you need "string" change ||string& text|| to ||string&& text|| so it can take rvalues reference

    string tmp = "";
    for(char x : text)
    {
        if(x == what) continue;
        else tmp += x;
    }
    text = tmp;
}

bool checkNIP(string&& NIP, int& flag)
{
    ///Starting condition
    //NIP number (taken out from the whole line)

    ///End condition
    //True if NIP is correct
    //False if not

    ///Exceptions:
    //Due to how C++ works this function will only take strings passed like this "string".
    //and since this function use is limited to only this excercise there is not much sense to make another one that would take variables
    //but if for some reason you need variable change ||string&& text|| to ||string& text|| so it can take lvalues references

    ///Flags:
    //Flag 1 - wrong length
    //Flag 2 - wrong bank
    //Flag 3 - wrong control number

    trunc(NIP,'-'); //removing eventual '-' frrom NIP

    if(NIP.size() != 10)
    {
        flag = 1;
        return false;
    }

    string nipp = NIP.substr(0,3);
    if(nipp != "771" && nipp != "772" && nipp != "773")
    {
        flag = 2;
        return false;
    }

    int tab[10]; //to store NIP digits
    int mtab[] = {6,5,7,2,3,4,5,6,7}; //weights to mulptiply by

    for(int i = 0; i < 10; i++) //string to int
    {
        tab[i] = NIP[i] - '0';
    }

    for(int i = 0; i < 9; i++) //multiplying first 9 digits by specified weights
    {
        tab[i] *= mtab[i];
    }

    int sum = 0;
    for(int i = 0; i < 9; i++) sum += tab[i]; //calculating sum of the first 9 digits

    if(sum%11 != tab[9]) //returns false if the last digits is not equal to the reminder; returns true otherwise
    {
        flag = 3;
        return false;
    }
    else return true;
}

#endif // BIB
