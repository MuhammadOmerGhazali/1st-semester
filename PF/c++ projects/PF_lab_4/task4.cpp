#include <iostream>
using namespace std;
void add(float n1,float n2);
void sub(float n1,float n2);
void multiply(float n1,float n2);
void divide(float n1,float n2);
int main()
{
	float n1,n2;
	char op;

	cout <<"Enter 1st number: ";
	cin>>n1;
	cout <<"Enter 2nd number: ";
	cin>>n2;
		
	cout<<"Enter an operator (+, -, *, /): ";
	cin>>op;

	if (op=='+')
	{
		add(n1,n2);
	}	
	if (op=='-')
	{
		sub(n1,n2);
	}	
	if (op=='*')
	{
		multiply(n1,n2);
	}	
	if (op=='/')
	{
		divide(n1,n2);
	}	
} 

void add(float n1,float n2)
{
	float ans;
	ans = n1+n2 ;
	cout<<"Addition: ";
	cout<<ans;
}
void sub(float n1,float n2)
{
	float ans;
	ans = n1-n2 ;
	cout<<"Subtraction: ";
	cout<<ans;
}
void divide(float n1,float n2)
{
	float ans;
	ans = n1/n2 ;
	cout<<"Division: ";
	cout<<ans;
}
void multiply(float n1,float n2)
{
	float ans;
	ans = n1*n2 ;
	cout<<"Multiplication: ";
	cout<<ans;
}