#include <iostream>

using namespace std;

void printTable(int number);

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    printTable(number);


}

void printTable(int number)
{
    for (int x = 1; x <= 10 ; x++)
        {
            cout <<number<<" x "<< x <<" = "<< number * x <<endl;
        }

}