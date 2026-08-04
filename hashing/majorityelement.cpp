#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    int arr[4]={2,2,3,2};
    unordered_map<int,int>mp;
    int freq=0;
    for(int i=0;i<4;i++){
        mp[arr[i]]++;
        if(mp[arr[i]]>4/2){
        cout<<arr[i];
    }
   
    }
    
    return 0;
    
}