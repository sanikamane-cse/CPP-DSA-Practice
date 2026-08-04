#include<iostream>
using namespace std;
class Student{
    public:

    Student(){
        cout<<"Constructor called"<<endl;
    }
    ~Student(){
        cout<<"Destructor called"<<endl;
    }
};
int main(){
    Student s1;

    Student s2;

    return 0;
}