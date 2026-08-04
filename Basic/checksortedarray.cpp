#include<iostream>
using namespace std;
int main(){
    int arr[5]={10,30,20,40,50};
    bool sorted=true;

    for(int i=0;i<4;i++){
        if(arr[i]>arr[i+1]){
            sorted=false;
            break;
        }
    }
    if(sorted){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is unsorted"<<endl;
    }
    return 0;
}