#include<iostream>
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

int main()
{
    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(6);


    int val = 6;


    while(head != NULL && head->data == val)
    {
        head = head->next;
    }


    Node* temp = head;

    while(temp != NULL && temp->next != NULL)
    {
        if(temp->next->data == val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }


    temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }


    return 0;
}