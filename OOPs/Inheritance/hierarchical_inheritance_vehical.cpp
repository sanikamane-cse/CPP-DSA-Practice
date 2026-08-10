#include<iostream>
using namespace std;
class Vehical{
    public:
    void show(){
        cout<<"This is vehical"<<endl;
    }
};
class Car:public Vehical{
    public:
    void fourwheels(){
        cout<<"Vehical is car"<<endl;
    }
};
class Bike:public Vehical{
    public:
    void twowheels(){
        cout<<"vehical is bike"<<endl;
    }
};
class Bus:public Vehical{
    public:
    void display(){
        cout<<"vehical is bus"<<endl;
    }
};
int main(){
    Car c;
    Bike b;
    Bus s;
    
    c.show();
    c.fourwheels();

    b.show();
    b.twowheels();

    s.show();
    s.display();

    return 0;
}