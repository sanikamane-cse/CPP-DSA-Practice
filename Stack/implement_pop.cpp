#include<iostream>
using namespace std;

int stack[5];
int top=-1;

void push(int value){
    if(top==4){
        cout<<"Stack is full";
    }else{
        top++;
        stack[top]=value;
        
    }
}

void pop(){
    if(top==-1){
        cout<<"Stack is empty";
    }
    else{
        cout<<"Popped:"<<stack[top]<<endl;
    }
}

int main(){
    push(10);
    push(20);
    push(30);

    pop();

    return 0;
}