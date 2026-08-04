#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter three numbers:";
    cin>>a>>b>>c;
    
    if(a>b && a>c){
        cout<<"A is Greatest"<<endl;
    }
    else if(b>c && b>a){
        cout<<"B is greatest"<<endl;
    }
    else{
        cout<<"C is greatest"<<endl;
    }
}