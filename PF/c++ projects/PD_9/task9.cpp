#include <iostream>
using namespace std;

string longestStr(string words[], int size);

int main() {
    int size;
    cout << "Enter the number of words: ";
    cin >> size;

    string words[size];
    cout << "Enter the words, one by one:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> words[i];
    }

    cout << "Longest 7-segment word: " << longestStr(words, size);

    return 0;
}

string longestStr(string words[], int size) {
    int maxLength = 0;
    string longestWord = "";

    for (int i = 0; i < size; i++) 
    {
        bool containsInvalidLetter = false;

        for (int j = 0; j < words[i].length(); j++) 
        {
            char c = words[i][j];
            if (c == 'k' || c == 'm' || c == 'v' || c == 'w' || c == 'x') //if word contain these chars, then ignore the word (meaning ith position).
            {
                containsInvalidLetter = true;
                break;
            }
        }

        if (!containsInvalidLetter && words[i].length() > maxLength) 
        {
            maxLength = words[i].length();
            longestWord = words[i];
        }
    }

    return longestWord;
}
