#include<iostream>
using namespace std;
int main(){
    int arr[]={-3,2,-3,4,2};
    int n=5;
    int runningSum=0;
    int minSum=runningSum;

    for(int i=0;i<n;i++){
        runningSum=runningSum+arr[i];

        if(runningSum<minSum){
            minSum=runningSum;
        }
    }
    int ans=1-minSum;

    cout<<ans<<endl;
    return 0;

}