#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums={2,3,5,8,4};

    int countEven=0;
    int countOdd=0;


    for(int i=0;i<nums.size();i++){

        if(nums[i]%2==0)
        {
            countEven++;
        }

        else
        {
            countOdd++;

        }

    }
    
    cout<<"Even number count is:"<<countEven<<endl;
    cout<<"Odd number count is:"<<countOdd<<endl;

    return 0;
}