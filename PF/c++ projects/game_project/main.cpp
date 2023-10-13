#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

/*normal game functions declaration*/
void ready();
void print_maze();
void gotoxy(int x ,int y);
char getCharAtxy(short int x, short int y);

//random number generator functions
void random_diagonal_dir();
void random_map_coordinates();

/*Score functions*/
void print_score();
void update_score();
void score_ball_spawner();

/*player functions functions declaration*/
void print_player();
void erase_player();
void move_player();


/*enemy functions functions declaration*/
void erase_enemy();
void move_spiky_boi();
void print_spiky_boi();

/*test cases*/
void test_case();

/*player var*/
int pX = 5,pY = 5;
char player_direction;
int gX =5 ,gY =5;

/* enemy common var */
int eX = 2,eY = 2;

/*spiky boi var*/
int sX = 7,sY = 5;
int sDir = 1;
bool sFrame =true ;

/*other var*/
int maze_h ,maze_l;
int rand_num;
int rand_dir;
int rand_X_map,rand_Y_map;

/*score variables*/
int current_score=0;
int scoreX , scoreY;
bool score_ball_eaten= false ;



int main()
{
    /*used to print menu */
    
    ready();
    print_spiky_boi();
    print_player();

    /*Game loop will replace by void update later*/
    
    while (true)
    {
        Sleep(50);
        getch();
        move_player();
        move_spiky_boi();
        test_case();
        print_score();
    }
    

    


}

/*normal game functions bodies*/
void ready()

{
    system("cls");

    cout<< "                                  "<<endl;
    cout<< "                                  "<<endl;
    cout<< "                                  "<<endl;
    cout<< "                                  "<<endl;
    cout<< "            GAME START            "<<endl;
    cout<< "                                  "<<endl;
    cout<< "                                  "<<endl;
    cout<< "                                  "<<endl;
    cout<< "    press any key to continue     "<<endl;

    getch();
    system("cls");

    /*enemy movement test only*/
    cout<<"this is a pysduo turnbased game so enemy will move after u move"<<endl;
    cout<<"4 is left movement "<<endl;
    cout<<"6 is right movement"<<endl;
    cout<<"2 is downward movement"<<endl;
    cout<<"8 is upward movement "<<endl;
    cout<<"3 is downright movement "<<endl;
    cout<<"7 is upleft movement "<<endl;
    cout<<"9 is upright movement "<<endl;
    cout<<"1 is downleft movement "<<endl;
    cout<<"enter enemy movement test case? ";
    cin >>sDir;
    system("cls");
    print_maze();

    /*makes player spawns in middle of map*/

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

//random value generators
void random_diagonal_dir()
{
    srand(time(0));
    rand_dir =rand() % 9 +1;
    if (rand_dir == 5 || rand_dir ==sDir)
        rand_dir =rand() % 9 +1;

}
void random_map_coordinates()
{
    srand(time(0));
    rand_X_map =rand() % 100 ;
    rand_Y_map =rand() % 100 ;
    // random x coordinate
    while (!(rand_X_map > 1 && rand_X_map < maze_l))
    {
        srand(time(0));
        rand_X_map =rand() % 100 ;
    }
    // random y coordinate
    while (!(rand_Y_map > 1 && rand_Y_map < maze_l))
    {
        srand(time(0));
        rand_Y_map =rand() % 100 ;
    }

}

/*Score function bodies*/
void print_score()
{
    gotoxy(2,16);
    cout << "Score = "<<current_score;
}
void update_score()
{
    if (scoreX == pX && scoreY == pY)
        {
            current_score = current_score + 1;
            score_ball_eaten = true;
        }
}
void score_ball_spawner()
{
    
}

/*maze functions*/
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

/*player function bodies*/
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

    if ((getCharAtxy(pX-1,pY) == ' ' ) && (GetAsyncKeyState(VK_LEFT)))
    {
        pX=pX-1;
        player_direction='L';
    }

    if ((getCharAtxy(pX+1,pY) == ' ' ) && (GetAsyncKeyState(VK_RIGHT)))
    {
        pX=pX+1;
        player_direction='R';
    }

    if ((getCharAtxy(pX,pY-1) == ' ' ) && (GetAsyncKeyState(VK_UP)))
    {
        pY=pY-1;
        player_direction='U';
    }

    if ((getCharAtxy(pX,pY+1) == ' ' ) && (GetAsyncKeyState(VK_DOWN)))
    {
        pY=pY+1;
        player_direction='D';

    }

    print_player();

}

/*enemy function bodies*/
void print_spiky_boi()
{
    gotoxy(sX,sY);
    
    if (sFrame == true)
        {
            cout<<"x";
        }
    if (sFrame == false)
    {
        cout<<"+";
    }
    sFrame= !sFrame;
}
void erase_enemy()
{
    gotoxy(eX,eY);
    cout<<" ";
}
void move_spiky_boi()
{
    eX = sX;
    eY = sY;

    erase_enemy();

/*sDir = 4 is left movement*/
    if ((getCharAtxy(sX-1,sY) == ' ' ) && (sDir == 4))
    {
        sX = sX - 1;
        if ((getCharAtxy(sX-1,sY) == ' ' ) ==false)
        {
            sDir = 6;
        }
    }
    ;

/*sDir = 6 is right movement*/
    if (((getCharAtxy(sX+1,sY) == ' ' ) && sDir == 6))
    {
        sX = sX + 1;
        if ((getCharAtxy(sX+1,sY) == ' ' ) == false)
        {
            sDir = 4;
        }
    }

/*sDir = 2 is downward movement*/
    if ((getCharAtxy(sX,sY+1) == ' ' ) && (sDir == 2))
    {
        sY = sY + 1;
        if ((getCharAtxy(sX,sY+1) == ' ' ) == false)
        {
            sDir = 8;
        }
    }

/*sDir = 8 is upward movement*/
    if ((getCharAtxy(sX,sY-1) == ' ' ) && (sDir == 8))
    {
        sY = sY - 1;
        if ((getCharAtxy(sX,sY-1) == ' ' ) == false)
        {
            sDir = 2;
        }
    }
/*sDir = 3 is downright movement*/
    if ((getCharAtxy(sX+1,sY+1) == ' ' ) && (sDir == 3))
    {
        sX = sX + 1;
        sY = sY + 1;
        if ((getCharAtxy(sX+1,sY+1) == ' ' ) == false)
        {
            sDir = 7;
        }
    }

/*sDir = 7 is upleft movement*/
    if ((getCharAtxy(sX-1,sY-1) == ' ' ) && (sDir == 7))
    {
        sX = sX - 1;
        sY = sY - 1;
        if ((getCharAtxy(sX-1,sY-1) == ' ' ) == false)
        {
            sDir =3;
        }
    }

/*sDir = 9 is upright movement*/
    if ((getCharAtxy(sX+1,sY-1) == ' ' ) && (sDir == 9))
    {
        sX = sX + 1;
        sY = sY - 1;
        if ((getCharAtxy(sX+1,sY-1) == ' ' ) == false)
        {
            
            sDir = 1;
        }
    }
/*sDir = 1 is downleft movement*/
    if ((getCharAtxy(sX-1,sY+1) == ' ' ) && (sDir == 1))
    {
        sX = sX - 1;
        sY = sY + 1;
        if ((getCharAtxy(sX-1,sY+1) == ' ' ) == false)
        {
            sDir = 9;
        }
    }

    print_spiky_boi();

}

/*test cases function bodies. dont mind .for debugging*/
void test_case()
{
 gotoxy(55, 4);
 cout <<" sX= "<<sX<<endl;
 gotoxy(55, 5);
 cout <<" sY= "<<sY<<endl;
 gotoxy(55, 6);
 cout <<" pX= "<<pX<<endl;
 gotoxy(55, 7);
 cout <<" pY= "<<pY<<endl;
 gotoxy(55, 8);
 cout <<" sframe= "<<sFrame<<endl;
 gotoxy(55, 9);
 cout <<" random= "<<rand_num<<endl;
}



