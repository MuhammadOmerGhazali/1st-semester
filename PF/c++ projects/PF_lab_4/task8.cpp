#include <iostream>
using namespace std;
void Discount(string day,float price);
int main()
{
	float price;
	string day;
	cout <<"Enter the day of purchase: ";
	cin>>day;
	cout <<"Enter the total purchase amount: $";
	cin>>price;
	Discount(day,price);

} 

void Discount(string day,float price)
{
	float pay;
	if (day =="Sunday")
	{
		pay = price-(price*0.1);
		cout<<"Payable Amount: $"<<pay;
	}	
	if (day !="Sunday")
	{
		pay = price;
		cout<<"Payable Amount: $"<<pay;
	}
}