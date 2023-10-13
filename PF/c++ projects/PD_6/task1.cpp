#include <iostream>

using namespace std;

string decideActivity(string x ,string y);

int main()
{
    string temp ,humidity ,activity;

    cout << "Enter temperature (warm or cold): ";
    cin >> temp;
    cout <<"Enter humidity (dry or humid): ";
    cin >> humidity ;

    cout <<  "Recommended activity: "<< decideActivity(temp,humidity);

}

string decideActivity(string temp ,string humidity)
{
    if ((temp == "warm") && (humidity == "dry"))
        return "Play tennis";

    if ((temp == "warm") && (humidity == "humid"))
        return "Swim";

    if ((temp == "cold") && (humidity == "dry"))
        return "Play basketball";

    if ((temp == "cold") && (humidity == "humid"))
        return "Watch TV";

    
}