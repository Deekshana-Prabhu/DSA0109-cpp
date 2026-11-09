#include <iostream>
using namespace std;

class Bill
{
public:
    double amount;

    Bill(double a)
    {
        amount = a;
    }

    virtual ~Bill() {}

    virtual double total()
    {
        return amount;
    }
};

class Payer
{
public:
    virtual double amountCovered(Bill &b) = 0;

    virtual ~Payer() {}
};

class SelfPay : public Payer
{
public:
    double amountCovered(Bill &b) override
    {
        return 0;
    }
};

class Insurance : public Payer
{
private:
    double coverLimit;
    double coPayment;

public:
    Insurance(double limit, double co)
    {
        coverLimit = limit;
        coPayment = co;
    }

    double amountCovered(Bill &b) override
    {
        double covered = b.total() * (1 - coPayment / 100);

        if (covered > coverLimit)
            covered = coverLimit;

        return covered;
    }
};

class GovernmentScheme : public Payer
{
private:
    double packageRate;

public:
    GovernmentScheme(double rate)
    {
        packageRate = rate;
    }

    double amountCovered(Bill &b) override
    {
        if (packageRate > b.total())
            return b.total();

        return packageRate;
    }
};

int main()
{
    Bill bill(50000);

    SelfPay self;
    Insurance insurance(40000, 20);
    GovernmentScheme government(30000);

    Payer *p;

    p = &self;
    cout << "Self Pay Coverage: "
         << p->amountCovered(bill) << endl;

    p = &insurance;
    cout << "Insurance Coverage: "
         << p->amountCovered(bill) << endl;

    p = &government;
    cout << "Government Scheme Coverage: "
         << p->amountCovered(bill) << endl;

    return 0;
}
