#include<iostream>
using namespace std;

class Display
{
public:
    void print(int value)
    {
        cout << value << endl;
    }

    void print(double value)
    {
        cout << value << endl;
    }

    void print(string value)
    {
        cout << value << endl;
    }
};

int main()
{
    Display d;

    d.print(10);
    d.print(10.5);
    d.print("Sanika");

    return 0;
}

