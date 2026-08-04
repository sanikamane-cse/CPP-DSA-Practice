#include<iostream>
#include<climits>
using namespace std;

int thirdlargest(int arr[],int n){

    
    int first=INT_MIN;
    int second=INT_MIN;
    int third=INT_MIN;

    for(int i=0;i<n;i++){
        int num=arr[i];
        if(num==first||num==second||num==third)
        continue;

        if(num>first){
            third=second;
            second=first;
            first=num;
        }else if(num>second){
            third=second;
            second=num;

        }else if(num>third){
            third=num;
        }
    }
    if (third==INT_MIN){
       return first;
    } 
    else{
        return third;
    }

   
}
int main(){
  int arr[4]={12,34,67,54};
  int n=4;
  cout<<"Thirdlargest="<<thirdlargest(arr,n)<<endl;
return 0;
}