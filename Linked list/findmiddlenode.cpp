#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
int main(){
    Node* head=new Node();
    Node* second=new Node();
    Node* third=new Node();
    Node* forth=new Node();
    Node* fifth=new Node();

    head->data=10;
    second->data=20;
    third->data=30;
    forth->data=40;
    fifth->data=50;

    head->next=second;
    second->next=third;
    third->next=forth;
    forth->next=fifth;
    fifth->next=NULL;

    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
    return 0;
}