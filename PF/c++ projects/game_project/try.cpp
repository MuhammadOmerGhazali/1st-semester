#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

// screen dimensions
const int screen_l=51;
const int screen_h=37;

// player variables
const int return_coordinates[2]= {25,25};
int player_coordinates[2]={25,25};
const float accel_factor=1;
const float deaccel_fator=2;
const int max_player_speed=4;
const int deaccel_speed=1;
int player_speed=0;


HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

//general use functions
int random_function(int total_options);
void cursor_hide();
void clearConsole();
void gotoxy(int x, int y);

//printing functions
void print_border();
void print_Array(char screen[screen_h][screen_l]);

//screen movement
void moveDown(char screen[screen_h][screen_l], char buffer[screen_h][screen_l], char randArrays[3][screen_h][screen_l]);

// player functions
void erase_player(char screen[screen_h][screen_l]);
void print_player(char screen[screen_h][screen_l]);
void move_player(char screen[screen_h][screen_l], int direction,bool input);
void check_player_input(char screen[screen_h][screen_l]);

// ui functions
void testcases();

int main() 
{
    system("cls");
    char screen[screen_h][screen_l] = {"#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#          #####                                 #",
                                       "#         #     #   ##   #    # ######           #",
                                       "#         #        #  #  ##  ## #                #",
                                       "#         #  #### #    # # ## # #####            #",
                                       "#         #     # ###### #    # #                #",
                                       "#         #     # #    # #    # #                #",
                                       "#          #####  #    # #    # ######           #",
                                       "#                                                #",
                                       "#          #####                                 #",
                                       "#         #     # #####   ##   #####  #####      #",
                                       "#         #         #    #  #  #    #   #        #",
                                       "#          #####    #   #    # #    #   #        #",
                                       "#               #   #   ###### #####    #        #",
                                       "#         #     #   #   #    # #   #    #        #",
                                       "#          #####    #   #    # #    #   #        #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#             Lets Gooooooooooo!!!!!!!           #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #"};

    char buffer[screen_h][screen_l] = {"#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #",
                                       "#                                                #"};

    char randArrays[3][screen_h][screen_l] = {{"#                                                #",
                                               "#                                                #",
                                               "#  :=+:                                          #",
                                               "# :***=-                                         #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                   %#::::::*:   #", 
                                               "#                                  *:*==::-  :*  #",  
                                               "#                                  -::::::-=::*:=#",  
                                               "#                                  =::*=::+#::=-:#",  
                                               "#                                  ==::::::-::::=#",  
                                               "#                                   %=-*:::-=::* #",  
                                               "#                                   :##+==--=#.  #",  
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                  +*#**+=--.                    #",  
                                               "#                @##@%****=--                    #",  
                                               "#              *@@%*@%****=-                     #", 
                                               "#              .@@@%#******+=:                   #",  
                                               "#              :@@@@@@%**@%**                    #", 
                                               "#                %@@@@@@@@@@@*=                  #",  
                                               "#                  .%@@@@@@%@#                   #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #"},
                                              {"#                                          %@@@@@#",
                                               "#                                       =+%@@@@@@#",
                                               "#                                   +%@%##@@@@@@@#",
                                               "#                                :#%@#*%@@@#@@@@@#",
                                               "#                             :%:#**###@@@@@@@@@@#",
                                               "#                           .**=+*%@@@@=*@@@@@@@@#",
                                               "#                          :====*=@@@@##@@@@@@@@@#",
                                               "#                         :*==+#*-=@@@@@=%@@@@@@@#",
                                               "#                        --+@@%*++@#@@#*#@@@@@@@@#",
                                               "#                      :=@@%@@@@@@%*#@##@@@@@@@@@#",
                                               "#                      -#@%*##@@@#@%@%@@@@@@@%@@@#",
                                               "#                     ::%##@*#@@%*@@@*%@@@@@@@@@@#",
                                               "#                    :-= =#@**%##@%*#@@@@%@@@@@@@#",
                                               "#                   ::--=*#@%@###%-#@@@@%=@@@@@@@#",
                                               "#                   :: --+%*#@%*@%**@@@@**@@@@@@@#",
                                               "#                   +-:::=%*@##@@@%*#@@@@@@@@@@@@#",
                                               "#                  :*+=#*:=%@%#@@@%@*@@@@@@@@@@@@#",
                                               "#                  :#**+==%@@@*%*@@@@@@@@@@@@@@@@#",
                                               "#                   %+=*%=*@@@@%@@@@@@@@@@%@@@@@@#",
                                               "#                   %@#%*=+%@@@%@@@@@@@@@@@@@@@@@#",
                                               "#                   +@+%##*#@@@@@@@@@%#@@@@@@@@@@#",
                                               "#                   .:%#@%#@@@@%@@@#@@@@@@@@@@@@@#",
                                               "#                    @@%@*%@@@#@@%@@@@@@@@@@@@@@@#",
                                               "#                     =@@%#@@@@@@@@#@@@@@@@@@@@@@#",
                                               "#                      :%@@@@@@@@@@@@@@@@@@@@@@@@#",
                                               "#                       :%@@@@@@@@@@@@@@@@@@@@@@@#",
                                               "#                        @@@@@@@@@@@@@@@@@@@@@@@@#",
                                               "#                         @@@@@@@@@@@@@@@@@@@@@@@#",
                                               "#                           @@@%@@@@@@@@@@@@@@@@@#",
                                               "#                            @@@@@@@@@@@@@@@@@@@@#",
                                               "#                             =@@@@@@@@@@@@@@@@@@#",
                                               "#                               .=%@@@@@@@@@@@@@@#",
                                               "#                                    -@@@@@@@@@@@#",
                                               "#                                            .#%@#",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #"},
                                              {"#                                                #",
                                               "#                                                #",
                                               "#        :===.                                   #", 
                                               "#    :#######+=                                  #",
                                               "#   =**###*+======:                              #",
                                               "#  =============**++====:                        #",
                                               "# :=====*##*+=============:                      #",
                                               "#.=====*####*==============                      #",
                                               "#=+*====+++================-                     #",
                                               "#=*+==============**=====*==                     #",
                                               "#=+==========+**===+====**==                     #",
                                               "#===+###+=====**===========                      #",
                                               "# ===*##*=================                       #",
                                               "#  :=========+*====*#+==:                        #",
                                               "#    ==+*===**+====*+==                          #",
                                               "#     ==*=============                           #",
                                               "#     :============-                             #",
                                               "#      .:                                        #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                    :=+:        #",
                                               "#                                   :***=-...    #",
                                               "#                                    :***=-###:=+#",
                                               "#                                   :***=-##:***=#",
                                               "#                                     .::!@@@##::#",
                                               "#                                    :=+:        #",
                                               "#                                   :***=-       #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #",
                                               "#                                                #"}};
    cursor_hide();
    while (true) 
    {
        
        clearConsole();
        check_player_input(screen);
        moveDown(screen, buffer, randArrays);
        print_Array(screen);
        testcases();
        Sleep(150);
        
    }

    return 0;
}
//general use functions
int random_function(int total_options)
{
    int return_int;
    srand(time(0));
    return_int =rand() % total_options ;
    return return_int;
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
void clearConsole() 
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

//Printing functions
void print_border()
{
    cout<<"##################################################"<<endl;
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
    print_player(screen);
    print_border();
}

//Screen movement
void moveDown(char screen[screen_h][screen_l], char buffer[screen_h][screen_l], char randArrays[3][screen_h][screen_l]) 
{
    static int count = 0;  // Counter to see how much of the buffer has moved down

    // Move each column one step down
    for (int j = 0; j < screen_l; ++j) {
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
        // Move the last row to the top
        screen[0][j] = buffer[screen_h - 1][j];
    }

    // Check for collisions with meteors
    for (int i = 0; i < screen_l; ++i) {
        if (screen[screen_h - 1][i] == '*' && buffer[screen_h - 1][i] == '#') {
            // Collision detected
            // Implement your collision handling logic here
            // For example, end the game or reduce player health
            // You may also want to reset the player's position
            player_coordinates[0] = return_coordinates[0];
            player_coordinates[1] = return_coordinates[1];
            player_speed = 0; // Reset player speed
            // Additional actions as needed...

            // For now, let's print a message to the console
            clearConsole();
            cout << "Game Over! Collision with meteor." << endl;
            Sleep(2000); // Sleep for 2 seconds before exiting (adjust as needed)
            exit(0); // Terminate the program
        }
    }

    // Check if all elements in the buffer have moved down
    if (++count % screen_h == 0) 
    {
        // Reset the counter
        count = 0;

        // Randomly select an array from randArrays and move it to the buffer
        int randIndex = random_function(3);
        for (int i = 0; i < screen_h; ++i) {
            for (int j = 0; j < screen_l; ++j) 
            {
                buffer[i][j] = randArrays[randIndex][i][j];
            }
        }
    }
}


//player functions
void check_player_input(char screen[screen_h][screen_l])
{
    bool input = false;

    if (GetAsyncKeyState(VK_LEFT))
    {
        input = true;
        move_player(screen, -1, input);
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        input = true;
        move_player(screen, 1, input);
    }
    else
    {
        // Check if the player is not at the target x-coordinate
        if (player_coordinates[1] != return_coordinates[1])
        {
            // Player hasn't reached the target, keep moving
            input = false;
            if(player_coordinates[1]>return_coordinates[1])
            {
                move_player(screen, -1, input);
            }
            else if(player_coordinates[1]<return_coordinates[1])
            {
                move_player(screen, 1, input);
            }
        }
    }
}


void erase_player(char screen[screen_h][screen_l])
{
    screen[player_coordinates[0]][player_coordinates[1]] = ' ';
}
void print_player(char screen[screen_h][screen_l])
{
    screen[player_coordinates[0]][player_coordinates[1]] = '*';
}
void move_player(char screen[screen_h][screen_l], int direction, bool input) 
{
    // Erase the player from the current position
    erase_player(screen);

        // Acceleration
        player_speed += (direction * accel_factor);
        // Ensure that acceleration does not exceed the maximum speed
        player_speed = min(player_speed, max_player_speed);
        // Check if damping should be applied
        int distanceToTarget = abs(player_coordinates[1] - return_coordinates[1]);
        if (distanceToTarget >= 1 && distanceToTarget <= 2) 
        {
            double dampingFactor = 0.9; // Adjust damping factor as needed
            player_speed += (direction * deaccel_fator);
            // Apply damping
            player_speed *= dampingFactor;
            // Ensure that deacceleration does not go below the deacceleration speed
            player_speed = (abs(player_speed) < deaccel_speed) ? 0 : player_speed;
        }
    

    // Move the player based on the direction
    player_coordinates[1] += static_cast<int>(player_speed);

    // Check for boundaries to prevent the player from going off the screen
    if (player_coordinates[1] < 1) 
    {
        player_coordinates[1] = 1;
        player_speed = 0; // Stop the player when reaching the left boundary
    } else if (player_coordinates[1] >= screen_l - 3) 
    {
        player_coordinates[1] = screen_l - 3;
        player_speed = 0; // Stop the player when reaching the right boundary
    }

    print_player(screen);
}


// ui functions
void testcases()
{
    gotoxy(screen_l+2,0);
    cout<<"Player X:- "<<player_coordinates[1];
    gotoxy(screen_l+2,1);
    cout<<"Player Y:- "<<player_coordinates[0];
    gotoxy(screen_l+2,3);
    cout<<"Returning X:- "<<return_coordinates[1];
    gotoxy(screen_l+2,4);
    cout<<"Returning Y:- "<<return_coordinates[0];    
    gotoxy(screen_l+2,5);
    cout<<"speed:- "<<player_speed;   
}