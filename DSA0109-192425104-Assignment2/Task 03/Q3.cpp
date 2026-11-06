#include <iostream>
using namespace std;

class Parcel
{
public:
    double weight;
    bool express;
    bool insured;
    Parcel(double w, bool e = false, bool i = false)
    {
        weight = w;
        express = e;
        insured = i;
    }
};
// Weight in kilograms
double charge(double weight, bool express = false,
              bool insured = false)
{
    double amount = weight * 50;
    if (express)
        amount += 100;
    if (insured)
        amount += 50;
    return amount;
}
// Weight in grams
double charge(int grams)
{
    return (grams / 1000.0) * 50;
}
// Parcel object
double charge(Parcel p)
{
    return charge(p.weight, p.express, p.insured);
}
int main()
{
    cout << "Charge 1: " << charge(2) << endl;
    cout << "Charge 2: " << charge(2.0f) << endl;
    cout << "Charge 3: " << charge(2.0) << endl;
    cout << "Charge 4: " << charge(2.0, true) << endl;
    cout << "Charge 5: " << charge(2.0, false, true) << endl;
    Parcel p(3.0, true, true);
    cout << "Charge 6: " << charge(p) << endl;
    return 0;
}
