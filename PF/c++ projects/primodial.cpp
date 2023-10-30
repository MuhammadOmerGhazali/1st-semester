#include <iostream>
using namespace std;
int primorial(int number);
bool prime(int number);
int main()
{
    int number ;
    cout <<"Enter number:";
    cin >> number ;
    primorial(number);
}
int primorial(int number)
{
    int value;
    value = 0;
    int result;
    result = 0;
    int answer;
    answer = 1;
    int x = 1;
    while(value==number)
    {
       result = prime(x);
       if(result==true)
       {
        answer = answer * x;
        value++;
        x++;
       }
       else 
       {
        x++;
       }

    }
    cout<<answer;
}

bool prime(int number)
{
    bool ans;
    ans = false;
    int value = 0;
    for(int x= 1; x<=number; x++)
    
{
    
        if(number%x==0)
        {
            value = value +1;
        }
}
    if(value == 2)
    {
        ans = true;
        return ans;
    }
    
}