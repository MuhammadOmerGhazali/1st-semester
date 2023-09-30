#include <iostream>
using namespace std;
int Bonus (int x,int y);
int main()
{
	int position,friend_pos;
	cout<<"Enter your position: ";
	cin>>position;
	cout<<"Enter your friend's position: ";
	cin>>friend_pos;
	Bonus(position,friend_pos);

}

int Bonus (int position ,int friend_pos)
{
	int temp;
	temp = friend_pos-position;
	if (temp <= 6)
		cout<<"true";
	if (temp > 6)
		cout<<"false";

}