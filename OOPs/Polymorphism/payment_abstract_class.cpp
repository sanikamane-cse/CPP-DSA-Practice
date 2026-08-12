#include<iostream>
using namespace std;

class Payment
{
public:
    virtual void pay() = 0;
};

class UPI : public Payment
{
public:
    void pay() override
    {
        cout << "Payment through UPI" << endl;
    }
};

class CreditCard : public Payment
{
public:
    void pay() override
    {
        cout << "Payment through Credit Card" << endl;
    }
};

int main()
{
    UPI u;
    CreditCard c;

    u.pay();
    c.pay();

    return 0;
}

