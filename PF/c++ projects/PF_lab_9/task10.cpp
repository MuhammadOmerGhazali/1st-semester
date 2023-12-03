#include <iostream>
using namespace std;

int main()
{
    string argument;

    cout << "Enter the argument 'a': ";
    getline(cin, argument);

    cout << "Result: something " << argument;
}