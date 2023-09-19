#include <iostream>
using namespace std;
int main()
{
	int mb;
	long kb;
	long b;
	long bit;
	cout<<"Enter the size in megabytes (MB): ";
	cin >>mb;
	kb=mb*1024;
	b=kb*1024;
	bit=b*8;
	cout<<mb;
	cout<<" MB is equivalent to ";
	cout<<bit;
	cout<<" bits.";
}