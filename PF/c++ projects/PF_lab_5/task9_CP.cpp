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

	int totaltime;
	int h,m;

	hours=hours % 24;

	minutes=minutes % 60;

	totaltime=hours * 60 + minutes + 15;

	h=totaltime/60;

	m=totaltime%60;

	cout << h << ":" << m;	
}	