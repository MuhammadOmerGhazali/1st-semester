#include <iostream>

using namespace std ;

int progress_days (int size );

int main()
{
    int size;
    cout << "Enter the number of Saturdays: ";
    cin >>size;

    cout << "Total progress days: " << progress_days(size);
}

int progress_days (int size )
{
    int miles[size] , progres_day = 0 , milerun1= 0,milerun2= 0;
    for (int x = 1 ; x<= size ; x++)
    {
        cout << "Enter miles run for Saturday "<< x <<": " ;
        cin >> miles[x-1];
    }

    for (int x = 0 ; x<= size-2 ; x++)
    {
        if (miles[x]<miles[x+1])
            progres_day = progres_day + 1;
    }
    return progres_day;
}