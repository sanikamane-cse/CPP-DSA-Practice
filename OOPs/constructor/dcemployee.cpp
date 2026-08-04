#include<iostream>
using namespace std;
class Employee{
    public:

    string name;
    int salary;
    
    Employee(){
        name="unknown";
        salary=0;

    }
};
int main(){
    Employee e1;

    cout<<"Employee Name:"<<e1.name<<endl;
    cout<<"Salary:"<<e1.salary;
    return 0;
}