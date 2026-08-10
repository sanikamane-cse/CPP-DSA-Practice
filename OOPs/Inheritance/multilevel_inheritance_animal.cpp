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
        cout<<"Dog is barking"<<endl;
    }
};
class Puppy:public Dog{
    public:
    void cry(){
        cout<<"Puppy is crying"<<endl;
    }
};
int main(){
    Puppy p;
    p.eat();
    p.bark();
    p.cry();

    return 0;
}