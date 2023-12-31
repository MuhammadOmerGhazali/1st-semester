#include <iostream>

using namespace std;

void generateFibonacci(int length);

int main()
{

    int length;

    cout << "Enter the length of the Fibonacci series: ";
    cin >> length;

    generateFibonacci(length) ;

}

void generateFibonacci(int length)
{
    int t1 = 0, t2 = 1, nextTerm = 0;

    for (int i = 1; i <= length; ++i) 
    {

        if(i == 1) 
        {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) 
        {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        if ( i == length)
            cout << nextTerm;    
        else
            cout << nextTerm << ", ";
    }
}