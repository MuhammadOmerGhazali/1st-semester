#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void ready();
void printmaze();
void eraseplayer();
void movePlayerLeft();
void movePlayerRight();
void fire();
void moveEnemy(char object, string direction);
void moveFire(int timeStep);
void printBoard();

//global variables
int player_x,player_y;
char player_dir;

const int screen_height = 15;
const int screen_length = 35;

string screen[screen_height];

int main()
{
    //initialize game state
    ready();

    //gameloop start
    while(true)
    {
    if(GetAsyncKeyState(VK_LEFT))
    {
        movePlayerLeft();
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        movePlayerRight();
    }
    
    printBoard();
    Sleep(200);
    }
    
}

void ready()
{
    system("cls");
    cout <<"Press any key to continue...................................";
    getch();
    system("cls");
    printmaze();

}
void printmaze()
{

    screen[0]  = "###################################";
    screen[1]  = "#                                 #";
    screen[2]  = "#                                 #";
    screen[3]  = "#               e                 #";
    screen[4]  = "#                                 #";
    screen[5]  = "#                                 #";
    screen[6]  = "#                    x            #";
    screen[7]  = "#                                 #";
    screen[8]  = "#                                 #";
    screen[9]  = "#                                 #";
    screen[10] = "#                                 #";
    screen[11] = "#                                 #";
    screen[12] = "#                p                #";
    screen[13] = "#                                 #";
    screen[14] = "###################################";

}

void print_player()
{
    cout<<"@";
}
void erase_player()
{
    cout<<" ";
}
void movePlayerLeft()
{
    for (int y = 0;y <= screen_height;y++)
    {
        for(int x = 0;x <= screen_length;x++)
        {
            if (screen[y][x] == 'p' && screen[y][x+1] !='#')
            {
                screen[y][x] == ' ';
                screen[y][x-1] == 'p';
            }
        }
    }
}
void movePlayerRight()
{
    for (int y = 0;y <= screen_height;y++)
    {
        for(int x = 0;x <= screen_length;x++)
        {
            if (screen[y][x] == 'p' && screen[y][x+1] !='#')
            {
                screen[y][x] == ' ';
                screen[y][x+1] == 'p';
            }
        }
    }
}

void printBoard()
{
    for (int y = 0;y <= screen_height;y++)
    {
        for(int x = 0;x <= screen_length;x++)
        {
            cout << screen[y][x];
        }
        cout << endl;
    }
}

