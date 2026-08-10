#include<iostream>
using namespace std;

class Father
{
public:
    void show()
    {
        cout << "Father's function" << endl;
    }
};

class Mother
{
public:
    void show()
    {
        cout << "Mother's function" << endl;
    }
};

class Child : public Father, public Mother
{
};

int main()
{
    Child c;

    // c.show();   // Ambiguity error

    c.Father::show();
    c.Mother::show();

    return 0;
}