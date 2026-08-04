#include<iostream>
#include<string>
using namespace std;

string checkevenodd(int n){

    if(n%2==0){ 
        return "Even";
    }
    else{
        return "Odd";
    }
}
int main(){

    int n;
    cout<<"Enter a number:";
    cin>>n;

    string result=checkevenodd(n);

    if(result=="Even"){
        cout<<"number is even";
    }
    else{
        cout<<"number is odd";
    }
    return 0;



}