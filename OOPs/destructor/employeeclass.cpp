#include<iostream>
using namespace std;
class Employee{
    public:

    int *salary;

    Employee(){
        salary=new int(20000);
    }
    ~Employee(){
        delete salary;
        cout<<"memory released";
    }
};
int main(){
    Employee e1;
    return 0;
}