#include <iostream>
#include <iomanip>
using namespace std;

class Money
{
    long long paise;
    Money(long long total, bool)
        : paise(total) {}
public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}
    Money operator+(const Money& m) const
    {
        return Money(paise + m.paise, true);
    }
    Money operator-(const Money& m) const
    {
        return Money(paise - m.paise, true);
    }
    Money& operator+=(const Money& m)
    {
        paise += m.paise;
        return *this;
    }
    bool operator==(const Money& m) const
    {
        return paise == m.paise;
    }
    bool operator<(const Money& m) const
    {
        return paise < m.paise;
    }
    friend ostream& operator<<(ostream& out, const Money& m)
    {
        long long amount = m.paise;
        if (amount < 0)
        {
            out << "-Rs ";
            amount = -amount;
        }
        else
        {
            out << "Rs ";
        }
        out << amount / 100 << "."
            << setw(2) << setfill('0')
            << amount % 100;
        return out;
    }
    friend istream& operator>>(istream& in, Money& m)
    {
        long long rupees;
        int p;
        cout << "Enter rupees and paise: ";
        if (in >> rupees >> p)
            m = Money(rupees, p);
        return in;
    }
};
int main()
{
    Money a(120, 75), b(79, 25);
    Money c = a + b;
    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;
    Money x(0, 75), y(0, 50);
    cout << "Carry: " << x + y << endl;
    Money p(10, 0), q(15, 0);
    cout << "Subtraction: " << p - q << endl;
    p += q;
    cout << "After addition: " << p << endl;
    cout << boolalpha << (x < y) << endl;
    return 0;
}


