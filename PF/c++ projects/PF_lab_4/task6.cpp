#include <iostream>
using namespace std;
void Marks(int marks);
int main()
{
	int marks;
	cout <<"Enter your score: ";
	cin>>marks;
	Marks(marks);

} 

void Marks(int marks)
{

	if (marks==50)
	{
		cout<<"Fail";
	}	
	if (marks>50)
	{
		cout<<"Pass";
	}
	if (marks<50)
	{
		cout<<"Fail";
	}
}