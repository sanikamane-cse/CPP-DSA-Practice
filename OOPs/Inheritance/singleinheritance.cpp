#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    void displayPerson(){
        cout<<"Name:"<<name<<endl;
    }
};
class Student:public Person{
    public:
    int rollno;
    void displayStudent(){
        cout<<"Roll No:"<<rollno<<endl;
    }
};
int main(){
    Student s;

    s.name="Sanika";
    s.rollno=95;

    s.displayPerson();
    s.displayStudent();

    return 0;
}