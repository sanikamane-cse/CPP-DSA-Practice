#include<iostream>
#include <climits>  
using namespace std;
int main(){
   int nums[5]={30,20,1,-15,38};
      int size=5;

      int smallest = INT_MAX;
      int largest = INT_MIN; 

      for(int i=0;i<size;i++){
        //largest=max(nums[i],largest);   short 
        if(nums[i]>largest){
            largest=nums[i];
        }
      }
      for(int i=0;i<size;i++){
        //smallest=min(nums[i],smallest);  short without using if conditions only use for
        if(nums[i]<smallest){
            smallest=nums[i];
        }
      }
      cout<<"largest="<<largest<<endl;
      cout<<"smallest="<<smallest<<endl;
      return 0;
}