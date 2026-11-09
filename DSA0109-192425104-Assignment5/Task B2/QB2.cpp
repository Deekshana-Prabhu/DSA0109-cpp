
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string input = "abc";
    double amount;
    stringstream ss(input);
    if (ss >> amount)
    {
        cout << "Amount: " << amount;
    }
    else
    {
        cout << "Invalid number: Please enter a valid amount";
    }
    return 0;
}


