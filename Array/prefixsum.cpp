#include<iostream>
using namespace std;
int main(){
    int arr[5]={2,4,1,3,7};
    for(int i=1;i<5;i++){
        arr[i]=arr[i]+arr[i-1];
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";

    }
    return 0;
}