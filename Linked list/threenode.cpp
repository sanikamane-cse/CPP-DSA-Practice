#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
int main(){

    Node* first=new Node();
    Node* second=new Node();
    Node* third=new Node();

    first->data=10;
    second->data=20;
    third->data=30;

    first->next=second;
    second->next=third;
    third->next=NULL;

    cout<<"All nodes connected successfully"<<endl;
    

    delete first;
    delete second;
    delete third;

    return 0;


}