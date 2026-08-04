#include<iostream>
using namespace std;
int main(){
    int arr[5]={3,4,2,6,5};
    int k=2;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int minsum=sum;
    for(int i=k;i<5;i++){
        sum=sum-arr[i-k]+arr[i];
        if(sum<minsum){
            minsum=sum;
        }
    }
    cout<<"Minsum="<<minsum;
    return 0;
    
}