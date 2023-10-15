#include<iostream>
using namespace std;
string pricalhot(string month, int staynums);
main(){
    string month;
    int staynums;
    cout<<"Enter the month (May, June, July, August, September, October): ";
    cin>>month;
    cout<<"Enter the number of stays: ";
    cin>>staynums;
    string calculatedAmount= pricalhot ( month, staynums);
    cout<<calculatedAmount;
}
string pricalhot(string month, int staynums){
    float studamu=0;
    float amufrapart=0;
    float amount=0;
    if(month=="May"||month=="October"){
        studamu=amount;
        amufrapart=65;
        amount=50;
    if(staynums>7)
    {
        studamu=amount-amount*0.05;
    }
    if(staynums>14)
    {
        studamu=amount-amount*0.3;
        amufrapart=amufrapart-(amufrapart*0.1);
    }
    studamu=studamu*staynums;
    amufrapart=amufrapart*staynums;
    }
    if(month=="June"||month=="September"){;
        amufrapart=amount;
        amount=75.20;
        int amount4=0;
        amufrapart=68.70;
        float totalamount9=0;
        if(staynums>14){
            studamu=amount-(amount*0.2);
            amufrapart=amufrapart-(amufrapart*0.1);
        }

        studamu=studamu*staynums;
        amufrapart=amufrapart*staynums;
    }
    if(month=="July"||month=="August")
    {
        studamu=amount;
        amount=76;
        amufrapart=77;
        if(staynums>14)
        {
            amufrapart=amufrapart-(amufrapart*0.1);
        }
        studamu=studamu*staynums;
        amufrapart=amufrapart*staynums;

    }

    return"Apartment: "+to_string(amufrapart)+"$.\nStudio: "+to_string(studamu)+"$.";

}

