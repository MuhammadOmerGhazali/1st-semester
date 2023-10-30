#include<iostream>

using namespace std ;

long int primorial(int num);

int main()
{
    int num ;
    cout <<"Enter Number: ";
    cin >> num;

    cout << primorial(num);
}

long int primorial(int num)
{
    if (num == 1)
        return 2;
    if (num == 2)
        return 1*2*3;
    if (num == 3)
        return 1*2*3*5;
    if (num == 4)
        return 1*2*3*5*7;
    if (num == 5)
        return 1*2*3*5*7*11;
    if (num == 6)
        return 1*2*3*5*7*11*13;
    if (num == 7)
        return 1*2*3*5*7*11*13*15;
    if (num == 8)
        return 9699690;
    
}
