#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums={23,43,76,13};
    int min=0;

    for(int i=0;i<nums.size();i++){
           min=nums[i];

          if(min>nums[i]){
            min=nums[i];
          }
    }
    cout<<"Minimum element:"<<min;
    return 0;

}