#include <iostream>
using namespace std;
int main()
{
	float age;
	float days;
	cout<<"Enter your age in years: ";
	cin >>age;
	days=age * 365;
	cout<<"Your age in days is approximately ";
	cout<<days;
	cout<<" days.";
}