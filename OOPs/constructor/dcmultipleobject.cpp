#include<iostream>
using namespace std;
class Student {
    public:
    Student(){
        cout<<"Default constructor called"<<endl;
    }
};
int main(){
    Student s1;
    Student s2;
    Student s3;
    return 0;
}