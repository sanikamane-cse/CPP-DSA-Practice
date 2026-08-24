#include<iostream>
using namespace std;

int main(){

    int arr[]={3,0,1};
    int n=3;

    int ans=0;

    for(int i=0;i<n;i++){
         ans=ans ^ arr[i];
    }

    for(int i=0;i<=n;i++){
        ans=ans ^ i;
    }
    
    cout<<"Missing number:"<<ans;
    return 0;
}