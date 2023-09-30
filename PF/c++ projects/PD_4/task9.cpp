#include <iostream>
using namespace std;
float tpChecker(int x,int y);
int main()
{
	float people,tp;

	cout<<"Number of people in the household: ";
	cin>>people;
	cout<<"Number of rolls of TP: ";
	cin>>tp;
	
	tpChecker(people , tp);	
}

float tpChecker( int people, int tp)
{
	float tp_square;
	int tp_use;
	tp_square = (people*57);
	tp_use =(500*tp)/tp_square;
	if (tp_use>=14)
	{
		cout<<"Your TP will last "<<tp_use<<" days, no need to panic!";
		
	}
		if (tp_use<14)
	{
		cout<<"Your TP will only last "<<tp_use<<" days, buy more!";
		
	}
}