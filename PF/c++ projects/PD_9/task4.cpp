#include <iostream>
using namespace std;

void evenOddTransform(int arr[], int size, int n);

main()
{
    int size;
    cout << "Enter the size of Array: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i+1 << ": ";
        cin >> arr[i];
    }

    int n;
    cout << "Enter number of times even-odd transformation need to be done: ";
    cin >> n;

    evenOddTransform(arr, size, n);
}

void evenOddTransform(int arr[], int size, int n)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[i] -= 2 * n;
            
            if (i == size - 1)
            {
                cout << arr[i] << "]";
            }
            else {
                cout << arr[i] << ", ";
            }
        }
        
        else {
            arr[i] += 2 * n;
            
            if (i == size - 1)
            {
                cout << arr[i] << "]";
            }
            else {
                cout << arr[i] << ", ";
            }
        }
    }
}
