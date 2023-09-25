#include <iostream>
using namespace std;
void inchesToFeet(float inch);
int main()
{
	float inch;
	cout <<"Enter the measurement in inches: ";
	cin>>inch;
	inchesToFeet(inch);

} 

void inchesToFeet(float inch)
{
	float feet;
	feet = inch / 12 ;
	cout<<"Equivalent in feet: ";
	cout<<feet;
}