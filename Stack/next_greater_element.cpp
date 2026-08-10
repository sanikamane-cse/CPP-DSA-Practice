#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){

    vector<int> nums1={4,1,2};
    vector<int> nums2={1,3,4,2};

    stack<int>st;
    unordered_map<int,int>mp;

    for(int num:nums2){
        while(!st.empty() && num>st.top()){
          mp[st.top()]=num;
          st.pop();
        }
        st.push(num);
    }
    while(!st.empty()){
        mp[st.top()]=-1;
         st.pop();
    }
    vector<int>ans;
    for(int num:nums1){
      ans.push_back(mp[num]);
      
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    
    return 0;
}