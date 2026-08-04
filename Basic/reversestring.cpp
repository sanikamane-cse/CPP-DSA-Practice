#include<iostream>
#include<string>
using namespace std;
int main(){
    string name ="Sanika";
    int start=0;
    int end=name.length()-1;
    while(start<end){
        swap(name[start],name[end]);
        start++;
        end--;
    }
    cout<<name;
    return 0;

}