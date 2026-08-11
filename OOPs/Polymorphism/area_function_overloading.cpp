#include<iostream>
using namespace std;

class Area
{
public:

    int area(int side)
    {
        return side * side;
    }

    int area(int length, int breadth)
    {
        return length * breadth;
    }

    double area(double base, double height)
    {
        return 0.5 * base * height;
    }

    double area(double radius)
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Area a;

    cout << "Area of Square: " << a.area(5) << endl;
    cout << "Area of Rectangle: " << a.area(5, 4) << endl;
    cout << "Area of Triangle: " << a.area(4.0, 5.0) << endl;
    cout << "Area of Circle: " << a.area(3.0) << endl;

    return 0;
}