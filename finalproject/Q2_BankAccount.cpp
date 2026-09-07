#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    BankAccount(int accNo, double bal, string name)
    {
        accountNumber = accNo;
        balance = bal;
        ownerName = name;
    }

    void credit(double amount)
    {
        balance = balance + amount;
    }

    void debit(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    void displayBalance()
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Owner Name     : " << ownerName << endl;
        cout << "Balance        : " << balance << endl;
    }
};

int main()
{
    BankAccount account(10101, 10000, "Harshit");

    cout << "Initial Account Details" << endl;
    account.displayBalance();

    account.credit(5000);
    cout << "\nAfter Credit of 5000" << endl;
    account.displayBalance();

    account.debit(3000);
    cout << "\nAfter Debit of 3000" << endl;
    account.displayBalance();

    return 0;
}
