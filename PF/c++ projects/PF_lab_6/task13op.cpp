#include <iostream>
using namespace std;
float lowestprice(int dis,string time);

main()
{
    int dis;
    string time;
    float answer;
    cout << "Enter the number of kilometers: ";
    cin >> dis;
    cout << "Enter the period of the day (day/night): ";
    cin >> time;
    answer = lowestprice( dis, time);
    cout << "Lowest price for " << dis << " kilometers: " << answer << " EUR";

}

float lowestprice(int dis,string time)
{
    float bus,taxi,train;
    float final;
    if (dis <20 && time == "day")
    {
        final = 0.70 + (dis * 0.79);
    }
    if (dis <20 && time == "night")
    {
        final = 0.70 + (dis * 0.90);
    }
    if (dis >= 20 )
    {
        final = dis * 0.09;
    }
    if (dis >= 100)
    {
        final = dis * 0.06;
    }
    return final;
}