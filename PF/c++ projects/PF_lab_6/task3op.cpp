#include <iostream>
#include <windows.h>
using namespace std;
float perimeter(string ch,float sides);
main ()
{
    string ch;
    float sides,get;
    cout <<"Enter the shape (s for square, c for circle, t for triangle, h for hexagon): ";
    cin >> ch;
    cout<< "Enter the value: ";
    cin >> sides;
    get= perimeter(ch,sides);
    cout<<"The perimeter is: "<< get;
}
float perimeter (string ch,float sides)
{
    float out;
    if (ch=="s")
    {
        out=4*sides;
        return out;
    }
    if(ch=="c")
    {
        out=6.28*sides;
        return out;
    }
    if (ch=="t")
    {
        out=3*sides;
        return out;
    }
    if (ch=="h")
    {
        out=6*sides;
        return out;    
    }
}