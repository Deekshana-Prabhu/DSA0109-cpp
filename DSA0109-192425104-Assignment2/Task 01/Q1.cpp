#include <iostream>
using namespace std;

// Call by Value
void concessionByValue(double fee, int percent)
{
    fee = fee - (fee * percent / 100);
    cout << "Inside value function: " << fee << endl;
}

// Call by Reference
void concessionByReference(double& fee, int percent)
{
    fee = fee - (fee * percent / 100);
    cout << "Inside reference function: " << fee << endl;
}

// Call by Pointer
void concessionByPointer(double* fee, int percent)
{
    *fee = *fee - (*fee * percent / 100);
    cout << "Inside pointer function: " << *fee << endl;
}

int main()
{
    double fee1 = 45000;
    double fee2 = 45000;
    double fee3 = 45000;

    concessionByValue(fee1, 10);
    cout << "Stored fee: " << fee1 << endl;

    concessionByReference(fee2, 10);
    cout << "Stored fee: " << fee2 << endl;

    concessionByPointer(&fee3, 10);
    cout << "Stored fee: " << fee3 << endl;

    return 0;
}


