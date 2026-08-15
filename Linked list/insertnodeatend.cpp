#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);

    head->next=second;

    Node* newNode=new Node(30);

    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;

    temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;

}