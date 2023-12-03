#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
int usertype,adminp;

string task1,task2,task3;
void header();
void homescreeninterface(int usertype);
void adminpage();
void tasklist();
void addingtasks();

int ending=0;

main(){
    header();
    homescreeninterface(usertype);

    if( ending == 0){
        adminpage();
    }


}
void header(){
    system ("cls");
    cout<<"============================================================================================================================="<<endl;
    cout<<"|************************************************Game studio managment system***********************************************|"<<endl;
    cout<<"============================================================================================================================="<<endl;
    
    
}
void tasklist(){
    system ("cls");
    cout<<"==========================================================================================================================="<<endl;
    cout<<"task No.  \tTask Name"<< endl;
    cout<<"1         \t"<<task1<<endl;
    cout<<"2         \t"<<task2<<endl;
    cout<<"3         \t"<<task3<<endl;
    cout<<"==========================================================================================================================="<<endl;
    cout<<"Press any key to continue";
    getch();
    return ;
}
void addingtasks(){

        cout<<"Enter first task Name: ";
        cin>>task1;
      
        cout<<"Enter Second task Name: ";
        cin>>task2;
        
        cout<<"Enter Third task Name: ";
        cin>>task3;


       tasklist();
       }
       

void adminpage(){
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|| A  D  M  I  N   P   A   G    E ||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||For Adding tasks ------>Enter 1.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||For Task List    ------>Enter 2.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||For Previous Menu------>Enter 0.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cin>>adminp;
     if (adminp==0){
        system ("cls");
        return homescreeninterface(usertype);
    }
    if(adminp==1){
        addingtasks();
    }
    if(adminp==2){
        tasklist();
    }
   
    }


void homescreeninterface(int usertype){
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||M     E      N      U||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||For USER---->Enter 1.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||For ADMIN--->Enter 2.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx||For Exiting->Enter 0.||xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cin>>usertype;
    if(usertype==1){
        system("cls");
        return homescreeninterface(usertype);
    }
    if(usertype==2){
        system("cls");
        adminpage();
    }
    if(usertype==0){
        system("cls");
        cout<<"Thanks ."<<endl;
        ending = 1;
    }
    
}