#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];

    cout<<"Enter array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
       
    }
    for(int i=1;i<n;i++){
        arr[i]=arr[i]+arr[i-1];
    }

    cout<<"Prefix sum of array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
   
}