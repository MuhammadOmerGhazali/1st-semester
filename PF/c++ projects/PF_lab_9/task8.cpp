#include <iostream>
using namespace std;

void insertArrayInMiddle(int firstArray[], int firstArraySize, int secondryArray[], int secondryArraySize);

main()
{
    int firstArraySize;

    cout << "Enter the number of elements for the first array (must be 2): ";
    cin >> firstArraySize;

    int firstArray[2];

    cout << "Enter 2 elements for the first array, one per line:" << endl;
    for(int i = 0; i < 2; i++)
    {
        cin >> firstArray[i];
    }

    int secondArraySize;
    cout << "Enter the number of elements for the second array: ";
    cin >> secondArraySize;

    int secondArray[secondArraySize];
    cout << "Enter " << secondArraySize << " elements for the second array, one per line:" << endl;
    for(int i = 0; i < secondArraySize; i++)
    {
        cin >> secondArray[i];
    }

    insertArrayInMiddle(firstArray, firstArraySize, secondArray, secondArraySize);
}

void insertArrayInMiddle(int firstArray[], int firstArraySize, int secondryArray[], int secondryArraySize)
{
    cout << "Resulting array: [" << firstArray[0] << ", ";

    for (int i = 0; i < secondryArraySize; i++)
    {
        cout << secondryArray[i] << ", ";
    }

    cout << firstArray[1] << "]";
}
