#include<iostream>
#include<vector>
using namespace std;
int main(){

    string s="anagram";
    string t="sfght";
    bool isAnagram=true;
    vector<int> count(26,0);

    if(s.size()!=t.size()){
        cout<<"not anagram"<<endl;
        return 0;
    }

    for(int i=0;i<s.size();i++){
        count[s[i]-'a']++;

    }
    for(int i=0;i<t.size();i++){
        count[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(count[i]!=0){
            isAnagram=false;
        }
    }
    if(isAnagram==true){
        cout<<"anagram"<<endl;
    }else{
        cout<<"not anagram"<<endl;
    }
    return 0;
}