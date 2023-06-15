#ifndef BIB
#define BIB

#include<iostream>
using namespace std; //for convinience, obviously for any use you should delete this and add std:: where needed

///Custom structures used:
struct List; //takes only correct IBANS from input file and sorts them in alphanumeric order

///List of functions used:
void listToFile(const List& ls); //sends given list to right files (if files are not present function creates them)
bool bankCheck(const string& IBAN); //checks if bank id is correct
bool firstControlDigit(const string& IBAN); //checks if first control digit is correct
int calculateModulo97(const string& number); //calculates IBAN mod 97
bool controlSumCheck(const string& IBAN); //checks if control sum is correct
bool isCorrectStructure(const string& IBAN); //checks if length is correct and if the first 2 characters are letters and the rest digits
bool checkIBAN(const string& IBAN); //checks if whole IBAN is correct utilizing functions above

///Code:
struct List
{
private:
    struct Node
    {
        string data;
        Node* next;
        Node(const string& d) : data(d), next(nullptr){}
    };
    Node* head;
    Node* tail;
public:
    List() : head(nullptr), tail(nullptr){}
    ~List();
    friend void listToFile(const List& ls);
};

void listToFile(const List& ls)
{

}

bool bankCheck(const string& IBAN)
{
    ///Starting conditions
    //String containing IBAN

    ///End conditions
    //Returns true if the bank identifier is correct
    //Returs false if the bank identifier is incorrect

    ///Exceptions
    //No excepitons, it is guaranteed that IBAN is correct, otherwise this function is not executed

    string toCheck; //bank indentifier
    for(int i = 4; i < 8; i++) //separating the string from whole IBAN
    {
        toCheck += IBAN[i];
    }

    return (toCheck == "1020" || toCheck == "1140" || toCheck == "2490") ? true : false;
}

bool firstControlDigit(const string& IBAN)
{
    ///Starting conditions
    //String containing IBAN

    ///End conditions
    //Returns true if the digit is correct
    //Returs false if the digit is incorrect

    ///Exceptions
    //No excepitons, it is guaranteed that IBAN is correct, otherwise this function is not executed

    int toCheck[8]; //digits from string with the first control digit that needs to be checked
    for(int i = 4; i < 12; i++) //separating the string from whole IBAN
    {
        toCheck[i-4] = IBAN[i]-'0';
    }

    //multiply 7 first digits as specified in the algorithm
    //and calculate the sum of first 7 numbers
    int multiplyBy[] = {7,1,3,9,7,1,3};
    int sum = 0;
    for(int i = 0; i <= 6; i++)
    {
        toCheck[i] *= multiplyBy[i];
        sum += toCheck[i];
    }

    //if sum%10 is the last number then it's correct
    //otherwise it's not
    return (sum%10 == toCheck[7]) ? true : false;
}

int calculateModulo97(const string& number)
{
    /// Starting conditions
    // String containing the 30-digit number

    /// End conditions
    // Returns the remainder (modulus) when dividing the number by 97
    // The remainder indicates if the number is correct or incorrect

    /// Exceptions
    // No exceptions. It is guaranteed that the number is correct, otherwise this function is not executed.

    int remainder = 0;

    for (char digit : number)
    {
        int currentDigit = digit - '0';  //char to int

        int currentNumber = remainder * 10 + currentDigit;
        remainder = currentNumber % 97;
    }

    return remainder;
}

bool controlSumCheck(const string& IBAN)
{
    ///Starting conditions
    //IBAN

    ///Ending conditions
    //True if control sum is correct
    //False otherwise

    ///Exceptions
    //No exceptions

    string tmp = "";

    for(int i = 4; i < 28; i++)
    {
        tmp += IBAN[i];
    }

    tmp = tmp + "2521" + IBAN[2] + IBAN[3];

    return (calculateModulo97(tmp) == 1) ? true : false;
}

bool isCorrectStructure(const string& IBAN)
{
    if(IBAN.size() != 28) return false; //checks if the length of IBAN is correct
    if(IBAN[0] - '0' >= 0 && IBAN[0] - '0' <= 9) return false; //if the first number is not a letter returns false
    if(IBAN[1] - '0' >= 0 && IBAN[1] - '0' <= 9) return false; //if the second number is not a letter returns false
    for(int i = 2; i < 28; i++) if(!(IBAN[i] - '0' >= 0 && IBAN[i] - '0' <= 9)) return false; //checks if everything else is a digit
    return true;
}

bool checkIBAN(const string& IBAN)
{
    ///Starting conditions
    //IBAN number

    ///End conditions
    //Returns true if IBAN can be passed to the list
    //Returns false if not

    ///Exceptions
    //No exceptions

    if(!(isCorrectStructure(IBAN))) return false;
    if(!(bankCheck(IBAN))) return false; //checks if bank id is one of three specified in excercise
    if(!(firstControlDigit(IBAN))) return false; //checks first control digit
    if(!(controlSumCheck(IBAN))) return false; //checks control sum of the whole IBAN number

    return true; //if everything is correct true is returned
}
#endif // BIB
