#include<iostream>
using namespace std;

int main(){

    int arr[]={2,2,1,1,1,2,2};
    int n=7;

    int element=0;
    int count=0;

    for(int i=0;i<n;i++){

        if(count==0){
            element =arr[i];
        }

        if(arr[i]=element){
            count++;
        }

        else{
            count--;
        }

    }
    
    cout<<"Majority element:"<<element;
    return 0;
}