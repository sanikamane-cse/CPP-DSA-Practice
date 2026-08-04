#include<iostream>
using namespace std;

int add(int a,int b){
    return a+b;
}

int main(){
    int x,y;
    cout<<"Enter value of x & y:";
    cin>>x>>y;

    int result=add(x,y);
    cout<<"Sum="<<result<<endl;
    
    return 0;

}