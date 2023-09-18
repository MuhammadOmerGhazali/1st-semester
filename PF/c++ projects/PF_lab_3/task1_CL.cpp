#include <iostream>
using namespace std;
int main()
{
	string name;
	int roll_num;
	float aggregate;
	string section;
	cout << "enter name : "; 
	cin >> name ;
	cout << "enter your aggragate : ";
	cin >> aggregate ;
	cout << "enter section : ";
	cin >> section ;
	cout << "Student Information "<<endl;
	cout << "_________________________________"<<endl;
	cout <<"=> Name : "<< name<<endl;
	cout <<"=> Roll number"<<roll_num << endl;
	cout <<"=> Aggregate : "<<aggregate <<endl; 
	cout <<"=> Section : "<<section <<endl;
	cout << "_________________________________"<<endl;
}