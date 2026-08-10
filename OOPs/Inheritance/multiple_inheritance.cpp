#include<iostream>
using namespace std;

class Teacher
{
public:
    void teach()
    {
        cout << "Teacher is teaching" << endl;
    }
};

class Researcher
{
public:
    void research()
    {
        cout << "Researcher is doing research" << endl;
    }
};

class Professor : public Teacher, public Researcher
{
public:
    void guide()
    {
        cout << "Professor is guiding students" << endl;
    }
};

int main()
{
    Professor p;

    p.teach();
    p.research();
    p.guide();

    return 0;
}