#include<iostream>
#include<vector>

using namespace std;

int main(){

    int arr[]={1,2,1};
    int n=3;

    vector<int>ans (2*n);

    for(int i=0;i<n;i++){
        ans[i]=arr[i];
        ans[i+n]=arr[i];
    }
    for(int i=0;i<2*n;i++){
        cout<<ans[i]<<" ";

    }
    return 0;
  
}