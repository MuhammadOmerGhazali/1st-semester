#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//ready functions
void ready(string x[],string y[],string z[],string employee_id,bool taskdone_pr[]);
void printHeader();

//login functions
string loginInput();
void loginMenu();
void sign_in(string x[],string y[],string z[],string employee_id);
void sign_up(string x[],string y[],string z[],string employee_id);

//other functions
int conv_ascii(string x);



int main()
{
    //sign in creditionals
    string employee_id;
    string username_database[10];
    string password_database[10];
    string user_perm[10];

    //tasklist variables
    bool taskdone_pr[20];
    string tasklist_pr[20];
    int taskid_pr = 0;



    // ready function initializes variables and creates the admin sign in creditionals
    ready(username_database[],password_database[],user_perm[],employee_id,taskdone_pr[]);

    //login menu redirects to required login menu
    loginMenu();


}



void ready(string username_database[],string password_database[],string user_perm[],string employee_id,bool taskdone_pr[])
{
    system ( "cls" );
    printHeader();
    cout << endl;
    cout <<"press any key to continue :-";
    getch();

    // for (int x =0 ;x <= 10 ;x++)
    // {
    //     username_database[x] = "0";
    //     password_database[x] = "0";
    // }
 
    username_database[0] = "admin";
    password_database[0] = "admin";
    user_perm[0] = "admin";
    employee_id = "0";

    system ( "cls" );
}

string loginInput()
{
    string option;
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
    return option;
}
void loginMenu()
{
    string option;
    option = loginInput();
    if (option == "1")
    {    
        sign_in();
    }

    else if (option =="2")
    {
        sign_up();
    }
    else if (option =="3")
    {
        main();
    }
    else
    {
        cout <<"INVALID OPTION (press any key to continue)";
        loginMenu();
    }
}

void printHeader()
{
cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" <<endl;
cout << "|***********************************************************************************************************************************|" <<endl;
cout << "|******************************************** Game studio management system ********************************************************|" <<endl;
cout << "|***********************************************************************************************************************************|" <<endl;
cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" <<endl;
}


void sign_in(string username_database[],string password_database[],string user_perm[],string employee_id,)
{
    string entered_username,entered_password;
    string entered_employee_id;
    string option;

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
    if ((entered_username == username_database[employee_id]) && (entered_password == password_database[employee_id]))
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
        if (option == "y")
            sign_in(username_database,password_database,user_perm,employee_id);
        if (option == "n")
            loginMenu();
        
    }
}

void sign_up(string username_database[],string password_database[],string user_perm[],string employee_id,)
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


int conv_ascii(string string)
{
    int x = 0;
    while (string[x] !='\0')
    {
        
        x++;
    }

}