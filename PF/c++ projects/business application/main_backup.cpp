#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

//gobal variables
string state;

//general use functions
int ascii_to_int(string x);
string get_string_input();
void gotoxy(int x, int y);
//program functions
void ready(string x[],string y[],string z[],string employee_id,bool taskdone_pr[], string tasklist_pr[]);
void printHeader();

//login functions
void loginMenu(string username_database[],string password_database[],string user_perm[],string employee_id);
string loginInput(string username_database[],string password_database[],string user_perm[],string employee_id);
string sign_in(string x[],string y[],string z[],string employee_id);
void sign_up(string x[],string y[],string z[],string employee_id);
void invalid_creditionals(string username_database[],string password_database[],string user_perm[],string employee_id);

//user front page
void admin_page(int task_num,bool taskdone_pr[20],string tasklist_pr[20],int taskid_pr);
void employee_page(int task_num,bool taskdone_pr[20],string tasklist_pr[20],int taskid_pr);

//tasklist
void add_tasks(int task_num,bool taskdone_pr[20],string tasklist_pr[20],int taskid_pr);
void view_task(int task_num,bool taskdone_pr[20],string tasklist_pr[20],int taskid_pr);
 
//validation functions
void validation_fail();
bool login_Input_validation(string option);
bool sign_up_validation(string option);



int main()
{
    system ( "cls" );
    printHeader();
    cout << endl;
    cout <<"press any key to continue :-";
    getch ();

    //sign in creditionals
    string employee_id;
    string username_database[10];
    string password_database[10];
    string user_perm[10];

    //general use variables
    string convert_to_int;

    //tasklist var
    int task_num = 0 ;
    bool taskdone_pr[20];
    string tasklist_pr[20];
    int taskid_pr = 0;

    ready(username_database,password_database,user_perm,employee_id, taskdone_pr, tasklist_pr);     //calling ready to initialize variables
    loginMenu(username_database,password_database,user_perm,employee_id);             //login menu redirects to required login menu
    
    if (state == "admin")
    {
        admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr);
    }
    else if (state == "employee")
    {
        employee_page(task_num,taskdone_pr,tasklist_pr,taskid_pr);
    }


}


//general use functions
int ascii_to_int(string convert_to_int)
{
    string temp_string;
    int temp_int;

    temp_string = convert_to_int;

    temp_int = stoi(temp_string);

    return temp_int;
}
string get_string_input()
{
    string temp_string;
    cin.ignore();
    getline(cin,temp_string); 
    return temp_string;
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
//headers
void printHeader()
{
cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" <<endl;
cout << "|***********************************************************************************************************************************|" <<endl;
cout << "|******************************************** Game studio management system ********************************************************|" <<endl;
cout << "|***********************************************************************************************************************************|" <<endl;
cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" <<endl;
}

//ready

void ready(string username_database[],string password_database[],string user_perm[],string employee_id,bool taskdone_pr[],string tasklist_pr[])
{


    for (int x =0 ;x < 10 ;x++)
    {
        username_database[x] = "0";
        password_database[x] = "0";
    }
    for (int x =0 ;x < 20 ;x++)
    {
        taskdone_pr[x] = false;
    }
    int x=0;
    for(int x =0;x<20;x++)
    {
        taskdone_pr[x] = false;

    }
    tasklist_pr[1] = "program";
    tasklist_pr[2] = "draw";
    tasklist_pr[3] = "manage";
    
    username_database[0] = "admin";
    password_database[0] = "admin";
    user_perm[0] = "admin";
    employee_id = "0";

    system ( "cls" );
}

//login functions
void loginMenu(string username_database[],string password_database[],string user_perm[],string employee_id)
{
    string option;
    option = loginInput(username_database,password_database,user_perm,employee_id);
    if (option == "1")
    {    
        sign_in(username_database,password_database,user_perm,employee_id);
    }

    else if (option =="2")
    {
        sign_up(username_database,password_database,user_perm,employee_id);
    }
    else if (option =="3")
    {
        main();
    }
    else
    {
        validation_fail();
        loginMenu(username_database,password_database,user_perm,employee_id);
    }
}
string loginInput(string username_database[],string password_database[],string user_perm[],string employee_id)
{
    string option;
    system ( "cls" );
    printHeader();

    std::cout << endl;
    std::cout << endl;
    std::cout << "1:) sign in"<<endl;        
    std::cout << "2:) sign up"<<endl;    
    std::cout << "3:) exit"<<endl;
    std::cout << endl;
    std::cout<< "Select option :-";

    cin >> option;

    if (login_Input_validation(option))
    {
        return option ;
    }
    else
    {
        validation_fail();
        loginMenu(username_database,password_database,user_perm,employee_id);
    }

}
string sign_in(string username_database[],string password_database[],string user_perm[],string employee_id)
{
    string entered_username,entered_password;
    int entered_employee_id;
    string option;
    system ( "cls" );
    printHeader();
    cout << endl;
    cout << "ENTER EMPLOYEE ID :- ";
    cin >> employee_id;
    entered_employee_id = ascii_to_int(employee_id);
    cout << "ENTER USERNAME :- ";
    cin >> entered_username;
    cout << "ENTER PASSWORD :- ";
    cin >> entered_password;
    cout <<endl;
    cout << "press any key to continue";
    getch();
    if ((entered_username == username_database[entered_employee_id]) && (entered_password == password_database[entered_employee_id]))
    {
        if (user_perm[entered_employee_id]=="admin")
            state ="admin";
        if ((user_perm[entered_employee_id]=="programmar") || (user_perm[entered_employee_id]=="artist"))
            state="employee";
    }
    else
    {
        invalid_creditionals(username_database,password_database,user_perm,employee_id);
    }
}
void sign_up(string username_database[],string password_database[],string user_perm[],string employee_id)
{
    int temp_int;                                                               //used to store conversion from ascii to int
    system ( "cls" );
    printHeader();
    cout << endl;
    cout << "ENTER EMPLOYEE ID :- ";
    cin >> employee_id;
    temp_int = ascii_to_int(employee_id);
    cout << "ENTER USERNAME :- ";
    cin >> username_database[temp_int];
    cout << "ENTER PASSWORD :- ";
    cin >> password_database[temp_int];
    cout << "admin , programmar or artist ? ";
    cin >> user_perm[temp_int];
    string option = user_perm[temp_int];
    if(sign_up_validation(option))
    {
        loginMenu(username_database,password_database,user_perm,employee_id);
    }
    else 
    {
        validation_fail();
        sign_up(username_database,password_database,user_perm,employee_id);
    }
}
void invalid_creditionals(string username_database[],string password_database[],string user_perm[],string employee_id)
{
    string option;
    cout <<endl;
    cout <<"INVALID CREDITIONALS (press y to retry or press n to go back to login screen)";
    cin >> option;
    if (option == "y")
        sign_in(username_database,password_database,user_perm,employee_id);
    else if (option == "n")
        loginMenu(username_database,password_database,user_perm,employee_id);
    else 
    {
        validation_fail();
        invalid_creditionals(username_database,password_database,user_perm,employee_id);
    }
            
}

void admin_page(int task_num,bool taskdone_pr[20],string tasklist_pr[20],int taskid_pr)
{
    system ( "cls" );
    char option;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||  A  D  M  I  N   P   A   G    E ||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Adding tasks ------>Enter 1.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Task List    ------>Enter 2.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| CHANGE USERS     ------>Enter 0.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    
    cin>> option;

    if (option =='0'||option =='1' ||option =='2')
    {
        if (option=='0')
        {
            main();
        }
        if (option=='1')
        {
            add_tasks(task_num,taskdone_pr,tasklist_pr,taskid_pr);
        }
        if(option=='2')
        {
            view_task(task_num,taskdone_pr,tasklist_pr,taskid_pr);
        }
    }
    else 
    {
        validation_fail();
        admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr);
    }
}
void employee_page(int task_num,bool taskdone_pr[20],string tasklist_pr[20],int taskid_pr)
{
 system ( "cls" );
    string option;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||  EMPLOYEE               PAGE    ||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    // cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For MARKING tasks ----->Enter 1.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Task List    ------>Enter 2.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| CHANGE USERS     ------>Enter 0.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    
    cin>> option;

    if (option =="0"||option =="1" ||option =="2")
    {
        if (option=="0")
        {
            main();
        }
        if(option=="2")
        {
            view_task(task_num,taskdone_pr,tasklist_pr,taskid_pr);
        }
    }
    else 
    {
        validation_fail();
        admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr);
        getch();
    }
}

//tasklist functions
void add_tasks(int task_num,bool taskdone_pr[20],string tasklist_pr[20],int taskid_pr)
{
    char option;
    bool loop_cont = true;
    while(loop_cont)
    {
        cout << "ENTER TASK :- ";
        tasklist_pr[taskid_pr]=get_string_input();
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
    admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr);
}
void view_task(int task_num,bool taskdone_pr[20],string tasklist_pr[20],int taskid_pr)
{
    int hei = 4;
    for (int i = taskid_pr; i>=1 ;i--)
    {   
        gotoxy(0,hei);
        cout<<i<<")- ";
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
    getch();

    admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr);

}

//validation functions
void validation_fail()
{
    cout <<"invalid input (press any key to continue)";
    getch();
}
bool login_Input_validation(string option)
{
    if (option == "1" || option =="2" || option =="3")
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool sign_up_validation(string option)
{
    if (option == "admin" || option =="programmar" || option =="artist")
    {
        return true;
    }
    else
    {
        return false;
    }
}







