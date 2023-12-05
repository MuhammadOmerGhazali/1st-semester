#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

//constants
const int screen_length = 70;
const int screen_height = 25;

//functions
void ready(char screen[screen_height][screen_length]);                     // initializes the game state
void resizeConsole();
void cursor_hide();
void cursor_show();
void initialize_maze(char screen[screen_height][screen_length]);           // initializes the maze 
void printBoard(char screen[screen_height][screen_length]);

void detect_player_input();                                                // detects player input
void move_player();                                                        // moves player


//player variables
int player_x , player_y;
char player_dir;


int main()
{
    resizeConsole();                                                        // risize console
    cursor_hide();                                                          // hide cursor
    char screen[screen_height][screen_length];                              // array used to print screen
    ready(screen);                                                          // initialize and the start screen
    bool game_over = false ;                                                // used to terminate game loop
    
    while(!game_over)                                                       // game loop
    {
        detect_player_input();                                              // detects player input and redirects to the required function

        printBoard(screen);                                                 // print the screen
    }
    

    cursor_show();                                                          // show the cursor again
}

void ready(char screen[screen_height][screen_length])
{
    system("cls");
    cout <<"Press any key to continue...................................";
    getch();
    system("cls");
    initialize_maze(screen);
}

void resizeConsole()
{
    COORD coord;
    SMALL_RECT rect;
    HWND console = GetConsoleWindow();

    coord.X = 100;  
    coord.Y = 30;   

    rect.Left = 0;
    rect.Top = 0;
    rect.Right = coord.X - 1;   
    rect.Bottom = coord.Y - 1;  

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);

    ShowWindow(console, SW_SHOWNORMAL);
}
void cursor_hide()
{
    /*
        For Removing Blinking Cursor on Screen
    */
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}
void cursor_show()
{
    /*
        For Removing Blinking Cursor on Screen
    */
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

void detect_player_input()
{
    if(GetAsyncKeyState(VK_LEFT))
    {
        player_dir='L';
        move_player();
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        player_dir='R';
        move_player();
    }

    if (GetAsyncKeyState(VK_UP))
    {
        player_dir='U';
        move_player();
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        player_dir='D';
        move_player();
    }

}
void move_player()
{

}

void initialize_maze(char screen[screen_height][screen_length])
{
    for (int y = 0;y <= screen_height;y++)
    {
        for(int x = 0;x <= screen_length;x++)
        {
            screen[y][x] = ' ';
        }
    }

    // Draw borders
    for (int x = 0; x < screen_length; x++)
    {
        screen[0][x] = '#';                                     // top row
        screen[screen_height][x] = '#';                         // bottom row
    }

    for (int y = 0; y < screen_height; y++)
    {
        screen[y][0] = '#';                                     // leftmost column
        screen[y][screen_length - 1] = '#';                     // rightmost column
    }
    screen[screen_height][screen_length] = '#';
}

void printBoard(char screen[screen_height][screen_length])
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

