#include<iostream>
using namespace std;

void reverseArray(int arr[],int size,int start,int end){
    
        while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
        for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
  
    }
}
int main(){
    int arr[5]={10,20,30,40,50};
    reverseArray(arr,5,0,4);
}