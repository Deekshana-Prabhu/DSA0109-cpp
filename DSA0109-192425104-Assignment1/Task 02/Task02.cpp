
#include <iostream>
using namespace std;

enum Zone {
    Inner,
    Middle,
    Outer
};

const int INNER_FARE = 1000;
const int MIDDLE_FARE = 2000;
const int OUTER_FARE = 3000;
const int MIN_BALANCE = 5000;

int getFare(Zone zone) {
    switch (zone) {
        case Inner:
            return INNER_FARE;

        case Middle:
            return MIDDLE_FARE;

        case Outer:
            return OUTER_FARE;
    }

    return 0;
}

int main() {
    Zone zone = Outer;

    int baseFare = getFare(zone);
    int peakFare = baseFare + baseFare * 20 / 100;

    cout << "Base fare: " << baseFare
         << " paise" << endl;

    cout << "Peak fare: " << peakFare
         << " paise" << endl;

    cout << "Minimum balance: "
         << MIN_BALANCE << " paise" << endl;

    return 0;
}

