#ifndef DANE
#define DANE
#include<iostream>
using namespace std;
bool checkNIP(const string& NIP); //checks if NIP meets requirements
bool checkKDR(const string& kdr); //checks if kdr is correct
struct Podatnik
{
private:
    string imie;
    string nazwisko;
    string NIP;
    string kdr;
public:
    Podatnik(const string& _imie, const string& _nazwisko, const string& _NIP, const string& _kdr) : imie(_imie), nazwisko(_nazwisko), NIP(_NIP), kdr(_kdr){}
    string getImie() const;
    string getNazwisko() const;
    string getNIP() const;
    string getKdr() const;

    void setImie(const string& a);
    void setNazwisko(const string& a);
    void setNIP(const string& a);
    void setKdr(const string& a);
    friend ostream& operator<< (ostream& os, const Podatnik& p); //wywalic
};

string Podatnik::getImie() const {return imie;}
string Podatnik::getNazwisko() const {return nazwisko;}
string Podatnik::getNIP() const {return NIP;}
string Podatnik::getKdr() const {return kdr;}

void Podatnik::setImie(const string& a) {imie = a;}
void Podatnik::setNazwisko(const string& a) {nazwisko = a;}
void Podatnik::setNIP(const string& a) {NIP = a;}
void Podatnik::setKdr(const string& a) {kdr = a;}

bool checkNIP(const string& NIP)
{
    ///Starting condition
    //NIP number

    ///End condition
    //True if NIP is correct
    //False if not

    ///Exceptions:
    //None

    if(NIP.size() != 10) return false;

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

    if(sum%11 != tab[9]) return false;//returns false if the last digits is not equal to the reminder

    return true;
}

bool checkKDR(const string& kdr)
{
    if(kdr.empty()) return false; //passed string is empty
    if(kdr.size() - 4 < 0) return false; //smallest possible amount of character is 4 (for example: 0.00)

    if(kdr[0] != '-' && !(kdr[0] - '0' >= 0 && kdr[0] - '0' <= 9)) return false; //if first character is not minus or digit the number is incorrect
    if(kdr[kdr.size() - 3] != '.' ) return false; //if the number doesn't have separator it's incorrect

    //intiger part
    if(kdr[0] == '-') //for negative numbers the number part starts at the second character
    {
        for(int i = 1; i < kdr.size() - 3; i++)
        {
            if(!(kdr[i] - '0' >= 0 && kdr[i] - '0' <= 9)) return false; //if anything is not digit number is incorrect
        }
    }
    else //for positive numbers the number part starts at the first character
    {
        for(int i = 0; i < kdr.size() - 3; i++)
        {
            if(!(kdr[i] - '0' >= 0 && kdr[i] - '0' <= 9)) return false; //if anything is not digit number is incorrect
        }
    }

    //decimal part
    for(int i = kdr.size() - 2; i < kdr.size(); i++)
    {
        if(!(kdr[i] - '0' >= 0 && kdr[i] - '0' <= 9)) return false; //if anything is not digit number is incorrect
    }

    return true;
}

bool checkNazwiskoImie(const string& line)
{
    if(line.empty()) return false;
    if(line[0] == ' ') return false;

    for(char c : line) if(c - '0' >= 0 && c - '0' <= 9) return false;
    //return true;

    string imie = "";
    string nazwisko = "";
    bool flag = true;

    for(char c : line)
    {
        if(flag && c != ' ') nazwisko += c;
        else flag = false;

        if(!flag) imie += c;
    }

    if(imie.empty()) return false;
    if(imie == " ") return false;

    return true;
}

void nazwiskoImieSeparator(const string& line, Podatnik& p)
{
    string imie = "";
    string nazwisko = "";
    bool flag = true;

    for(char c : line)
    {
        if(flag && c != ' ') nazwisko += c;
        else flag = false;

        if(!flag) imie += c;
    }

    p.setImie(imie.substr(1)); //cuts out space at the beginning
    p.setNazwisko(nazwisko);
}

#endif // DANE
