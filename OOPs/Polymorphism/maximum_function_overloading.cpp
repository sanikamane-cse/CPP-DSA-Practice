#include<iostream>
using namespace std;

class Maximum
{
public:
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int max(int a, int b, int c)
    {
        return (a > b && a > c) ? a : (b > c ? b : c);
    }

    double max(double a, double b)
    {
        return (a > b) ? a : b;
    }
};

int main()
{
    Maximum m;

    cout << m.max(10, 20) << endl;
    cout << m.max(10, 20, 30) << endl;
    cout << m.max(10.5, 20.5) << endl;

    return 0;
}

