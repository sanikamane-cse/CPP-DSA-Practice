#include<iostream>
using namespace std;
class Animal{
    public:
    void show(){
        cout<<"Animal is sleeping"<<endl;
    }
};
class Cat:public Animal{
    public:
    void sound(){
        cout<<"meaw meaw"<<endl;
    }
};
int main(){
    Cat c;
    c.show();
    c.sound();
    return 0;
}