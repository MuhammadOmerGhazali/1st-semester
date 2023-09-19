#include <iostream>
using namespace std;
int main()
{
	float length;
	float width;
	float area ;
	cout << "Enter the length of the rectangle: ";
	cin >> length;
	cout << "Enter the width of the rectangle: ";
	cin >> width;
	area = width * length ;
	cout << "The area of the rectangle is: ";
	cout << area <<endl;
}