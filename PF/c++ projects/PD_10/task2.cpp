#include <iostream>

using namespace std;

void check_char(int size) ;

int main()
{
    int size;
    cout <<"Enter how many words you want to enter: ";
    cin >> size;

    check_char(size);
}

void check_char(int size)
{
    char cha;
    string words[size];
    string word;

      for (int x = 1;x <= size ;x++ )
    {
        cout <<"Enter word 1: ";
        cin >> words[x-1];
    }

    cout <<"Enter the letter you want to count: ";
    cin >> cha;
    int i = 0,letter = 0;
    for (int x=0 ; x<size; x++)
    {
        word = words[x];
        while(word[i] != '\0')
        {
            cout <<words[x] [i];
            if (words[x] [i] == cha)
            {
                letter = letter + 1;
            }
            i++;
        }
    }

    cout << cha <<" shows up "<<letter<<" times in th data.";



}

