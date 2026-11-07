#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Complex
{
    double real, imag;
public:
    Complex() : real(0), imag(0) {}
    Complex(double r) : real(r), imag(0) {}
    Complex(double r, double i)
        : real(r), imag(i) {}
    Complex operator+(const Complex& c) const
    {
        return Complex(real + c.real,
                       imag + c.imag);
    }
    Complex operator-(const Complex& c) const
    {
        return Complex(real - c.real,
                       imag - c.imag);
    }
    Complex operator*(const Complex& c) const
    {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }
    Complex operator/(const Complex& c) const
    {
        double denominator =
            c.real * c.real + c.imag * c.imag;
        if (denominator == 0)
            throw runtime_error("Division by zero");
        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }
    bool operator==(const Complex& c) const
    {
        return real == c.real && imag == c.imag;
    }
    double magnitude() const
    {
        return sqrt(real * real + imag * imag);
    }
    friend ostream& operator<<(ostream& out,
                               const Complex& c)
    {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";
        return out;
    }
};
int main()
{
    Complex a(10, 5);
    Complex b(3, 2);
    cout << fixed << setprecision(3);
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Magnitude: " << a.magnitude() << endl;
    cout << boolalpha;
    cout << "Equal: " << (a == b) << endl;
    try
    {
        Complex zero(0, 0);
        cout << a / zero << endl;
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
    }
    double pi = 3.141592653589793;
    double frequency = 50;
    double R = 10;
    double L = 0.1;
    double C = 0.0001;
    double w = 2 * pi * frequency;
    Complex ZR(R, 0);
    Complex ZL(0, w * L);
    Complex ZC(0, -1 / (w * C));
    Complex series = ZR + ZL + ZC;
    cout << "Series RLC impedance: "
         << series << endl;
    cout << "Series magnitude: "
         << series.magnitude() << endl;
    Complex parallel =
        ((ZR * ZL) / (ZR + ZL) * ZC) /
        ((ZR * ZL) / (ZR + ZL) + ZC);
    cout << "Parallel RLC impedance: "
         << parallel << endl;
    cout << "Parallel magnitude: "
         << parallel.magnitude() << endl;
    return 0;
}


