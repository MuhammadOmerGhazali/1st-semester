#include <iostream>
using namespace std ;

float Minimum(float x ,float y );

int main()
{
    float num1 , num2 ;
    
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    Minimum(num1,num2);

}

float Minimum(float num1 ,float num2 )
{

    if (num1>num2)
    {
        cout <<"The minimum of "<<num1<<" and "<<num2<<" is: "<<num2;
    }
    else  cout <<"The minimum of "<<num1<<" and "<<num2<<" is: "<<num1;
}