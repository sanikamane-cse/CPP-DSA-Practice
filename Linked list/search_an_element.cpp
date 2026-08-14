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
    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);

    first->next=second;
    second->next=third;
    third->next=NULL;

    int key=20;
    bool found=false;

    Node* temp=first;
    while(temp!=NULL){
       if(temp->data==key){
        found=true;
        break;
       }
       temp=temp->next;
    }
    if(found){
        cout<<"Element found";
    }else{
        cout<<"Element not found";
    }
    return 0;


}