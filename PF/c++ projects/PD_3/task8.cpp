#include <iostream>
using namespace std;
int main()
{
	float veg_kilo;
	cout<<"Enter vegetable price per kilogram (in coins): ";
	cin>>veg_kilo;
	float fruit_kilo;
	cout<<"Enter fruit price per kilogram (in coins): ";
	cin>>fruit_kilo;
	int total_veg;
	cout<<"Enter total kilograms of vegetables: ";
	cin>>total_veg;
	int total_fruit;
	cout<<"Enter total kilograms of fruits: ";	
	cin>>total_fruit;
	float total_earn;
	total_earn = (veg_kilo*total_veg+fruit_kilo*total_fruit)/1.94;
	cout<<"Total earnings in Rupees (Rps): "<<total_earn;
	
}