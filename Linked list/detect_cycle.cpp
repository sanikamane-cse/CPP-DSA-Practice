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
bool detectCycle(Node* head){

        Node* slow=head;
        Node* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                return true;
            }

        }
        return false;
    }
int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* forth=new Node(40);

    head->next=second;
    second->next=third;
    third->next=forth;

    forth->next=second;

    if(detectCycle(head)){
        cout<<"Cycle is detected";
    }else{
        cout<<"Cycle is not detected";
    }
}