#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int screen_l=51;
const int screen_h=37;

void print_Array(char screen[screen_h][screen_l]);
void moveDown(char screen[screen_h][screen_l], char buffer[screen_h][screen_l], char randArrays[3][screen_h][screen_l]);
int random_function(int x);
void cursor_hide();
void clearConsole();

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int main() 
{
    char screen[screen_h][screen_l] = {"                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "           #####                                  ",
                                       "          #     #   ##   #    # ######            ",
                                       "          #        #  #  ##  ## #                 ",
                                       "          #  #### #    # # ## # #####             ",
                                       "          #     # ###### #    # #                 ",
                                       "          #     # #    # #    # #                 ",
                                       "           #####  #    # #    # ######            ",
                                       "                                                  ",
                                       "           #####                                  ",
                                       "          #     # #####   ##   #####  #####       ",
                                       "          #         #    #  #  #    #   #         ",
                                       "           #####    #   #    # #    #   #         ",
                                       "                #   #   ###### #####    #         ",
                                       "          #     #   #   #    # #   #    #         ",
                                       "           #####    #   #    # #    #   #         ",
                                       "                                                  ",
                                       "                                                  ",
                                       "              Lets Gooooooooooo!!!!!!!            ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  "};

    char buffer[screen_h][screen_l] = {"                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  ",
                                       "                                                  "};

    char randArrays[3][screen_h][screen_l] = {{"                                                  ",
                                               "                                                  ",
                                               "   :=+:                                           ",
                                               "  :***=-                                          ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                    %#::::::*:    ", 
                                               "                                   *:*==::-  :*   ",  
                                               "                                   -::::::-=::*:= ",  
                                               "                                   =::*=::+#::=-: ",  
                                               "                                   ==::::::-::::= ",  
                                               "                                    %=-*:::-=::*  ",  
                                               "                                    :##+==--=#.   ",  
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                   +*#**+=--.                     ",  
                                               "                 @##@%****=--                     ",  
                                               "               *@@%*@%****=-                      ", 
                                               "               .@@@%#******+=:                    ",  
                                               "               :@@@@@@%**@%**                     ", 
                                               "                 %@@@@@@@@@@@*=                   ",  
                                               "                   .%@@@@@@%@#                    ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  "},
                                              {"                                           %@@@@@@",
                                               "                                        =+%@@@@@@@",
                                               "                                    +%@%##@@@@@@@@",
                                               "                                 :#%@#*%@@@#@@@@@@",
                                               "                              :%:#**###@@@@@@@@@@@",
                                               "                            .**=+*%@@@@=*@@@@@@@@@",
                                               "                           :====*=@@@@##@@@@@@@@@@",
                                               "                          :*==+#*-=@@@@@=%@@@@@@@@",
                                               "                         --+@@%*++@#@@#*#@@@@@@@@@",
                                               "                       :=@@%@@@@@@%*#@##@@@@@@@@@@",
                                               "                       -#@%*##@@@#@%@%@@@@@@@%@@@@",
                                               "                      ::%##@*#@@%*@@@*%@@@@@@@@@@@",
                                               "                     :-= =#@**%##@%*#@@@@%@@@@@@@@",
                                               "                    ::--=*#@%@###%-#@@@@%=@@@@@@@@",
                                               "                    :: --+%*#@%*@%**@@@@**@@@@@@@@",
                                               "                    +-:::=%*@##@@@%*#@@@@@@@@@@@@@",
                                               "                   :*+=#*:=%@%#@@@%@*@@@@@@@@@@@@@",
                                               "                   :#**+==%@@@*%*@@@@@@@@@@@@@@@@@",
                                               "                    %+=*%=*@@@@%@@@@@@@@@@%@@@@@@@",
                                               "                    %@#%*=+%@@@%@@@@@@@@@@@@@@@@@@",
                                               "                    +@+%##*#@@@@@@@@@%#@@@@@@@@@@@",
                                               "                    .:%#@%#@@@@%@@@#@@@@@@@@@@@@@@",
                                               "                     @@%@*%@@@#@@%@@@@@@@@@@@@@@@@",
                                               "                      =@@%#@@@@@@@@#@@@@@@@@@@@@@@",
                                               "                       :%@@@@@@@@@@@@@@@@@@@@@@@@@",
                                               "                        :%@@@@@@@@@@@@@@@@@@@@@@@@",
                                               "                         @@@@@@@@@@@@@@@@@@@@@@@@@",
                                               "                          @@@@@@@@@@@@@@@@@@@@@@@@",
                                               "                            @@@%@@@@@@@@@@@@@@@@@@",
                                               "                             @@@@@@@@@@@@@@@@@@@@@",
                                               "                              =@@@@@@@@@@@@@@@@@@@",
                                               "                                .=%@@@@@@@@@@@@@@@",
                                               "                                     -@@@@@@@@@@@@",
                                               "                                             .#%@@",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  "},
                                              {"                                                  ",
                                               "                                                  ",
                                               "         :===.                                    ", 
                                               "     :#######+=                                   ",
                                               "    =**###*+======:                               ",
                                               "   =============**++====:                         ",
                                               "  :=====*##*+=============:                       ",
                                               " .=====*####*==============                       ",
                                               " =+*====+++================-                      ",
                                               "-=*+==============**=====*==                      ",
                                               "-=+==========+**===+====**==                      ",
                                               " ===+###+=====**===========                       ",
                                               "  ===*##*=================                        ",
                                               "   :=========+*====*#+==:                         ",
                                               "     ==+*===**+====*+==                           ",
                                               "      ==*=============                            ",
                                               "      :============-                              ",
                                               "       .:                                         ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                     :=+:         ",
                                               "                                    :***=-...     ",
                                               "                                     :***=-###:=+:",
                                               "                                    :***=-##:***=-",
                                               "                                      .::!@@@##::.",
                                               "                                     :=+:         ",
                                               "                                    :***=-        ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  ",
                                               "                                                  "}};
    cursor_hide();
    while (true) 
    {
        
            clearConsole();
            moveDown(screen, buffer, randArrays);
            print_Array(screen);
            Sleep( 150);
        
    }

    return 0;
}


void print_Array(char screen[screen_h][screen_l])
 {
    string temp = "";
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
}

void moveDown(char screen[screen_h][screen_l], char buffer[screen_h][screen_l], char randArrays[3][screen_h][screen_l]) 
{
    static int count = 0;  // Counter to track the number of times moveDown is called

    // Move each column one step down
    for (int j = 0; j < screen_l; ++j) {
        // Shift elements down in the buffer
        for (int i = screen_h - 1; i > 0; --i) {
            buffer[i][j] = buffer[i - 1][j];
        }
        // Move the last row from screen to the top of the buffer
        // buffer[0][j] = screen[screen_h - 1][j];

        // Shift elements down in the screen
        for (int i = screen_h - 1; i > 0; --i) {
            screen[i][j] = screen[i - 1][j];
        }
        // Move the last row to the top
        screen[0][j] = buffer[screen_h - 1][j];
    }

    // Check if all elements in the buffer have moved down
    if (++count % screen_h == 0) {
        // Reset the counter
        count = 0;

        // Randomly select an array from randArrays and move it to the buffer
        int randIndex = random_function(3);
        for (int i = 0; i < screen_h; ++i) {
            for (int j = 0; j < screen_l; ++j) {
                buffer[i][j] = randArrays[randIndex][i][j];
            }
        }
    }
}

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
    COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
