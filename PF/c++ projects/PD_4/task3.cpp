#include <iostream>
using namespace std;
float Discount(string x , float y);
int main()
{
string country_name;
float price;
cout<<"Enter the country's name: ";
cin>>country_name;
cout<<"Enter the ticket price in dollars: $";
cin>>price;
Discount(country_name,price);
}

float Discount(string country_name , float price)
{
	float discount;
	if (country_name == "Pakistan")
	{
		discount = price - (price * 0.05) ;
	}
	if (country_name == "Ireland")
	{
		discount = price - (price * 0.1) ;
	}
	if (country_name == "India")
	{
		discount = price - (price * 0.2);
	}
	if (country_name == "England")
	{
		discount = price - (price * 0.3) ;
	}
	if (country_name == "Canada")
	{
		discount = price - (price * 0.45) ;
	}
	cout<<"Final ticket price after discount: $"<<discount;
}