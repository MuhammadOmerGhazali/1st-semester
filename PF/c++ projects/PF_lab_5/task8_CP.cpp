#include <iostream>
using namespace std ;

int main()
{
	int num,dig1,dig2,dig3,dig4,dig5,sum;

	cout<<"Enter a five-digit number: ";

	cin>>num;
	
	dig1 = num/10000;
	dig2 = (num/1000)%10;
	dig3 = (num/100)%10;
	dig4 = (num/10)%10;
	dig5 = num%10;
	
	sum = dig1+dig2+dig3+dig4+dig5;
	
	if (sum%2==0)

		cout<<"Evenish";
	else 
		cout<<"Oddish";

}