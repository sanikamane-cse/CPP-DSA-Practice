#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

};
int main(){
Node* first=new Node();
first->data=10;
first->next=NULL;
cout<<"Node 10 conncted successfully"<<endl;
cout<<first->data;
delete first;
return 0;

}




