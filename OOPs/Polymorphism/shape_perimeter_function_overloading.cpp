#include<iostream>
using namespace std;

class Perimeter
{
public:
    int perimeter(int side)
    {
        return 4 * side;
    }

    int perimeter(int length, int breadth)
    {
        return 2 * (length + breadth);
    }

    double perimeter(double radius)
    {
        return 2 * 3.14 * radius;
    }
};

int main()
{
    Perimeter p;

    cout << "Square: " << p.perimeter(5) << endl;
    cout << "Rectangle: " << p.perimeter(5, 4) << endl;
    cout << "Circle: " << p.perimeter(3.0) << endl;

    return 0;
}

