#include "ATM.h"

string AccountType[] = { "", "CHECKINGS", "SAVINGS" };

int AccountDetails[] =
{
    1234,
    100,
    600
};

bool validatePin(int pin)
{
    return pin == AccountDetails[0];
}

Account::Account(int b)
{
    balance = b;
}

Account::~Account() {}

Checkings::Checkings() : Account(AccountDetails[1]) {}

void Checkings::showBalance()
{
    cout << "Checkings Balance: $" << balance << endl;
}

void Checkings::withdraw(int amount)
{
    if (amount <= 0)
        throw string("Invalid withdrawal amount");

    if (amount > balance)
        throw string("Insufficient balance");

    balance -= amount;
    AccountDetails[1] = balance;
    cout << "Withdrawn $" << amount << endl;
}

void Checkings::deposit(int amount)
{
    if (amount <= 0)
        throw string("Invalid deposit amount");

    balance += amount;
    AccountDetails[1] = balance;
    cout << "Deposited $" << amount << endl;
}

Savings::Savings() : Account(AccountDetails[2]) {}

void Savings::showBalance()
{
    cout << "Savings Balance: $" << balance << endl;
}

void Savings::withdraw(int amount)
{
    if (amount <= 0)
        throw string("Invalid withdrawal amount");

    if (amount > balance)
        throw string("Insufficient balance");

    balance -= amount;
    AccountDetails[2] = balance;
    cout << "Withdrawn $" << amount << endl;
}

void Savings::deposit(int amount)
{
    if (amount <= 0)
        throw string("Invalid deposit amount");

    balance += amount;
    AccountDetails[2] = balance;
    cout << "Deposited $" << amount << endl;
}

void accountMenu(Account* acc)
{
    int choice, amount;

    while (true)
    {
        cout << "\n1. Balance\n2. Withdraw\n3. Deposit\n4. Back\n";
        cin >> choice;

        try
        {
            if (choice == 1)
                acc->showBalance();
            else if (choice == 2)
            {
                cout << "Enter amount: ";
                cin >> amount;
                acc->withdraw(amount);
            }
            else if (choice == 3)
            {
                cout << "Enter amount: ";
                cin >> amount;
                acc->deposit(amount);
            }
            else
                break;
        }
        catch (string msg)
        {
            cout << msg << endl;
        }
    }
}

void menu()
{
    int option;

    while (true)
    {
        cout << "\nMain Menu\n1. Checkings\n2. Savings\n3. Exit\n";
        cin >> option;

        if (option == 1)
        {
            Checkings c;
            accountMenu(&c);
        }
        else if (option == 2)
        {
            Savings s;
            accountMenu(&s);
        }
        else
            break;
    }
}
