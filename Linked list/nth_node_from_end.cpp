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
    Node* forth=new Node(40);

    head->next=second;
    second->next=third;
    third->next-forth;

    int n=3;
    Node* slow=head;
    Node* fast=head;

    for(int i=1;i<n;i++){
        if(fast==NULL){
            cout<<"invalid position";
            return 0;
        }
        fast=fast->next;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    cout<<"Nth node from end:"<<slow->data;
    return 0;


}