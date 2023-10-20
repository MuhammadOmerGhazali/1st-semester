#include <iostream>

using namespace std ;

void print_aster(int rows);

int main()
{
    int rows = 0;
    cout << "Enter desired number of rows: ";
    cin >> rows;

    print_aster(rows);
}

void print_aster(int rows)
{
    for(int i = rows ; i >= 1 ; i--)
    {
        int x = 1;
        while (x <= i)
        {
            cout << "*";
            x++;
        }
        cout << endl;
    }
}
