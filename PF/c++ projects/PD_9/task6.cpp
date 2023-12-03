#include <iostream>
using namespace std;

int coloringTime(string cols[], int size);

main()
{
    int size;
    cout << "Enter the size of Array: ";
    cin >> size;

    string cols[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i+1 << ": ";
        cin >> cols[i];
    }

    cout << "Time to color: " << coloringTime(cols, size) << " seconds";
}

int coloringTime(string cols[], int size)
{
    int colors = size * 2;
    int colsSwitch = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (cols[i] != cols[i+1])
        {
            colsSwitch++;
        }
    }

    int result = colors + colsSwitch;
    return result;
}
