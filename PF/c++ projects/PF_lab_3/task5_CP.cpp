#include <iostream>
using namespace std;
int main()
{
	string name;
	float mat_mark;
	float int_mark;
	float ecat_mark;
	float aggregate;
	cout << "Enter the student's name: "; 
	cin >> name ;
	cout << "Enter matriculation marks (out of 1100): ";
	cin >> mat_mark ;
	cout << "Enter intermediate marks (out of 550): ";
	cin >> int_mark ;
	cout << "Enter Ecat marks (out of 400): ";
	cin >> ecat_mark ;
	aggregate = ((mat_mark/1100)*10)+((int_mark/550)*40)+((ecat_mark/400)*50);
	cout <<"Aggregate score for ";
	cout <<name;
	cout <<" in UET is: ";
	cout <<aggregate;
	cout <<"%";
}