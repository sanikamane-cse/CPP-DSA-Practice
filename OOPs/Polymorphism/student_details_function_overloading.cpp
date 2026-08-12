#include<iostream>
using namespace std;

class Student
{
public:
    void display(string name)
    {
        cout << "Name: " << name << endl;
    }

    void display(string name, int age)
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    void display(string name, int age, int rollNo)
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

int main()
{
    Student s;

    s.display("Sanika");
    cout << endl;

    s.display("Sanika", 20);
    cout << endl;

    s.display("Sanika", 20, 101);

    return 0;
}

