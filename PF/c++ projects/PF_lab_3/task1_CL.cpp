#include <iostream>
using namespace std;
int main()
{
	string name;
	int roll_num;
	float aggregate;
	string section;
	cout << "Enter your name: "; 
	cin >> name ;
	cout << "Enter your roll number: ";
	cin >> roll_num ;
	cout << "Enter your aggregate: ";
	cin >> aggregate ;
	cout << "Enter your section: ";
	cin >> section ;
	cout << "Student Information:"<<endl;
	cout <<"Name: "<< name<<endl;
	cout <<"Roll number: "<<roll_num << endl;
	cout <<"Aggregate: "<<aggregate <<endl; 
	cout <<"Section: "<<section <<endl;

}