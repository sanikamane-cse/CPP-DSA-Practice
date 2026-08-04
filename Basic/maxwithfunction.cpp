#include<iostream>
using namespace std;

int findmax(int a,int b,int c){

    int max=a;

    if(b>max){
        max=b;
    }

    if(c>max){
       max=c;
    }

    return max;
}

int main(){
    
        int x,y,z;
        cout<<"Enter three numbers:";
        cin>>x>>y>>z;

        int result=findmax(x,y,z);
        cout<<"Maximum="<<result<<endl;
        return 0;
    }