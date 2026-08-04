#include<iostream>
using namespace std;
void changeValue(int* ptr){
    *ptr=100;
}
int main(){
    int num=10;
    cout<<"Before change num:"<<num<<endl;

    changeValue(&num);

    cout<<"After change num:"<<num<<endl;

    return 0;
}