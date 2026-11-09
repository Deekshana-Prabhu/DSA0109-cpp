
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string regNo;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double rate)
    {
        regNo = r;
        dailyRate = rate;
        rented = false;
    }

    virtual double charge(int days) const = 0;

    void rent()
    {
        if (!rented)
        {
            rented = true;
            cout << regNo << " rented successfully" << endl;
        }
        else
        {
            cout << regNo << " is already rented" << endl;
        }
    }

    void returnVehicle(int daysLate)
    {
        if (rented)
        {
            rented = false;

            double lateFee = daysLate * 200;

            cout << regNo << " returned successfully" << endl;
            cout << "Late charge: " << lateFee << endl;
        }
        else
        {
            cout << regNo << " was not rented" << endl;
        }
    }

    virtual void display() const
    {
        cout << "Registration: " << regNo
             << ", Daily rate: " << dailyRate << endl;
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle
{
public:
    Bicycle(string r, double rate)
        : Vehicle(r, rate) {}

    double charge(int days) const
    {
        return dailyRate * days;
    }
};

class MotorVehicle : public Vehicle
{
protected:
    double fuelLevel;
    string serviceDate;

public:
    MotorVehicle(string r, double rate,
                 double fuel, string date)
        : Vehicle(r, rate)
    {
        fuelLevel = fuel;
        serviceDate = date;
    }
};

class TwoWheeler : public MotorVehicle
{
public:
    TwoWheeler(string r, double rate,
               double fuel, string date)
        : MotorVehicle(r, rate, fuel, date) {}

    double charge(int days) const
    {
        return dailyRate * days;
    }
};

class Car : public MotorVehicle
{
protected:
    int seatingCapacity;

public:
    Car(string r, double rate, double fuel,
        string date, int seats)
        : MotorVehicle(r, rate, fuel, date)
    {
        seatingCapacity = seats;
    }

    double charge(int days) const
    {
        return dailyRate * days;
    }
};

class ElectricCar : public Car
{
private:
    double batteryCapacity;
    double costPerKWh;

public:
    ElectricCar(string r, double rate, double fuel,
                string date, int seats,
                double battery, double cost)
        : Car(r, rate, fuel, date, seats)
    {
        batteryCapacity = battery;
        costPerKWh = cost;
    }

    double charge(int days) const
    {
        double rental = dailyRate * days;
        double chargingCost = batteryCapacity * costPerKWh;

        return rental + chargingCost;
    }
};

class ElectricBus : public Vehicle
{
private:
    double batteryCapacity;
    double costPerKWh;

public:
    ElectricBus(string r, double rate,
                double battery, double cost)
        : Vehicle(r, rate)
    {
        batteryCapacity = battery;
        costPerKWh = cost;
    }

    double charge(int days) const
    {
        return dailyRate * days +
               batteryCapacity * costPerKWh;
    }
};

int main()
{
    vector<Vehicle*> fleet;

    fleet.push_back(new Bicycle("B101", 100));

    fleet.push_back(new TwoWheeler(
        "T201", 300, 80, "2026-12-01"));

    fleet.push_back(new Car(
        "C301", 1000, 60, "2026-12-05", 5));

    fleet.push_back(new ElectricCar(
        "E401", 1500, 0, "2026-12-10",
        5, 50, 8));

    fleet.push_back(new ElectricBus(
        "EB501", 2500, 100, 8));

    cout << "VEHICLE RENTAL FLEET" << endl;

    for (int i = 0; i < fleet.size(); i++)
    {
        fleet[i]->display();
    }

    cout << "\nRENTAL DETAILS" << endl;

    for (int i = 0; i < fleet.size(); i++)
    {
        fleet[i]->rent();

        cout << "Rental charge for 2 days: "
             << fleet[i]->charge(2) << endl;
    }

    cout << "\nRETURN DETAILS" << endl;

    fleet[0]->returnVehicle(1);
    fleet[1]->returnVehicle(0);
    fleet[2]->returnVehicle(2);
    fleet[3]->returnVehicle(0);
    fleet[4]->returnVehicle(0);

    // Free allocated memory
    for (int i = 0; i < fleet.size(); i++)
    {
        delete fleet[i];
    }

    return 0;
}

