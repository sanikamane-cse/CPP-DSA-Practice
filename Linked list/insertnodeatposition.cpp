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
    Node* third=new Node(30);

    head->next=second;
    second->next=third;

    int pos=3;
    
    Node* newNode=new Node(25);
  
    Node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;

    temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;

    
}