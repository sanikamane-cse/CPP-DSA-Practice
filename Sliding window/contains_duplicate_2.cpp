#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){

    vector<int>nums={1,2,3,1};
    unordered_map<int,int>mp;
    int k=3;

    bool isduplicate=false;

    for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i])!=mp.end()){
            if(i-mp[nums[i]]<=k){

                isduplicate=true;
                break;

            }
             
        }
        mp[nums[i]]=i;
        
    }
    cout<<isduplicate;
    return 0;

}