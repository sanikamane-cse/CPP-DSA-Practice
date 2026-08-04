#include<iostream>
using namespace std;
void printEven(int arr[],int size){
    for(int i=0;i<size;i++){
        if(arr[i]%2==0){
            cout<<arr[i]<<" ";
        }
    }
}
int main(){
    int arr[5]={23,54,66,87,20};
    cout<<"Even numbers in array:";
    printEven(arr,5);
}