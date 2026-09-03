#include<iostream>
#include<string>
#include<vector>

using namespace std;

string removeduplicate(string s){

    vector<char> freq (26,0);
    string ans="";

    for(int i=0;i<s.length();i++){

        if(freq[s[i] - 'a']==0){
            ans+=s[i];

            freq[s[i] - 'a']=1;
        }
    }
    return ans;
}
int main(){
    string s="programming";
    cout<<"String after removing duplicates:"<<removeduplicate(s);
}