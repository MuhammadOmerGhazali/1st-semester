#include <iostream>

using namespace std ;

int main()
{
    system ("cls");
    int array[11];
    int temp_var1,temp_var2,i=0;
    for (int x = 0 ; x < 11 ; x++)
    {
        array[x]=x;
    }
    bool contine = true,contin2;
    while(contine)
    {
        for (int x = 1 ; x < 11 ; x++)
        {
            
            if (((array[x+i] % 2) != 0)&&((array[x+i+1] % 2) == 0))
            {
                temp_var1 = array[x+i];
                array[x+i] = array [x+i+1];
                array[x+i+1] = temp_var1;
            }

        }

        if(((array[0] % 2) == 0)&&((array[1] % 2) == 0)&&((array[2] % 2) == 0)&&((array[3] % 2) == 0)&&((array[4] % 2) == 0)&&((array[5] % 2) == 0))
        {
            contine = false;
        }
    }
    cout <<"Now the separated array is :- "<<endl;
    for (int x = 0 ; x < 11 ; x++)
    {
        cout << array[x]<<endl;
    }
    
}