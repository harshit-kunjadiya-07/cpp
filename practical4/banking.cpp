#include <iostream>

using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int number, string name, double amount)
    {
        accountNumber = number;
        accountHolderName = name;
        balance = amount;
    }

    virtual void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw "Invalid deposit amount!";
        }

        balance = balance + amount;
        cout << "Amount deposited successfully.\n";
    }

    virtual void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw "Invalid withdrawal amount!";
        }

        if (amount > balance)
        {
            throw "Insufficient balance!";
        }

        balance = balance - amount;
        cout << "Amount withdrawn successfully.\n";
    }

    double getBalance()
    {
        return balance;
    }

    virtual void calculateInterest()
    {
        cout << "Interest calculation is not available.\n";
    }

    virtual void displayAccountInfo()
    {
        cout << "\n-----------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : " << balance << endl;
    }

    virtual ~BankAccount()
    {
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int number, string name, double amount, double rate)
        : BankAccount(number, name, amount)
    {
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest;

        interest = balance * interestRate / 100;

        cout << "Interest Rate : " << interestRate << "%" << endl;
        cout << "Interest      : " << interest << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n===== SAVINGS ACCOUNT =====\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : " << balance << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int number, string name, double amount, double limit)
        : BankAccount(number, name, amount)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount <= 0)
        {
            throw "Invalid withdrawal amount!";
        }

        if (amount > balance + overdraftLimit)
        {
            throw "Withdrawal exceeds overdraft limit!";
        }

        balance = balance - amount;

        cout << "Amount withdrawn successfully.\n";
    }

    void checkOverdraft()
    {
        if (balance < 0)
        {
            cout << "Overdraft Used : " << -balance << endl;
        }
        else
        {
            cout << "No overdraft used.\n";
        }

        cout << "Overdraft Limit : " << overdraftLimit << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n===== CHECKING ACCOUNT =====\n";
        cout << "Account Number  : " << accountNumber << endl;
        cout << "Account Holder  : " << accountHolderName << endl;
        cout << "Balance         : " << balance << endl;
        cout << "Overdraft Limit : " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int number, string name, double amount,
                        int months, double rate)
        : BankAccount(number, name, amount)
    {
        term = months;
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest;

        interest = balance * interestRate * term / (100 * 12);

        cout << "Interest Rate : " << interestRate << "%" << endl;
        cout << "Term          : " << term << " months" << endl;
        cout << "Interest      : " << interest << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n===== FIXED DEPOSIT ACCOUNT =====\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : " << balance << endl;
        cout << "Term           : " << term << " months" << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;
    }
};

int main()
{
    BankAccount *accounts[10];

    int accountCount = 0;
    int choice;

    cout << "====================================\n";
    cout << "        BANKING SYSTEM\n";
    cout << "====================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Display Account Information\n";
        cout << "5. Deposit Money\n";
        cout << "6. Withdraw Money\n";
        cout << "7. Calculate Interest\n";
        cout << "8. Check Overdraft\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                int number;
                string name;
                double amount, rate;

                cout << "\nEnter Account Number: ";
                cin >> number;

                cout << "Enter Account Holder Name: ";
                cin >> name;

                cout << "Enter Initial Balance: ";
                cin >> amount;

                if (amount < 0)
                {
                    throw "Balance cannot be negative!";
                }

                cout << "Enter Interest Rate: ";
                cin >> rate;

                accounts[accountCount] =
                    new SavingsAccount(number, name, amount, rate);

                accountCount++;

                cout << "Savings account created successfully.\n";
            }
            else if (choice == 2)
            {
                int number;
                string name;
                double amount, limit;

                cout << "\nEnter Account Number: ";
                cin >> number;

                cout << "Enter Account Holder Name: ";
                cin >> name;

                cout << "Enter Initial Balance: ";
                cin >> amount;

                if (amount < 0)
                {
                    throw "Balance cannot be negative!";
                }

                cout << "Enter Overdraft Limit: ";
                cin >> limit;

                accounts[accountCount] =
                    new CheckingAccount(number, name, amount, limit);

                accountCount++;

                cout << "Checking account created successfully.\n";
            }
            else if (choice == 3)
            {
                int number;
                string name;
                int months;
                double amount, rate;

                cout << "\nEnter Account Number: ";
                cin >> number;

                cout << "Enter Account Holder Name: ";
                cin >> name;

                cout << "Enter Deposit Amount: ";
                cin >> amount;

                if (amount < 0)
                {
                    throw "Deposit amount cannot be negative!";
                }

                cout << "Enter Term in Months: ";
                cin >> months;

                cout << "Enter Interest Rate: ";
                cin >> rate;

                accounts[accountCount] =
                    new FixedDepositAccount(
                        number, name, amount, months, rate);

                accountCount++;

                cout << "Fixed deposit account created successfully.\n";
            }
            else if (choice == 4)
            {
                int i;

                if (accountCount == 0)
                {
                    cout << "No accounts available.\n";
                }
                else
                {
                    for (i = 0; i < accountCount; i++)
                    {
                        accounts[i]->displayAccountInfo();
                    }
                }
            }
            else if (choice == 5)
            {
                int index;
                double amount;

                cout << "Enter Account Index (1-" << accountCount << "): ";
                cin >> index;

                if (index < 1 || index > accountCount)
                {
                    throw "Invalid account index!";
                }

                cout << "Enter Deposit Amount: ";
                cin >> amount;

                accounts[index - 1]->deposit(amount);

                cout << "New Balance: "
                        << accounts[index - 1]->getBalance() << endl;
            }
            else if (choice == 6)
            {
                int index;
                double amount;

                cout << "Enter Account Index (1-" << accountCount << "): ";
                cin >> index;

                if (index < 1 || index > accountCount)
                {
                    throw "Invalid account index!";
                }

                cout << "Enter Withdrawal Amount: ";
                cin >> amount;

                accounts[index - 1]->withdraw(amount);

                cout << "New Balance: "
                        << accounts[index - 1]->getBalance() << endl;
            }
            else if (choice == 7)
            {
                int index;

                cout << "Enter Account Index (1-" << accountCount << "): ";
                cin >> index;

                if (index < 1 || index > accountCount)
                {
                    throw "Invalid account index!";
                }

                accounts[index - 1]->calculateInterest();
            }
            else if (choice == 8)
            {
                int index;

                cout << "Enter Account Index (1-" << accountCount << "): ";
                cin >> index;

                if (index < 1 || index > accountCount)
                {
                    throw "Invalid account index!";
                }

                CheckingAccount *checking;

                checking =
                    dynamic_cast<CheckingAccount *>(accounts[index - 1]);

                if (checking != nullptr)
                {
                    checking->checkOverdraft();
                }
                else
                {
                    cout << "Selected account is not a checking account.\n";
                }
            }
            else if (choice == 9)
            {
                cout << "\nThank you for using Banking System.\n";
            }
            else
            {
                cout << "Invalid choice!\n";
            }
        }
        catch (const char *error)
        {
            cout << "Error: " << error << endl;
        }

    } while (choice != 9);

    int i;

    for (i = 0; i < accountCount; i++)
    {
        delete accounts[i];
    }

    return 0;
}