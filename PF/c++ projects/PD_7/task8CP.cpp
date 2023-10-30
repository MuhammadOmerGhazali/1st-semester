#include <iostream>
#include<iomanip>

using namespace std ;

void cargo(int num);

int main()
{
    int num;
    
    cout << "Enter the count of cargo for transportation: ";
    cin >> num;

    cargo(num);
}

void cargo(int num)
{
    float tonnage,price,minibus=0,truck =0,train = 0,sum =0,minibus_p,truck_p,train_p,avg_p;
    for (int i = 1; i <= num; i++)
    {
        cout <<"Enter the tonnage of cargo "<<i<<": ";
        cin >> tonnage;

        if (tonnage <= 3)
        {
            minibus = minibus + tonnage;
        }
        else if (tonnage >3 && tonnage <= 11)
        {
            truck = truck + tonnage;
        }
        else if (tonnage > 11)
        {
            train = train + tonnage ;
        }

        

    }
        sum = minibus + train + truck;
        minibus_p = (minibus/sum)*100;
        truck_p = (truck/sum)*100;
        train_p = (train/sum)*100;

        avg_p = ((minibus*200)+(truck *175)+(train*120))/sum;

        cout  << fixed <<setprecision(2) <<avg_p<<endl;
        cout  << fixed << setprecision(2) <<minibus_p<<"%"<<endl;
        cout  << fixed << setprecision(2) <<truck_p<<"%"<<endl;
        cout  << fixed << setprecision(2) <<train_p<<"%"<<endl;



}