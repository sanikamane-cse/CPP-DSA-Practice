
#include<iostream>
using namespace std;

class BankAccount
{
public:
    virtual void calculateInterest()
    {
        cout << "Bank Account Interest" << endl;
    }
};

class SavingsAccount : public BankAccount
{
public:
    void calculateInterest() override
    {
        cout << "Savings Account Interest" << endl;
    }
};

int main()
{
    SavingsAccount s;

    s.calculateInterest();

    return 0;
}

