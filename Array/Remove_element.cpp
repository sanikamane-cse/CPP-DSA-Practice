#include<iostream>
using namespace std;

int main(){

    int arr[]={0,1,2,2,3,0,4,2};
    int n=8;
    int i=0;

    int val=2;

    for(int j=0;j<n;j++){
        if(arr[j]!=val){
            arr[i]=arr[j];
            i++;
        }
    }
    
    cout<<"Modified array:";
    for(int j=0;j<i;j++){
         cout<<arr[j]<<" ";

    }
    
    cout<<endl;
    cout<<"Total element :"<<i;
   
    return 0;
}