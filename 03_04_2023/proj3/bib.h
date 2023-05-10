#ifndef bib
#define bib

#include<iostream>
#include<stdexcept>
using namespace std;

struct Process
{
private:
    unsigned int PID;
    unsigned int liczba_watkow;
public:
    Process(unsigned int _PID = 0, unsigned _lw = 1);
    ~Process() = default;
    unsigned int getPID() const;
    unsigned int getLW() const;
    void changeLW(unsigned int lw);
    void printProcess() const;
};


#endif // bib
