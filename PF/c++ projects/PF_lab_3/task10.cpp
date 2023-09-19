#include <iostream>
using namespace std;
int main()
{
	float wins;
	float draw;
	float loss;
	float point;
	string name;
	cout<<"Enter the name of the cricket team: ";
	cin >>name;
	cout<<"Enter the number of wins: ";
	cin >>wins;
	cout<<"Enter the number of draws: ";
	cin >>draw;
	cout<<"Enter the number of losses: ";
	cin >>loss;
	point = wins*3 +loss*0 +draw*1;
	cout<<name;
	cout<<" has obtained ";
	cout<<point;
	cout<<" points in the Asia Cup tournament.";
}