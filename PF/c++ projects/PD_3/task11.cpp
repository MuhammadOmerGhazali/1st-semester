#include <iostream>
using namespace std;
int main()
{
	int age;
	cout<<"Enter the person's age: ";
	cin>>age;
	int move;
	cout<<"Enter the number of times they've moved: ";
	cin>>move;
	int avg;
	avg=age/(move+1);
	cout<<"Average number of years lived in the same house: "<<avg;
	 	


}