#include <iostream>
using namespace std;

string projectTimeCalculation (int x,int y,int z);

int main()
{
    int required_hours,days,workers;

    cout<<"Enter the needed hours: ";
    cin>>required_hours;
    cout<<"Enter the days that the firm has: ";
    cin>>days;
    cout <<"Enter the number of all workers: ";
    cin>>workers;

    projectTimeCalculation (required_hours,days,workers);

}

string projectTimeCalculation (int required_hours,int days,int workers)
{
    int hours,training_hours,overtime_hours,total_hours;

    training_hours = (days*8) * 0.1;
    overtime_hours = days*2;
    total_hours = ((days*8)-training_hours)+overtime_hours;

    if (total_hours>required_hours)
       { 
            hours = total_hours-required_hours;
            cout<<"Yes!"<<hours<<" hours left.";
       }
    if (total_hours<required_hours)
        {
            hours = required_hours-total_hours+1;
            cout<<"Not enough time! "<<hours<<" hours needed.";
        }

}