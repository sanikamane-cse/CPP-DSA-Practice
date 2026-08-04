#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int age;

    Student(string n,int a ){
        name=n;
        age=a;
    }
    Student (const Student &obj){
        name=obj.name;
        age=obj.age;
    }
};
int main(){
    Student s1("Sanika",20);

    Student s2=s1;

    cout<<s2.name<<endl;
    cout<<s2.age<<endl;
    return 0;
}