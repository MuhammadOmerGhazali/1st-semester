#include <iostream>
using namespace std;

bool isAlreadyEntered(int arr[], int size, int);

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " numbers, one per line:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        
        if (isAlreadyEntered(arr, i, arr[i]))
        {
            cout << "Already Entered: " << arr[i] << endl;
        }
    }

    //Check unique numbers
    cout << "Unique numbers entered: ";
    for (int i = 0; i < size; i++) 
    {
        if (!isAlreadyEntered(arr, i, arr[i])) 
        {
            cout << arr[i] << ' ';
        }
    }

}

bool isAlreadyEntered(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++) //A loop which matches each elements of array with given number to check if they matches it means this num is already present.
    {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}
