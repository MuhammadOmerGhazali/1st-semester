#include <iostream>
using namespace std;
int LongestTime(int x,int y);
int main()
{
	int hour,minute;
	cout<<"Enter the number of hours: ";
	cin>>hour;
	cout<<"Enter the number of minutes: ";
	cin>>minute;
	LongestTime(hour,minute);

}
int LongestTime(int hour,int minute)
{
	int conv_hour;
	conv_hour = hour*60;
	if (conv_hour<minute)
	{
		cout<<minute;
	}
	if (conv_hour>=minute)
	{
		cout<<hour;
	}
}