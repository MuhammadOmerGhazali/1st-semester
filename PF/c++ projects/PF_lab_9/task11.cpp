#include <iostream>
using namespace std;

main()
{
    string sentence, result;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    cout << "Enter a string: ";
    getline(cin, sentence);

    for (int i = 0; i < sentence.length(); i++)
    {
        bool isVowel = false;
        for (int j = 0; j < 5; j++)
        {
            if (sentence[i] == vowels[j])
            {
                isVowel = true;
                break;
            }
        }

        if (!isVowel)
        {
            result += sentence[i];
        }
    }

    cout << "String with vowels removed: " << result;
}