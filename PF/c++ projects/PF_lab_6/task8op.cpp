#include <iostream>
#include <windows.h>
using namespace std;
float discount(string day,string month,float amount);
main ()
{
    float amount,get;
    string day,month;
    cout<<"Enter Purchase Day: ";
    cin >> day;
    cout<<"Enter Purchase Month: ";
    cin >> month;
    cout<<"Enter Purchase Amount: ";
    cin >> amount;
    get = discount(day,month,amount);
    cout<<"Payable Amount after discount: "<<get;
}
float discount(string day,string month,float amount)
{
    float payable;
    payable=amount;
    if(day=="Sunday" && (month=="March"|| month=="October" || month=="August"))
    {
        payable=amount-(amount*0.1);
        return payable;
    }
    if (day=="Monday" && (month=="November" || month=="December"))
    {
        payable=amount-(amount * 0.05);
        return payable;
    }
    return payable;
}