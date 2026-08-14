#include<iostream>
using namespace std;
class  Node{
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
   
    cout<<"Data:"<<first->data<<" ";
    return 0;
}