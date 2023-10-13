#include <iostream>
using namespace std;

float pyraVol (float x ,float y, float z,string u);

int main()
{
    float length , width ,height ;
    string unit;

    cout <<"Enter the length of the pyramid (in meters): ";
    cin >> length ;
    cout <<"Enter the width of the pyramid (in meters): ";
    cin >> width ;
    cout <<"Enter the height of the pyramid (in meters): ";
    cin >> height ;
    cout <<"Enter the desired output unit (millimeters, centimeters, meters ,kilometers): ";
    cin >> unit ;

    pyraVol (length , width ,height ,unit);

}

float pyraVol (float length ,float width, float height,string unit)
{
    float volume ;
    
    volume = (length*width*height)/3;

    if (unit == "centimeters")
        {
            volume = volume * 1000000;

            cout <<"The volume of the pyramid is: "<< volume <<" cubic "<< unit;

        } 
    if (unit == "millimeters")
        {
            volume = volume * 1000000000;

            cout <<"The volume of the pyramid is: "<< volume <<" cubic "<< unit;
            
        } 
        
    if (unit == "kilometers")
        {
            volume = volume*0.000000001;

            cout <<"The volume of the pyramid is: "<< volume <<" cubic "<< unit;
            
        } 
    if (unit == "meters")
        {

            cout <<"The volume of the pyramid is: "<< volume <<" cubic "<< unit;
            
        } 

}