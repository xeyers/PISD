#ifndef BIB
#define BIB

#include<iostream>
using namespace std;

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

bool checkNIP(string& NIP)
{
    ///Starting condition
    //NIP number (taken out from the whole line)

    ///End condition
    //True if NIP is correct
    //False if not

    ///Exceptions:
    //Due to how C++ works this function will only take variable, strings passed like this "string" will not work
    //and since this function use is limited to only this excercise there is not much sense to make another one that would take "string"
    //but if for some reason you need "string" change ||string& text|| to ||string&& text|| so it can take rvalues reference

    trunc(NIP,'-'); //specified in the pdf
    if(NIP.size() != 10) return false;

    int tab[10]; //to store NIP digits
    int mtab[] = {6,5,7,2,3,4,5,6,7}; //weights to mulptiply by

    for(int i = 0; i < 10; i++) //string to int
    {
        tab[i] = NIP[i] - '0';
    }

    for(int i = 0; i < 8; i++) //multiplying first 9 digits by specified weights
    {
        tab[i] *= mtab[i];
    }

    int sum = 0;
    for(int i = 0; i < 8; i++) sum += tab[i]; //calculating sum of the first 9 digits

    return !(sum%11 != tab[9]); //returns false if the last digits is not equal to the reminder; returns true otherwise
}

#endif // BIB
