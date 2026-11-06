
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class BusTicket
{
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    explicit BusTicket(const string& n)
    {
        seat = 0;
        name = n;

        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
    }

    static int count()
    {
        return issued;
    }

    void print() const
    {
        cout << name << ": ";

        if (seat != 0)
        {
            cout << "Seat " << seat;
        }
        else
        {
            cout << "Waiting";
        }

        cout << endl;
    }
};

int BusTicket::issued = 0;

int main()
{
    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (int i = 0; i < 4; i++)
    {
        trip[i].print();
    }

    cout << "Issued: " << BusTicket::count() << endl;

    return 0;
}
