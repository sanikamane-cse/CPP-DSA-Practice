#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node* top = NULL;

void push(int value)
{
    Node* newNode = new Node(value);

    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Popped: " << top->data << endl;

        Node* temp = top;
        top = top->next;

        delete temp;
    }
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Top: " << top->data << endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    peek();

    pop();

    peek();

    return 0;
}