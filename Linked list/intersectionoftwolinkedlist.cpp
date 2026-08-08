#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
int main(){
  
    Node* list1=new Node(10);
    list1->next=new Node(20);
    list1->next->next=new Node(30);

   
    Node* list2=new Node(5);
    list2->next=new Node(15);
    

    Node* common1=new Node(40);
    Node* common2=new Node(50);

    common1->next=common2;
    common2->next=NULL;

    list1->next->next->next=common1;
    list2->next->next=common1;

    Node* A=list1;
    Node* B=list2;
    while(A!=B){
        if(A==NULL){
            A=list2;
        }else{
            A=A->next;
        }
        if(B==NULL){
          B=list1;
        }else{
            B=B->next;
        }
       
    }
    if(A!=NULL){
      cout<<"Intersection Node:"<<A->data<<endl;
    }else{
        cout<<"No Intersection";
    }
    return 0;


}