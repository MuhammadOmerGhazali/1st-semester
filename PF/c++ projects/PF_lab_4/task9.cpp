#include <iostream>
using namespace std;
void Fuel(float distance);
int main()
{
	float distance;
	cout <<"Enter the distance: ";
	cin>>distance;
	Fuel(distance);
	
} 

void Fuel(float distance)
{
	
	float fuel;
	fuel = distance * 10 ;
	if (fuel<100)
	{
		fuel=100;
		cout<<"Fuel needed: "<<fuel;
	}
	if (fuel>100)
	{

		cout<<"Fuel needed: "<<fuel;
	}

}