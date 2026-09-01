#include<iostream>
#include<string>
using namespace std;

int main(){

    string s="HELLO WORLD";

    for(int i=0;i<s.size();i++){

        if(s[i] >= 'A' && s[i] <='Z'){

            s[i]=s[i] - 'A' + 'a';

        }
    }

    cout<<"Lower case string : "<<s<<endl;
    return 0;
}