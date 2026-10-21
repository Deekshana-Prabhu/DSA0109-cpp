#include <iostream>
using namespace std;

enum Zone
{
    Inner,
    Middle,
    Outer
};

const int fare[] = {1000, 2000, 3000};

class SmartCard
{
private:
    long long balance;

public:
    SmartCard(long long b)
    {
        balance = b;
    }

    void travel(Zone z, bool peak)
    {
        long long cost = fare[z];

        if (peak)
            cost = cost + cost * 20 / 100;

        if (balance - cost >= 5000)
        {
            balance = balance - cost;
            cout << "Journey approved" << endl;
            cout << "Fare: Rs. " << cost / 100.0 << endl;
        }
        else
        {
            cout << "Journey denied" << endl;
        }

        cout << "Balance: Rs. "
             << balance / 100.0 << endl;
    }
};

int main()
{
    SmartCard card(10000);

    card.travel(Inner, false);
    card.travel(Outer, true);

    return 0;
}
