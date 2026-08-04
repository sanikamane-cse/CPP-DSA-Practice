#include<iostream>
using namespace std;

int reversearray(int arr[],int n){
int startindex=0;
int endindex=n-1;


while(startindex<endindex){
    int temp=arr[startindex];
    arr[startindex]=arr[endindex];
    arr[endindex]=temp;
    startindex++;
    endindex--;

}

}
int main(){
    int arr[]={1,2,3,4,5};
    int n=5;

    reversearray(arr,n);
    cout<<"reversedarray:"<<" ";
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   }
    
    return 0;
}


