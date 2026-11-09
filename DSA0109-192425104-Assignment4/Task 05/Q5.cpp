#include <iostream>
using namespace std;

class Cart
{
    double amount;
public:
    Cart(double amount)
    {
        this->amount = amount;
    }
    Cart& add(double amount)
    {
        this->amount += amount;
        return *this;
    }
    double total() const
    {
        return amount;
    }
};
int main()
{
    // 1. Directly by object name
    Cart c(100);
    cout << "Direct: " << c.total() << endl;
    // 2. Through pointer
    Cart* p = &c;
    cout << "Pointer: " << p->total() << endl;
    // 3. Through reference
    Cart& r = c;
    cout << "Reference: " << r.total() << endl;
    // 4. Dynamic object using new and delete
    Cart* d = new Cart(200);
    cout << "Dynamic: " << d->total() << endl;
    delete d;
    // Method chaining
    c.add(50).add(25);
    cout << "After adding: " << c.total() << endl;
    return 0;
}

