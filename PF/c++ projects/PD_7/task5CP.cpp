#include <iostream>

using namespace std ;

bool is_prime(int num);

int main()
{
    int num ;
    
    cout << "Enter Number: ";
    cin >> num;

    cout << is_prime(num);

}

bool is_prime(int num)
{
    int n = 1;
    int Pnum = 0;
    if (num == 2 || num == 3 || num ==5 || num ==7 || num == 11 || num == 13 || num == 19 || num == 17)
        return true;
    while (Pnum < 40)
    {
        Pnum = 6 * n + 1;
         if (Pnum == num)
         {
             return true;
         }
        n++;
    }
    n = 1;
    Pnum = 0;
    while (Pnum < 40)
    {
        Pnum = 6 * n - 1;
         if (Pnum == num)
         {
             return true;
         }
        n++;
    }
    return false; 
}