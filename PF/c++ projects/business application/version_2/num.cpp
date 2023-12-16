// #include <iostream>
// #include <conio.h>
// #include <string>
// using namespace std;

// int main()
// {
//     string input_string;
//     string output_string = "";
//     cin >> input_string;

//     int x = 0,y=0;
//     while (input_string[x] != '\0' )
//     {
//         if(isdigit(input_string[x]))
//         {
//             output_string[y] = input_string[x];
//             cout<<output_string[y]<<endl;
//             y=y+1;
//         }
//         x=x+1;

//     }
//     cout << "output string is: "<<output_string;
// }

#include <iostream>
#include <string>

using namespace std;

int string_to_int(string input_string)
{

    int result = 0;

    for (char ch : input_string) 
    {
        if (isdigit(ch)) 
        {
            result = result * 10 + (ch - '0');
        }
    }

    return result;
}


