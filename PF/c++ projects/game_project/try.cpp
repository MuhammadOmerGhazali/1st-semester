#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int screen_l = 51;
const int screen_h = 37;

void print_Array(char screen[screen_h][screen_l]);
void print_border();
void moveDown(char screen[screen_h][screen_l], char buffer[screen_h][screen_l], char randArrays[3][screen_h][screen_l], int &playerPosition, bool &gameOver);
void movePlayer(char screen[screen_h][screen_l], int &playerPosition);
bool checkCollision(char screen[screen_h][screen_l], int playerPosition);
int random_function(int x);
void cursor_hide();
void clearConsole();

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    char screen[screen_h][screen_l] = {/* your initial background array here */};
    char buffer[screen_h][screen_l] = {/* your initial buffer array here */};
    char randArrays[3][screen_h][screen_l] = {/* your initial random arrays here */};
    cursor_hide();

    int playerPosition = screen_l / 2; // Initial position of the player
    bool gameOver = false;

    while (!gameOver)
    {
        clearConsole();
        moveDown(screen, buffer, randArrays, playerPosition, gameOver); // Pass player position and gameOver flag
        movePlayer(screen, playerPosition);                            // Move the player
        print_Array(screen);
        Sleep(150);
    }

    cout << "Game Over!" << endl;

    return 0;
}

void print_Array(char screen[screen_h][screen_l])
{
    string temp = "";
    print_border();
    SetConsoleTextAttribute(color, 8);
    for (int i = 0; i < screen_h; ++i)
    {
        for (int j = 0; j < screen_l; ++j)
        {
            temp += screen[i][j];
        }
        temp += "\n";
    }
    cout << temp;
    print_border();
}

void print_border()
{
    cout << "##################################################" << endl;
}

void moveDown(char screen[screen_h][screen_l], char buffer[screen_h][screen_l], char randArrays[3][screen_h][screen_l], int &playerPosition, bool &gameOver)
{
    // Move each column one step down
    for (int j = 0; j < screen_l; ++j)
    {
        // Shift elements down in the buffer
        for (int i = screen_h - 1; i > 0; --i)
        {
            buffer[i][j] = buffer[i - 1][j];
        }

        // Shift elements down in the screen
        for (int i = screen_h - 1; i > 0; --i)
        {
            screen[i][j] = screen[i - 1][j];
        }

        // Check for collision with player ship
        if (checkCollision(screen, playerPosition))
        {
            gameOver = true;
            return;
        }

        // Move the last row to the top
        screen[0][j] = buffer[screen_h - 1][j];
    }

    // Check if all elements in the buffer have moved down
    int count = 0; // Counter to track the number of times moveDown is called
    if (++count % screen_h == 0)
    {
        // Reset the counter
        count = 0;

        // Randomly select an array from randArrays and move it to the buffer
        int randIndex = random_function(3);
        for (int i = 0; i < screen_h; ++i)
        {
            for (int j = 0; j < screen_l; ++j)
            {
                buffer[i][j] = randArrays[randIndex][i][j];
            }
        }
    }
}

void movePlayer(char screen[screen_h][screen_l], int &playerPosition)
{
    // Check for keyboard input to move the player
    if (_kbhit())
    {
        char key = _getch();
        if (key == 'a' && playerPosition > 1)
        {
            // Move player left
            screen[screen_h - 1][playerPosition] = ' ';     // Clear current position
            screen[screen_h - 1][playerPosition - 1] = ' '; // Clear left of the player
            playerPosition--;
        }
        else if (key == 'd' && playerPosition < screen_l - 3)
        {
            // Move player right
            screen[screen_h - 1][playerPosition] = ' ';     // Clear current position
            screen[screen_h - 1][playerPosition + 1] = ' '; // Clear right of the player
            playerPosition++;
        }
    }

    // Place the player ship on the screen
    screen[screen_h - 1][playerPosition] = 'P';                 // Replace 'P' with your player ship character
    screen[screen_h - 1][playerPosition + 1] = 'P';             // Extend the player ship horizontally
}

bool checkCollision(char screen[screen_h][screen_l], int playerPosition)
{
    // Check for collision with player ship
    int i = screen_h - 1;
    if ((screen[i][playerPosition] != ' ' && screen[i][playerPosition] != 'P') ||
        (screen[i][playerPosition + 1] != ' ' && screen[i][playerPosition + 1] != 'P'))
    {
        return true;
    }
    return false;
}
