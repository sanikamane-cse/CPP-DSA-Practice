#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n=5;
    int arr[5]={1,-5,3,4,10};

    int maxSum=INT_MIN;

    for(int st=0;st<n;st++){   //st=start
       int currSum=0;
       for(int end=st;end<n;end++){
        currSum+=arr[end];
        maxSum=max(currSum,maxSum);
       }
    }
    cout<<"max subarray sum="<<maxSum<<endl;
    
return 0;
}