#include <iostream>
using namespace std;
string calculatePoolState(int volume,int pipe1,int pipe2,float hours);
main()
{	int volume,pipe1,pipe2;
	float hours;
	cout << "Enter volume of the pool in liters: ";
	cin >> volume;
	cout << "Enter flow rate of the first pipe per hour: ";
	cin >> pipe1;
	cout << "Enter flow rate of the second pipe per hour: ";
	cin >> pipe2;
	cout << "Enter hours that the worker is absent: ";
	cin >> hours;
	calculatePoolState(volume,pipe1,pipe2,hours);
}
string calculatePoolState(int volume,int pipe1,int pipe2,float hours)
{	
	int volumefilledbypipe1=pipe1*hours;
	int volumefilledbypipe2=pipe2*hours;
	int totalvolumefilled=volumefilledbypipe1+volumefilledbypipe2;
	if(volume>=totalvolumefilled)
	{
	int percentpipe1=volumefilledbypipe1*100/(totalvolumefilled);
	int percentpipe2=volumefilledbypipe2*100/(totalvolumefilled);
	int totalpercent=totalvolumefilled*100/(volume);
	cout << "The pool is " << totalpercent << "% full. Pipe 1: " << percentpipe1 << "%. Pipe 2: "<< percentpipe2 <<"%." ;
	}
	if(volume<totalvolumefilled)
	{
	float overflow=totalvolumefilled-volume;
	cout << "For " << hours << " hours, the pool overflows with " << overflow << " liters.";
	}
}