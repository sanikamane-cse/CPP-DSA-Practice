#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums={0,1,0,3,12};

    int i=0;
    for(int j=0;j<nums.size();j++){
        if(nums[j]!=0){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
        }
    }

        
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
   
}