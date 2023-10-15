#include<iostream>
using namespace std;
float frucalprice(string fruit, string weekday, double amount);
main(){
    string fruit,weekday;
    cout<<"Enter the fruit name: ";
    cin>>fruit;
    cout<<"Enter the day of the week (e.g., Monday, Sunday): ";
    cin>>weekday;
    double amount;
    cout<<"Enter the quantity; ";
    cin>>amount;
        if ((fruit!="apple"&&fruit!="kiwi"&&fruit!="pineapple"&&fruit!="banana"&&fruit!="grapesfruit"&&fruit!="grapes"&fruit!="orange") || (weekday!="Monday"&&weekday!="Tuesday"&&weekday!="Wednesday"&&weekday!="Thursday"&&weekday!="Friday"&&weekday!="Saturday"&&weekday!="Sunday"))
            {
                cout<<"error";
            }
        else{
        cout<<frucalprice(fruit,weekday,amount);
            }

}
float frucalprice(string fruit, string weekday, double amount){
    int fruitprice1=0;
    double price=0;
    if (weekday=="Monday"||weekday=="Tuesday"||weekday=="Wednesday"||weekday=="Thursday"||weekday=="Friday")
    { 
        if (fruit=="apple"){
                            int fruitprice2=0;
                            price=1.20*amount;
                            return price;
                                            }
        if (fruit=="orange"){
                            int fruitprice3=0;
                            price=0.85*amount;
                            return price;
                                            }
        if (fruit=="banana"){
                            int fruitprice4=0;
                            price=2.50*amount;
                            return price;
                                            }
        if (fruit=="pineapple"){
                            int fruitprice5=0;
                            price=5.50*amount;
                            return price;
                                            }
        if (fruit=="grapefruit"){
                            int fruitprice6=0;
                            price=1.45*amount;
                            return price;
                                            }
        if (fruit=="grapes"){
                            int fruitprice7=0;
                            price=3.85*amount;
                            return price;
                                            }
        if (fruit=="kiwi"){
                            int fruitprice8=0;
                            price=2.70*amount;
                            return price;
                                            }
    }
        else {
            if (fruit=="apple"){
                                int fruitprice9=0;
                                price=1.25*amount;
                                return price;
                                                }
            if (fruit=="orange"){
                                int fruitprice10=0;
                                price=0.90*amount;
                                return price;
                                                }
            if (fruit=="banana"){
                                int fruitprice11=0;
                                price=2.70*amount;
                                return price;
                                                }
            if (fruit=="pineapple"){
                                int fruitprice12=0;
                                price=5.60*amount;
                                return price;
                                                }
            if (fruit=="grapefruit"){
                                int fruitprice13=0;
                                price=1.60*amount;
                                return price;
                                                }
            if (fruit=="grapes"){
                                int fruitprice14=0;
                                price=4.20*amount;
                                return price;
                                                }
            if (fruit=="kiwi"){
                                int fruitprice15=0;
                                price=3.00*amount;
                                return price;
                                                }
    }
    int fruitprice0=0;
    return price;
}




