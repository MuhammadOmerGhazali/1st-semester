#include <iostream>
using namespace std;

string containsSeven(int numbers[], int size);

int main()
{
    int size;
    cout << "Enter the size of Array: ";
    cin >> size;

    int numbers[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i+1 << ": ";
        cin >> numbers[i];
    }

    cout << containsSeven(numbers, size);
    return 0;
}

string containsSeven(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        string numToString = to_string(numbers[i]);
        for (int j = 0; j < numToString.length() - 1; j++)
        {
            if (numToString[j] == '7')
            {
                return "Boom!";
            }
        }
    }
    return "there is no 7 in the array";
}
