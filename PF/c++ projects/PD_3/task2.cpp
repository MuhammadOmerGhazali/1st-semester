#include <iostream>
using namespace std;
int main()
{
	int min;
	cout<< "Number of Minutes: ";
	cin>>min;
	int fps;
	cout<< "Frames per Second: ";
	cin>>fps;
	int total;
	total = (min*60)*fps;
	cout<<"Total Number of Frames: ";
	cout<<total;
}