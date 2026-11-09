
#include <iostream>
#include <vector>
using namespace std;

class Bill
{
public:
    virtual double total() const = 0;

    virtual ~Bill() {}
};

class OutPatientBill : public Bill
{
private:
    double consultation, tests;

public:
    OutPatientBill(double c, double t)
    {
        consultation = c;
        tests = t;
    }

    double total() const
    {
        return consultation + tests;
    }
};

class InPatientBill : public Bill
{
private:
    int days;
    double perDay, surgery;

public:
    InPatientBill(int d, double p, double s)
    {
        days = d;
        perDay = p;
        surgery = s;
    }

    double total() const
    {
        return days * perDay + surgery;
    }
};

int main()
{
    vector<Bill*> bills;

    bills.push_back(new OutPatientBill(500, 1200));
    bills.push_back(new InPatientBill(3, 2500, 40000));

    double sum = 0;

    for (int i = 0; i < bills.size(); i++)
    {
        sum = sum + bills[i]->total();
    }

    cout << "Total: " << sum << endl;

    for (int i = 0; i < bills.size(); i++)
    {
        delete bills[i];
    }

    return 0;
}

