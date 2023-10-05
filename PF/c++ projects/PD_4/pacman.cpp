//Program to partrol a player inside the maze

#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y);
void printMaze();
void playerMove(int height, int player);


int main() {
	system("cls");
	printMaze();

	int height = 9; 	// Set the height of your maze

	int player = 1; 	// Initial position of the player
	int direction = 1; 	// 1 for moving down, -1 for moving up

	while (true) 
	{
		playerMove(height, player);

	        player += direction; 		//Move the player up or down

        	if (player <= 1) 
			{         
            		direction *= -1;	 //Reverse the direction when reaching the top
		        }

		if (player >= height - 1) 
			{         
            		direction *= -1;	//Reverse the direction when reaching the bottom
		        }
       }
}

void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMaze()
{
	cout << "##########################" << endl;
	cout << "#                        #" << endl;
	cout << "#                        #" << endl;
	cout << "#                        #" << endl;
	cout << "#                        #" << endl;
	cout << "#                        #" << endl;
	cout << "#                        #" << endl;
	cout << "#                        #" << endl;
	cout << "#                        #" << endl;
	cout << "##########################" << endl;
}

void playerMove(int height, int player)
{
        	gotoxy(10, player);
        	cout << "P"; 		// Display the player at the current position

        	Sleep(200); 		// Sleep to control the speed

	        gotoxy(10, player);
        	cout << " "; 		// Clear the player at the current position
}
