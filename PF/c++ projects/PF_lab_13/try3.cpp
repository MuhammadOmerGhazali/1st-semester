#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line;
    fstream file;
    file.open("example.txt",ios::in);
        cout << "stuff in file is :- "<<endl;
    while(!file.eof())
    {
        getline(file,line);
        cout << line<<endl;
        
    }
    file.close();
}