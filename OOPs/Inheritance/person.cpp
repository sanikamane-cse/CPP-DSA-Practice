#include<iostream>
using namespace std;

class Person{
    public:
    void show(){
        cout<<"This is person"<<endl;
        
    }
};
class Student:public Person{
    public:
    void display(){
        cout<<"Person is student"<<endl;
    }
};
int main(){
    Student s;
    s.show();
    s.display();
    return 0;

}