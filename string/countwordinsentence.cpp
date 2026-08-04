#include<iostream>
#include<string>
using namespace std;
int main(){
    string s=" I Love C++ programming";
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ' && (i==0 || s[i-1]==' ')){
            count++;
        }
    }
    cout<<count<<endl;
}
