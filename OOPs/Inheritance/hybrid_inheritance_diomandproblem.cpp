#include<iostream>
using namespace std;

class Person
{
public:
    void displayPerson()
    {
        cout << "This is Person" << endl;
    }
};

class Student : virtual public Person
{
public:
    void study()
    {
        cout << "Student is studying" << endl;
    }
};

class Employee : virtual public Person
{
public:
    void work()
    {
        cout << "Employee is working" << endl;
    }
};

class TeachingAssistant : public Student, public Employee
{
public:
    void assist()
    {
        cout << "Teaching Assistant is assisting" << endl;
    }
};

int main()
{
    TeachingAssistant obj;

    obj.displayPerson();
    obj.study();
    obj.work();
    obj.assist();

    return 0;
}