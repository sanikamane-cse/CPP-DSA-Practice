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

    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    head = prev;

    Node* temp = head;

   while(temp != NULL)
   {
    cout << temp->data << " ";
    temp = temp->next;
   }

    return 0;

}