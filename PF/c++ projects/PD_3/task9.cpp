#include <iostream>
using namespace std;
int main()
{
	int num;
	cout<<"Enter a 4-digit number: ";
	cin>>num;
	int first;
	first=num/1000;
	int second;
	second=num/100;
	second=second%10;
	int third;
	third=num/10;
	third=third%10;
	int fourth;
	fourth=num%10;
	int sum;
	sum=first+second+third+fourth;
	cout<<"Sum of the individual digits: "<<sum;


}