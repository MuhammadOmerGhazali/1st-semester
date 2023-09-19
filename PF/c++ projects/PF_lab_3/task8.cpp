#include <iostream>
using namespace std;
int main()
{
	float volt;
	float amp;
	float power;
	cout<<"Enter voltage (in volts): ";
	cin >>volt;
	cout<<"Enter current (in amperes): ";
	cin >>amp;
	power=volt * amp;
	cout<<"The power is ";
	cout<<power;
	cout<<" watts.";
}