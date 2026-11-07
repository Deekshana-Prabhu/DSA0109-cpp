#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Time
{
    int totalSeconds;
public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        totalSeconds = h * 3600 + m * 60 + s;
    }
    Time& operator++()
    {
        totalSeconds++;
        return *this;
    }
    Time operator++(int)
    {
        Time old = *this;
        totalSeconds++;
        return old;
    }
    bool operator==(const Time& t) const
    {
        return totalSeconds == t.totalSeconds;
    }
    bool operator<(const Time& t) const
    {
        return totalSeconds < t.totalSeconds;
    }
    void display() const
    {
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        cout << setfill('0')
             << setw(2) << h << ":"
             << setw(2) << m << ":"
             << setw(2) << s << endl;
    }
};
class Playlist
{
    vector<string> songs;
public:
    Playlist()
    {
        songs.push_back("Song A");
        songs.push_back("Song B");
        songs.push_back("Song C");
    }
    string& operator[](int index)
    {
        if (index < 0 || index >= (int)songs.size())
            throw out_of_range("Invalid playlist index");
        return songs[index];
    }
    const string& operator[](int index) const
    {
        if (index < 0 || index >= (int)songs.size())
            throw out_of_range("Invalid playlist index");
        return songs[index];
    }
    int size() const
    {
        return songs.size();
    }
};
int main()
{
    Time t(0, 0, 5);
    Time a = t++;
    Time b = ++t;
    cout << "Postfix result: ";
    a.display();
    cout << "Prefix result: ";
    b.display();
    cout << "Current time: ";
    t.display();
    Time x(0, 59, 59);
    ++x;
    cout << "After rollover: ";
    x.display();
    Playlist p;
    cout << "First song: " << p[0] << endl;
    p[1] = "New Song";
    cout << "Updated song: " << p[1] << endl;
    try
    {
        cout << p[-1] << endl;
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << p[p.size()] << endl;
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
