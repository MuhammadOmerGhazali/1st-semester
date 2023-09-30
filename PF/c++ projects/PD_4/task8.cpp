#include <iostream>
using namespace std;
int holidays(int holiday);
int main()
{
int holiday;
cout<<"Holidays: ";
cin>>holiday;
holidays(holiday);
}
int holidays(int holiday)
{
int working_day;
working_day=365-holiday;
int games;
games =((working_day*63)+(holiday*127));

int hour,minute,norm;
norm=30000-games;
if (games>30000)
{
			
	hour=(norm/60)*-1;
	minute=(norm%60)*-1;
	cout<<"Tom will run away"<<endl<<hour<<" hours and "<<minute<<" minutes for play";


}
if (games<30000)
{	
		
	hour=norm/60;
	minute=(norm%60);
	cout<<"Tom sleeps well"<<endl<<hour<<" hours and "<<minute<<" minutes less for play";

}
}