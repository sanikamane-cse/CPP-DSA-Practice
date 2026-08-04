#include<iostream>
using namespace std;
int main(){
    int arr[5]={10,35,23,47,5};
    int* ptr=arr;
    int min=*ptr;
    for(int i=0;i<5;i++){
        if(*(ptr+i)<min){
            min=*(ptr+i);
        }
    }
    cout<<"Minimum="<<min;
}