#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;

    file.open("example.txt",ios::out);

    file <<"this is sample text";
    file.close();
}