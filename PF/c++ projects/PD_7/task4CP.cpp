#include <iostream>

using namespace std ;

void triangle(int num);

int main()
{
    int num;
    cout << "Enter number of Triangle: ";
    cin >> num ;

    triangle(num);
}

void triangle(int num)
{
    int sum = 0;
    for(int i = 1 ; i <= num ; i ++)
    {
        int x = 1;
        while (x <= i)
        {
            x++;
            sum = sum + 1;
        }
    }
    cout << "Dots in the Triangle: "<< sum;

}