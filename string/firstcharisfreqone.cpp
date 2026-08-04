#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s="programming";
    vector<int> freq(26,0);

    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    for(int i=0;i<s.size();i++){
        if(freq[s[i]-'a']==1){
           cout<<s[i];
           break;
        }
    }
    
    return 0;


}