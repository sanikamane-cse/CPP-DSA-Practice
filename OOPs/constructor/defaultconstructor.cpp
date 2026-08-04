#include<iostream>
using namespace std;

class Student{
    public:
    Student(){
        cout<<"Default constructor called";
    }
};
int main(){
    Student s1;
    return 0;
}
