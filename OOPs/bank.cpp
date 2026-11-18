
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    int accountNo;
    string name;
    double balance;

public:
    void acceptDetails()
    {
        cout << "Enter Account Number: ";
        cin >> accountNo;

        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw "Deposit amount must be positive.";

        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw "Withdrawal amount must be positive.";

        if (amount > balance)
            throw "Insufficient balance.";

        balance -= amount;
        cout << "Amount withdrawn successfully.\n";
    }

    void display()
    {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNo << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account;
    int choice;
    double amount;

    account.acceptDetails();

    do
    {
        cout << "\n1. Deposit Money";
        cout << "\n2. Withdraw Money";
        cout << "\n3. Display Account Details";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.display();
                break;

            case 4:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice.\n";
            }
        }
        catch (const char *msg)
        {
            cout << "Exception: " << msg << endl;
        }

    } while (choice != 4);

    return 0;
}
