#include <iostream>
using namespace std;
int main()
{
	string name;
	cout<< "Enter the Name of the Person: ";
	cin>>name;
	float target;
	cout<< "Enter the target weight loss in kilograms: ";
	cin>>target;
	float day;
	day = target*15;
	cout<<name;
	cout<<" will need ";
	cout<<day;
	cout<<" days to lose ";
	cout<<target;
	cout<<" kg of weight by following the doctor's suggestions";
}