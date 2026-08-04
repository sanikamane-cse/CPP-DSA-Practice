#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    int age;
    Student(){
        name="Sanika";
        age=20;
    }
};
int main(){
    Student s1;
    cout<<"Name="<<s1.name<<endl;
    cout<<"Age="<<s1.age;
    return 0;
}