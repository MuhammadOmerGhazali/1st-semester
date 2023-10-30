#include <iostream>

using namespace std ;

void print_aster(int rows);

int main()
{
    int rows = 0;
    cout << "Enter desired number of rows: ";
    cin >> rows;
    rows = rows/2;
    print_aster(rows);
}

void print_aster(int rows)
{
    for (int i = (rows-1) ; i >= 1 ; i--)
    {
        int x = 1;
        while (x <= 1)
        {
            cout << "-";
            x++;
        }
        for(int z = rows ; z >= 1 ; z--)
         {
             int y = 1;
             while (y <= z)
             {
                 cout << "*";
                 y++;
             }
             cout << endl;
         }
    }
}

// for(int i = rows ; i >= 1 ; i--)
//     {
//         int x = 1;
//         while (x <= i)
//         {
//             cout << "-";
//             x++;

//             for(int z = rows ; z >= 1 ; z--)
//         {
//             int y = 1;
//             while (y <= z)
//             {
//                 cout << "*";
//                 y++;
//             }
//             cout << endl;
//         }
//         }
        
//     for(int i = 1 ; i <= rows ; i++)
//     {
//         int x = 1;
//         while (x <= i)
//         {
//             cout << "-";
//             x++;
//         }
//         for(int z = 1 ; z <= rows ; z++)
//             {
//                 int y = 1;
//                 while (y <= z)
//                 {
//                     cout << "*";
//                     y++;
//                 }
//                 cout << endl;
//             }
//     }

    
