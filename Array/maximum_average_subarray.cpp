#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int sum=0;
    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    int maxSum=sum;

    for(int i=k;i<nums.size();i++){
        sum=sum-nums[i-k]+nums[i];
        maxSum=max(maxSum,sum);
    }
    cout<<"Average="<<(double)maxSum/k<<endl;
    return 0;
    
}