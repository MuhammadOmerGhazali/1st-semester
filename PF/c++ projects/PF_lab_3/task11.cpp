#include <iostream>
using namespace std;
int main()
{
	float world_population;
	float birth_rate;
	float end_popu;
	cout<<"Enter the current world population: ";
	cin >>world_population;
	cout<<"Enter the monthly birth rate (number of births per month): ";
	cin >>birth_rate;
	end_popu = world_population + (12*30)*birth_rate;
	cout<<"The population in three decades will be: ";
	cout<<end_popu;
}