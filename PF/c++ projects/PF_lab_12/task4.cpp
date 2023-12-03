#include <iostream>

using namespace std;

void printSum(int x[][3],int rows);

int main()
{
    int rows;

    cout <<"Enter row size: ";
    cin >>rows;

    int array[rows][3];

    cout <<"Enter the elements of the matrix: "<<endl;

    for (int x = 0 ; x<rows;x++)
    {
        for (int y = 0;y<3;y++)
        {
            cout <<"Enter element at position ["<<x<<"]["<<y<<"]: ";
            cin >> array[x][y];
        }
    }

    printSum(array,rows);
}

void printSum(int array[][3],int rows)
{
    int sum = 0;

    for (int x = 0 ; x<rows;x++)
    {
        for (int y = 0;y<3;y++)
        {
            sum = sum + array[x][y];
        }
    }

    cout <<"The sum of elements in the matrix is: "<< sum;
}