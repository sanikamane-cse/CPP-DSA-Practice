#include<iostream>
using namespace std;
class Person{
    public:
    string name;

    void displayPerson(){
        cout<<"Name:"<<name<<endl;
    }
};
class Employee:public Person{
    public:
    int salary;
    void displayEmployee(){
        cout<<"Salary:"<<salary<<endl;
    }
};
class Manager:public Employee{
    public:
    string dep;
    void displayManager(){
        cout<<"Department:"<<dep<<endl;

    }
};
int main(){
   Manager m;
   m.name="Sanika";
   m.salary=10000;
   m.dep="CSE";

   m.displayPerson();
   m.displayEmployee();
   m.displayManager();
   return 0;

}
