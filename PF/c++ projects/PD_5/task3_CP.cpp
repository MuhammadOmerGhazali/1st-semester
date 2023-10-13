#include <iostream>
using namespace std;

float taxCalculator(char code, float price);

int main()
{
    float initial_price ;
    char code;
    
    cout<<"Enter the vehicle type code (M, E, S, V, T): ";
    cin>> code;
    cout<< "Enter the price of the vehicle: $";
    cin>> initial_price;

    taxCalculator(code,initial_price);


}

float taxCalculator(char code, float initial_price)
{
    float final_price,tax;

    if (code == 'M')
        tax = .06;
    if (code == 'E')
        tax = 0.08;
    if (code == 'S')
        tax = .10;
    if (code == 'V')
        tax = .12;
    if (code == 'T')
        tax = .15;

    final_price = initial_price + (initial_price*tax);

    cout <<"The final price of a vehicle of type "<<code<<" after adding the tax is $"<<final_price;
    
}