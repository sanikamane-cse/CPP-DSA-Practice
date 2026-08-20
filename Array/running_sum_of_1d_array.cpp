#include<iostream>
using namespace std;

int main(){

     int arr[]={1,2,3,4};
     int n=4;

     for(int i=1;i<n;i++){
        arr[i]=arr[i]+arr[i-1];

     }
     
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }

     return 0;
}