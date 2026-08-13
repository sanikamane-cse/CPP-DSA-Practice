#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(6);
    Node* fourth = new Node(4);
    Node* fifth = new Node(6);
    Node* sixth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    int val = 6;

    Node dummy(0);
    dummy.next = head;

    Node* previous = &dummy;
    Node* current = head;

    while(current != NULL)
    {
        if(current->data == val)
        {
            previous->next = current->next;
            current = current->next;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    Node* temp = dummy.next;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}