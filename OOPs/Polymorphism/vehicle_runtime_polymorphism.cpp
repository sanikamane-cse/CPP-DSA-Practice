#include<iostream>
using namespace std;
class Vehicle{
    public:
    virtual void start(){
        cout<<"Vehicle start"<<endl;
    }
};
class Car:public Vehicle{
    public:
    void start()override{
        cout<<"Car start"<<endl;
    }
};
class Bike:public Vehicle{
    public:
    void start()override{
        cout<<"Bike start"<<endl;
    }

};
int main(){
Vehicle *ptr;
Car c;
Bike b;

ptr=&c;
ptr->start();

ptr=&b;
ptr->start();

return 0;

}

