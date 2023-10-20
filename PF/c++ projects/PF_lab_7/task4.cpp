#include <iostream>

using namespace std;

int frequencyChecker(int number, int digit);
int totalDigits(int number);

int total_digits = 0;

int main()
{

    int number, digit;

    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the digit to check: ";
    cin >> digit;

    cout << "Frequency: " << frequencyChecker(number,digit);

}

int frequencyChecker(int number, int digit)
{
    total_digits = totalDigits(number);
    int digit_num = 0 ,dig,x=1;


    for (int i = 1 ; i <= total_digits ; i ++)
    {
        dig = (number/x)%10;
        x = x * 10 ;
    if (dig == digit)
            {
                digit_num = digit_num + 1 ;
            }
        
    }

    return digit_num ;
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