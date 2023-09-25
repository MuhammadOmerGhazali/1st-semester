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
	cout<<"Fuel needed: ";
	cout<<fuel;
}