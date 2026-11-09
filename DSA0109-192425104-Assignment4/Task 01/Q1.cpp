
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Staff
{
protected:
    string name;
    int id;

public:
    Staff(string n, int i)
    {
        name = n;
        id = i;
    }

    virtual double pay() const = 0;

    virtual void display() const
    {
        cout << name << " (" << id << ") - ";
        cout << pay() << endl;
    }

    virtual ~Staff() {}
};

class Professor : public Staff
{
private:
    double basic, research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i)
    {
        basic = b;
        research = r;
    }

    double pay() const
    {
        return basic + (basic * 0.42) + research;
    }
};

class LabAssistant : public Staff
{
private:
    double basic;

public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i)
    {
        basic = b;
    }

    double pay() const
    {
        return basic + (basic * 0.42);
    }
};

class GuestFaculty : public Staff
{
private:
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i)
    {
        hours = h;
        rate = r;
    }

    double pay() const
    {
        return hours * rate;
    }
};

int main()
{
    vector<Staff*> staff;

    staff.push_back(new Professor("Arun", 101, 50000, 5000));
    staff.push_back(new LabAssistant("Priya", 102, 30000));
    staff.push_back(new GuestFaculty("Kumar", 103, 40, 500));

    cout << "Staff Salary Details:" << endl;

    for (int i = 0; i < staff.size(); i++)
    {
        staff[i]->display();
    }

    for (int i = 0; i < staff.size(); i++)
    {
        delete staff[i];
    }

    return 0;
}

