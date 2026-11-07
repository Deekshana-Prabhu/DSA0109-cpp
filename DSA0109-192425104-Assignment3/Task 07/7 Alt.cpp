#include <iostream>
#include <complex>
using namespace std;

int main()
{
    complex<double> a(10, 5);
    complex<double> b(3, 2);

    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;

    cout << "Magnitude: " << abs(a) << endl;

    return 0;
}


