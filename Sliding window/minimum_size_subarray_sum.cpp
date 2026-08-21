#include<iostream>
#include <climits>
using namespace std;

int main(){

    int arr[6]={2,3,1,2,4,3};
    int target=7;

    int left=0;
    int sum=0;
    int minLength=INT_MAX;

    for(int right=0;right<6;right++){
        sum+=arr[right];

        while(sum>=target){
            minLength=min(minLength,right-left+1);
            sum-=arr[left];
            left++;
        }
    }

    if(minLength==INT_MAX){
        cout<<"No subarray found";
    }else{
       cout<<"Minimum Length:"<<minLength<<endl;
    }

    
    return 0;
  
}
