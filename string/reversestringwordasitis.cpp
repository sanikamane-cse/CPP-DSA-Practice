#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string s="the sky is blue";
    reverse(s.begin(), s.end());

    int n=s.size();
    int start=0;
    for(int i=0;i<=n;i++){
       
        if(i==n || s[i]==' '){
           reverse(s.begin()+start, s.begin()+i);
            start = i+1;
        }
    }
    cout<<s;
    return 0;

}