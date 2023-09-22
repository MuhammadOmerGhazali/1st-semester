#include <iostream>
using namespace std;
int main()
{
	float i;
	cout<< "Enter Imposter Count: ";
	cin>>i;
	float p;
	cout<< "Enter Player Count: ";
	cin>>p;
	float chance;
	chance = 100 * (i/p);
	int round;
	round=chance;
	cout<<"Chance of being an imposter: ";
	cout<<round;
	cout<<"%";
}