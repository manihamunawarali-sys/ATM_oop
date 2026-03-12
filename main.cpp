#include "ATM.h"

int main()
{
    int pin;
    cout << "Welcome to ATM\nEnter PIN: ";

    while (true)
    {
        cin >> pin;

        if (validatePin(pin))
        {
            menu();
            break;
        }
        else
        {
            cout << "Invalid PIN. Try again: ";
        }
    }

    return 0;
}
