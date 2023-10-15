#include<iostream>
using namespace std;
int volybalgamecal(int leave,int weekend,string yearType);
main(){
    string year;
    cout<<"Enter year type: ";
    cin>>year;
    int leave,weekend;
    cout<<"Enter number of holidays: ";
    cin>>leave;
    cout<<"Enter number of weekends: ";
    cin>>weekend;
    int final=volybalgamecal(leave,weekend,year);
    cout<<final;
}
int volybalgamecal(int leave,int weekend,string year){
    int call1=0;
    int number=0;
    int total;
    leave=leave*0.67;
    weekend=weekend*0.75;
    total=leave+weekend;
        if (year=="normal"){
            number=48-(48*0.15);
            number=number+total;
            number=number-(number*0.15);
        if(number>=44){
            number=number+1;
                            }
        else{
            number=number+2;
                            }
                            }
        else{
            number=48-(48*0.15);
            number=number+total+1;
        }
            return number;
}
