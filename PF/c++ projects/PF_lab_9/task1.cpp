#include <iostream>
using namespace std;

void position(string word);

main()
{
    string word;

    cout << "Enter a word: ";
    cin >> word;

    position(word);
}

void position(string word)
{
    for (int i = 0; i < word[i] != '\0'; i++)
    {
        cout << word[i] << " found at position " << i << endl;
    }
}