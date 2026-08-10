#include<iostream>
using namespace std;
class Animal{
    public:
    void eat(){
        cout<<"Animal is eatting"<<endl;
    }
};
class Dog:public Animal{
    public:
    void bark(){
        cout<<"This animal is dog"<<endl;
    }
};
class Cat:public Animal{
    public:
    void meow(){
        cout<<"This animal is cat"<<endl;
    }
};
int main(){
    Dog d;
    Cat c;

    d.eat();
    d.bark();

    c.eat();
    c.meow();

    return 0;
}