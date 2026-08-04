#include<iostream>
using namespace std;
 class Student{
    public:
    string name;
    int age;
 };
 int main(){
    Student s1,s2;
    s1.name="sanika";
    s1.age=20;
    s2.name="priya";
    s2.age=19;
    cout<<"Name:"<<s1.name<<endl;
    cout<<"Age:"<<s1.age<<endl;
    cout<<"Name:"<<s2.name<<endl;
    cout<<"Age:"<<s2.age<<endl;
    
    return 0;


 }