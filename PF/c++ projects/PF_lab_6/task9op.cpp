#include <iostream>
#include <windows.h>
using namespace std;
string title(int age,char gender);
main ()
{
    int age;
    char gender;
    string get;
    cout<<"Enter your age: ";
    cin >> age;
    cout<<"Enter your gender (m/f): ";
    cin >> gender;
    get=title(age,gender);
    cout<<"Your personal title is: "<<get;
}
string title(int age,char gender)
{
    if (age>=16 && gender=='m')
    {
        return "Mr.";
    }
    if (age<16 && gender=='m')
    {
        return "Master";
    }
    if (age>=16 && gender=='f')
    {
        return "Ms.";
    }
    if (age<16 && gender=='f')
    {
        return "Miss";
    }
}