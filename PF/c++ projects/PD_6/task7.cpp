#include <iostream>
using namespace std;
string timecheck(int ehours, int emins, int shours, int smins);
main(){
    int ehours,emins,shours,smins;
    cout<<"Enter Exam Starting Time (hour): ";
    cin>>ehours;
    cout<<"Enter Exam Starting Time (minutes): ";
    cin>>emins;
    cout<<"Enter Student hour of arrival: ";
    cin>>shours;
    cout<<"Enter Student minutes of arrival: ";
    cin>>smins;
    string final= timecheck(ehours,emins, shours, smins);
    cout<<final;

}
string timecheck(int ehours, int emins, int shours, int smins){
    float minsdifference1=0;
    string cout1="empty";
    int etimeinmins=(ehours*60)+emins;
    int stimeinmins=(shours*60)+smins;
    int minsdiff=(etimeinmins-stimeinmins);
    int empty1=0;
    int hourformat=(minsdiff/60);
    int minformat=(minsdiff%60);
    int minsdifffrlate=(-minsdiff);
    int hourformatfrlate=(minsdifffrlate/60);
    int minsformatfrlate=(minsdifffrlate%60);
    float minsdifference2=0;
    int check=0;
    if (minsdiff<0)
        {
            cout<<"Late"<<endl;
            cout<<"Test: "<<minsdifffrlate<<endl;
        if (minsdifffrlate<60)
        {
            cout1=to_string(minsdifffrlate)+" minutes after the start";
            return cout1;}
        if(minsdifffrlate>=60){
            cout1=to_string(hourformatfrlate)+":"+to_string(minsformatfrlate)+" hours after the start";
            return cout1;}  
        }
    if (minsdiff>30)
        {
            cout<<"Early"<<endl;
            cout<<"Test: "<<minsdiff<<endl;
            if (minsdiff<60)
            {
                cout1=to_string(minsdiff)+" minutes before the start";
                return cout1;
            }
            if(minsdiff>=60)
            {
                cout1=to_string(hourformat)+":"+to_string(minformat)+" hours before the start";
                return cout1;
            }  
        }
    if (minsdiff>0 && minsdiff<31)
    {
        cout<<"On time"<<endl;
        cout<<"Test: "<<minsdiff<<endl;
        cout1=to_string(minsdiff)+" minutes before the start";
        return cout1;
    }
    if (etimeinmins=stimeinmins)
    { 
        return "On time";
    }
    return cout1;
}




