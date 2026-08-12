#include<iostream>
using namespace std;

class Employee
{
public:
    virtual void calculateSalary() = 0;
};

class Manager : public Employee
{
public:
    void calculateSalary() override
    {
        cout << "Manager Salary: 50000" << endl;
    }
};

class Developer : public Employee
{
public:
    void calculateSalary() override
    {
        cout << "Developer Salary: 40000" << endl;
    }
};

int main()
{
    Manager m;
    Developer d;

    m.calculateSalary();
    d.calculateSalary();

    return 0;
}

