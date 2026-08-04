#include<iostream>
using namespace std;
class Student {
    public:
    Student(){
        cout<<"Student object created"<<endl;
    }
};

int main(){
    Student s1;
    Student s2;
    return 0;
}