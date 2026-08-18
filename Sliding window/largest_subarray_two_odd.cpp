#include<iostream>
using namespace std;

int main(){

    int arr[7]={2,5,1,8,2,9,1};

    int left=0;
    int odd_count=0;
    int max_length=0;

    for(int right=0;right<7;right++){
        if(arr[right]%2!=0){
           odd_count++;
        }

        while(odd_count>2){

            if(arr[left]%2!=0){
                odd_count--;
            }

            left++;
        }

        int currentlength=right-left+1;

        if(currentlength>max_length){
            max_length=currentlength;
        }
    }

    cout<<"Largest length:"<<max_length<<endl;

    return 0;
    
  
}