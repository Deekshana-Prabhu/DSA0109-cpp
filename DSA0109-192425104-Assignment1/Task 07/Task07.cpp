
#include <iostream>
using namespace std;

const long long MIN_BALANCE = 5000;

// Procedural approach
bool canTravel(long long balance, long long fare)
{
    return fare >= 0 && balance - fare >= MIN_BALANCE;
}

int main()
{
    // Procedural approach
    long long balance = 10000;
    long long fare = 3000;

    if (canTravel(balance, fare))
    {
        balance = balance - fare;
        cout << "Procedural balance: Rs "
             << balance / 100 << '\n';
    }

    // Object-oriented approach
    class SmartCard
    {
    private:
        long long balance;

    public:
        SmartCard(long long b)
        {
            balance = b;
        }

        bool canTravel(long long fare)
        {
            return fare >= 0 &&
                   balance - fare >= MIN_BALANCE;
        }

        void deduct(long long fare)
        {
            if (canTravel(fare))
                balance = balance - fare;
        }

        long long getBalance()
        {
            return balance;
        }
    };

    SmartCard card(10000);

    if (card.canTravel(fare))
    {
        card.deduct(fare);
        cout << "OOP balance: Rs "
             << card.getBalance() / 100 << '\n';
    }

    return 0;
}

