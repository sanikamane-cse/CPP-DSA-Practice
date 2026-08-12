#include<iostream>
#include<stack>
#include<vector>
using namespace std;
  int main(){
 vector<int> nums={1,2,1};
stack<int>st;

vector<int>ans(nums.size(),-1);

for(int i=0;i<2*nums.size();i++){
    int index=i%nums.size();
    while(!st.empty() && nums[index]>nums[st.top()]){
        ans[st.top()] = nums[index];
         st.pop();
    }
   
    if(i<nums.size()){
    st.push(index);
}
    
}
for(int i=0;i<ans.size();i++){
  cout<<ans[i]<<" ";
}

return 0;
  }




