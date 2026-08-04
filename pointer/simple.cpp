#include<iostream>
using namespace std;
int main(){
    int x=10;
    int* ptr=&x;
    cout<<&x<<endl;
    cout<<*ptr<<endl;
    cout<<x<<endl;
    return 0;
}