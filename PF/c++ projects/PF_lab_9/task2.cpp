#include <iostream>
using namespace std;

string reverse(string);

main ()
{
    string word;

    cout << "Enter a string: ";
    cin >> word;

    cout << "Reversed String: " << reverse(word);
}

string reverse(string word)
{
    string result = "";
    for (int i = word.length() - 1; i >= 0 ; i--)
    {
        result = result + word[i];
    }
    return result;
}