#include <iostream>
using namespace std;

string nextLetter(string word);

main()
{
    string word;

    cout << "Enter a String: ";
    getline(cin, word);

    cout << "Shifted String: " << nextLetter(word);

}

string nextLetter(string word)
{
    string result = "";

    for (int i = 0; word[i] != '\0'; i++)
    {
        int asciiCode = word[i];
        if(word[i] == ' ')
        {
            asciiCode = word[i];
        }
        else {
        asciiCode += 1;
        }
        if(word[i] == 'z')
        {
            asciiCode = 'a';
        }
        else if(word[i] == 'Z')
        {
            asciiCode = 'A';
        }

        //convert ascii code to character
        char newChar = static_cast<char>(asciiCode);

        result += newChar;
    }
    return result;
}

