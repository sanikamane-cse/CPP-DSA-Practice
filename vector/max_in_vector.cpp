#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums={20,13,56,43};

    int max=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]>max){
            max=nums[i];
        }
    }
    cout<<"Maximum element:"<<max;
    return 0;
}