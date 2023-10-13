#include<iostream>

using namespace std;

bool truefalse(int n1,int n2);

main()
{

    int n1,n2 ;
    bool result;

    cout<<"Enter the first number: ";
    cin>>n1;

    cout<<"Enter the second number: ";
    cin>>n2;

    result=truefalse(n1,n2);

    if(result==1)
    {
        cout<<"1";
    }
    if(result==0)
    {
        cout<<"0";
    }
}
bool truefalse(int n1,int n2)
{
    if(n1>n2)
    {
    return true;
    }
    else
    {
        return false;
    }
}