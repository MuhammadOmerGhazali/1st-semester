#include <iostream>
using namespace std;

void printReverseOrder(int numbers[], int elements);

main()
{
    int elements;

    cout << "Enter the number of elements: ";
    cin >> elements;

    if (elements <= 0)
    {
        cout << "Invalid input. Number of elements must be greater than 0." << endl;
        return 0;
    }

    int numbers[elements];
    
    cout << "Enter " << elements << " numbers, one per line:" << endl; 
    for(int i = 0; i < elements; i++)
    {
        cin >> numbers[i];
    }

    cout << "Numbers in reverse order: ";
    printReverseOrder(numbers, elements);
}

void printReverseOrder(int numbers[], int elements)
{
    for (int i = elements-1; i >= 0; i--)
    {
        cout << numbers[i] << ' ';
    }
}
