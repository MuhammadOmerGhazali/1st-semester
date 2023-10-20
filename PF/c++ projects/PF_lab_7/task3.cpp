#include <iostream>

using namespace std;

int totalDigits(int number);

int main()
{

    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Total number of digits: " << totalDigits(number) ;

}

int totalDigits(int number)
{
    int total_digits = 0 ,x = 1;

    while( number / x != 0)
    {
        total_digits = total_digits + 1;
        x = x * 10;
    }

    return total_digits ;
}