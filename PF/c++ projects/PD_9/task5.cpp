#include <iostream>
using namespace std;

int common(string, string);

main()
{
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    cout << "Number of common characters: " << common(str1, str2);

    return 0;
}

int common(string str1, string str2)
{
    int count = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
        {
            if (str1[i] == str2[j])
            {
                count++;
                str2[j] = '!';
                break;
            }
        }
    }

    return count;
}
