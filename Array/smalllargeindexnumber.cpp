#include<iostream>
#include<climits>
using namespace std;
int main(){
    int nums[5]={23,45,6,-9,20};
    int size=5;

    int small=INT_MAX;
    int index=-1;
    

    for(int i=0;i<size;i++){
        if(nums[i]<size){
            small=nums[i];
            index=i;
        }
    }
    cout<<"small = "<<small<<endl;
    cout<<"index = "<<index<<endl;
    return 0;
}