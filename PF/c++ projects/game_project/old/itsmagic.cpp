#include <iostream>
#include <windows.h>
using namespace std;

// void generateCharacters();
void generateColors();

main()
{
  // char squar = 254;
  // cout <<squar;
  // generateCharacters();
  generateColors();
}

// void generateCharacters()
// {
//   char character;
//   for (int x = 0; x < 256; x++)
//   {
//     // pick the characters combinations to make your players and enemies
//     character = x;
//     cout << x << " " << character << "\t";
//     if (x%4==0)
//     {
//       cout<<endl<<endl;
//     }
    
//   }
// }

void generateColors()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  for (int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " Learning is never done without errors and defeat!" << endl;
  }
}

// #include <iostream>
// #include <windows.h>  // For Windows API functions

// void playSound(int frequency, int duration) {
//     Beep(frequency, duration);
// }

// int main() {
//     // Sci-fi soundtrack frequencies
//     int frequencies[] = {500, 600, 700, 800, 900};

//     // Loop for a simple sci-fi soundtrack
//     for (int i = 0; i < 10; ++i) {
//         for (int j = 0; j < 5; ++j) {
//             playSound(frequencies[j], 200);
//         }
//     }

//     return 0;
// }
