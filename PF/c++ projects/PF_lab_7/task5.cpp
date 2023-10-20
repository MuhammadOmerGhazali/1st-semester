#include <iostream>

using namespace std;

int digitSum(int number);
int totalDigits(int number);

int total_digits = 0;

int main()
{

    int number, digit;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Sum of digits: " << digitSum(number);

}

int digitSum(int number)
{
    total_digits = totalDigits(number);
    int dig,x=1,sum = 0;


    for (int i = 1 ; i <= total_digits ; i ++)
    {
        dig = (number/x)%10;
        sum = sum + dig ;
        x = x * 10 ;
    
    }

    return sum ;
}

int totalDigits(int number)
{
    int x = 1;

    while( number / x != 0)
    {
        total_digits = total_digits + 1;
        x = x * 10;
    }

    return total_digits ;
}