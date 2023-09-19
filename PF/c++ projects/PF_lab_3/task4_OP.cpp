#include <iostream>
using namespace std;
int main()
{
	float charge;
	float current;
	float time ;
	cout << "Enter the charge (Q) in Coulombs: ";
	cin >>charge;
	cout << "Enter the time (t) in seconds: ";
	cin >>time;
	current = charge / time ;
	cout << "The current (I) is: ";
	cout <<current;
	cout << " Amperes.";
}