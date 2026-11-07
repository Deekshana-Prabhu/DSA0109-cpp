#include <iostream>
using namespace std;

class Auditorium
{
    int rows, seats;
    char** seatMap;
    int booked;
public:
    Auditorium(int r, int s)
        : rows(r), seats(s), booked(0)
    {
        seatMap = new char*[rows];
        for (int i = 0; i < rows; i++)
        {
            seatMap[i] = new char[seats];
            for (int j = 0; j < seats; j++)
                seatMap[i][j] = 'O';
        }
        cout << "Auditorium created\n";
    }
    void bookSeat(int r, int s)
    {
        if (r < 0 || r >= rows || s < 0 || s >= seats)
        {
            cout << "Invalid seat\n";
            return;
        }
        if (seatMap[r][s] == 'O')
        {
            seatMap[r][s] = 'X';
            booked++;
            cout << "Seat booked\n";
        }
        else
        {
            cout << "Seat already booked\n";
        }
    }
    void cancelSeat(int r, int s)
    {
        if (r < 0 || r >= rows || s < 0 || s >= seats)
        {
            cout << "Invalid seat\n";
            return;
        }
        if (seatMap[r][s] == 'X')
        {
            seatMap[r][s] = 'O';
            booked--;
            cout << "Booking cancelled\n";
        }
        else
        {
            cout << "Seat is not booked\n";
        }
    }
    void display()
    {
        cout << "Seat Map:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < seats; j++)
                cout << seatMap[i][j] << " ";
            cout << endl;
        }
    }
    ~Auditorium()
    {
        for (int i = 0; i < rows; i++)
            delete[] seatMap[i];
        delete[] seatMap;
        cout << "Auditorium closed. Booked seats: "
             << booked << endl;
    }
};
int main()
{
    Auditorium a1(2, 3);
    a1.bookSeat(0, 1);
    a1.display();
    {
        Auditorium a2(2, 2);
        a2.bookSeat(1, 1);
    }
    Auditorium* a3 = new Auditorium(2, 3);
    a3->bookSeat(0, 0);
    delete a3;
    return 0;
}
