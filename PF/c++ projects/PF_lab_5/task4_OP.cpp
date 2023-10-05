#include <iostream>
#include <cmath>
using namespace std ;

int main()
{
	float height,distance,angle;

	cout<<"Enter the distance from the base of the tree (in feet): ";
	cin>>distance;
	cout<<"Enter the angle of elevation (in degrees): ";
	cin>>angle;
	
	angle = angle/57.2958;
	height = tan(angle) * distance;  

	cout<<"The height of the tree is: "<<height<<" feet";
}