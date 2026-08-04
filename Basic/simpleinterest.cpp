#include<iostream>
using namespace std;
int main(){
    int p,r,t,SI;
    cout<<"enter principle amount :";
    cin>>p;
    cout<<"enter rate amount:";
    cin>>r;
    cout<<"enter time:";
    cin>>t;
    SI=(p*r*t)/100;
    cout<<"simple interest is:"<<SI<<endl;
    return 0;

}