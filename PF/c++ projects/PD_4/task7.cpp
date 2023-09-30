#include <iostream>
using namespace std;
float flowerShop(float x,float y ,float z);
int main()
{
	float redRose,whiteRose,Tulips;

	cout<<"Red Rose: ";
	cin>>redRose;
	cout<<"White Rose: ";
	cin>>whiteRose;
	cout<<"Tulips: ";
	cin>>Tulips;
	
	flowerShop(redRose,whiteRose,Tulips);	
}

float flowerShop(float redRose,float whiteRose ,float Tulips)
{
	float price,discount;
	
	price = (redRose*2)+(whiteRose*4.1)+(Tulips*2.5);
	cout<<"Original Price: $"<<price<<endl;
	discount = price-(price*0.2);
	if (price>=200)
	{
		cout<<"Price after Discount: $"<<discount;
	}
	else
		cout<<"No discount applied.";
}