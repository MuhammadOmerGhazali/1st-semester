#include <iostream>
using namespace std;

bool isLengthEven(string word);

int main()
{
    string word;
    cout << "Enter a String: ";
    cin >> word;

    cout << isLengthEven(word);
    return 0;
}

bool isLengthEven(string word)
{
    int count = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        count++;
    }

    if (count % 2 == 0)
    {
        return true;
    }
    else {
        return false;
    }
}
