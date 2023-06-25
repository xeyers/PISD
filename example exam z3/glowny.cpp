#include "kontener.h"
#include "dane.h"
#include <fstream>
#include <cmath> //for floor function

ostream& operator<< (ostream& os, const Podatnik& p)//wywalic
{
    os << p.nazwisko << endl << p.imie << endl << p.NIP << endl << p.kdr;
    return os;
}


template<typename T>
void listToFile(List<T>& ls, const string& fileName)
{
    ///Starting condition
    //List and file name

    ///End condition
    //Everything from the list is send to file (it's out mode so the data is either replaced or new file is created if it doesn't exist already)

    ///Exceptions:
    //None

    fstream file(fileName, ios::out);

    Node<T>* n = ls.getHead();
    while(n)
    {
        file << n->data << endl << endl;
        n = n->next;
    }
}

string roundFloat(float value)
{
    ///Starting condition
    //Float number (presumably a string converted to a float)

    ///End condition
    //Returns rounded number (classical rounding) as a string

    ///Exceptions:
    //None

    int rounded = static_cast<int>(value); //intiger part od the number
    float fractional = value - rounded; //decimal part of the number

    if (fractional >= 0.5f) //rounded according to math rules
    {
        rounded += 1;
    }

    return to_string(rounded); //to_string function used to convert int to string
}

int main()
{
    fstream podatnicy("podatnicy.txt",ios::in);
    fstream rozliczenia("rozliczenia.txt",ios::in);
    fstream wyniki("wyniki.txt",ios::out);

    if(!podatnicy) throw runtime_error("podatnicy.txt does not exist");
    if(!rozliczenia) throw runtime_error("rozliczenia.txt does not exist");

    ///Checks if every single taxpayer can have tax amount assigned, if not program is terminated
    int podatnicyCounter = 0;
    int rozliczeniaCounter = 0;
    string dummyString;

    while(getline(podatnicy, dummyString))
    {
        podatnicyCounter++;
    }

    if (dummyString.empty()) //to count last empty line correctly
    {
        podatnicyCounter++;
    }

    while(getline(rozliczenia, dummyString))
    {
        if(dummyString.empty()) throw runtime_error("Empty line in rozliczenia.txt detected"); //rozliczenia.txt cannot have any empty lines
        rozliczeniaCounter++;
    }

    if(dummyString.empty()) throw runtime_error("Last line in rozliczenia.txt is empty"); //rozliczenia.txt cannot have any empty lines

    if(rozliczeniaCounter * 3 != podatnicyCounter) throw runtime_error("Incorrect number of lines in the files"); //for every line in rozliczenia.txt there must be 3 lines in podatnicy.txt

    //rewind the files
    podatnicy.clear();  //clear any error flags
    podatnicy.seekg(0, ios::beg);  //set the file position indicator to the beginning

    rozliczenia.clear();  //clear any error flags
    rozliczenia.seekg(0, ios::beg);  //set the file position indicator to the beginning
    ///===========================================================================================

    List<Podatnik> ls;
    Podatnik dummy("dummy","dummy","dummy","dummy");
    string line, line2;
    int counter = 1;
    bool flag = true, generalFlag = true;

    while(getline(podatnicy,line) || !podatnicy.eof()) //imports NIP, name and surname into dummy taxpayer
    {
        switch(counter)
        {
            case 1:
                if(checkNIP(line)) dummy.setNIP(line);
                else
                {
                    flag = false;
                    generalFlag = false; //because name can be set even if NIP is incorrect. This orevents dummy from being put on the list
                }
                break;
            case 2:
                if(flag)
                {
                  if(checkNazwiskoImie(line))
                  {
                      nazwiskoImieSeparator(line,dummy);

                      getline(rozliczenia,line2);
                      if(checkKDR(line2)) dummy.setKdr(roundFloat(stof(line2)));
                      else dummy.setKdr("DO WERYFIKACJI");
                  }
                  else
                  {
                      getline(rozliczenia,line2);
                      flag = false;
                      generalFlag = false;
                  }
                }

                if(generalFlag) ls.add(dummy); //no need to reset flag if it is in its' default state
                else generalFlag = true; //flag reset

                break;
            case 3:
                counter = 0;
                flag = true;
                break;
        }
        counter++;
    }


    listToFile<Podatnik>(ls,"wyniki.txt");

    podatnicy.close();
    rozliczenia.close();
    wyniki.close();
    return 0;
}
