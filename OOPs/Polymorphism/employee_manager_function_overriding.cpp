#include<iostream>
using namespace std;

class Employee{

    public:
    virtual void work(){
        cout<<"Thsi is employee class"<<endl;
    }
};

class Manager:public Employee{
    public:
    void work()override{
        cout<<"Manager sees work"<<endl;
    }
};

int main(){
    Manager m;
    m.work();
    return 0;
}