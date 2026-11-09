
#include <iostream>
#include <string>
using namespace std;

class Bill
{
protected:
    string patient;
    int billNo;

public:
    Bill(string p, int b)
    {
        patient = p;
        billNo = b;
    }

    virtual double total() const = 0;
    virtual string type() const = 0;

    virtual void print() const
    {
        cout << type() << " - " << patient
             << " - " << total() << endl;
    }

    virtual ~Bill() {}
};

class OutPatientBill : public Bill
{
private:
    double consultation, tests;

public:
    OutPatientBill(string p, int b, double c, double t)
        : Bill(p, b)
    {
        consultation = c;
        tests = t;
    }

    double total() const
    {
        return consultation + tests;
    }

    string type() const
    {
        return "Out Patient";
    }
};

class InPatientBill : public Bill
{
private:
    int days;
    double room, procedures, medicines;

public:
    InPatientBill(string p, int b, int d,
                  double r, double pr, double m)
        : Bill(p, b)
    {
        days = d;
        room = r;
        procedures = pr;
        medicines = m;
    }

    double total() const
    {
        return days * room + procedures + medicines;
    }

    string type() const
    {
        return "In Patient";
    }
};

class DayCareBill : public Bill
{
private:
    double packagePrice;

public:
    DayCareBill(string p, int b, double price)
        : Bill(p, b)
    {
        packagePrice = price;
    }

    double total() const
    {
        return packagePrice;
    }

    string type() const
    {
        return "Day Care";
    }
};

class EmergencyBill : public Bill
{
private:
    double baseCharge, hourlyCharge;
    int hours;

public:
    EmergencyBill(string p, int b, double base,
                  double hourly, int h)
        : Bill(p, b)
    {
        baseCharge = base;
        hourlyCharge = hourly;
        hours = h;
    }

    double total() const
    {
        return baseCharge + hourlyCharge * hours;
    }

    string type() const
    {
        return "Emergency";
    }
};

int main()
{
    OutPatientBill b1("Arun", 101, 500, 1000);

    InPatientBill b2("Priya", 102, 3, 2000, 3000, 1500);

    DayCareBill b3("Kumar", 103, 4500);

    EmergencyBill b4("Ravi", 104, 1000, 500, 3);

    cout << "HOSPITAL BILL DETAILS" << endl;

    b1.print();
    b2.print();
    b3.print();
    b4.print();

    return 0;
}

