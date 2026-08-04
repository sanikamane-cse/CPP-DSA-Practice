#include<iostream>
using namespace std;
class Employee{
    public:
    string name;
    double salary;

};
int main(){
    Employee e1,e2;
    e1.name="sanika";
    e1.salary=10000;

    e2.name="atharv";
    e2.salary=20000;

    cout<<"Name:"<<e1.name<<endl;
    cout<<"Salary:"<<e1.salary<<endl;

    cout<<"Name:"<<e2.name<<endl;
    cout<<"Salary:"<<e2.salary<<endl;

    return 0;



}
