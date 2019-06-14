#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void tripleNumbers (int&, int&);
void timesTwo(int&, int&);
void square(int&, int&);
void cube(int&, int&);
void exchange(int&, int&);
void getNumber(int&, int&);
void printNum(int, int);

// exercise to assign an array of pointers to functions
main()
{
    int numone=1, numtwo=2;
    int selection, n;

    const int maxArray = 5;
    void (*pFunArray[maxArray])(int&, int&);

    for (n=0;n< maxArray;n++)
    {
        cout << "(1) To change numbers  ";
        cout << "(2) For Square  ";
        cout << "(3) For Cube  ";
        cout << "(4) To swap numbers  " ;
        cout << "(5) Double the numbers ";
        cout << "(6) Triple the numbers ";
        cin >> selection;
        switch (selection)
            {
            case 1:
                pFunArray[n] = getNumber;
                break;
            case 2:
                pFunArray[n] = square;
                break;
            case 3:
                pFunArray[n] = cube;
                break;
            case 4:
                pFunArray[n] = exchange;
                break;
            case 5:
                pFunArray[n] = timesTwo;
                break;
            case 6:
                pFunArray[n] = tripleNumbers;
                break;
            default:
                pFunArray[n] = 0;
            }
    }
    for (n=0;n< maxArray;n++)
    {
        pFunArray[n](numone,numtwo);
        printNum(numone,numtwo);
    }
    return 0;
}
void printNum(int a, int b)
{
    cout << "a: "<< a << " b: " << b << endl;
}
void square(int &rA, int &rB)
{
    rA *= rA;
    rB *= rB;
}
void cube (int &rA, int &rB)
{
    rA = rA * rA * rA;
    rB = rB * rB * rB;
}
void exchange(int &rA, int &rB)
{
    int temp;
    temp = rA;
    rA = rB;
    rB = temp;
}
void getNumber(int &rA, int &rB)
{
    cout << "Enter New number for numone"<< endl;
    cin >> rA;
    cout << "Enter New number for numtwo"<< endl;
    cin >> rB;
}
void timesTwo(int &rA, int &rB)
{
    rA += rA;
    rB += rB;
}

void tripleNumbers (int &rA, int &rB)
{
    rA = 3 * rA;
    rB = 3 * rB;
}
