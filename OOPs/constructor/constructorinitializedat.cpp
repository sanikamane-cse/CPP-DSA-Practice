#include<iostream>
using namespace std;

class Student{
    public:

    string name;
    int rollno;

    Student(){
        name="Sanika";
        rollno=95;
    }
};
int main(){
    Student s1;
    cout<<"Name="<<s1.name<<endl;
    cout<<"RollNo="<<s1.rollno;
    return 0;
}