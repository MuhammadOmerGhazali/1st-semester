#include <iostream>
#include <windows.h>
using namespace std;
string checkSpeed (float n1);
main ()
{
    int n1;
    string get;
    cout<<"Enter the speed: ";
    cin >> n1;
    get=checkSpeed (n1);
    cout<<get;
}
string checkSpeed (float n1)
{
    if(n1>=0 && n1<=10)
    {
        return "slow";
    }
    if(n1>10 && n1<=50)
    {
        return "average";
    }
    if (n1>51 && n1<=150)
    {
        return "fast";
    }
    if (n1>151 && n1<=1000)
    {
        return "ultra-fast";
    }
    if (n1>1000)
    {
        return "extremely fast";
    }
}
