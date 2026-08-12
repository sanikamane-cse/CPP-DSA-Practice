#include<iostream>
using namespace std;

class Shape
{
public:
    virtual void area()
    {
        cout << "Shape Area" << endl;
    }
};

class Circle : public Shape
{
public:
    void area() override
    {
        cout << "Circle Area: " << 3.14 * 5 * 5 << endl;
    }
};

class Rectangle : public Shape
{
public:
    void area() override
    {
        cout << "Rectangle Area: " << 5 * 4 << endl;
    }
};

int main()
{
    Shape *ptr;

    Circle c;
    Rectangle r;

    ptr = &c;
    ptr->area();

    ptr = &r;
    ptr->area();

    return 0;
}

