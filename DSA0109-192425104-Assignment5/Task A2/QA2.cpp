#include <iostream>
using namespace std;

class Bill
{
public:
    virtual void calculate()
    {
        cout << "Base Bill Calculation" << endl;
    }

    virtual ~Bill()
    {
        cout << "~Bill" << endl;
    }
};

class OPBill : public Bill
{
public:
    void calculate() override
    {
        cout << "500" << endl;
    }

    ~OPBill()
    {
        cout << "~OPBill" << endl;
    }
};

int main()
{
    Bill *b;
    OPBill op;

    b = &op;

    b->calculate();

    return 0;
}
