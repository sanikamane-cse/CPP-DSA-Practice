#include<iostream>
using namespace std;
int main(){
    int* ptr=nullptr;
    int x=100;
    ptr=&x;
    cout<<*ptr;
    return 0;
}