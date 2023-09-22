#include <iostream>
using namespace std;
int main()
{
	int num_sqr;
	cout<<"Number of square meters you can paint: ";
	cin>>num_sqr;
	int width;
	cout<<"Width of the single wall (in meters): ";
	cin>>width;
	int height;
	cout<<"Height of the single wall (in meters): ";
	cin>>height;
	int num_wall;
	int wall_sqr;
	wall_sqr=width*height;
	num_wall=num_sqr/wall_sqr;
	cout<<"Number of walls you can paint: "<<num_wall;	


}