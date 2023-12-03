#include <iostream>
#include <cmath>
using namespace std;

int findLargestNumber(int arr[], int size);

int main()
{
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " numbers, one per line: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "The largest number entered is: " << findLargestNumber(arr, size);
}

int findLargestNumber(int arr[], int size)
{
    int largest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return largest;
}