#include<iostream>
using namespace std;
int main(){
    int arr[5]={-1,-5,4,6,8};
    int left=0;
    int right=4;     //arrysize()-1 ,5-1=4
    int index=4;
    int result[5];
    
    while(left<=right){
      int leftSquare=arr[left]*arr[left];
      int rightSquare=arr[right]*arr[right];
        if(leftSquare>rightSquare){
          result[index]=leftSquare;
          left++;
    }
       else{
        result[index]=rightSquare;
        right--;
       }
       index--;
    }
    cout<<"Sorted Squares:";
    for(int i=0;i<5;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}