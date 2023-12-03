#include <iostream>
#include <cctype>
using namespace std;

void convertPINToDance(string pin);

int main()
{
    string pin;
    cout << "Enter your PIN (4 digits): ";
    cin >> pin;

    // Check if pin is valid or not.
    bool isValid = true;
    for (int i = 0; i < 4; i++) {
        if (pin.length() != 4 || !isdigit(pin[i]))
        {
            cout << "Invalid input.";
            isValid = false;
            break;
        }
    }

    if (pin.length() == 4 && isValid) {
        convertPINToDance(pin);
    }
}

void convertPINToDance(string pin)
{
    string moves[10] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado", "Pop", "Lock", "Arabesque"};
    int index;
    for (int i = 0; i < pin.length() ; i++)
    {
        index = pin[i] - '0'; // convert char into integer.
        
        index = (index + i) % 10;  //add pin to i for next move.

        cout << moves[index];

        //check if it is not last iteration
        if (i < pin.length() - 1)
        {
            cout << ", ";
        }
    }
}