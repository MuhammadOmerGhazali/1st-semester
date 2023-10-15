#include <iostream>
using namespace std;
string pointposcheck(int x,int y,int height);
main(){
    int height;
    cout<<"Enter the height: ";
    cin>>height;
    int x;
    cout<<"Enter the x coordinates: ";
    cin>>x;
    int y;
    cout<<"Enter the y coordinates: ";
    cin>>y;
    string final=pointposcheck(x,y,height);
    cout<<final;
}
string pointposcheck(int x,int y,int height){
char check;
int check1=0;
bool bordercheck1=(x == height && y >= height);
bool bordercheck2=( y <= 3 * height);
bool bordercheck3=(x >= 0 && x <= 3 * height);
bool bordercheck4=(y == 0 || y == height);
bool bordercheck5=(y >= 0 && y <= 4 * height);
bool bordercheck6=(x == 0 || x == 2 * height);
bool borderchecksemi1=(bordercheck1 && bordercheck2);
bool borderchecksemi2=(bordercheck3 && (bordercheck4));
bool borderchecksemi3=(bordercheck5 && (bordercheck6));
if(borderchecksemi1 || borderchecksemi2 || borderchecksemi3)
{
    check ='b';             
    return "Border";
}
else if(x > 0 && x < 2 * height && y > 0 && y < 4 * height)
{
    check = 'i';
    return "Inside";
                                        
}
else
{
    return "Outside";
}
}
        
    




