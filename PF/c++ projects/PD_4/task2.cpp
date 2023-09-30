#include <iostream>
using namespace std;
string reverse(string input);
int main()
{
string input;
cout<<"Enter 'true' or 'false': ";
cin>>input;
reverse(input);
}
string reverse(string input)
{
if (input=="true")
	cout<<"false";
if (input=="false")
	cout<<"true";
}