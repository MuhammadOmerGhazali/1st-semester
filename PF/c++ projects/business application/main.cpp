#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <cmath>
#include <limits>
#include <fstream>

using namespace std;

//general use functions
int ascii_to_int(string convert_to_int)
{
    int result = 0;

    for (char ch : convert_to_int) 
    {
        if (isdigit(ch)) 
        {
            result = result * 10 + (ch - '0');
        }
    }

    return result;
}
string get_string_input()
{
    string string_input;
    cin.ignore();
    getline(cin,string_input); 
    return string_input;
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
    for(int x =1;x<=20;x++)
    {
        taskdone_pr[x] = false;

    }

    username_database[0] = "admin";
    password_database[0] = "admin";
    user_perm[0] = "admin";
    employee_id = "0";

    system ( "cls" );
}

//login functions
string loginMenu(string username_database[], string password_database[], string user_perm[], string employee_id,int num_accounts)
{
    string option;
    string current_user_perms;
    option = loginInput(username_database,password_database,user_perm,employee_id,num_accounts);
    if (option == "1")
    {    
        current_user_perms =sign_in(username_database,password_database,user_perm,employee_id,num_accounts);
    }

    else if (option =="2")
    {
        sign_up(username_database, password_database, user_perm, employee_id, num_accounts);
    }
    else if (option =="3")
    {
        main();
    }
    else
    {
        validation_fail();
        loginMenu(username_database,password_database,user_perm,employee_id,num_accounts);
    }

    return current_user_perms;

}
string loginInput(string username_database[], string password_database[], string user_perm[], string employee_id,int num_accounts)
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
string sign_up(string username_database[], string password_database[], string user_perm[], string& employee_id, int &num_accounts)
{
    string entered_username, entered_password;
    int entered_employee_id;
    string option;
    system("cls");
    printHeader();
    cout << endl;
    cout << "ENTER EMPLOYEE ID :- ";
    cin >> employee_id;
    entered_employee_id = ascii_to_int(employee_id);
    cout << "ENTER USERNAME :- ";
    cin >> entered_username;
    cout << "ENTER PASSWORD :- ";
    cin >> entered_password;
    cout << endl;
    cout << "press any key to continue";
    getch();
    if ((entered_username == username_database[entered_employee_id]) && (entered_password == password_database[entered_employee_id]) && (entered_employee_id >= 0 && entered_employee_id < 10))
    {
        if (user_perm[entered_employee_id] == "admin")
        {
            return "admin";
        }
        else if ((user_perm[entered_employee_id] == "programmar") || (user_perm[entered_employee_id] == "artist"))
        {
            return "employee";
        }
    }
    else
    {
        invalid_credentials(username_database, password_database, user_perm, employee_id);
        return "invalid creds";
    }
}
void store_signup_info(string username_database[], string password_database[], string user_perm[], const string& username, const string& password, const string& user_perm_value, const string& employee_id, int& num_accounts)
{
    // Check if the employee ID already exists
    if (is_employee_id_exists(employee_id))
    {
        cout << "Employee ID already exists. Please choose a different one." << endl;
        return;
    }

    // Append the new sign-up information to the arrays
    if (num_accounts < 10)
    {
        username_database[num_accounts] = username;
        password_database[num_accounts] = password;
        user_perm[num_accounts] = user_perm_value;
        num_accounts++;
    }
    else
    {
        cout << "Maximum number of accounts reached." << endl;
    }

    // Append the new sign-up information to the text file
    ofstream outputFile("signup_info.txt", ios::app);

    if (outputFile.is_open())
    {
        outputFile << employee_id << " " << username << " " << password << " " << user_perm_value << endl;
        outputFile.close();
    }
    else
    {
        cout << "Error opening file for signup_info.txt" << endl;
    }

    // Store the updated accounts in the file
    store_accounts(username_database, password_database, user_perm, num_accounts);
}

bool is_employee_id_exists(const string& employee_id)
{
    ifstream inputFile("signup_info.txt");

    if (inputFile.is_open())
    {
        string stored_employee_id;
        while (inputFile >> stored_employee_id)
        {
            if (stored_employee_id == employee_id)
            {
                inputFile.close();
                return true; // Employee ID already exists
            }

            // Skip the rest of the line
            inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        inputFile.close();
    }

    return false; // Employee ID doesn't exist
}
void admin_page(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr,string current_user_perms)
{
    system ( "cls" );
    string option;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||  A  D  M  I  N   P   A   G    E ||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Adding tasks ------>Enter 1.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Task List    ------>Enter 2.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| Mark Task as Done ----->Enter 3.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| Remove Task      ------>Enter 4.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| Change Users     ------>Enter 0.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    
    cin>> option;

    if (option =="0"||option =="1" ||option =="2"||option=="3"||option=="4")
    {
        if (option=="0")
        {
            main();
        }
        if (option=="1")
        {
            add_tasks(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
        }
        if(option=="2")
        {
            view_task(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
        }
        if(option=="3")
        {
            mark_task_done(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
        }
        if (option == "4")
        {
            remove_task(task_num, taskdone_pr, tasklist_pr, taskid_pr, current_user_perms);
        }
    }
    else 
    {
        validation_fail();
        admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
    }
}
void employee_page(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr,string current_user_perms)
{
 system ( "cls" );
    char option;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||  EMPLOYEE               PAGE    ||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Marking tasks ----->Enter 1.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| For Task List    ------>Enter 2.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| Change Users     ------>Enter 0.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    
    
    cin>> option;

    if (option =='0'||option =='1' ||option =='2')
    {
        if (option=='0')
        {
            main();
        }
        if (option=='1')
        {
            mark_task_done(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
        }
        if(option=='2')
        {
            view_task(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
        }

    }
    else
    {
        validation_fail();
        employee_page(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
    }
}

//tasklist functions
void add_tasks(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr,string current_user_perms)
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
        else
        {
            validation_fail();
        }
    }
    store_tasks(tasklist_pr, taskdone_pr, taskid_pr);
    admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
}
void remove_task(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int &taskid_pr, string current_user_perms)
{
    load_tasks(tasklist_pr, taskdone_pr, taskid_pr);

    int hei = 7;
    for (int i = 0; i < taskid_pr; i++)
    {
        gotoxy(0, hei);
        cout << i + 1 << ")- ";
        gotoxy(5, hei);
        cout << tasklist_pr[i];
        gotoxy(55, hei);
        if (taskdone_pr[i])
        {
            cout << "done";
        }
        else
        {
            cout << "not done";
        }

        cout << endl;
        hei = hei + 1;
    }
    hei = hei + 1;
    gotoxy(0, hei);
    int temp_int;
    cout << "Enter task number to remove: ";
    cin >> temp_int;

    if (temp_int <= taskid_pr && temp_int > 0)
    {
        // Moving tasks to fill the gap
        for (int i = temp_int - 1; i < taskid_pr - 1; i++)
        {
            tasklist_pr[i] = tasklist_pr[i + 1];
            taskdone_pr[i] = taskdone_pr[i + 1];
        }

        // Decrement taskid_pr as a task is removed
        taskid_pr--;

        cout << "Task " << temp_int << " removed." << endl;
    }
    else
    {
        validation_fail();
    }

    store_tasks(tasklist_pr, taskdone_pr, taskid_pr);

    if (current_user_perms == "admin")
    {
        admin_page(task_num, taskdone_pr, tasklist_pr, taskid_pr, current_user_perms);
    }
    else if (current_user_perms == "employee")
    {
        employee_page(task_num, taskdone_pr, tasklist_pr, taskid_pr, current_user_perms);
    }
}
void view_task(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr,string current_user_perms)
{
    load_tasks(tasklist_pr, taskdone_pr, taskid_pr);

    int hei = 7;
    for (int i =0; i <taskid_pr; i++)
    {
        gotoxy(0, hei);
        cout << i+1 << ")- ";
        gotoxy(5, hei);
        cout << tasklist_pr[i];
        gotoxy(55, hei);
        if (taskdone_pr[i])
        {
            cout << "done";
        }
        else
        {
            cout << "not done";
        }

        cout << endl;
        hei = hei + 1;
    }
    getch();


    if (current_user_perms == "admin")
    {
        admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
    }
    else if (current_user_perms == "employee")
    {
        employee_page(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
    }

}
void mark_task_done(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr,string current_user_perms)
{
    int hei = 7;
    for (int i =0; i <taskid_pr; i++)
    {
        gotoxy(0, hei);
        cout << i+1 << ")- ";
        gotoxy(5, hei);
        cout << tasklist_pr[i];
        gotoxy(55, hei);
        if (taskdone_pr[i])
        {
            cout << "done";
        }
        else
        {
            cout << "not done";
        }

        cout << endl;
        hei = hei + 1;
    }
    hei = hei + 1;
    gotoxy(0, hei);
    int temp_int;
    cout <<"Enter task number to mark as done): ";
    cin>>temp_int;
    if (temp_int<= taskid_pr && temp_int > 0)
    {
        taskdone_pr[temp_int-1] = true;
        cout << "Task " << taskid_pr << " marked as done." << endl;
    }
    else
    {
        validation_fail();
    }
    if (current_user_perms == "admin")
    {
        admin_page(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
    }
    else if (current_user_perms == "employee")
    {
        employee_page(task_num,taskdone_pr,tasklist_pr,taskid_pr,current_user_perms);
    }
}
void store_tasks(string tasklist_pr[], bool taskdone_pr[], int taskid_pr)
{
    ofstream outputFile("tasks.txt");

    if (outputFile.is_open())
    {
        for (int i = 0; i < taskid_pr; i++)
        {
            outputFile << tasklist_pr[i] << endl;
            outputFile << taskdone_pr[i] << endl;
        }

        outputFile.close();
    }
}
void load_tasks(string tasklist_pr[], bool taskdone_pr[], int &taskid_pr) 
{
    ifstream inputFile("tasks.txt");

    if (inputFile.is_open())
    {
        // Clear existing tasks before loading
        taskid_pr = 0;
        while (!inputFile.eof())
        {
            getline(inputFile, tasklist_pr[taskid_pr]);
            inputFile >> taskdone_pr[taskid_pr];
            inputFile.ignore(); // Ignore newline character

            taskid_pr++;

            if (taskid_pr >= 20)
            {
                break; // Break if the array is full
            }
        }

        inputFile.close();
    }
}

//validation functions
void validation_fail()
{
    cout <<"invalid input (press any key to continue)"<<endl;
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
void invalid_credentials(string username_database[], string password_database[], string user_perm[], string employee_id)
{
    string option;
    cout << endl;
    cout << "INVALID CREDENTIALS (press y to retry or press n to go back to the login screen)";
    cin >> option;
    if (option == "y")
        sign_in(username_database, password_database, user_perm, employee_id);
    else if (option == "n")
        loginMenu(username_database, password_database, user_perm, employee_id);
    else
    {
        validation_fail();
        invalid_credentials(username_database, password_database, user_perm, employee_id);
    }
}


int main()
{
    system("cls");
    printHeader();
    cout << endl;
    cout << "Press any key to continue: ";
    getch();

    // Sign-in credentials
    const int max_accounts = 10;
    string employee_id;
    string username_database[max_accounts];
    string password_database[max_accounts];
    string user_perm[max_accounts];
    int num_accounts = 0;

    // Tasklist variables
    int task_num = 0;
    bool taskdone_pr[20];
    string tasklist_pr[20];
    int taskid_pr = 0;
    string current_user_perms;

    // Calling ready to initialize variables
    ready(username_database, password_database, user_perm, employee_id, taskdone_pr, tasklist_pr);
    load_accounts(username_database, password_database, user_perm, num_accounts);
    bool loggedIn = false;
    while (!loggedIn)
    {
        // Calling loginMenu, storing the return value
        current_user_perms = loginMenu(username_database,password_database,user_perm,employee_id,num_accounts);

        // Check the user type and display the respective page
        if (current_user_perms == "admin" || current_user_perms == "employee")
        {
            loggedIn = true;
            if (current_user_perms == "admin")
            {
                admin_page(task_num, taskdone_pr, tasklist_pr, taskid_pr, current_user_perms);
            }
            else
            {
                employee_page(username_database,password_database,user_perm,employee_id);
            }
        }
    }


}
