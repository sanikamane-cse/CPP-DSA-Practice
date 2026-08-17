#include <iostream>
using namespace std;

int stack[5];
int top = -1;

void push(int value)
{
    if (top == 4)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

     cout << "Stack elements:" << endl;

    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }


    return 0;
}