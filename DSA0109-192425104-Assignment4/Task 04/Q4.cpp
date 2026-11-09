#include <iostream>
#include <vector>
using namespace std;
class Account
{
public:
    virtual double rate() const
    {
        return 3.5;
    }
    virtual ~Account()
    {
        cout << "Account destroyed" << endl;
    }
};
class SeniorAccount : public Account
{
private:
    double* history;
public:
    SeniorAccount()
    {
        history = new double[100];
    }
    double rate() const
    {
        return 4.0;
    }
    ~SeniorAccount()
    {
        delete[] history;
        cout << "SeniorAccount destroyed" << endl;
    }
};
int main()
{
    vector<Account*> accounts;
    accounts.push_back(new Account());
    accounts.push_back(new SeniorAccount());
    for (int i = 0; i < accounts.size(); i++)
    {
        cout << accounts[i]->rate() << endl;
    }
    for (int i = 0; i < accounts.size(); i++)
    {
        delete accounts[i];
    }
    return 0;
}


