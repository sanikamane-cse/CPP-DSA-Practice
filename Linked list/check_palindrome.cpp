#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
    }

};
int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third= new Node(2);
    Node* forth=new Node(1);

    head->next=second;
    second->next=third;
    third->next=forth;
    forth->next=NULL;

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* previous=NULL;
    Node* current=slow;
    Node* next;

    while(current!=NULL){
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    
    }
    Node* first=head;
    Node* secondhalf=previous;
    bool palindrome=true;
  

    while(secondhalf!=NULL){
        if(first->data!=secondhalf->data){
           palindrome=false;
           break;
        }
            first=first->next;
            secondhalf=secondhalf->next;
        
    }
    if(palindrome){
        cout<<"palindrome"<<endl;
    }else{
        cout<<"not palindrome";
    }

    return 0;

}