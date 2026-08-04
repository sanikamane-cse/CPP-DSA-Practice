#include<iostream>
using namespace std;
int main(){
    int arr[5];

    cout<<"Enter element of array:";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    int min=arr[0];

    for(int i=1;i<5;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"Minimum:"<<min<<endl;
    return 0;
}