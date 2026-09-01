#include<iostream>
#include<string>

using namespace std;

int main(){

    string s="hello word cpp";
    string ans=" ";

    for(int i=0;i<s.size();i++){

        if(s[i]!=' '){
            ans+=s[i];
        }
    }
    cout<<"String without spaces:"<<ans;
    
    return 0;
}
