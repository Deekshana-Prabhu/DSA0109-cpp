#include <iostream>
using namespace std;

class Cart
{
    double amount;

public:
    Cart(double a) : amount(a) {}

    double total() const
    {
        return amount;
    }
};

int main()
{
    Cart c1(500), c2(800), c3(600);

    Cart* carts[3] = {&c1, &c2, &c3};

    Cart* highest = carts[0];

    for (int i = 1; i < 3; i++)
    {
        if (carts[i]->total() > highest->total())
            highest = carts[i];
    }

    cout << "Highest cart total: "
         << highest->total() << endl;

    return 0;
}



