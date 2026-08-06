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

head->data=10;
head->next=second;

second->data=20;
second->next=NULL;

Node* newNode=new Node();
newNode->data=30;
newNode->next=NULL;

Node* temp=head;
while(temp->next != NULL){
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
