#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    char num;string num_1;
    file.open("example.txt",ios::out);
    cout << "Enter number";
    cin >> num;
    file <<num;
    file.close();
    file.open("example.txt",ios::in);
    file >>num_1;
    cout << num_1;
    file.close();

}

