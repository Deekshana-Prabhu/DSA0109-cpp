
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
    int start;
    int count;

public:
    SavingsAccount(int acc, double amount)
    {
        accountNumber = acc;
        balance = amount;
        start = 0;
        count = 0;
    }

    void addTransaction(string transaction)
    {
        int position = (start + count) % 10;
        transactions[position] = transaction;

        if (count < 10)
        {
            count++;
        }
        else
        {
            start = (start + 1) % 10;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;

            ostringstream s;
            s << amount;

            addTransaction("Deposit: " + s.str());
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;

            ostringstream s;
            s << amount;

            addTransaction("Withdraw: " + s.str());
        }
        else
        {
            cout << "Insufficient balance or invalid amount"
                 << endl;
        }
    }

    void miniStatement()
    {
        cout << "Account Number: "
             << accountNumber << endl;

        cout << "Balance: "
             << balance << endl;

        cout << "\nLast 10 Transactions:\n";

        for (int i = 0; i < count; i++)
        {
            int position = (start + i) % 10;
            cout << transactions[position] << endl;
        }
    }
};

int main()
{
    SavingsAccount account(1001, 5000);

    for (int i = 1; i <= 12; i++)
    {
        account.deposit(100);
    }

    account.miniStatement();

    return 0;
}
