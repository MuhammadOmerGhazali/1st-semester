#include <iostream>
using namespace std;
int Speed (int x);
int main()
{
	int speed;
	cout<<"Speed: ";
	cin>>speed;
	Speed(speed);

}

int Speed (int speed)
{
	if (speed <= 100)
		cout<<"Perfect! You're going good.";
	if (speed > 100)
		cout<<"Halt... YOU WILL BE CHALLENGED!!!";

}