#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std ;

char getCharAtxy(short int x, short int y);
void gotoxy(int x ,int y);
void move_player();
void erase_player();
void print_player();

int pX,pY;

int main()
{
    system (" cls ");
    print_player();
    /*Game loop will replace by void update later*/
    
    while (true)
    {
        Sleep(300)
        move_player();

    }
}

void print_player()
{
    gotoxy(pX,pY);
    cout<<"@";
    
}

void erase_player()
{
    gotoxy(pX,pY);
    cout<<" ";
    

}

void move_player()
{
    erase_player();

    if ((GetAsyncKeyState(VK_LEFT)) && (getCharAtxy(pX-1,pY) == ' '))
    {

            pX = pX-1;
        
    }

if ((GetAsyncKeyState(VK_RIGHT)) && (getCharAtxy(pX+1,pY) == ' '))
    {

            pX=pX+1;
        
    }

if ((GetAsyncKeyState(VK_UP)) && (getCharAtxy(pX,pY-1) == ' '))
    {
            pY=pY-1;
        
    }

if ((GetAsyncKeyState(VK_DOWN)) && (getCharAtxy(pX,pY+1) == ' '))
    {

            pY=pY+1;
        

    }

    print_player();

}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0, 0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}