#include <iostream>
using namespace std;
int main()
{
	float Vi;
	cout<< "Enter Initial Velocity (m/s): ";
	cin>>Vi;
	float accel;
	cout<< "Enter Acceleration (m/s^2): ";
	cin>>accel;
	float time;
	cout<< "Enter Time (s): ";
	cin>>time;
	float Vf;
	Vf = accel*time +Vi;
	cout<<"Final Velocity (m/s): ";
	cout<<Vf;
}