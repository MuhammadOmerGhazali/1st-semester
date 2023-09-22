#include <iostream>
using namespace std;
int main()
{
	string name;
	cout<< "Enter the movie name: ";
	cin>>name;
	int adult_p;
	cout<< "Enter the adult ticket price: $";
	cin>>adult_p;
	int child_p;
	cout<< "Enter the child ticket price: $";
	cin>>child_p;
	int ticket_a;
	cout<< "Enter the number of adult tickets sold: ";
	cin>>ticket_a;
	int ticket_c;
	cout<< "Enter the number of child tickets sold: ";
	cin>>ticket_c;
	float percen;
	cout<< "Enter the percentage of the amount to be donated to charity: ";
	cin>>percen;
	cout<<endl;
	cout<<"Movie: ";
	cout <<name<<endl;
	int total_g;
	total_g = ticket_a*adult_p+ticket_c*child_p;
	cout<<"Total amount generated from ticket sales: "<<"$"<<total_g<<endl;
	float charity;
	charity = total_g*(percen/100);
	cout <<"Donation to charity "<<"("<<percen<<"%): "<<"$"<<charity<<endl;
	float remainAmount;
	remainAmount = total_g-charity;
	cout<<"Remaining amount after donation: "<<"$"<<remainAmount;



}