#include<iostream>
#include<climits>
using namespace std;

int secondlargest(int arr[],int n){
    if(n<2) return -1;
    int largest=INT_MIN;
    int secondlargest=INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondlargest=largest;
            largest=arr[i];
        }else if(arr[i]<largest && arr[i]>secondlargest){
            secondlargest=arr[i];
        }
    }
    if(secondlargest==INT_MIN)
       return -1;
       
    return secondlargest;
}

int main(){
    int arr[]={10,34,56,76,30};
    int n=5;
    cout<<"Second largest="<<secondlargest(arr,n)<<endl;
    return 0;
}