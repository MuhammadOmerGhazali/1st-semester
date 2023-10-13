#include <iostream>
#include <windows.h>
using namespace std;
float totalIncome (string n,int n1, int n2);
main ()
{
    int n1,n2;
    float get;
    string n;
    cout<<"Enter the screening type (Premiere/Normal/Discount): ";
    cin>> n;
    cout<<"Enter the number of rows: ";
    cin>> n1;
    cout<<"Enter the number of columns: ";
    cin>> n2;
    get=totalIncome (n, n1, n2);
    cout<<get;

}
float totalIncome (string n,int n1, int n2)
{
    float out;
    if (n=="Premiere")
    {
        out=n1*n2*12.00;
    }
    if (n=="Normal")
    {
        out=n1*n2*7.50;
    }
    if (n=="Discount")
    {
        out=n1*n2*5.00;
    }
    return out;
}
    
