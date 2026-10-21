#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int fare = 1000;  // Rs. 10 in paise
    int trips[] = {20000, 500000, 3000000};

    cout << fixed << setprecision(2);

    for (int i = 0; i < 3; i++)
    {
        long long totalPaise = (long long)fare * trips[i];
        double totalRupees = (double)fare * trips[i] / 100.0;

        cout << "Trips: " << trips[i] << endl;
        cout << "Total in paise: " << totalPaise << endl;
        cout << "Total in rupees: Rs. "
             << totalRupees << endl;
        cout << "-------------------" << endl;
    }

    return 0;
}
