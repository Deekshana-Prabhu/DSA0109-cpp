#include <iostream>
#include <string>
using namespace std;
// Base class Bill
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
    virtual ~Bill() {}
};
// PharmacyBill class
class PharmacyBill : public Bill
{
private:
    double medicineCost, serviceCharge;
public:
    PharmacyBill(string p, int b, double m, double s)
        : Bill(p, b)
    {
        medicineCost = m;
        serviceCharge = s;
    }
    double total() const
    {
        return medicineCost + serviceCharge;
    }
    string type() const
    {
        return "Pharmacy";
    }
};
// Base class Payer
class Payer
{
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual ~Payer() {}
};
// CorporatePayer class
class CorporatePayer : public Payer
{
private:
    double discount;
public:
    CorporatePayer(double d)
    {
        discount = d;
    }
    double amountCovered(const Bill& b) const
    {
        return b.total() * (1 - discount / 100);
    }
};
// Main function
int main()
{
    PharmacyBill medicine("Ravi", 105, 2000, 200);
    CorporatePayer corporate(10);
    cout << medicine.type() << endl;
    cout << "Bill amount: "
         << medicine.total() << endl;
    cout << "Corporate payment: "
         << corporate.amountCovered(medicine) << endl;
    return 0;
}

