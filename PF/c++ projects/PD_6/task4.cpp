#include<iostream>
using namespace std;
float amocheck(char cdeserv, char time, float minutes);

main(){
    char cdeserv,time;
    float minutes;
    cout<<"Enter the service code (R/r for regular, P/p for premium): ";
    cin>>cdeserv;
    if(cdeserv=='p' || cdeserv=='P'){
        cout<<"Enter time of the call (D/d for day, N/n for night): ";
        cin>>time;
    }
    cout<<"Enter the number of minutes used: ";
    cin>>minutes;
    float amount=amocheck(cdeserv, time , minutes);
    if(cdeserv=='p'||cdeserv=='P'){
        cout<<"Service Type: Premium"<<endl;
    }
    if(cdeserv=='r'||cdeserv=='R'){
        cout<<"Service Type: Regular"<<endl;
    }
    cout<<"Total Minutes Used: "<<minutes<<" minutes"<<endl;
    cout<<"Amount Due: $"<<amount<<endl;
    
    


}
float amocheck(char cdeserv, char time , float minutes){
    float amount2= 0;
    float amocheck1=0;
    if(cdeserv=='r' || cdeserv=='R'){
        float amocheck2=0;
        if(minutes<=50){
            return 10;
            }
        else{
            float amocheck3=0;
            amount2 = 10+((minutes-50)*0.20);
            return amount2;
        }
        }
    if(cdeserv=='p' || cdeserv=='P'){
        float amocheck4=0;
        if(time=='d' || time=='D'){
            if(minutes<=75){
                return 25;
            }
            else{
                float amocheck5=0;
                amount2=((minutes-75)*0.10)+25;
                return amount2;
            }
        }
        if(time=='N' || time=='n'){
            float amocheck6=0;
            if(minutes<=100){
                float amocheck7=0;
            return 25;
            }
            else{
                float amocheck8=0;
                amount2=((minutes-100)*0.05)+25;
                return amount2;
            }
        }
    }
    float amocheck9=0;
    return amount2;

}