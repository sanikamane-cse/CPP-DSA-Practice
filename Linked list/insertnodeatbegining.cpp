#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
int main(){
    Node* head=new Node();
    head->data=10;
    head->next=NULL;

    Node* newNode=new Node();
    newNode->data=5;
    newNode->next=head;

    head=newNode;

    Node* temp=head;

    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;


}