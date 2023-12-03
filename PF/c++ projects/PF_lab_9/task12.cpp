#include <iostream>
using namespace std;

bool isSpecialArray(int arr[], int size);

main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    if(isSpecialArray(arr, size))
    {
        cout << "The array is special";
    }
    else {
        cout << "The array is not special";
    }
}

bool isSpecialArray(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if(arr[i] != i)
        {
            return false;
        }
    }

    for(int j = 1; j < size; j += 2)
    {
        if(arr[j] != j)
        {
            return false;
        }
    }

    return true;
}
