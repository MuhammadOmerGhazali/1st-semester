#include <iostream>
using namespace std;

string findBrokenKeys(string correctPhrase, string
actualTyped);

int main()
{
    string correctPhrase, actualTyped;

    cout << "Enter the correct phrase: ";
    getline(cin, correctPhrase);

    cout << "Enter what you actually typed: ";
    getline(cin, actualTyped);

    cout << "Broken keys: " << findBrokenKeys(correctPhrase, actualTyped);
    return 0;
}

string findBrokenKeys(string correctPhrase, string actualTyped)
{
    string result = "";

    for (int i = 0; i < correctPhrase.length(); i++) {
        if (correctPhrase[i] != actualTyped[i]) {
            bool found = false;
            
            for (int j = 0; j < result.length(); j++) {
                if (correctPhrase[i] == result[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                result += correctPhrase[i];
            }
        }
    }
    return result;
}
