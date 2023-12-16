#include <iostream>
#include <windows.h>

using namespace std;

void drawGameWorld(char[][36]);
void drawGameBounds(char[][36]);
void shootProjectile(char[][36]);
void moveProjectile(char[][36], int step);
void clearProjectile(char[][36]);
void movePlayer(char[][36], char, char);
void moveOpponent(char [][36], char, char);
bool checkCollision(char[][36]); // for projectile
void moveProjectile(char [][36]);
int getRandomDirection();      /// for random opponent movement

int main()
{
    char gameArea[16][36] = {"###################################",
                             "#                                 #", 
                             "#                                 #", 
                             "#               e                 #", 
                             "#           e      x              #", 
                             "#         e         x             #", 
                             "#       e            x            #", 
                             "#                                 #",  
                             "#                                 #",  
                             "#                                 #",  
                             "#                                 #",  
                             "#                                 #",  
                             "#                p                #",  
                             "#                                 #",  
                             "###################################"};
    bool projectileActive = false;

    drawGameWorld(gameArea);

    while(true)
    {
        if(GetAsyncKeyState(VK_LEFT))
        {
            movePlayer(gameArea, 'l', ' ');
            drawGameWorld(gameArea);
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            movePlayer(gameArea, 'r', ' ');
            drawGameWorld(gameArea);
        }
        if(GetAsyncKeyState(VK_UP))
        {
            movePlayer(gameArea, 'u', ' ');
            drawGameWorld(gameArea);
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            movePlayer(gameArea, 'd', ' ');
            drawGameWorld(gameArea);
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            if(!projectileActive)
            {
                shootProjectile(gameArea);    
                drawGameWorld(gameArea);       
                projectileActive = true;
            }
        }
        if (projectileActive)  /// if true then move projectile
        {
            if (checkCollision(gameArea))
            {
                moveProjectile(gameArea);
                drawGameWorld(gameArea);
            }
            else
            {
                projectileActive = false;
                drawGameWorld(gameArea);
            }
        }
        int randomDirection = getRandomDirection();
        if (randomDirection == 0)
        {
            moveOpponent(gameArea, 'e', 'r');
            moveOpponent(gameArea, 'x', 'l');
            drawGameWorld(gameArea);
        }
        else
        {
            moveOpponent(gameArea, 'e', 'l');
            moveOpponent(gameArea, 'x', 'r');
            drawGameWorld(gameArea);
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
    }
    return 0;
}

int getRandomDirection()
{
    return rand() % 2; // 0 or 1
}

void clearProjectile(char gameArea[][36])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if (gameArea[i][j] == '.')
            {
                gameArea[i][j] = ' ';
                break;
            }
        }
    }
}

void moveOpponent(char gameArea[][36], char opponentType, char move)
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if (gameArea[i][j] == opponentType)
            {
                if (move == 'r')     /// right
                {
                    if (gameArea[i][j] == opponentType && gameArea[i][j + 1] == ' ')     /// wall collision
                    {
                        gameArea[i][j] = ' ';
                        gameArea[i][j + 1] = opponentType;
                        break;
                    }
                }
                else if (move == 'l')       /// left
                {
                    if (gameArea[i][j - 1] == ' ' && gameArea[i][j - 1] != '#')
                    {
                        gameArea[i][j] = ' ';
                        gameArea[i][j - 1] = opponentType;
                        break;
                    }  
                }
                else if (move == 'u')       /// up
                {
                    if (i - 1 >= 0 && gameArea[i - 1][j] == ' ')
                    {
                        gameArea[i][j] = ' ';
                        gameArea[i - 1][j] = opponentType;
                        break;
                    }
                }
                else if (move == 'd')       /// down
                {
                    if (i + 1 < 16 && gameArea[i + 1][j] == ' ')
                    {
                        gameArea[i][j] = ' ';
                        gameArea[i + 1][j] = opponentType;
                        break;
                    }
                }
            }
        }
    }
}

void movePlayer(char gameArea[][36], char direction, char boundary)
{
   for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if (gameArea[i][j] == 'p')
            {
                if (direction == 'r')     /// right
                {
                    if (j + 1 < 36 && gameArea[i][j + 1] == boundary)     /// wall or boundary collision
                    {
                        gameArea[i][j] = ' ';
                        gameArea[i][j + 1] = 'p';
                        break;
                    }
                }
                else if (direction == 'l')       /// left
                {
                    if (j - 1 >= 0 && gameArea[i][j - 1] == boundary)
                    {
                        gameArea[i][j] = ' ';
                        gameArea[i][j - 1] = 'p';
                        break;
                    }  
                }
                else if (direction == 'u')       /// up
                {
                    if (i - 1 >= 0 && gameArea[i - 1][j] == boundary)
                    {
                        gameArea[i][j] = ' ';
                        gameArea[i - 1][j] = 'p';
                        break;
                    }
                }
                else if (direction == 'd')       /// down
                {
                    if (i + 1 < 16 && gameArea[i + 1][j] == boundary)
                    {
                        gameArea[i][j] = ' ';
                        gameArea[i + 1][j] = 'p';
                        break;
                    }
                }
            }
        }
    }
}

void moveProjectile(char gameArea[][36], int step)
{
    while(step != 0)
    {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 36; j++)
            {
                if (gameArea[i][j] == '.')
                {
                    gameArea[i][j] = ' ';
                    gameArea[i - 1][j] = '.';
                }
            }
        }
        step--;    
    }
}

void moveProjectile(char gameArea[][36])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if (gameArea[i][j] == '.')
            {
                gameArea[i][j] = ' ';
                gameArea[i - 1][j] = '.';
            }
        }
    }
}

void shootProjectile(char gameArea[][36])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if (gameArea[i][j] == 'p')
            {
                gameArea[i - 1][j] = '.';
            }
        }
    }
}

// this function will only print the bounds of the board
void drawGameBounds(char gameArea[][36])
{
    system("cls");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            // apply if condition to print only the bounds
            // if the element is '#' or ' ' then print it
            if (gameArea[i][j] == '#' || gameArea[i][j] == ' ')
                cout << gameArea[i][j];
            else
                cout << ' ';
        }
        cout << endl;
    }   
}

void drawGameWorld(char gameArea[][36])
{
    string buffer = "";
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            buffer += gameArea[i][j];    /// storing each element of the array in the buffer string variable
        }
        buffer += "\n";
    }
    system("cls");
    cout << buffer;               /// printing the buffer string variable which has the whole board
}

bool checkCollision(char arr[][36])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if (arr[i][j] == '.' && (arr[i - 1][j] == '#' || arr[i - 1][j] == 'p'))
            {
                arr[i][j] = ' ';  // remove projectile
                return false; // Collision detected, stop moving
            }
        }
    }
    return true; // No collision detected, continue moving
}