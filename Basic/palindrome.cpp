#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter value of n:";
    cin>>n;

    int original=n;
    int rem,rev=0;

    while(n>0){
    rem=n%10;
    rev=rev*10+rem;
    n=n/10;
   }
   
   if(original==rev){
    cout<<"Palindrome";
   }
   else{
    cout<<"Not Palindrome";
   }
return 0;

}
