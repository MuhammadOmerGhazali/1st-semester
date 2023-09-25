#include <iostream>
using namespace std;
void howManyStickers(int side);
int main()
{
	int side;
	cout <<"Enter the side length of the Rubik's Cube: ";
	cin>>side;
	howManyStickers(side);

} 

void howManyStickers(int side)
{
	int sticker;
	sticker = (side*side)*6 ;
	cout<<"Number of stickers needed: ";
	cout<<sticker;
}