#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main(){
    Node* first = new Node(10);
    first->next = new Node(20);
    first->next->next = new Node(40);

    Node* second=new Node(15);
    second->next=new Node(25);
    second->next->next=new Node(50);

    Node* head=NULL;
    Node* tail=NULL;

    if(first->data<second->data){
          head=first;
          first=first->next;

    }else{
        head=second;
        second=second->next;
    }

    tail=head;

    while(first!=NULL && second!=NULL){
         if(first->data < second->data)
        {
            tail->next = first;
            first = first->next;
        }
        else
        {
            tail->next = second;
            second = second->next;
        }

        tail = tail->next;
    }

     if(first != NULL)
        tail->next = first;
    else
        tail->next = second;

  
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}