#include<iostream>
using namespace std;
class Car{
    public:
    string name;
    int price;

};
int main(){
    Car c1,c2;

    c1.name="BMW";
    c1.price=10000000;

    c2.name="Ertiga";
    c2.price=500000;

    cout<<"Brand name:"<<c1.name<<endl;
    cout<<"Price:"<<c1.price<<endl;

    cout<<endl;
    
    cout<<"Brand name:"<<c2.name<<endl;
    cout<<"Price:"<<c2.price<<endl;

    return 0;

}