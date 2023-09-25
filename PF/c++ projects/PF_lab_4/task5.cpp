#include <iostream>
using namespace std;
void Age(int age);
int main()
{
	int age;
	cout <<"Enter your age: ";
	cin>>age;
	Age(age);

} 

void Age(int age)
{

	if (age==18)
	{
		cout<<"You are eligible to vote.";
	}	
	if (age>18)
	{
		cout<<"You are eligible to vote.";
	}
	if (age<18)
	{
		cout<<"You are not eligible to vote.";
	}
}