#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class BillingError : public runtime_error
{
public:
    BillingError(string message)
        : runtime_error(message)
    {
    }
};
class ClaimError : public BillingError
{
public:
    ClaimError(string message)
        : BillingError(message)
    {
    }
};
class PackageError : public BillingError
{
public:
    PackageError(string message)
        : BillingError(message)
    {
    }
};
class PatientError : public BillingError
{
public:
    PatientError(string message)
        : BillingError(message)
    {
    }
};
int main()
{
    try
    {
        throw ClaimError("Invalid insurance claim");
    }
    catch (const ClaimError& e)
    {
        cout << "Claim Error: " << e.what() << endl;
    }
    catch (const BillingError& e)
    {
        cout << "Billing Error: " << e.what() << endl;
    }
    return 0;
}



