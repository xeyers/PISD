#include "bib.h"

    void Process::changeLW(unsigned int lw)
    {
        liczba_watkow += lw;
    }

    Process::Process(unsigned int _PID, unsigned _lw)
    {
        if(_lw <= 0) throw runtime_error("zla liczba watkow");

        PID = _PID;
        liczba_watkow = _lw;
    }

    unsigned int Process::getPID() const
    {
        return PID;
    }

    unsigned int Process::getLW() const
    {
        return liczba_watkow;
    }


    void Process::printProcess() const
    {
        cout << "Numer PID: " << PID << endl;
        cout << "Liczba watkow: " << liczba_watkow << endl;
    }
