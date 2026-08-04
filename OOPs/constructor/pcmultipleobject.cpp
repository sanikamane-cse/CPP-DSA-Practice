#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int rollno;

    Student(string n,int r){
        name=n;
        rollno=r;
    }
};
int main(){
    Student s1("Sanika",95);
    Student s2("priya",98);
    Student s3("Nita",101);

    cout<<s1.name<<" "<<s1.rollno<<endl;
    cout<<s2.name<<" "<<s2.rollno<<endl;
    cout<<s3.name<<" "<<s3.rollno<<endl;
    return 0;

}