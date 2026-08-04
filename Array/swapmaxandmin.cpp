#include<iostream>
using namespace std;

void swapminmax(int arr[],int n){
    int minIndex=0,maxIndex=0;

    for(int i=1;i<n;i++){
        if(arr[i]<arr[minIndex])
        minIndex=i;
        if(arr[i]>arr[maxIndex])
        maxIndex=i;
    }
    int temp =arr[minIndex];
    arr[minIndex]=arr[maxIndex];
    arr[maxIndex]=temp;
}
int main(){
    int arr[]={1,2,3,4};
    int n=4;
    swapminmax(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


