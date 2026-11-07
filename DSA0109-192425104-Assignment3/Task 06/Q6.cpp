#include <iostream>
#include <cstring>
using namespace std;

class Text
{
    char* data;
    static int copyCount;
public:
    Text(const char* str = "")
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    Text(const Text& t)
    {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
        copyCount++;
    }
    Text& operator=(const Text& t)
    {
        if (this != &t)
        {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);
            delete[] data;
            data = temp;
        }
        return *this;
    }
    Text operator+(const Text& t) const
    {
        int len1 = strlen(data);
        int len2 = strlen(t.data);
        char* temp = new char[len1 + len2 + 1];
        strcpy(temp, data);
        strcat(temp, t.data);
        Text result(temp);
        delete[] temp;
        return result;
    }
    bool operator==(const Text& t) const
    {
        return strcmp(data, t.data) == 0;
    }
    bool operator!=(const Text& t) const
    {
        return !(*this == t);
    }
    friend ostream& operator<<(ostream& out, const Text& t)
    {
        out << t.data;
        return out;
    }
    ~Text()
    {
        delete[] data;
    }
    static int getCopyCount()
    {
        return copyCount;
    }
};
int Text::copyCount = 0;
int main()
{
    Text a("Hello ");
    Text b("World");
    Text c("!");
    Text result = a + b + c;
    cout << "Combined text: " << result << endl;
    Text x("Hello");
    Text y("Hello");
    cout << boolalpha;
    cout << "Equal: " << (x == y) << endl;
    cout << "Not Equal: " << (x != y) << endl;
    x = x;
    cout << "After self assignment: " << x << endl;
    Text empty("");
    cout << "Empty text: [" << empty << "]" << endl;
    cout << "Copy constructor calls: "
         << Text::getCopyCount() << endl;
    return 0;
}

