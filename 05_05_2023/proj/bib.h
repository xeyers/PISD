#ifndef towar
#define towar

struct Towar
{
private:
    int kod;
    double ilosc;
public:
    Towar(int k = 0, int i = 0) : kod(k), ilosc(i){}
    int getKod() const;
    int getIlosc() const;
    void setKod(int k);
    void setIlosc(int i);
    bool operator<(const Towar& t) const;
    bool operator==(const Towar& t) const;
    void wypiszTowar() const;
};
#endif // towar
