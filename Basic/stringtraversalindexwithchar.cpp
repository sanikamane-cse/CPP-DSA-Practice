#include<iostream>
#include<string>
using namespace std;
int main(){
    string name="Sanika";
    
    for(int i=0;i<name.length();i++){
        
        cout<<"Index "<<i<<"="<<name[i]<<endl;
    }
    return 0;
}