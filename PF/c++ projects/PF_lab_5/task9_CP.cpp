#include <iostream>
using namespace std;
string timeTravel(int hours,int minutes);
main()
{	int hours,minutes;
	cout << "Enter Hours: ";
	cin >> hours;
	cout << "Enter Minutes: ";
	cin >> minutes;
	timeTravel(hours,minutes);
}
string timeTravel(int hours,int minutes)
{	
	hours=hours%24;
	minutes=minutes%60;
	int totaltime=hours*60+minutes+15;
	int h=totaltime/60;
	int m=totaltime%60;
	cout << h << ":" << m;	
}	