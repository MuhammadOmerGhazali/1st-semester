#include <iostream>
using namespace std;
int main()
{
	string name;
	int mat_mark;
	int int_mark;
	int ecat_mark;
	float aggregate;
	cout << "enter students name : "; 
	cin >> name ;
	cout << "enter your matriculation marks(out of 1100) : ";
	cin >> mat_mark ;
	cout << "enter intermidiate marks(out of 550) : ";
	cin >> int_mark ;
	cout << "enter ecat marks(out of 400) : ";
	cin >> ecat_mark ;
	aggregate = ((mat_mark/1100)*50)+((int_mark/550)*40)+((ecat_mark/400)*10);
	cout << "Student Information "<<endl;
	cout << "_________________________________"<<endl;
	cout <<"=> Name : "<< name<<endl;
	cout <<"=> matriculation marks : "<<mat_mark << endl;
	cout <<"=> intermidiate marks : "<<int_mark <<endl; 
	cout <<"=> ecat marks : "<<ecat_mark <<endl;
	cout << "_________________________________"<<endl;
	cout <<"=> aggregate is  : "<<aggregate <<endl;
	cout << "_________________________________"<<endl;
}