#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std ;

// some game functions
void ready();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void test_case();

//level functions
void print_maze();

//player functions

void print_player();
void erase_player();
void move_player();
bool check_player_collisions();
bool player_movement_dictionary(char x);


/*player var*/
int pX,pY;
char player_direction;
bool player_movable = false ;

int maze_l = 0 , maze_h = 0;

int main()
{
    ready();
    print_player();

    while (true)
    {
        move_player();
    }
    


}

void ready()
{
    system("cls");

    cout<< "|                                  |"<<endl;
    cout<< "|                                  |"<<endl;
    cout<< "|                                  |"<<endl;
    cout<< "|                                  |"<<endl;
    cout<< "|            GAME START            |"<<endl;
    cout<< "|                                  |"<<endl;
    cout<< "|                                  |"<<endl;
    cout<< "|                                  |"<<endl;
    cout<< "|    press any key to continue     |"<<endl;
    cout<< "|                                  |"<<endl;
    cout<< "|                                  |"<<endl;

    getch();
    system("cls");

    print_maze();
    pX=maze_l/2;
    pY=maze_h/2;    
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


//player functions
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

    if(GetAsyncKeyState(VK_LEFT))
    {
        player_direction='L';
        if ((check_player_collisions() == true))
            pX = pX-1;
        
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        player_direction='R';
        if ((check_player_collisions() == true))
            pX=pX+1;
        
    }

    if (GetAsyncKeyState(VK_UP))
    {
        player_direction='U';
        if (check_player_collisions() == true)
            pY=pY-1;
        
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        player_direction='D';
        if (check_player_collisions() == true)
            pY=pY+1;
        

    }

    print_player();

}
bool check_player_collisions()
{
    char check_character;
// left input
    if (player_direction == 'L')
        {
            check_character = getCharAtxy(pX-1,pY);
            return player_movement_dictionary(check_character);
        }
// right input
    if(player_direction == 'R')
        {
            check_character = getCharAtxy(pX+1,pY);
            return player_movement_dictionary(check_character);
        }
// up input 

    if(player_direction == 'U')
        {
            check_character = getCharAtxy(pX,pY-1);
            return player_movement_dictionary(check_character);
        }
// down input

    if(player_direction == 'D')
        {
            check_character = getCharAtxy(pX,pY+1);
            return player_movement_dictionary(check_character);
        }

}
bool player_movement_dictionary(char check_character)
{
    if (check_character == ' ')
                return player_movable = true;
            else if (check_character == '.')
                return player_movable = true;
            else 
                return player_movable =false;
}

// maze functions

void print_maze()

{
    cout<< "####################################################"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "#                                                  #"<<endl;
    cout<< "####################################################"<<endl;

    maze_l = 52;
    maze_h = 16;
}

// /*test cases function bodies. dont mind .for debugging*/
// void test_case()
// {
//  gotoxy(55, 4);
//  cout <<" sX= "<<sX<<endl;
//  gotoxy(55, 5);
//  cout <<" sY= "<<sY<<endl;
//  gotoxy(55, 6);
//  cout <<" pX= "<<pX<<endl;
//  gotoxy(55, 7);
//  cout <<" pY= "<<pY<<endl;
//  gotoxy(55, 8);
//  cout <<" sframe= "<<sFrame<<endl;
//  gotoxy(55, 9);
//  cout <<" random= "<<rand_num<<endl;
// }