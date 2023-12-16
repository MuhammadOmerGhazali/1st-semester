#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

// General use functions
int ascii_to_int(string x);
string get_string_input();
void gotoxy(int x, int y);

// Program functions
void ready(string x[], string y[], string z[], string employee_id, bool taskdone_pr[], string tasklist_pr[]);
void printHeader();

// Login functions
string loginMenu(string username_database[], string password_database[], string user_perm[], string employee_id);
string loginInput(string username_database[], string password_database[], string user_perm[], string employee_id);
string sign_in(string username_database[], string password_database[], string user_perm[], string employee_id);
void sign_up(string username_database[], string password_database[], string user_perm[], string employee_id);
bool is_employee_id_exists(const string& employee_id);
void load_accounts(string username_database[], string password_database[], string user_perm[], int& num_accounts);
void invalid_credentials(string username_database[], string password_database[], string user_perm[], string employee_id);

// User front page
void admin_page(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr, string current_user_perms);
void employee_page(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr, string current_user_perms);

// Tasklist
void add_tasks(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr, string current_user_perms);
void remove_task(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int& taskid_pr, string current_user_perms);
void view_task(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr, string current_user_perms);
void mark_task_done(int task_num, bool taskdone_pr[20], string tasklist_pr[20], int taskid_pr, string current_user_perms);
void store_tasks(string tasklist_pr[], bool taskdone_pr[], int taskid_pr);
void load_tasks(string tasklist_pr[], bool taskdone_pr[], int& taskid_pr);
void store_accounts(string username_database[], string password_database[], string user_perm[], int num_accounts);
void load_accounts(string username_database[], string password_database[], string user_perm[], int& num_accounts);

// Validation functions
void validation_fail();
bool login_Input_validation(string option);
bool sign_up_validation(string option);

int main()
{
    // ... (remaining code)

    // Sign-in credentials
    const int max_accounts = 10;
    string employee_id;
    string username_database[max_accounts];
    string password_database[max_accounts];
    string user_perm[max_accounts];
    int num_accounts = 0; // Track the number of accounts

    // ... (remaining code)

    // Load existing accounts
    load_accounts(username_database, password_database, user_perm, num_accounts);

    bool loggedIn = false;
    while (!loggedIn)
    {
        // ... (remaining code)
    }

    return 0;
}

// ... (remaining code)

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

void store_accounts(string username_database[], string password_database[], string user_perm[], int num_accounts)
{
    ofstream outputFile("accounts.txt");

    if (outputFile.is_open())
    {
        for (int i = 0; i < num_accounts; i++)
        {
            outputFile << username_database[i] << " " << password_database[i] << " " << user_perm[i] << endl;
        }

        outputFile.close();
    }
}


void load_accounts(string username_database[], string password_database[], string user_perm[], int& num_accounts)
{
    ifstream inputFile("accounts.txt");

    if (inputFile.is_open())
    {
        // Clear existing accounts before loading
        num_accounts = 0;
        while (!inputFile.eof())
        {
            inputFile >> username_database[num_accounts] >> password_database[num_accounts] >> user_perm[num_accounts];
            inputFile.ignore(); // Ignore newline character

            num_accounts++;

            if (num_accounts >= 10)
            {
                break; // Break if the array is full
            }
        }

        inputFile.close();
    }
}
