#include<iostream>
using namespace std;
int main(){
    int arr[5]={10,20,30,40,50};

    int* left=arr;
    int* right=arr+4;

    while(left<right){
        int temp=*left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    cout<<"Reversed array:";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}