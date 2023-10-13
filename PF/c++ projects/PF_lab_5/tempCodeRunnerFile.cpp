#include <iostream>
#include <cmath>
using namespace std ;



int main()
{
	float base , expo;

	cout<<"Enter the base number: ";
	cin>>base;
	cout<<"Enter the exponent: ";
	cin>>expo;
	cout<<base<<" raised to the power "<<expo<<" is: "<<pow(base,expo);
	
}
