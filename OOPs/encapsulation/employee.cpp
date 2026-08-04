#include<iostream>
using namespace std;
class Employee{
    private:
    double salary;
    public:
    void setSalary(double s){
        if(s>0){
            salary=s;
        }
        else{
            cout<<"Invalid salary"<<endl;
        }
    }
    int getSalary(){
        return salary;
    }
};
int main(){
    Employee e1;
    e1.setSalary(-50000);
    cout<<"Salary="<<e1.getSalary();
    return 0;
}