#include <iostream>
using namespace std;
void EvenOrOdd(int n);
int main()
{
	int n;
	cout <<"Enter a number: ";
	cin>>n;
	EvenOrOdd(n);

} 

void EvenOrOdd(int n)
{
	int m;
	m =n%2;
	if (m==1)
	{
		cout<<"Number "<<n<<" is odd";
	}	
	if (m==0)
	{
		cout<<"Number "<<n<<" is even";
	}
	
}