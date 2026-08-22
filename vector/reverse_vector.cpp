#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int>  nums={10,20,30,40,50};

    int start=0;
    int end=nums.size()-1;

    while(start<end){
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;

        start++;
        end--;
    }
    cout<<"Reverse vector:";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}