#include<iostream>
using namespace std;

bool isEven(int n)
{
    if(n % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;

    bool result = isEven(n);

    if(result)
    {
        cout << "Number is Even" << endl;
    }
    else
    {
        cout << "Number is Odd" << endl;
    }

    return 0;
}