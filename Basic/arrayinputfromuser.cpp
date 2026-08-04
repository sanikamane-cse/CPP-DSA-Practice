#include<iostream>
using namespace std;
int main(){
    int arr[5];
    int n;
    int largest=arr[0];
    
    cout<<"Enter elements of array:";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    cout<<"Elements of array:";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
    

}