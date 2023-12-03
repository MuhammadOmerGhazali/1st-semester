#include <iostream>
using namespace std;

bool areAllElementsIdentical(string arr[], int size);

main()
{
    int size;
    cout << "Enter the size of Array: ";
    cin >> size;

    string arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i+1 << ": ";
        cin >> arr[i];
    }
    
    bool result = areAllElementsIdentical(arr, size);
    cout << result;
}

bool areAllElementsIdentical(string arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[0])
        {
            return false;
        }
    }
    return true;
}
