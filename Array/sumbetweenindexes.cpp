#include<iostream>
using namespace std;
int main(){
    int arr[5]={2,3,5,1,7};

    for(int i=1;i<5;i++){
        arr[i]=arr[i]+arr[i-1];   //{2,5,10,11,18}
    }

    int left=2;
    int right=4;
    int sum=0;

    if(left==right){
        sum=arr[right];
    }else{
        sum=arr[right]-arr[left-1];
    }
    cout<<"Sum="<<sum<<endl;
    return 0;
    
}