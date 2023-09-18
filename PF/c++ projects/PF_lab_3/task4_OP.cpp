#include <iostream>
using namespace std;
int main()
{
	float charge;
	float current;
	float time ;
	cout << "enter charge : ..";
	cin >> charge;
	cout << "enter time : ..";
	cin >> time;
	current = charge / time ;
	cout << "_________________________________"<<endl;
	cout << "=> current is:";
	cout << current <<endl;
	cout << "_________________________________"<<endl;
}