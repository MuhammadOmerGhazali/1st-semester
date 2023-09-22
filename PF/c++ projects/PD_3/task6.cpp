#include <iostream>
using namespace std;
int main()
{
	int size;
	cout<< "Enter the size of the fertilizer bag in pounds: ";
	cin>>size;
	int cost;
	cout<< "Enter the cost of the bag: $";
	cin>>cost;
	int area;
	cout<< "Enter the area in square feet that can be covered by the bag: ";
	cin>>area;
	float cost_p;
	cost_p = cost/size;
	cout<<"Cost of fertilizer per pound: ";
	cout<<"$"<<cost_p<<endl;
	float cost_a;
	cost_a = cost/area;
	cout<<"Cost of fertilizing per square foot: ";
	cout<<"$"<<cost_a;
}