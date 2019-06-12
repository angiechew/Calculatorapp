#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void myFunc(int *x) {
  cout << "Please number to be stored in a memory location" << endl;
  cin >> *x;
  cout << endl;
}

// Outputs 100

// Add Function
int add(int n1, int n2)
{
    cout << "Running Addition... \n";
    return (n1+n2);
}
// Add Function
int subtract(int n1, int n2)
{
    cout << "Running Subtraction... \n";
    return (n1-n2);
}
// Multiplication Function
int multiply(int n1, int n2)
{
    cout << "Running Multiplication... \n";
    return (n1*n2);
}
// Division Function
int divide(int n1, int n2)
{
    cout << "Running Division... \n";
    if (n2==0)
    {
        cout << "Please enter a number other than 0" << endl;
        cin >> n2;
    }
        return (n1/n2);

}

// Entry input function
 int input_1(int entry1)
{
    cout << endl;
    cout << "Enter other numbers is quit\n";
    cout << "Enter 1 for multiplication\n";
    cout << "Enter 2 for addition\n";
    cout << "Enter 3 for subtraction\n";
    cout << "Enter 4 for division\n";
    cin >> entry1;
    return entry1;
}

// Factorial function is a recursive function
int factorial(int n) {
  if (n==1) {
    return 1;
  }
  else {
    return n * factorial(n-1);
  }
}

// Passing an array through a function
void printArray(int arr[], int size) {
  for(int x=0; x<size; x++) {
    cout <<arr[x];
  }
}

int main()
{
// Simple calculator for addition, subtraction, multiplication and division
    bool fquit;
    fquit =true;
    cout << "Let's do some simple arithmetic!" << endl;
    while (fquit==true)
    {
   // Get the arithmetic function
    int arithmetic = input_1(0);

    // x and y are numbers to be entered
    int x;
    int y;

    //using switch to select the arithmetic function
    switch (arithmetic)
    {
        case 1:
            cout << "Input the first number" << endl;
            cin >> x;
            cout << "Input the next number" << endl;
            cin >> y;
            cout << "Answer is " << multiply(x,y) << endl;
            break;
        case 2:
            cout << "Input the first number" << endl;
            cin >> x;
            cout << "Input the next number" << endl;
            cin >> y;
            cout << "Answer is " << add(x,y) << endl;
            break;
        case 3:
            cout << "Input the first number" << endl;
            cin >> x;
            cout << "Input the next number" << endl;
            cin >> y;
            cout << "Answer is " << subtract(x,y) << endl;
            break;
        case 4:
            cout << "Input the first number" << endl;
            cin >> x;
            cout << "Input the next number" << endl;
            cin >> y;
            cout << "Answer is " << divide(x,y) << endl;
            break;
        default:
            fquit=false;
            break;
    }
    }
//Random number game
    //cout << rand();
    int game;
    int n1;

    game=1;
    cout << endl;
    cout << "Let's play a random number game!" << endl;
        while (game >= 1 and game <= 8)
        {
        cout << endl;
        cout << "Please enter a number from 1 to 8 if you want to play a game.  Other numbers will quit the game." << endl;
        cin >> game;
        if (game >= 1 and game <= 8)
        {
        n1 = 1+(rand() % game);
        switch (n1)
        {
            case 1:
            cout << "Penang is beautiful. You should go there." << endl;
            break;
            case 2:
            cout << "What is the Capital of Malaysia? It's Kuala Lumpur!" << endl;
            break;
            case 3:
            cout << "Singapore is 1 degree above the equator." << endl;
            break;
            case 4:
            cout << "A delicious dish in Singapore is called Laksa!" << endl;
            break;
            case 5:
            cout << "Dim Sum means little dishes in Cantonese. In Mandarin it is called Dian Xing." << endl;
            break;
            case 6:
            cout << "Ipoh Hor Fun is a delicacy in Ipoh.  Ipoh is a city in Perak, Malaysia." << endl;
            break;
            case 7:
            cout << "Japan is the land of the rising sun. Mmmmm... Sahimi and Ramen." << endl;
            break;
            case 8:
            cout << "Taiwan has the best Xiao Lung Bao.  Little meat dumplings with broth inside the dumplings!" << endl;
            break;
            case 9:
            cout << "Curry puffs, pineapple tarts and many more are quite the delicacies in Malaysia and Singapore." << endl;
            break;
            default:
            cout << "Game over, if you want to play hire Sing Wah as a programmer" << endl;
            break;
        }
        }
        else
            cout << "Game over, if you want to play hire Sing Wah as a programmer" << endl;
        }
// Having fun with C++
// Practicing Recursive Functions with Factorials
{
    int factorialnumber;
    cout << endl;
    cout << "Practicing Factorials. Please enter number to perform factorial for" << endl;
    cin >> factorialnumber;
    cout << endl;
    cout << factorialnumber << " ! = " <<factorial(factorialnumber) << endl;

}
// understanding pointers and addresses
{
    int var;
    cout << endl;
    cout << "Enter a number to be stored in this location. "<< &var << endl;
    cin >> var;
    cout << endl;
    cout << "Memory location " << &var << " contains the value " << var << endl;
    myFunc(&var);
    cout << endl;
    cout << "Memory location " << &var << " contains the value " << var << endl;
    cout << endl;
    cout << "we can use pointers to change the value in a particular memory location." << endl;
    cout << endl;
}

    cout << "Hoped you had fun!" << endl;
    cout << endl;
  return 0;
}


