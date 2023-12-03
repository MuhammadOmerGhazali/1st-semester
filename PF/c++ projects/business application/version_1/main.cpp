#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void ready();
void gotoxy(int x ,int y);
void printHeader();
void loginMenu();
void sign_in();
void sign_up();
void admin_page();
void employee_page();
void add_tasks();
void view_task();

int employee_id;
int task_num = 0 ;
string username_database[10];
string password_database[10];
string user_perm[10];

bool taskdone_pr[20];
string tasklist_pr[20];
int taskid_pr = 0;


int main()
{
    ready();
    loginMenu();
}

void ready()
{
    system ( "cls" );
    printHeader();
    cout << endl;
    cout <<"press any key to continue :-";
    getch();

    for (int x =0 ;x <= 10 ;x++)
    {
        username_database[x] = "0";
        password_database[x] = "0";
    }
    for (int x =0 ;x <= 20 ;x++)
    {
        taskdone_pr[x] = false;
    }
    username_database[0] = "admin";
    password_database[0] = "admin";
    user_perm[0] = "ADMIN";
    employee_id = 0;

    system ( "cls" );
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void printHeader()
{
cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" <<endl;
cout << "|***********************************************************************************************************************************|" <<endl;
cout << "|******************************************** Game studio management system ********************************************************|" <<endl;
cout << "|***********************************************************************************************************************************|" <<endl;
cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" <<endl;
}

void loginMenu()
{
    char option;
    system ( "cls" );
    printHeader();
    cout <<endl;
    cout <<endl;
    cout <<"1:) sign in"<<endl;        
    cout <<"2:) sign up"<<endl;    
    cout <<"3:) exit"<<endl;
    cout <<endl;
    cout<<"Select option :-";
    cin >> option;


    if (option == '1')
    {    
        sign_in();
    }

    else if (option =='2')
    {
        sign_up();
    }
    else if (option =='3')
    {
        main();
    }
    else
    {
        cout <<"INVALID OPTION (press any key to continue)";
        loginMenu();
    }

    
        
}
void sign_in()
{
    string entered_username,entered_password;
    int entered_employee_id;
    char option;
    system ( "cls" );
    printHeader();
    cout << endl;
    cout << "ENTER EMPLOYEE ID :- ";
    cin >> entered_employee_id;
    employee_id = entered_employee_id;
    cout << "ENTER USERNAME :- ";
    cin >> entered_username;
    cout << "ENTER PASSWORD :- ";
    cin >> entered_password;
    cout <<endl;
    cout << "press any key to continue";
    getch();
    if ((entered_username == username_database[employee_id])&&(entered_password == password_database[employee_id]))
    {
        if (user_perm[employee_id]=="ADMIN")
            admin_page();
        if ((user_perm[employee_id]=="PROGRAMMER") || (user_perm[employee_id]=="ARTIST"))
            employee_page();
    }
    else
    {
        cout <<endl;
        cout <<"INVALID CREDITIONALS (press y to retry or press n to go back to login screen)";
        cin >> option;
        if (option == 'y')
            sign_in();
        if (option == 'n')
            loginMenu();
        
    }
}
void sign_up()
{
    system ( "cls" );
    printHeader();
    cout << endl;
    cout << "ENTER EMPLOYEE ID :- ";
    cin >> employee_id;
    cout << "ENTER USERNAME :- ";
    cin >> username_database[employee_id];
    cout << "ENTER PASSWORD :- ";
    cin >> password_database[employee_id];
    cout << "ADMIN , PROGRAMMER or ARTIST ? ";
    cin >> user_perm[employee_id];
    loginMenu();
}

void admin_page()
{
    system ( "cls" );
    char option;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||  A  D  M  I  N   P   A   G    E ||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Adding tasks ------>Enter 1.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Task List    ------>Enter 2.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| CHANGE USERS     ------>Enter 0.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    
    cin>> option;

    if (option=='0')
    {
        loginMenu();
    }
    if (option=='1')
    {
        add_tasks();
    }
    if(option=='2')
    {
        view_task();
    }
   
}
void add_tasks()
{
    char option;
    bool loop_cont = true;
    while(loop_cont)
    {
        cout << "ENTER TASK :- ";
        cin >>tasklist_pr[taskid_pr];
        cout << "ENTER ANOTHER TASK (y or n) ?";
        cin >> option;
        if (option =='y')
        {
            loop_cont = true;
            taskid_pr = taskid_pr + 1 ;
        }
        else if (option =='n')
        {
            loop_cont = false;
            taskid_pr = taskid_pr + 1 ;
        }
    }
    admin_page();
}
void view_task()
{
    int hei = 4;
    for (int i = taskid_pr; i>=1 ;i--)
    {   
        gotoxy(5,hei);
        cout<<tasklist_pr[i];
        gotoxy(55,hei);
        if (taskdone_pr[i])
        {
            cout <<"done";
        }
        else cout <<"not done";

        cout <<endl;
        hei = hei + 1;
    }
    hei = 4;
    gotoxy(0,hei);
    cout <<"                                                                    ";
    getch();

    admin_page();

}



void employee_page()
{
        cout <<"imagine employee page here";
}



