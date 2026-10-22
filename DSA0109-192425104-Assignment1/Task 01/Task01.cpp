
#include <iostream>
using namespace std;

class SmartCard {
private:
    long long balancePaise;

public:
    SmartCard(long long balance) : balancePaise(balance) {}

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 &&
               balancePaise - farePaise >= 5000;
    }

    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) {
            return false;
        }

        balancePaise -= farePaise;
        return true;
    }

    long long getBalance() const {
        return balancePaise;
    }
};

int main() {
    SmartCard card(10000);

    if (card.deduct(3000)) {
        cout << "Journey approved\n";
    } else {
        cout << "Journey denied\n";
    }

    cout << "Balance: Rs "
         << card.getBalance() / 100 << '\n';

    if (card.deduct(6000)) {
        cout << "Journey approved\n";
    } else {
        cout << "Journey denied\n";
    }

    cout << "Balance: Rs "
         << card.getBalance() / 100 << '\n';

    return 0;
}

