#include<iostream>

using namespace std;

bool chkpar(int n);

main()
{
    int n;
    bool result;

    cout<<"Enter a 3-digit number: ";
    cin>>n;

    result=chkpar(n);

    if(result==1)
    {
        cout<<"1";
    }

    if(result==0)
    {
        cout<<"0";
    }
}

bool chkpar(int n)
{
    int num,sum;

    num=n%10;
    sum=num+(n/10)%10;
    sum=sum+(n/100)%10;

    if(n%2==0 && sum%2==0)
    {
        return true;
    }
    else
    {
        return false;
    }
   
}