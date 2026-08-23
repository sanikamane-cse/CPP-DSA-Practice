#include<iostream>
using namespace std;

int main(){

    int arr[9]={-2,1,-3,4,-1,2,1,-5,4};

    int currentSum=arr[0];
    int maxSum=arr[0];

    for(int i=0;i<9;i++){
        currentSum=max(arr[i],currentSum+arr[i]);
        maxSum=max(maxSum,currentSum);
    }
    cout<<"Maximum Sum:"<<maxSum;
    return 0;
}
