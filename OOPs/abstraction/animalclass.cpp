#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void sound()=0;
};

class Cat:public Animal{
    public:
    void sound(){
        cout<<"animal is cat"<<endl;
    }
};

class Dog:public Animal{
    public:
    void sound(){
        cout<<"animal is dog";
    }
};
int main(){
    Cat c;
    Dog d;
    c.sound();
    d.sound();
}