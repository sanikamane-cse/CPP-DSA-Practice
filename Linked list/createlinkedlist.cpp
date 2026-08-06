#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
int main(){
Node* first=new Node();
Node* second=new Node();
Node* third=new Node();
Node* forth=new Node();

first->data=10;
second ->data=20;
third->data=30;
forth->data=40;

first->next=second;
second->next=third;
third->next=forth;
forth->next=NULL;

Node* temp=first;

while(temp != NULL){
   cout<<temp->data<<" ";
   temp=temp->next;

}
delete first;
delete second;
delete third;
delete forth;
return 0;

}
