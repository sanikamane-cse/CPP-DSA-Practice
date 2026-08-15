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
 Node* head=new Node(1);
Node* second=new Node(2);
Node* third=new Node(3);
Node* forth=new Node(4);
Node* fifth=new Node(5);

head->next=second;
second->next=third;
third->next=forth;
forth->next=fifth;

int left=2;
int right=4;

Node dummy(0);
dummy.next=head;

Node* prev=&dummy;
for(int i=1;i<left;i++){
    prev=prev->next;
}

Node* curr=prev->next;
for(int i=0;i<right-left;i++){
    Node* next=curr->next;
    curr->next=next->next;
    next->next=prev->next;
    prev->next=next;
}
Node* temp = dummy.next;

while(temp != NULL){
    cout << temp->data << " ";
    temp = temp->next;
}

return 0;


}

