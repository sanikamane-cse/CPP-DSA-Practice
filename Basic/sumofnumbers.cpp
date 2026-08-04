#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cout<<"Enter value of N:";
    cin>>n;

    for(int i=0;i<=n;i++){
        sum=sum+i;
    
    }
    cout<<"Sum="<<sum<<endl;
    return 0;
}