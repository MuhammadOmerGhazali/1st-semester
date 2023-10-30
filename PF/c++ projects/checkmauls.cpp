#include <iostream>
#include <math.h>

using namespace std;

int Avg_malus(int number);
int totalDigits(int number);

int total_digits = 0;

int main()
{

    int number, digit;

    cout << "Enter a number: ";
    cin >> number;

    cout << "average maulus is : " << Avg_malus(number);

}

int Avg_malus(int number)
{
    total_digits = totalDigits(number);
    int dig,x=1,sum = 0;


    for (int i = total_digits ; i >= 1 ; i --)
    {
        dig = (number/x)%10;
        sum = sum + pow(dig,i);
        x = x * 10 ;
    
    }
    sum = sum + 1 ;
    return sum;
}

int totalDigits(int number)
0{
    int x = 1;

    while( number / x != 0)
    {
        total_digits = total_digits + 1;
        x = x * 10;
    }

    return total_digits ;
}