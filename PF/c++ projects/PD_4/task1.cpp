#include <iostream>
using namespace std;
int IsEqual(int no1,int no2);
int main()
{
int no1 , no2;
cout<<"Enter the first number: ";
cin>>no1;
cout<<"Enter the second number: ";
cin>>no2;
IsEqual(no1,no2);
}

int IsEqual(int no1,int no2)
{
if (no1==no2)
	cout<<"true";
else 
	cout<<"false";
}