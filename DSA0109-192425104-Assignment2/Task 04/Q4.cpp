
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    string transactions[10];
    int count;

    void addTransaction(string transaction)
    {
        if (count < 10)
        {
            transactions[count] = transaction;
            count++;
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                transactions[i] = transactions[i + 1];
            }

            transactions[9] = transaction;
        }
    }

public:
    SavingsAccount(int acc, double amount)
    {
        accountNumber = acc;
        balance = amount;
        count = 0;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;

            ostringstream s;
            s << amount;

            addTransaction("Deposited: " + s.str());
        }
        else
        {
            cout << "Invalid deposit amount\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;

            ostringstream s;
            s << amount;

            addTransaction("Withdrawn: " + s.str());
        }
        else
        {
            cout << "Insufficient balance or invalid amount\n";
        }
    }

    void miniStatement()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nBalance: " << balance << endl;

        cout << "\nMini Statement:\n";

        for (int i = 0; i < count; i++)
        {
            cout << transactions[i] << endl;
        }
    }
};

int main()
{
    SavingsAccount account(1001, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.miniStatement();

    return 0;
}
