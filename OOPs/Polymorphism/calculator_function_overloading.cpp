#include<iostream>
using namespace std;

class Calculator{
    public:
    int add(int a ,int b){
    return a+b;
}
   int add(int a,int b,int c){
   return a+b+c;
}
};

int main(){
    Calculator c;
    
    cout<<c.add(10,20)<<endl;
    cout<<c.add(10,20,30);
    return 0;
}