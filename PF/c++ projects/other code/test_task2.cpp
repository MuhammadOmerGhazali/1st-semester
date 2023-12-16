#include <iostream>

using namespace std ;

int main()
{
    int array[7];
    for(int x = 0 ;x < 7;x++)
    {
        array[x] = (x +1)*10;
    }
    
    for(int x = 0 ;x < 7;x++)
    {
        cout << *(array+x)<<endl;
    }
}