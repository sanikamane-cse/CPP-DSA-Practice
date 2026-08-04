#include<iostream>
using namespace std;
int main(){
    int arr[6]={10,20,11,3,7,1};

    int count=0;

    for(int i=0;i<6;i++){
        if(arr[i]>5){
            count++;
        }
    }
    cout<<"Count:"<<count;
    return 0;


}