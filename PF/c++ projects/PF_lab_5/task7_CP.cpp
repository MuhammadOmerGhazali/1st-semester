#include <iostream>
using namespace std ;

int main()
{
	int num,dig1,dig2,dig3;
	cout<<"Enter a three-digit number: ";
	cin>>num;
	
	dig1 = num/100;
	dig3 = num%10;
	
	if (dig1==dig3)
		cout<<"The number is symmetrical.";
	else 
		cout<<"The number is not symmetrical.";

}