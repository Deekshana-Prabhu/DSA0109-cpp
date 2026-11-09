
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
};

class Address
{
private:
    string city;
    int pin;

public:
    Address(string c, int p)
    {
        city = c;
        pin = p;
    }

    string str() const
    {
        stringstream ss;
        ss << city << "-" << pin;
        return ss.str();
    }
};

class Student : public Person
{
private:
    long long regNo;
    Address home;

public:
    Student(string n, int a, long long r, string c, int p)
        : Person(n, a), regNo(r), home(c, p)
    {
    }

    void print() const
    {
        cout << regNo << " " << name << " ("
             << age << ") " << home.str() << endl;
    }
};

int main()
{
    Student s("Kavya", 19, 192311001, "Salem", 636001);

    s.print();

    return 0;
}

