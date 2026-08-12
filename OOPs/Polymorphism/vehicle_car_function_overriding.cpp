#include<iostream>
using namespace std;

class Vehical{

    public:

    virtual void start(){
        cout<<"Vehical start"<<endl;
    }
};

class Car:public Vehical{

    public:

    void start()override{
        cout<<"This vehical is car";
    }
};

int main(){

    Car c;

    c.start();
    
    return 0;
}