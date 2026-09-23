#include<iostream>
using namespace std;
int main(){

    int arr[]={2,3,-1,8,4};
    int n=5;

    int totalSum=0;

    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }

    int leftSum=0;

    for(int i=0;i<n;i++){
        int rightSum=totalSum-leftSum-arr[i];

        if(leftSum==rightSum){
          cout << i << endl;
        }
        leftSum += arr[i];
    }

    return 0;



}