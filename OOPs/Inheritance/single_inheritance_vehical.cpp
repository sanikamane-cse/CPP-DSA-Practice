#include<iostream>
using namespace std;
class Vehical{
    public:
    void start(){
        cout<<"This is vehical"<<endl;
    }
    void stop(){
        cout<<"vehical is stopped"<<endl;
    }
};
class Car:public Vehical{
    public:
    void drive(){
        cout<<"This vehical is car "<<endl;
    }
};
int main(){
    Car c;
    c.start();
    c.stop();
    c.drive();
    return 0;
}