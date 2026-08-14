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

    head->data=10;
    second->data=20;
    third->data=30;

    head->next=second;
    second->next=third;
    third->next=NULL;


   int count=0;

   Node* temp=head;
   while(temp!=NULL){
   count++;
   temp=temp->next;
   }
   cout<<"Number of nodes:"<<count;
   return 0;

}