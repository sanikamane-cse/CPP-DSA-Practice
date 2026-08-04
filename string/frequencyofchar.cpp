#include<iostream>
#include<vector>
using namespace std;
int main(){

    string s="programming";
    vector<int> count(26,0);

    for(int i=0;i<s.size();i++){
        count[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
       if(count[i]>0){
        cout<<char('a'+i)<<" ";
        cout<<count[i]<<endl;
       }
    }
    return 0;
}